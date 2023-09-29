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
 FILE : HSMSOI_eval_newPT.inc

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

begin : HSMSOI_eval_newPT
    // Use this module when COPT > 0 and MUPT > 0.0.
`define C_PHI__MINIMUM (1e-7)

    real dphi_vds , wk , Vbs , phim , UC_WK_NJUNC ;
    real Vbipn , Leff , Ec , T1w ;
    real Ps0 , t_SOI , Vgp , wk_Vth ;       // protect external Ps0 and beta
    real WK_XJ , WK_Mu , WK_JNPT_A ;
    real conpt00 , conpt0 ;
    real sq1npt  , Qn0npt ;

    real wfactor; // accounts for diminished influence exerted by gate; in aid of depletion width
    real wQbu, Wdep, delta;    // depletion width in association with Ps0//

    Leff  = Lgleff ;
    t_SOI = `t_SOI ;
    Vgp   = Vgs - Vfb + dVth - dPpg - VFBPT ; // 20180221
    wk_Vth = Vth + VFBPT ;                    // 20180221
    WK_Mu = MUPT ;
    WK_XJ = XJPT ;
    UC_WK_NJUNC = MKS_NJUNC ;
    Vbipn = beta_inv* ln(UC_WK_NJUNC/Nin * Nsub/Nin); //  All conc here in 1/m^3.
    Vbs  = (COBCNODE == 1) ? Vbsz2 : phi_b0_SOI ;  // for SOI

    Ec = sqrt( 2 * `C_QE * (Vbipn - Vbs)/`C_ESI* Nsub * UC_WK_NJUNC/(Nsub+UC_WK_NJUNC)); //
    // Potential build-up (lowering potential barrier seen from source) due to Vds.
    wk   = Ec * Leff;                      // [V]  positive
    dphi_vds = -0.25 * wk*wk / (Vds + wk); // [V] negative

`include "HSMSOI_analyticalPs0.inc"    // analyticalPs0   // 20180205
    if (COPSPT==1) begin
        Ps0_ini = Ps0 ;
`include "HSMSOI_iterativePs0.inc"     // iterativePs0    // 20180221
    end

    // From Ps0 here, depletion width will be estimated.
    T5 = -beta *(Ps0 - dphi_vds);
    T6 = exp(T5);
    T7= T6 - 1.0 - T5;
    if (T5 >= `C_PHI__MINIMUM) begin
        Qbu = -cnst0SOI*sqrt(T7); // sign inverted; accumulation side
    end else begin
        Qbu =  cnst0SOI*sqrt(T7); // sign inverted; depletion, inversion side
    end
    `Fn_SZtemp(wQbu, Qbu, 1e-6)
    Wdep = wQbu / (`C_QE * Nsub) ;
    T1 = Wdep - WK_XJ ;
    delta = Wdep*0.01;
    `Fn_SZtemp(T2, T1, delta)  // protection against negative T1 ( i.e. Wdep < WK_XJ)
    wfactor = T2/Wdep*T2/Wdep; // area ratio between small and large triangles

    phim = (Ps0 - dphi_vds) * wfactor + dphi_vds; // measured from source
    TY = exp(beta*phim) - exp(beta*(phim-Vds));   // 20180215

    conpt00 = sqrt (2.0 * `C_QE * UC_WK_NJUNC * `C_ESI );
    conpt0 = conpt00 * sqrt(beta_inv) ;
    T1w = beta * (phim - dphi_vds) ;
    `Fn_SL_CP( T1 , T1w , 0 , 0.2*beta , 1 )
    sq1npt = sqrt (T1 + `epsm10);
    Qn0npt = conpt0 * sq1npt ;
    WK_JNPT_A = 2.0 * beta_inv / Leff * Qn0npt ;

    IdsPT1 = WK_JNPT_A * WK_Mu * weff_nf * TY ;
    Ids   = Idsorg + IdsPT1 ;

end // newPT_model
