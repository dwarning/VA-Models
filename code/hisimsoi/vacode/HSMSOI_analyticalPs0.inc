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
 FILE : HSMSOI_analyticalPss.inc

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

begin : HSMSOI_analyticalPs0

    real Vbs , Vth ; // different from outside
    Vbs = dphi_vds ;
    Vth = wk_Vth ;

    //-----------------------------------------------------------*
    //* Initial guess for Ps0. (start)
    //*-----------------//
    //---------------------------------------------------*
    //* Ps0_iniA: solution of subthreshold equation assuming zone-D1/D2.
    //*-----------------//
    TX = 1.0e0 + 4.0e0 * ( beta * ( Vgp - Vbs ) - 1.0e0 ) / ( fac1p2 * beta2 ) ;
    TX = `Fn_Max( TX , `epsm10 ) ;
    Ps0_iniA = Vgp + fac1p2 * beta * 0.5 * ( 1.0e0 - sqrt( TX ) ) ;

    // use analytical value in subthreshold region. //
    if ( Vgs <( Vfb + Vth ) * 0.5 ) begin
        flg_pprv = 0 ;
    end

    if ( flg_pprv == 0 || 1) begin

        //---------------------------------------------------*
        //* Analytical initial guess.
        //*-----------------//
        //-------------------------------------------*
        //* Common part.
        //*-----------------//
        Chi = beta * ( Ps0_iniA - Vbs ) ;
        if ( Chi < `znbd3 ) begin
            //-----------------------------------*
            //* zone-D1/D2
            //* - Ps0_ini is the analytical solution of Qs=Qb0 with
            //*   Qb0 being approximated to 3-degree polynomial.
            //*-----------------//
            TY = beta * ( Vgp - Vbs ) ;
            T1 = 1.0e0 / ( `cn_nc3 * beta * fac1 ) ;
            T2 = 81.0 + 3.0 * T1 ;
            T3 = -2916.0 - 81.0 * T1 + 27.0 * T1 * TY ;
            T4 = 1458.0 - 81.0 * ( 54.0 + T1 ) + 27.0 * T1 * TY ;
            T4 = T4 * T4 ;
            T5 = `Fn_Pow( T3 + sqrt( 4 * T2 * T2 * T2 + T4 ) , `C_1o3 ) ;
            TX = 3.0 - ( `C_2p_1o3 * T2 ) / ( 3.0 * T5 )
              + 1.0 / ( 3.0 * `C_2p_1o3 ) * T5 ;
            Ps0_iniA = TX * beta_inv + Vbs ;
            Ps0_ini = Ps0_iniA ;
        end else if ( Vgs - shift <= Vth ) begin
            //-----------------------------------*
            //* Accumulation & Weak inversion zone.
            //*-----------------//
            if (COBCNODE==0) begin
                T0 = 1.0 / C_fox ;
                T1 = t_SOI / `C_ESI ;
                T2 = 1.0 / C_box ;
                T3 = 1.0 / (T0 + T1 + T2) ;
                T4 = T3 * (Vgp - Vbsbiz + (T2 + 0.5 * T1) * (-Q_s0_dep_ini)) ;
                Ps0_iniA = Vgp - T4 / C_fox ;
            end
            Ps0_ini = Ps0_iniA ;
        end else begin
            //-----------------------------------*
            //* Strong inversion zone.
            //* - Ps0_iniB : upper bound.
            //*-----------------//
            T1 = 1.0 / cnst1SOI / cnstC_foxi ;
            T2 = T1 * (Vgp - shift) * (Vgp - shift) ;
            T3 = beta + 2.0 / (Vgp - shift) ;
            Ps0_iniB = ln ( T2 ) / T3 + PSLIMPT ;
            `Fn_SUtemp( Ps0_ini , Ps0_iniA, Ps0_iniB, `c_ps0ini_2)
        end

        if (COBCNODE==0) begin
            if ( Vgs - shift <= Vth ) begin
                //-----------------------------------*
                //* Accumulation & Weak inversion zone.
                //*-----------------//
                T0 = 1.0 / C_fox ;
                T1 = t_SOI / `C_ESI ;
                T2 = 1.0 / C_box ;
                T3 = 1.0 / (T0 + T1 + T2) ;
                T4 = T3 * (Vgp - Vbsbiz + (T2 + 0.5 * T1) * (-Q_s0_dep_ini)) ;
                Ps0_iniA = Vgp - T4 / C_fox ;
                Ps0_ini = Ps0_iniA ;
            end else begin
                //---------------------------------------------------*
                //* Ps0_iniA: solution of subthreshold equation assuming zone-D1/D2.
                //*-----------------//
                // begin
                T0 = 1.0 / C_fox ;
                T1 = t_SOI / `C_ESI ;
                T2 = 1.0 / C_box ;
                T3 = 1.0 / (T0 + T1 + T2) ;
                T4 = T3 * (Vgp - Vbsbiz + (T2 + 0.5 * T1) * (-Q_s0_dep_ini)) ;
                Ps0_iniA = Vgp - T4 / C_fox ;
                // end
                Ps0_ini = Ps0_iniA ;

                if ( Vgp - shift > 0 ) begin // for smoothing
                    //---------------------------------------------------*
                    //* Analytical initial guess.
                    //*-----------------//
                    //-------------------------------------------*
                    //* Common part.
                    //*-----------------//
                    T1 = 1.0 / cnst1SOI / cnstC_foxi ;
                    T2 = T1 * (Vgp - shift) * (Vgp - shift) ;
                    T3 = beta + 2.0 / (Vgp - shift) ;
                    Ps0_iniB = ln (T2) / T3 + PSLIMPT ;
                    `Fn_SU_CP(Ps0_ini, Ps0_iniA, Ps0_iniB * 0.98 , 0.4 , 2)
                end // End of smoothing
            end // End of FD
        end // COBCNODE==0
    end // Vgs <( Vfb + Vth ) * 0.5
    TX = Vbs + `ps_conv / 2 ;
    if ( Ps0_ini < TX ) Ps0_ini = TX ;

    //---------------------------------------------------*
    //* Assign initial guess.
    //*-----------------//
    Ps0 = Ps0_ini ;
    Psl_lim = Ps0_iniA ;

    if ( 0 ) begin
        Pds_max = `Fn_Max( Ps0_iniA - Ps0 , 0.0e0 ) ;
        `Fn_SUtemp( Pds_ini , PSLIMPT , (1.0e0 + `c_pslini_1) * Pds_max, `c_pslini_2 )
        Pds_ini = `Fn_Min( Pds_ini , Pds_max ) ;
        if ( Pds_ini < 0.0 ) Pds_ini = 0.0 ;
        else if ( Pds_ini > Vds ) Pds_ini = Vds ;
        Psl_lim = Ps0 + Pds_ini  ;
    end

    // Initial guess for Ps0. (end) //

end // block: newPunchAnalyticalPs0
