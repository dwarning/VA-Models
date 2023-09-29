/***********************************************************************

 HiSIM (Hiroshima University STARC IGFET Model)
 Copyright (C) 2000-2016 Hiroshima University and STARC
 Copyright (C) 2016-2021 Hiroshima University
 HiSIM_SOI (Silicon-On-Insulator Model)
 Copyright (C) 2012-2016 Hiroshima University and STARC
 Copyright (C) 2016-2021 Hiroshima University

 MODEL NAME : HiSIM_SOI
 ( VERSION : 1  SUBVERSION : 5  REVISION : 0 )
 Model Parameter 'VERSION' : 1.50
 FILE : HSMSOI_BT_module.inc

 Date : 2021.10.08

 released by Hiroshima University

***********************************************************************/
//
////////////////////////////////////////////////////////////////
//
//
//Licensed under the Educational Community License, Version 2.0
//(the "License"); you may not use this file except in
//compliance with the License.
//
//You may obtain a copy of the License at:
//
//      http://opensource.org/licenses/ECL-2.0
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

//================ Start of executable code.=================//

//start_of_routine

//-----------------------------------------------------------*
//Determine PD or FD by WdSOI at strong inversion condition.
//- The same definition is used for both source and drain.
//-----------------//
Vbcs_cl = Vbsc ;
if (WdSOI_ini < `t_SOI) begin
    flg_depmode = 1 ; // Partially Depleted (PD) mode //
end else begin
    flg_depmode = 2 ; // Fully Depleted (FD) mode //
end

//-----------------------------------------------------------*
//Solve Poisson's equation for BT devices
//----------------//

// Start of hsmsoieval_btsolps.h //

//-----------------------------------------------------------*
//* Accumulation zone. (zone-A)
//* - evaluate basic characteristics and exit from this part.
//*-----------------//
Vgs_fb = Vfb - dVth + dPpg + Vbcs_cl ; // for BTSOI //
if ( Vgs < Vgs_fb ) begin
    flg_zone = -1 ;

    //---------------------------------------------------*
    //* Evaluation of Ps0.
    //* - Psa : Analytical solution of
    //*             C_fox( Vgp - Psa ) = cnst0SOI * Qacc
    //*         where Qacc is the 3-degree series of(fdep)^{1/2}.
    //*         The unknown  is transformed to Chi=beta(Ps0-Vbs).
    //* - Ps0_min : |Ps0_min| when Vbs=0.
    //*-----------------//
    // Ps0_min: approx. solution of Poisson equation at Vgs_min //
    //          ( easy to improve, if necessary  )              //
    //    Ps0_min = Eg - Pb2 ;
    Ps0_min = 2.0 * beta_inv * ln (-Vgs_min/fac1) ;
    TX = beta * ( Vgp - Vbcs_cl ) ;
    T1 = 1.0 / ( beta * cnst0SOI ) ;
    TY = T1 * C_fox ;
    Ac41 = 2.0 + 3.0 * `C_SQRT_2 * TY ;
    Ac4 = 8.0 * Ac41 * Ac41 * Ac41 ;
    T4 = ( TX - 2.0 ) ;
    T5 = 9.0 * TY * T4 ;
    Ac31 = 7.0 * `C_SQRT_2 - T5 ;
    Ac3 = Ac31 * Ac31 ;
    if ( Ac4 < Ac3 * 1.0e-8 ) begin
        Ac1 = -7.0 * `C_SQRT_2 + Ac31 + 0.5 * Ac4 / Ac31 + T5 ;
    end else begin
        Ac2 = sqrt( Ac4 + Ac3 ) ;
        Ac1 = -7.0 * `C_SQRT_2 + Ac2 + T5 ;
    end
    Acd = `Fn_Pow( Ac1 , `C_1o3 ) ;
    Acn = -4.0 * `C_SQRT_2 - 12.0 * TY + 2.0 * Acd + `C_SQRT_2 * Acd * Acd ;
    T1 = 1.0 / Acd ;
    Chi = Acn * T1 ;
    Psa = Chi * beta_inv + Vbcs_cl ;
    T1 = Psa - Vbcs_cl ;
    T2 = T1 / Ps0_min ;
    T3 = sqrt( 1.0 + ( T2 * T2 ) ) ;
    Ps0 = T1 / T3 + Vbcs_cl ;

end else begin //if( Vgs < Vgs_fb ) begin
    //-----------------------------------------------------------*
    //* Initial guess for Ps0.
    //*-----------------//

`ifndef DISABLE_COPPRV

    //-------------------------------------------------------------------*
    // Update initial potential values by previous values
    //----------------//

    vtol_pprv = 5.0e-2 ;
    vtol_pprv_u = 6.0e-2;
    vtol_pprv_l = 4.0e-2;

    if ( COPPRV ) begin

        if (called >= 1 && flg_zone_prv != -1) begin
            Vbsc_dif = Vbsc - vbsc_prv ;
            Vdsc_dif = Vdsc - vdsc_prv ;
            Vgsc_dif = Vgsc - vgsc_prv ;
            sum_vdif = abs(Vbsc_dif) + abs(Vdsc_dif) + abs(Vgsc_dif) ;

            flg_pprv = (flg_pprv_prv > 0 )? 1 : 0 ;

            if (sum_vdif > vtol_pprv_u) flg_pprv = 0;
            if (sum_vdif <= vtol_pprv_l) flg_pprv = 1;
            if (mode * mode_prv < 0) flg_pprv = 0;

            if ( called >=2 && flg_pprv ==1 ) begin
                Vbsc_dif2 = vbsc_prv - vbsc_prv2 ;
                Vdsc_dif2 = vdsc_prv - vdsc_prv2 ;
                Vgsc_dif2 = vgsc_prv - vgsc_prv2 ;
                sum_vdif2 = abs(Vbsc_dif2) + abs(Vdsc_dif2) + abs(Vgsc_dif2) ;
            end
            dVbs = Vbsc_dif ;
            dVds = Vdsc_dif ;
            dVgs = Vgsc_dif ;
            ddVbs = dVbs * dVbs /2 ;
            ddVds = dVds * dVds /2 ;
            ddVgs = dVgs * dVgs /2 ;
            //
            if ( flg_pprv >= 1 ) begin
                Pss0_ini = pss0_prv ;
                Pssl_ini = pssl_prv ;
            end

            flg_pprv_prv = flg_pprv;

        end else begin
            Vbsc_dif  = 0.0 ;
            Vdsc_dif  = 0.0 ;
            Vgsc_dif  = 0.0 ;
            Vbsc_dif2 = 0.0 ;
            Vdsc_dif2 = 0.0 ;
            Vgsc_dif2 = 0.0 ;
            sum_vdif  = 0.0 ;
            sum_vdif2 = 0.0 ;
            flg_pprv = 0 ;

        end

        flg_pprv_prv = flg_pprv;

    end // End of if (COPPRV)

`endif // COPPRV

    if ( flg_pprv >= 1 ) begin
        phi_s0_SOI  = Pss0_ini ;
        Ps0_ini = Pss0_ini ;
    end else begin  // ( flg_pprv == 0 )
        //---------------------------------------------------*
        //* Ps0_iniA: solution of subthreshold equation assuming zone-D1/D2.
        //*-----------------//
        TX = 1.0e0 + 4.0e0 * ( beta * ( Vgp - Vbcs_cl ) - 1.0e0 ) / ( fac1p2 * beta2 ) ;
        TX = `Fn_Max( TX , `epsm10 ) ;
        Ps0_iniA = Vgp + fac1p2 * beta * 0.5 * ( 1.0e0 - sqrt( TX ) ) ;

        //---------------------------------------------------*
        //* Analytical initial guess.
        //*-----------------//
        //-------------------------------------------*
        //* Common part.
        //*-----------------//
        Chi = beta * ( Ps0_iniA - Vbcs_cl ) ;
        if ( Chi < `znbd3 ) begin
            //-----------------------------------*
            //* zone-D1/D2
            //* - Ps0_ini is the analytical solution of Qs=Qb0 with
            //*   Qb0 being approximated to 3-degree polynomial.
            //*-----------------//
            TY = beta * ( Vgp - Vbcs_cl ) ;
            T1 = 1.0e0 / ( `cn_nc3 * beta * fac1 ) ;
            T2 = 81.0 + 3.0 * T1 ;
            T3 = -2916.0 - 81.0 * T1 + 27.0 * T1 * TY ;
            T4 = 1458.0 - 81.0 * ( 54.0 + T1 ) + 27.0 * T1 * TY ;
            T4 = T4 * T4 ;
            T5 = `Fn_Pow( T3 + sqrt( 4 * T2 * T2 * T2 + T4 ) , `C_1o3 ) ;
            TX = 3.0 - ( `C_2p_1o3 * T2 ) / ( 3.0 * T5 )
                + 1.0 / ( 3.0 * `C_2p_1o3 ) * T5 ;
            Ps0_iniA = TX * beta_inv + Vbcs_cl ;
            Ps0_ini = Ps0_iniA ;
        end else if ( Vgs <= Vth ) begin
            //-----------------------------------*
            //* Weak inversion zone.
            //*-----------------//
            Ps0_ini = Ps0_iniA ;
        end else begin
            //-----------------------------------*
            //* Strong inversion zone.
            //* - Ps0_iniB : upper bound.
            //*-----------------//
            T1 = 1.0 / cnst1SOI / cnstC_foxi ;
            T2 = T1 * Vgp * Vgp ;
            T3 = beta + 2.0 / Vgp ;
            Ps0_iniB = ln ( T2 ) / T3 ;
            `Fn_SUtemp( Ps0_ini , Ps0_iniA, Ps0_iniB, `c_ps0ini_2)
        end
        TX = Vbcs_cl + `ps_conv / 2 ;
        if ( Ps0_ini < TX ) Ps0_ini = TX ;
    end // if ( flg_pprv == 0 )

    //---------------------------------------------------*
    //* Assign initial guess.
    //*-----------------//
    Ps0 = Ps0_ini ;
    Psl_lim = Ps0_iniA ;

end // end of if( Vgs < Vgs_fb )

//Floating-body effects for body-contacted (a.k.a., body-tie) SOI devices
if (COISUB == 1 && COFBE == 2) begin
    Qhs = `NQS_CAP * V(nqs_qhs) ;
end else begin
    Qhs = 0 ;
end
OP_QHS   = Qhs; // 20201013 probing
`ifdef _fdisplay_
$write ("Vds %e Vgs %e Isub %e Qhs %e \n", Vds, Vgs, Isub, Qhs);
`endif
//
//---------------------------------------------------*
//* Calculation of Ps0. (beginning of Newton loop)
//* - Fs0 : Fs0 = 0 is the equation to be solved.
//* - dPs0 : correction value.
//*-----------------//
exp_bVbs = exp( beta * Vbcs_cl ) ;
cfs1 = cnst1SOI * exp_bVbs ;
flg_conv = 0 ;

phi_s0_SOI = Ps0 ;

dphi_sb = q_Nsub * `t_SOI * `t_SOI / 2.0 / `C_ESI ;
T0 = sqrt(2.0 * beta * dphi_sb) ;
T1 = (exp(T0) + exp(-T0)) / 2 ;
c_sb = ln(T1) / dphi_sb ;

for ( lp_s0 = 1 ; lp_s0 <= lp_s0_max + 1 ; lp_s0 = lp_s0 + 1 ) begin
    phi_SOI0 = phi_s0_SOI - Vbcs_cl ;
    Chi = beta * phi_SOI0 ;

    TY = c_sb * (phi_SOI0 - dphi_sb) ;
    if ( TY < `large_arg ) begin
        T1 = exp(TY) ;
        T0 = exp(- c_sb * dphi_sb) ;
        T2 = T1 - T0 ;
        phi_SOIb = ln(1 + T2) / c_sb ;
        phi_SOIb_dPss = T1 / (1 + T2) ;
    end else begin
        phi_SOIb = phi_SOI0 - dphi_sb ;
        phi_SOIb_dPss = 1 ;
    end
    Chib = beta * phi_SOIb ;

    if (abs(Chi) < 1E-16) begin
        T0 = sqrt((1 - phi_SOIb_dPss * phi_SOIb_dPss) / 2) ;
        fb = Chi * T0 ;
        fb_dPss = beta * T0 ;
        if (Chi < 0) begin
            fb = -fb ;
            fb_dPss = -fb_dPss ;
        end
    end else if (abs(Chi) < 5E-3) begin

        T0 = Chi * Chi / 2 * (1 - Chi / 3 * (1 - Chi / 4 * (1 - Chi / 5))) ;
        T1 = Chi * (1 - Chi / 2 * (1 - Chi / 3 * (1 - Chi / 4))) ;
        T2 = Chib * Chib / 2 * (1 - Chib / 3 * (1 - Chib / 4 * (1 - Chib / 5))) ;
        T3 = Chib * (1 - Chib / 2 * (1 - Chib / 3 * (1 - Chib / 4))) ;
        fb = sqrt(T0 - T2) ;
        fb_dPss = beta * 0.5 * (T1 - phi_SOIb_dPss * T3) / fb ;
    end else begin
        //-------------------------------------------*
        //* zone-D3.  (phi_s0_SOI)
        //*-----------------//

        T0 = exp(-Chi) ;
        T1 = exp(-Chib) ;
        fb = sqrt(Chi - Chib + (T0 - T1)) ;
        fb_dPss = beta * 0.5 * (1 - T0 - phi_SOIb_dPss * (1 - T1)) / fb ;
    end // check nest level. ok. //if (abs(Chi) < 1E-8) begin

    if (flg_conv == 1 && Chi < 0.0) begin
        flg_zone = -1 ;
    end
    if (flg_zone == -1) begin
        WdSOI = 0 ;
    end else begin
        WdSOI = C_W_SOI * fb ;
    end

    if (WdSOI < `t_SOI*1.01) begin
        flg_depmode = 1 ; // PD //
    end else begin
        flg_depmode = 2 ; // FD //
    end

    Q_dep_SOI = q_Nsub * WdSOI ;

    if (Chi < 0) begin
        fs02 = -fb ;
        fs02_dPs0 = -fb_dPss ;
    end else if (Chi < 1E-7) begin
        fs02 = fb ;
        fs02_dPs0 = fb_dPss ;
    end else begin
        if ( Chi < `large_arg ) begin // avoid exp_Chi to become extremely large
            exp_Chi = exp( Chi ) ;
            fs01 = cfs1 * ( exp_Chi - (Chi + 1) ) ;
            fs01_dPs0 = cfs1 * beta * ( exp_Chi - 1 ) ;
        end else begin
            exp_bPs0 = exp( beta*phi_s0_SOI ) ;
            fs01 = cnst1SOI * ( exp_bPs0 - exp_bVbs * (Chi + 1) ) ;
            fs01_dPs0 = cnst1SOI * beta * ( exp_bPs0 - exp_bVbs ) ;
        end
        fs02 = sqrt(fb * fb + fs01) ;
        fs02_dPs0 = 0.5 * (2 * fb_dPss * fb + fs01_dPs0) / fs02 ;
    end

    // Revised Fs0 //
    Fs0 = - Vgp + phi_s0_SOI + fac1 * fs02 - C_fox_inv * Qhs ;
    Fs0_dPs0 = 1.0 + fac1 * fs02_dPs0 ;
    if ( flg_conv == 1 ) begin
        lp_s0 = lp_s0_max+1 ; // break
    end else begin
        dPs0 = - Fs0 / Fs0_dPs0 ;

        //-------------------------------------------*
        //* Update Ps0 .
        //* - clamped to Vbcs_cl if Ps0 < Vbcs_cl .
        //*-----------------//
        dPlim = 0.5*`dP_max*(1.0 + `Fn_Max(1.0e0,abs(phi_s0_SOI))) ;
        if ( abs( dPs0 ) > dPlim ) dPs0 = dPlim * `Fn_Sgn( dPs0 ) ;
        phi_s0_SOI = phi_s0_SOI + dPs0 ;

        //-------------------------------------------*
        //* Check convergence.
        //* NOTE: This condition may be too rigid.
        //*-----------------//
        if ( abs( dPs0 ) <= `ps_conv && abs( Fs0 ) <= `gs_conv ) begin
            flg_conv = 1 ;
        end

    end
end // end of phi_s0_SOI Newton loop //

// Reduce loop count to exclude the sweep for derivative calculation //
lp_s0 = lp_s0 - 1 ;

//-------------------------------------------*
//* Procedure for diverged case.
//*-----------------//
Q_depS0 = Q_dep_SOI ;
Q_dep0 = Q_depS0 ;
Ps0 = phi_s0_SOI ;

flg_conv_0 = flg_conv ; // for Ps0 only

//-----------------------------------*
//* Xi0
//*-----------------//
Q_depS0_SOI_o_cnst0SOI = Q_depS0 / cnst0SOI ;
Xi0 = `Fn_Sqr(Q_depS0_SOI_o_cnst0SOI) + `epsm10 ;
T1 = 2 * Q_depS0_SOI_o_cnst0SOI ;
Xi0p12 = Q_depS0_SOI_o_cnst0SOI + `epsm10 ;

//-----------------------------------------------------------*
//* Qb0 : Qb at source side.
//* Qn0 : Qi at source side.
//*-----------------//
Qb0 = cnst0SOI * Xi0p12 ;
T1 = 1.0 / ( fs02 + Xi0p12 ) ;
Qn0 = cnst0SOI * fs01 * T1 ;
Q_n0 = -Qn0 ;

//---------------------------------------------------*
//* VgVt : Vgp - Vth_qi. ( Vth_qi is Vth for Qi evaluation. )
//*-----------------//
VgVt = Qn0 * C_fox_inv ;

//-----------------------------------------------------------*
//* make Qi=Qd=Ids=0 if VgVt <= VgVt_Small
//*-----------------//
if ( flg_zone == -1 || VgVt <= `VgVt_Small ) begin
    flg_zone = 4 ;
    flg_noqi = 1 ;
    T2 = ( Vgp - Ps0 ) ;
    Qbu = C_fox * T2 ;
    T0 = -weffcv_nf * Leff_cv ; // 20180717 affects accumulation region
    Qb = T0 * Qbu ;
    Qi = 0.0 ;
    Qd = 0.0 ;
    T2 = -area_bt_n  * Qbu ; // adding BT area * Qbu

    Qbody_bt_n_sud = T2 * Qdrat;
    Qbody_bt_n_sus = T2 - Qbody_bt_n_sud ;
    Qbody_bt_n_iud = 0.0  ;
    Qbody_bt_n_ius = 0.0  ;
    Ids = 0.0 ;
    VgVt = 0.0 ;
    flg_noqi = 1 ;
    phi_sL_SOI = phi_s0_SOI ;
    Psl = Ps0 ;
    Psdl = Psl ;
    end_of_part_1 = 1 ;
end

if (end_of_part_1 == 0) begin

    //-----------------------------------------------------------*
    //* Start point of Psl(= Ps0 + Pds) calculation.(label)
    //*-----------------//
    // start_of_Psl:

    // Vdseff(begin) //
    begin : SetVdseffBT
        real T1, T2, T3, T4, T6, T7, T10;

        Vdsorg = Vds ;
        T10 = `Small ;
        T2 = qnsub_esi / (C_fox * C_fox) ;
        T4 = 1.0e0 + 2.0e0 / T2 * ( Vgp -  T10 ) ;
        T5 = 1.0e0 + 2.0e0 / T2 ;
        `Fn_SL_CP( T4 , T4 , 0, T5 , 4 )
        T3 = sqrt(T4) ;
        T10 = Vgp + T2 * ( 1.0 - T3 )  ;
        `Fn_SZtemp(T10, T10, 0.01)
        Vdsat = T10 ;
        T1 = Vds / T10 ;
        T2 = `Fn_Pow(T1, DDLTe - 1.0e0) ;
        T7 = T2 * T1 ;
        T3 = 1.0 + T7 ;
        T4 = `Fn_Pow(T3, 1.0 / DDLTe - 1.0) ;
        T6 = T4 * T3 ;
        Vdseff = Vds / T6 ;
        Vds = Vdseff  ;
    end // SetVdseff
    // Vdseff(end) //
    exp_bVbsVds = exp( beta * ( Vbcs_cl - Vds ) ) ;

    //---------------------------------------------------*
    //* Skip Psl calculation when Vds is very Small.
    //*-----------------//
    if ( Vds <= 0.0 ) begin
        Pds = 0.0 ;
        Psl = Ps0 ;
        flg_conv = 0 ;
    end else begin

        if ( flg_pprv >= 1 ) begin
            phi_sL_SOI  = Pssl_ini ;
            Pds_ini = Pssl_ini - Ps0 ;
        end
        if ( flg_pprv == 0 ) begin // ( flg_pprv == 0 )

            //-----------------------------------------------------------*
            //* Initial guess for Pds( = Psl - Ps0 ).
            //*-----------------//
            //---------------------------------------------------*
            //* Analytical initial guess.
            //*-----------------//
            Pds_max = `Fn_Max( Psl_lim - Ps0 , 0.0e0 ) ;
            `Fn_SUtemp( Pds_ini , Vds, (1.0e0 + `c_pslini_1) * Pds_max, `c_pslini_2 )
            Pds_ini = `Fn_Min( Pds_ini , Pds_max ) ;

        end // if ( flg_pprv == 0 )

        if ( Pds_ini < 0.0 ) Pds_ini = 0.0 ;
        else if ( Pds_ini > Vds ) Pds_ini = Vds ;

        //---------------------------------------------------*
        //* Assign initial guess.
        //*-----------------//
        Pds = Pds_ini ;
        Psl = Ps0 + Pds ;
        //---------------------------------------------------*
        //* Calculation of Psl by solving Poisson eqn.
        //* (beginning of Newton loop)
        //* - Fsl : Fsl = 0 is the equation to be solved.
        //* - dPsl : correction value.
        //*-----------------//
        flg_conv = 0 ;

    end // end of start_of_loop_Psl

    //---------------------------------------------------*
    //* start of Psl calculation. (label)
    //*-----------------//
    // start_of_loop_Psl:
    phi_sL_SOI = Psl ;

    for ( lp_sl = 1 ; lp_sl <= lp_sl_max + 1 ; lp_sl = lp_sl + 1 ) begin
        phi_SOIL = phi_sL_SOI - Vbcs_cl ;
        Chi = beta * phi_SOIL ;

        TY = c_sb * (phi_SOIL - dphi_sb) ;
        if ( TY < `large_arg ) begin
            T1 = exp(TY) ;
            T0 = exp(- c_sb * dphi_sb) ;
            T2 = T1 - T0 ;
            phi_SOIb = ln(1 + T2) / c_sb ;
            phi_SOIb_dPss = T1 / (1 + T2) ;
        end else begin
            phi_SOIb = phi_SOIL - dphi_sb ;
            phi_SOIb_dPss = 1 ;
        end
        Chib = beta * phi_SOIb ;

        if (abs(Chi) < 1E-16) begin
            T0 = sqrt((1 - phi_SOIb_dPss * phi_SOIb_dPss) / 2) ;
            fb = Chi * T0 ;
            fb_dPss = beta * T0 ;
            if (Chi < 0) begin
                fb = -fb ;
                fb_dPss = -fb_dPss ;
            end
        end else if (abs(Chi) < 5E-3) begin
            //
            //-------------------------------------------*
            //* zone-D1/D2.  (phi_sL_SOI)
            //* - Qb0 is approximated to 5-degree polynomial.
            //*-----------------//

            T0 = Chi * Chi / 2 * (1 - Chi / 3 * (1 - Chi / 4 * (1 - Chi / 5))) ;
            T1 = Chi * (1 - Chi / 2 * (1 - Chi / 3 * (1 - Chi / 4))) ;
            T2 = Chib * Chib / 2 * (1 - Chib / 3 * (1 - Chib / 4 * (1 - Chib / 5))) ;
            T3 = Chib * (1 - Chib / 2 * (1 - Chib / 3 * (1 - Chib / 4))) ;
            fb = sqrt(T0 - T2) ;
            fb_dPss = beta * 0.5 * (T1 - phi_SOIb_dPss * T3) / fb ;
        end else begin
            //-------------------------------------------*
            //* zone-D3.  (phi_sL_SOI)
            //*-----------------//

            T0 = exp(-Chi) ;
            T1 = exp(-Chib) ;
            fb = sqrt(Chi - Chib + (T0 - T1)) ;
            fb_dPss = beta * 0.5 * (1 - T0 - phi_SOIb_dPss * (1 - T1)) / fb ;
        end

        if (flg_zone == -1) begin
            WdSOI = 0 ;
        end else begin
            WdSOI = C_W_SOI * fb ;
        end
        Q_dep_SOI = q_Nsub * WdSOI ;

        if (Chi < 0) begin
            fsl2 = -fb ;
            fsl2_dPsl = -fb_dPss ;
        end else if (Chi < 1E-7) begin
            fsl2 = fb ;
            fsl2_dPsl = fb_dPss ;
        end else begin
            Rho = beta * ( phi_sL_SOI - Vds ) ;
            exp_Rho = exp( Rho ) ;
            fsl1 = cnst1SOI * ( exp_Rho - exp_bVbsVds * (Chi + 1) ) ;
            fsl1_dPsl = cnst1SOI * beta * ( exp_Rho - exp_bVbsVds ) ;
            fsl2 = sqrt(fb * fb + fsl1) ;
            fsl2_dPsl = 0.5 * (2 * fb_dPss * fb + fsl1_dPsl) / fsl2 ;
        end

        // Revised Fsl //
        //         Fsl = - Vgp + phi_sL_SOI + fac1 * fsl2 ;
        Fsl = - Vgp + phi_sL_SOI + fac1 * fsl2 - C_fox_inv * Qhs ;
        Fsl_dPsl = 1.0 + fac1 * fsl2_dPsl ;
        if ( flg_conv == 1 && lp_sl > 3) begin
            lp_sl = lp_sl_max+1 ; // break
        end else begin
            dPsl = - Fsl / Fsl_dPsl ;

            //-------------------------------------------*
            //* Update phi_sL_SOI .
            //* - clamped to Vbcs_cl if Psl < Vbcs_cl .
            //*-----------------//
            dPlim = 0.5*`dP_max*(1.0 + `Fn_Max(1.0e0,abs(phi_sL_SOI))) ;
            if ( abs( dPsl ) > dPlim ) dPsl = dPlim * `Fn_Sgn( dPsl ) ;
            phi_sL_SOI = phi_sL_SOI + dPsl ;

            //-------------------------------------------*
            //* Check convergence.
            //* NOTE: This condition may be too rigid.
            //*-----------------//
            if ( abs( dPsl ) <= `ps_conv && abs( Fsl ) <= `gs_conv ) begin
                flg_conv = 1 ;
            end
        end
    end // end of phi_sL_SOI Newton loop //

    // Reduce loop count to exclude derivative calculation sweep //
    lp_sl = lp_sl - 1 ;

    //-------------------------------------------*
    //* Procedure for diverged case.
    //*-----------------//
    Q_depSL = Q_dep_SOI ; // bugfixed //
    Q_depL = Q_depSL ;
    Psl = phi_sL_SOI ;

    flg_conv_L = flg_conv ; // for Psl only

    //-----------------------------------*
    //* Xil
    //*-----------------//
    Q_depSL_SOI_o_cnst0SOI = Q_depSL / cnst0SOI ;
    Xilp12 = Q_depSL_SOI_o_cnst0SOI + `epsm10 ;

    //-----------------------------------------------------------*
    //* Qb0 : Qb at source side.
    //* Q_nL : Qi at source side.
    //*-----------------//
    //    Qb0 = cnst0SOI * Xilp12 ;
    T1 = 1.0 / ( fsl2 + Xilp12 ) ;
    Q_nL = cnst0SOI * fsl1 * T1 ;
    Q_nL = -Q_nL ;
    Pds = Psl - Ps0 ;
    // Vdseff //
    Vds = Vdsorg ;

`ifndef DISABLE_COPPRV
    //Restore present values for next bias step
    //-----------------------------------------------------------*
    //Restore values for next calculation.
    //----------------//
    if ( COPPRV && ( flg_conv_0 + flg_conv_L == 2 )) begin
        //Activate COPPRV only when iteration has been successful on both sides (source and drain).
        // Confined biases //
        if ( called >= 1 ) begin
            vbsc_prv2 = vbsc_prv ;
            vdsc_prv2 = vdsc_prv ;
            vgsc_prv2 = vgsc_prv ;
            mode_prv2 = mode_prv ;
        end
        vbsc_prv = Vbsc ;
        vdsc_prv = Vdsc ;
        vgsc_prv = Vgsc ;
        mode_prv = mode ;
        flg_zone_prv = flg_zone ;
        // Surface potentials //
        pss0_prv = phi_s0_SOI ;
        pssl_prv = phi_sL_SOI ;

    end // (COPPRV)
`endif // COPPRV

    //-----------------------------------------------------------*
    //* Evaluate Idd .
    //* - Eta : substantial variable of QB'/Pds and Idd/Pds.
    //* - note: Eta   = 4 * GAMMA_beginhisim_0end
    //*-----------------//
    T1 = beta / Xi0 ;
    Eta = T1 * Pds ;

    // ( Eta + 1 )^n //
    Eta1 = Eta + 1.0e0 ;
    Eta1p12 = sqrt( Eta1 ) ;

    // 1 / ( ( Eta + 1 )^n + 1 ) //
    Zeta12 = 1.0e0 / ( Eta1p12 + 1.0e0 ) ;

    //---------------------------------------------------*
    //* F00 := PS00/Pds(n=1/2)
    //*-----------------//
    F00 = Zeta12 / Xi0p12 ;

    //---------------------------------------------------*
    //* F10 := PS10/Pds(n=3/2)
    //*-----------------//
    // if(flg_depmode <= 1) begin // accumulation & PD //
    //   T1 = 3.0e0 + Eta * ( 3.0e0 + Eta ) ;
    //   F10 = `C_2o3 * Xi0p12 * Zeta32 * T1 ;
    // end else begin // FD //
    F10 = 0.5 * (Q_depS0_SOI_o_cnst0SOI + Q_depSL_SOI_o_cnst0SOI) ;
    // end

    T1 = Vgp + beta_inv - 0.5e0 * ( 2.0e0 * Ps0 + Pds ) ;
    T2 = - F10 + F00 ;
    T3 = beta * C_fox ;
    T4 = beta * cnst0SOI ;
    Fdd = T3 * T1 + T4 * T2 ;

    //---------------------------------------------------*
    //*  Idd:
    //*-----------------//
    Ab = (Q_depL + Q_dep0) / 2;
    Ai = - (Q_nL + Q_n0) / 2;
    Db = Q_depL - Q_dep0;
    Di = - (Q_nL - Q_n0);
    C2 = cnst0SOI * cnst0SOI;
    if (flg_depmode <= 1) begin // accumulation & PD //
        Idd = Ai * beta * Pds - Di - Db * Db * Db / C2 / 6;
    end else begin
        Idd = Pds * Fdd ;
    end

    if (flg_info >= 1 && Idd < 0.0) begin
        $write("Warning: Idd = %e < 0  ", Idd) ;
        $write("Vds= %e Pds= %e ", Vds, Pds) ;
        $write("\n") ;
        Idd = 0.0 ;
    end

    //---------------------------------------------------*
    //* Qbu : -Qb in unit area.
    //*-----------------//
    if (flg_depmode <= 1) begin // accumulation & PD //
        if (abs(Pds) > 1e-6) begin
            Qbu = Ab * (Ai * beta * Pds - Di) + (Ai - 2 * Ab
                + C_fox / beta * (1 - 2 * Ab * Ab / C2 + Db * Db / C2 / 10))
                * Db * Db * Db / C2 / 6;
            Qbu = Qbu / Idd;
        end else begin
            Qbu = Ab;
        end
    end else begin // FD //
        Qbu = 0.5 * (Q_depL + Q_dep0) ;
    end

    //---------------------------------------------------*
    //* preparation for Qi and Qd.
    //* - DtPds: Delta * Pds ;
    //* - Achi: (1+Delta) * Pds ;
    //*-----------------//
    T1 = 2.0e0 * fac1 ;
    DtPds = T1 * ( F10 - Xi0p12 ) ;
    Achi = Pds + DtPds ;

    //-----------------------------------------------------------*
    //* Alpha : parameter to evaluate charges.
    //* - Achi: (1+Delta) * Pds ;
    //* - clamped to 0 if Alpha < 0.
    //*-----------------//
    T1 = 1.0 / VgVt ;
    T2 = Achi * T1 ;
    T3 = 1.0e0 - T2 ;
    TX = 1.0 - T3 ;
    `Fn_CP(TY, TX, 1.0, 4)
    Alpha = 1.0 - TY ;

    // End of hsmsoieval_btsolps.h //

    // start_of_charges:

    //-----------------------------------------------------------*
    //* Qiu : -Qi in unit area.
    //*-----------------//
    Qinm = 1.0 + Alpha * (1.0 + Alpha) ;
    Qidn = `Fn_Max(1.0 + Alpha, `epsm10) ;
    T1 = `C_2o3 * VgVt * Qinm / Qidn ;

    if (flg_depmode <= 1) begin // accumulation & PD //
        // BT device //
        if (abs(Pds) > 1e-6) begin
            Qiu = (Ai * Ai + Di * Di / 12) * beta * Pds - Ai * Di - (2 * Ai
                + C_fox / beta * Db * Db / C2 / 5) * Db * Db * Db / C2 / 6;
            Qiu = Qiu / Idd;
        end else begin
            Qiu = Ai;
        end
    end else begin // if (flg_depmode == 1)
        Qiu = -0.5 * (Q_n0 + Q_nL);
    end

    if (flg_conv_0 == 0) begin
        $write("*** warning(HiSIM_SOI): Went Over Iteration Maximum(%M:Ps0): \n") ;
    end
    if (flg_conv_L == 0) begin
        $write("*** warning(HiSIM_SOI): Went Over Iteration Maximum(%M:Psl): \n") ;
    end
    if (flg_conv_0+flg_conv_L < 1) begin
        $write( " Vbse   = %g Vdse = %g Vgse = %g \n" ,
            Vbse , Vdse , Vgse ) ;
    end


end // end if(end_of_part_1==0)
