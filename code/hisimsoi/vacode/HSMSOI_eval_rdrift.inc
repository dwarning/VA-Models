/***********************************************************************

 HiSIM (Hiroshima University STARC IGFET Model)
 Copyright (C) 2000-2016 Hiroshima University and STARC
 Copyright (C) 2016-2018 Hiroshima University
 HiSIM_SOI (Silicon-On-Insulator Model)
 Copyright (C) 2012-2016 Hiroshima University and STARC
 Copyright (C) 2016-2018 Hiroshima University

 MODEL NAME : HiSIM_SOI
 ( VERSION : 1  SUBVERSION : 4  REVISION : 0 )
 Model Parameter 'VERSION' : 1.40
 FILE : vaFiles/HSOI_eval_rdrift.inc

 Date : 2018.07.30

 released by Hiroshima University

***********************************************************************/
//
////////////////////////////////////////////////////////////////
//
//Licensed under the Educational Community License, Version 2.0
//(the "License"); you may not use this file except in
//compliance with the License.
//
//You may obtain a copy of the License at:
//
//  http://opensource.org/licenses/ECL-2.0
//
//Unless required by applicable law or agreed to in writing,
//software distributed under the License is distributed on an
//"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
//either express or implied. See the License for the specific
//language governing permissions and limitations under the
//License.
//
//
//The HiSIM_SOI standard has been supported by the members of
//Silicon Integration Initiative's Compact Model Coalition. A
//link to the most recent version of this standard can be found
//at:
//
//http://www.si2.org/cmc
//
////////////////////////////////////////////////////////////////
//

//begin : HSMHV_eval_rdrif

// Input instance parameters : NRD , NRS , NF ;
// Input model parameters : RSH , XLD , LDRIFT , LDRIFTS ;
// -- RDRMUED , RDRVMAXD , RDRMUETMP , RDRVTMP  , RDRDJUNC ;
// -- RDRMUES , RDRVMAXS ;
// Input variables : Weff , TTEMP , UC_TNOM , NOVER , NOVERS ;
real Rdrmuele , Rdrvmaxwe , Rdrvmaxle ;
real MKS_RDRMUE , MKS_RDRVMAX , RRDRBB ;
real Rsd0 , Vrdr , Tratio ;
real Ldrifte, Nover, Mu0, Vmaxe, Edri, Vdri;
real Mu, Xov, GD, Weff_nf ;

if ( rdmod == 1 ) begin
    // source resistance
    Nover = NOVERS   / `C_cm2m_p3; //"cm^-3"
    MKS_RDRMUE  = RDRMUES ;
    MKS_RDRVMAX = RDRVMAXS ;
    RRDRBB      = RDRBBS ;
    Rsd0 = (RSH > 0.0 ) ? RSH * NRS : 0.0 ;
    Ldrifte = LDRIFTS ;
    Vrdr  = TYPE * V(BRsps);  // get bias
end else begin
    // drain resistance
    Nover = NOVER    / `C_cm2m_p3; //"cm^-3"
    MKS_RDRMUE  = RDRMUED ;
    MKS_RDRVMAX = RDRVMAXD ;
    RRDRBB      = RDRBBD ;
    Rsd0 = (RSH > 0.0 ) ? RSH  * NRD : 0.0 ;
    Ldrifte = LDRIFT  ;
    Vrdr  = TYPE * V(BRddp);  // get bias
end
Xov  = sqrt( RDRDJUNC * RDRDJUNC + XLD * XLD ) ;
Weff_nf = Weff * NF ;

//-----------------------------------------------------------*
//* Change units into MKS.
//*-----------------//
MKS_RDRMUE  = MKS_RDRMUE   / `C_m2cm_p2 ;
MKS_RDRVMAX = MKS_RDRVMAX  / `C_m2cm ;

//-----------------------------------------------------------*
//* Temperature dependent constants.
//*-----------------//
Tratio = TTEMP / UC_TNOM ;

// Phonon Scattering(temperature-dependent part) //
T1 =  `Fn_Pow( Tratio, RDRMUETMP ) ;
Mu0 = MKS_RDRMUE / T1 ;

// Velocity Temperature Dependence //
T0 = 1.8 + 0.4 * Tratio + 0.1 * Tratio * Tratio - RDRVTMP * ( 1.0 - Tratio ) ;
Vmaxe = MKS_RDRVMAX / T0 ;

//Toshiba model //
RRDRBB = RRDRBB + RDRBBTMP * (TTEMP-UC_TNOM) ;

// LW dependence of RDRMUE and RDRVMAX
Rdrmuele  = 1.0e0 + (RDRMUEL  / pow( LGLE, RDRMUELP )) ;
Rdrvmaxle = 1.0e0 + (RDRVMAXL / pow( LGLE, RDRVMAXLP)) ;
Rdrvmaxwe = 1.0e0 + (RDRVMAXW / pow( WG  , RDRVMAXWP)) ;
Mu0   = Mu0   * Rdrmuele ;
Vmaxe = Vmaxe * Rdrvmaxwe * Rdrvmaxle + `Small ;

`ifdef __DEBUG_RDRIFTS__
    $write(" RDRMUEL %g RDRMUELP %g LGLE  %g Rdrmuele %g Mu0 %g \n", RDRMUEL,RDRMUELP,LGLE,Rdrmuele,Mu0);
    $write(" RDRVMAXL %g RDRVMAXLP %g RDRVMAXW %g RDRVMAXWP %g LGLE %g WG %g Rdrvmaxle %g Rdrvmaxwe %g Vmaxe %g\n",
    RDRVMAXL,RDRVMAXLP,RDRVMAXW,RDRVMAXWP,LGLE,WG,Rdrvmaxle,Rdrvmaxwe,Vmaxe );

    $write("debug_eval_rdrifts_0[ %g %g %g %g ]\n",rdmod, Vmaxe, MKS_RDRVMAX, Mu0);
`endif

Edri  = Vrdr / Ldrifte ;
Vdri  = Mu0 * Edri ;
//-----------------------------------------------------------*
//* Mu : mobility
//*-----------------//
if ( Vrdr >= 0 ) begin
    T1    =   Vdri / Vmaxe ;
end else  begin
    T1    = - Vdri / Vmaxe ;
end
`ifdef __DEBUG_RDRIFTS__
    $write("debug_eval_rdrifts_a[ %g %g %g  %g %g ]\n", rdmod, Vdri, Vmaxe, Edri, Mu0);
`endif
if ( T1 == 0.0 ) begin
    T2 = 0.0 ;
    T4 = 1.0 ;
end else begin
    if ( 1.0e0 - `epsm10 <= RRDRBB && RRDRBB <= 1.0e0 + `epsm10 ) begin
        T3 = 1.0e0 ;
    end else if ( 2.0e0 - `epsm10 <= RRDRBB && RRDRBB <= 2.0e0 + `epsm10 ) begin
        T3 = T1 ;
    end else  begin
        T3 = `Fn_Pow( T1 , RRDRBB - 1.0e0 ) ;
    end
    T2 = T1 * T3 ;
    T4 = 1.0e0 + T2 ;
end
if ( 1.0e0 - `epsm10 <= RRDRBB && RRDRBB <= 1.0e0 + `epsm10 ) begin
    T5 = 1.0 / T4 ;
end else if ( 2.0e0 - `epsm10 <= RRDRBB && RRDRBB <= 2.0e0 + `epsm10 ) begin
    T5 = 1.0 / sqrt( T4 ) ;
end else  begin
    T6 = `Fn_Pow( T4 , ( - 1.0e0 / RRDRBB - 1.0e0 ) ) ;
    T5 = T4 * T6 ;
end
Mu   = Mu0 * T5 ;  // velocity saturation accounted
`ifdef __DEBUG_RDRIFTS__
    $write("debug_eval_rdrifts_b[ %g %g %g ]\n", Mu, Mu0, T5);
`endif

//-----------------------------------------------------------*
//* Rd : drift resistance
//*-----------------//
T1 = `C_QE / ( Ldrifte );
GD = T1 * Xov * Mu * Nover ;
`ifdef __DEBUG_RDRIFTS__
    $write("debug_eval_rdrifts_c[ %g %g %g %g %g  %g %g %g  %g ]\n", GD, T1, Xov, Mu, Nover, Mu0, Vdri, Vmaxe, Edri);
`endif

`ifdef REPLACE_CLIPPING_WITH_SMOOTHING //revised for continuity (Rsd)
    `Fn_SL_CP(GD, GD, 0, `Small, 2)
`else
    if ( GD <= 0 ) begin
        GD = `Small ;
    end
`endif

Rsd = 1.0 / GD ;
// Weff dependence of the resistances //
Rsd = Rsd  /  Weff_nf ;

// Sheet resistances are added. //
Rsd = Rsd + Rsd0 ;

// Re-stamps for hsmhvnoi.c //
Conductance =  ( Rsd > `Res_min && COTHRML != 0 ) ? Mfactor / Rsd : 0.0 ;

// Clamping to Res_min //
if (Rsd < `Res_min) begin Rsd = `Res_min ; end

`ifdef __DEBUG_RDRIFTS__
    $write("debug_eval_rdrifts_d[ %g %g %g %g %g %g  ]\n", rdmod, GD, Rsd, Rsd0, Weff_nf, Conductance);
`endif

//end HSMHV_eval_rdrifrs

