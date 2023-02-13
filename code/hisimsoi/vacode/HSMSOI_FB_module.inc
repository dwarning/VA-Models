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
 FILE : HSMSOI_FB_module.inc

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

//================ Start of executable code.=================//


//start_of_routine

begin : HSOI_calc_Phis_FB

    real C_soi , C_soi_inv , t_SOI , WdSOI_ini1_dlt , QDEPB_DLT ;
    real Q_FD_dlt1, Q_FD_dlt2 ;


    //-----------------------------------------------------------*
    // Initial guess of the depletion charge for source side    //
    //
    QDEPB_DLT = 7.0 ;
    Vgp_ini = Pb2 + 1.0 ;
    T1 = 1.0 / cnst1SOI / cnstC_foxi ;
    T2 = T1 * (Vgp_ini - shift) * (Vgp_ini - shift) ;
    T3 = beta + 2.0 / (Vgp_ini - shift) ;
    Ps0_iniC = ln (T2) / T3 ;
    WdSOI_ini0 = sqrt(cnst_2esi_q_Nsubs * Ps0_iniC) ;
    WdSOI_ini0 = (WdSOI_ini0 > `t_SOI) ? `t_SOI : WdSOI_ini0 ;
    Q_WdSOI_max = -`C_QE * `N_sub_SOI * WdSOI_ini0 ;

    // Modifiy Q_FD_SOI and t_SOI
    t_SOI = `t_SOI ;
    Q_FD_SOI = -`C_QE * `N_sub_SOI * t_SOI ;
    WdSOI_ini1_dlt = 1.5 ;
    C_soi = `C_ESI / t_SOI ;
    C_soi_inv = 1.0 / C_soi ;
    Q_FD_dlt1 = -Q_FD_SOI * 1e-3 ;
    Q_FD_dlt2 = -Q_FD_SOI * 1e-5 ;

    //---------------------------------------------------*
    //    phi_s0_bulk_0 :
    //    -----------------//
    // initial value(phi_s0_bulk_0) start //

    begin : InitialValueForPhiS0Bulk0
        real T0, T1, T2, T3, psb_iniA, psb_iniB;

        if (COVBSBIZ) Vbsbiz = Vbsz + Vbi_SOI ;
        else  Vbsbiz = Vbs  + Vbi_SOI ;

        Pb2_bulk = 2.0 / beta * ln (`N_sub_bulk / Nin) ;
        T0 = cnst0bulk * cnst0bulk * C_box_FD_inv * C_box_FD_inv ;
        T1 = -(Vbsbiz) ;
        T2 = (2 * T1 + T0 * beta) * (2 * T1 + T0 * beta) - 4 * (T1 * T1 + T0) ;
        T2 = `Fn_Max(T2, `epsm10) ;
        T2 = sqrt(T2) ;
        T3 = 2 * T1 + T0 * beta ;
        psb_iniA = (T3 - T2) / 2 ;
        psb_iniB = ln (T1 * T1 / T0 / cnst1bulk) / (beta + 2.0 / T1) ;
        if (psb_iniA < Pb2_bulk) begin
            phi_s0_bulk_0 = psb_iniA ;
        end else begin
            `Fn_SUtemp(phi_s0_bulk_0, psb_iniA, psb_iniB, `c_ps0ini_2)
        end
    end
    // initial value(phi_s0_bulk_0) end //

    // newton loop(phi_s0_bulk_0) start //
    begin : NewtonLoopForPhiS0Bulk0
        real T1, T2, T3, T0, T4, T5, T6, T7;

        for (lp_s0 = 0 ; lp_s0 < lp_s0_max ;  lp_s0 = lp_s0 + 1 ) begin

            T1 = cnst0bulk ;
            T2 = beta * phi_s0_bulk_0 ;
            T3 = exp(-T2) ;
            if (phi_s0_bulk_0 > `C_PHI_1_MINIMUM) begin
                T0 = exp(beta * phi_s0_bulk_0) ;
                T4 = -T1 * sqrt(T3 + T2 - 1 + cnst1bulk * (T0 - 1)) ;
                T5 = c0bulk / T4 * (-T3 + 1 + cnst1bulk * (T0)) ;
            end else if (phi_s0_bulk_0 < -`C_PHI_1_MINIMUM) begin
                T4 = T1 * sqrt(T3 + T2 - 1) ;
                T5 = c0bulk / T4 * (-T3 + 1) ;
            end else begin
                T4 = -sqrt(c0bulk / beta) * beta * phi_s0_bulk_0 ;
                T5 = -sqrt(c0bulk * beta) ;
            end
            `Fn_SZ_DX(T6, T4, Q_FD_dlt1, T7)
            `Fn_SU_DX(T6, T6, (-Q_FD_SOI), Q_FD_dlt2, T8)
            T7 = T7 * ( T5 * T8 ) ;
            phi_b_dep0 = T6 * T6 / 2.0 / `C_ESI / `C_QE / `N_sub_SOI ;
            phi_b_dep0_dPsb = 2 * phi_b_dep0 * T7 / T6 ;

            T6 = phi_s0_bulk_0 - ((-phi_s0_bulk_0 + T4 / C_box - Vbsbiz + phi_b_dep0)
            / (-1 + T5 / C_box + phi_b_dep0_dPsb)) ;
            if (abs(T6 - phi_s0_bulk_0) < `ps_conv) begin
                lp_s0 = lp_s0_max ;
            end
            phi_s0_bulk_0 = T6 ;
            Q_s0_bulk_0 = T4 ;
        end
    end  // newton loop(phi_s0_bulk_0) end //

    // Vgs_fb shift for initial guess(start) //
    begin : VgsfbShiftForInitialGuess
        real T0, T1, T2, T3, T4, T5;

        phi_b_dep = phi_b_dep0 ;
        T1 = sqrt(`cnst_2esi_q * phi_b_dep / `N_sub_SOI) ;
        if (T1 > 0.99 * t_SOI) begin
            T0 = 1.0 / C_fox ;
            T1 = t_SOI / `C_ESI ;
            T2 = 1.0 / C_box ;
            T3 = 1.0 / (T0 + T1 + T2) ;
            T4 = 1 - T3 * T0 ;
            T5 = T0 * (T3 * (- Vbsbiz + (T2 + 0.5 * T1) * (-Q_FD_SOI))) ;
            shift = T5 / T4 ;
            Vgs_fb = Vgs_fb + shift ;
        end
    end  //  Vgs_fb shift for initial guess(end) //

    begin : Vxsztmp
        real T1, Vzadd;
        T1 = Vbsc_dVbse * Vds / 2 ;
        `Fn_SymAdd(Vzadd, T1, 10e-2) //10e-3
        if (Vzadd < `ps_conv) begin
            Vzadd = `ps_conv ;
        end
        T3 = Vzadd;
    end //

    Vgpd = Vgs + T3 - Vfb + dVth - dPpg ;
    WdSOI_ini1 = WdSOI_ini0 / (WdSOI_ini1_dlt * Pb2) * Vgpd ;
    `Fn_SL_CP(WdSOI_ini2, WdSOI_ini1,          0, t_SOI * `QDEP_DLT  , `QDEP_PW )
    `Fn_SU_CP(WdSOI_ini2, WdSOI_ini2, WdSOI_ini0, t_SOI * `QDEP_DLT2 , `QDEP_PW )
    Q_s0_dep_ini =  - WdSOI_ini2 * q_Nsub ;

    // Initial guess of the depletion charge for source side end  //
    //-----------------------------------------------------------*

    //-----------------------------------------------------------*
    //* Initial Guess for Source Side.
    //*-----------------//

    FD_start = (-Q_FD_SOI) * t_SOI / 2.0 / `C_ESI + beta_inv ;
    FD_end = FD_start - Q_s0_bulk_0 * t_SOI / `C_ESI ;

`ifdef DISABLE_COPPRV
`else

    //-------------------------------------------------------------------*
    // Update initial potential values by previous values
    //----------------//

            vtol_pprv = 5.0e-2 ;
            vtol_pprv_u = 6.0e-2;
            vtol_pprv_l = 4.0e-2;


            if ( COPPRV ) begin
                if (called >= 1) begin
                    Vbsc_dif = Vbsc - vbsc_prv ; Vdsc_dif = Vdsc - vdsc_prv ; Vgsc_dif = Vgsc - vgsc_prv ;
                    sum_vdif = abs(Vbsc_dif) + abs(Vdsc_dif) + abs(Vgsc_dif) ;

                    flg_pprv = (flg_pprv_prv > 0 )? 1 : 0 ;
                    if (sum_vdif > vtol_pprv_u) flg_pprv = 0;
                    if (sum_vdif <= vtol_pprv_l) flg_pprv = 1;
                    if (mode * mode_prv < 0) flg_pprv = 0;

                    if ( called >=2 && flg_pprv ==1 ) begin
                        Vbsc_dif2 = vbsc_prv - vbsc_prv2 ; Vdsc_dif2 = vdsc_prv - vdsc_prv2 ; Vgsc_dif2 = vgsc_prv - vgsc_prv2 ;
                        sum_vdif2 = abs(Vbsc_dif2) + abs(Vdsc_dif2) + abs(Vgsc_dif2) ;
                        if (`epsm10 < sum_vdif2 && sum_vdif2 <= vtol_pprv && mode_prv * mode_prv2 > 0 ) flg_pprv = 2 ;
                    end
                    dVbs = Vbsc_dif ; dVds = Vdsc_dif ; dVgs = Vgsc_dif ;
                    ddVbs = dVbs * dVbs /2 ; ddVds = dVds * dVds /2 ; ddVgs = dVgs * dVgs /2 ;
                    //
                    if ( flg_pprv >= 1 ) begin
                        Pss0_ini = pss0_prv;
                        Pbs0_ini = pbs0_prv;
                        Psb0_ini = psb0_prv;


                        Pssl_ini = pssl_prv;
                        Pbsl_ini = pbsl_prv;
                        Psbl_ini = psbl_prv;
                    end

                    flg_pprv_prv = flg_pprv;

                end else begin
                    Vbsc_dif  = 0.0 ; Vdsc_dif  = 0.0 ; Vgsc_dif  = 0.0 ;
                    Vbsc_dif2 = 0.0 ; Vdsc_dif2 = 0.0 ; Vgsc_dif2 = 0.0 ;
                    sum_vdif  = 0.0 ; sum_vdif2 = 0.0 ; flg_pprv = 0 ;

                    flg_pprv_prv = flg_pprv;

                end
            end // End of (COPPRV)

`endif // COPPRV

        if ( flg_pprv >= 1 ) begin
            phi_s0_SOI  = Pss0_ini ;
            phi_b0_SOI  = Pbs0_ini ;
            phi_s0_bulk = Psb0_ini ;
            flg_depmode = (phi_s0_SOI < FD_end) ? 1 : 2 ;
        end

        else begin : HSOI_calc_ini
            //-----------------------------------------------------------*
            //* Initial guess for Ps0. (start)
            //*-----------------//
`define  ps_conv_ini 1E-3

            //---------------------------------------------------*
            //* Ps0_iniA: solution of subthreshold equation assuming zone-D1/D2.
            //*-----------------//
            TX = 1.0e0 + 4.0e0 * ( beta * ( Vgpz ) - 1.0e0 ) / ( fac1p2 * beta2 ) ;
            TX = `Fn_Max( TX , `epsm10 ) ;
            Ps0_iniA = Vgpz + fac1p2 * beta * 0.5 * ( 1.0e0 - sqrt( TX ) ) ;

            //---------------------------------------------------*
            //* Analytical initial guess.
            //*-----------------//
            //-------------------------------------------*
            //* Common part.
            //*-----------------//
            Chi = beta * ( Ps0_iniA ) ;
            if ( Chi < `znbd3 ) begin
                //-----------------------------------*
                //* zone-D1/D2
                //* - Ps0_ini is the analytical solution of Qs=Qb0 with
                //*   Qb0 being approximated to 3-degree polynomial.
                //*-----------------//
                TY = beta * ( Vgpz - Vbs ) ;
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
                T0 = 1.0 / C_fox ;
                T1 = t_SOI / `C_ESI ;
                T2 = 1.0 / C_box ;
                T3 = 1.0 / (T0 + T1 + T2) ;
                T4 = T3 * (Vgpz - Vbsbiz + (T2 + 0.5 * T1) * (-Q_s0_dep_ini)) ;
                Ps0_iniA = Vgpz - T4 / C_fox ;
                Ps0_ini = Ps0_iniA ;
            end else begin
                //-----------------------------------*
                //* Strong inversion zone.
                //* - Ps0_iniB : upper bound.
                //*-----------------//
                T1 = 1.0 / cnst1SOI / cnstC_foxi ;
                T2 = T1 * (Vgpz - shift) * (Vgpz - shift) ;
                T3 = beta + 2.0 / (Vgpz - shift) ;
                Ps0_iniB = ln ( T2 ) / T3 ;
                `Fn_SUtemp( Ps0_ini , Ps0_iniA, Ps0_iniB, `c_ps0ini_2)
            end

            WdSOI = (Ps0_ini > 0.0) ? sqrt(`cnst_2esi_q * Ps0_ini / `N_sub_SOI) : 0.0 ;
            if (WdSOI < t_SOI) begin
                flg_depmode = 1 ; /* PD mode */
            end else begin
                flg_depmode = 2 ; /* FD mode */
            end
            if ( Vgs - shift <= Vth ) begin
                //-----------------------------------*
                //* Accumulation & Weak inversion zone.
                //*-----------------//
                T0 = 1.0 / C_fox ;
                T1 = t_SOI / `C_ESI ;
                T2 = 1.0 / C_box ;
                T3 = 1.0 / (T0 + T1 + T2) ;
                T4 = T3 * (Vgpz - Vbsbiz + (T2 + 0.5 * T1) * (-Q_s0_dep_ini)) ;
                Ps0_iniA = Vgpz - T4 / C_fox ;
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
                T4 = T3 * (Vgpz - Vbsbiz + (T2 + 0.5 * T1) * (-Q_s0_dep_ini)) ;
                Ps0_iniA = Vgpz - T4 / C_fox ;
                // end
                Ps0_ini = Ps0_iniA ;

                if ( Vgpz - shift > 0 ) begin // for smoothing
                    //---------------------------------------------------*
                    //* Analytical initial guess.
                    //*-----------------//
                    //-------------------------------------------*
                    //* Common part.
                    //*-----------------//
                    T1 = 1.0 / cnst1SOI / cnstC_foxi ;
                    T2 = T1 * (Vgpz - shift) * (Vgpz - shift) ;
                    T3 = beta + 2.0 / (Vgpz - shift) ;
                    Ps0_iniB = ln (T2) / T3 ;
                    `Fn_SU_CP(Ps0_ini, Ps0_iniA, Ps0_iniB * 0.98 , 0.4 , 2)
                end // End of smoothing
            end // End of FD

            //---------------------------------------------------*
            //* Assign initial guess.
            //*-----------------//
            phi_s0_SOI = Ps0_ini ;
            Psl_lim = Ps0_iniA ;
            // Initial guess for Ps0. (end) //

            // initial guess for phi_s0_bulk. (start) //
            T1 = phi_s0_SOI + 0.5 * Q_FD_SOI * C_soi_inv - Vbsbiz ; // A
            if (T1 < 0.0) begin
                // New equation.
                T2 = cnst0bulk * (C_box_inv + C_soi_inv) ; T2 = T2 * T2 ; // B
                T5 = -1.6 * T1 + 0.6 ; // D2
                T4 = 0.5 ;
                `Fn_SUtemp(T4, T4, T5, (T5*1e-3))
                T3 = T2 * T4 * beta2 ;
                phi_s0_bulk = ( T1 * ( 1.0 - sqrt( T3 ) ) ) / ( 1.0 - T3 );
            end else begin
                // Old equation
                T0 = cnst0bulk * cnst0bulk * C_box_FD_inv * C_box_FD_inv ;
                begin : phi_s0_bulk_newton
                    T1 = -(Vbsbiz - phi_s0_SOI - Q_FD_SOI / 2 * t_SOI / `C_ESI) ;
                    T2 = (2 * T1 + T0 * beta) * (2 * T1 + T0 * beta) - 4 * (T1 * T1 + T0) ;
                    T2 = `Fn_Max(T2, `epsm10) ;
                    T2 = sqrt(T2) ;
                    T3 = 2 * T1 + T0 * beta ;
                    psb_iniA = (T3 - T2) / 2 ;
                    psb_iniB = ln (T1 * T1 / T0 / cnst1bulk) / (beta + 2.0 / T1) ;
                    if (psb_iniA < Pb2_bulk) begin
                        phi_s0_bulk = psb_iniA ;
                    end else begin
                        `Fn_SUtemp(phi_s0_bulk, psb_iniA, psb_iniB, `c_ps0ini_2)
                    end
                end // phi_s0_bulk_ana
            end // End of Old Eq.
            // initial guess for phi_s0_bulk. (end) //

            // newton loop for phi_s0_bulk(start) //
            begin : phi_s0_bulk_itr
                for (lp_s0 = 0 ; lp_s0 < lp_s0_max ;  lp_s0 = lp_s0 + 1 ) begin
                    T1 = cnst0bulk ;
                    T2 = beta * phi_s0_bulk ;
                    T3 = exp(-T2) ;
                    if (phi_s0_bulk > `C_PHI_1_MINIMUM) begin
                        T0 = exp(beta * phi_s0_bulk) ;
                        T4 = -T1 * sqrt(T3 + T2 - 1 + cnst1bulk * (T0 - 1)) ;        //Qbulk
                        T5 = c0bulk / T4 * (-T3 + 1 + cnst1bulk * T0) ;      //dQbulk_dPsb
                    end else if (phi_s0_bulk < -`C_PHI_1_MINIMUM) begin
                        T4 = T1 * sqrt(T3 + T2 - 1) ;        //Qbulk
                        T5 = c0bulk / T4 * (-T3 + 1) ;       //dQbulk_dPsb
                    end else begin
                        T4 = -sqrt(c0bulk / beta) * beta * phi_s0_bulk ;     //Qbulk
                        T5 = -sqrt(c0bulk * beta) ;  //dQbulk_dPsb
                    end
                    `Fn_SZ_DX(T6, T4, Q_FD_dlt1, T7)
                    `Fn_SU_DX(T6, T6, (-Q_FD_SOI), Q_FD_dlt2, T8)
                    T7 = T7 * ( T5 * T8 ) ;
                    phi_b_dep = T6 * T6 / 2.0 / `C_ESI / `C_QE / `N_sub_SOI ;
                    phi_b_dep_dPsb = 2 * phi_b_dep * T7 / T6 ;

                    T6 = (phi_s0_bulk -
                    (phi_s0_SOI - phi_s0_bulk + T4 / C_box + (T4 + Q_FD_SOI / 2) * t_SOI / `C_ESI - Vbsbiz +
                    phi_b_dep) / (-1 + T5 / C_box + T5 * t_SOI / `C_ESI + phi_b_dep_dPsb)) ;
                    T7 = lp_s0 ;
                    if (abs(T6 - phi_s0_bulk) < `ps_conv_ini) begin
                        lp_s0 = lp_s0_max ;
                    end
                    phi_s0_bulk = T6 ;
                    Q_s0_bulk = T4 ;

                    // T8 = Vbsbiz + phi_s0_bulk ;
                    // T9 = T8 - Q_s0_bulk / C_box ;
                end
                // phi_s0_bulk = T8 ;
                phi_s0_bulk= Vbsbiz + phi_s0_bulk ;
                phi_b0_SOI = phi_s0_SOI + C_soi_inv * ( 0.5 * Q_FD_SOI + Q_s0_bulk ) ;
            end // phi_s0_bulk_itr
            // FD case(end) //
            // newton loop for phi_s0_bulk(end) //

            // end // End of Initial guess for Ps0s
            //-----------------------------------------------------------*
        end // HSOI_calc_ini

        if (COISUB == 1 &&(Vgs > Vgs_fb + 0.2)) begin
            //---------------------------------------------------*
            //*  Floating Body Effect(FBE) 081120  @@@ ***
            //----------------//

            vfbsub1 = vfbsub0 ;
            Vgpsub = Vgsz - vfbsub1 + dVth - dPpg ;

            sti2_dlt = SUBDLT ;

            //---------------------------------------------------*
            //***  Simplified Isub for FBE
            //*-----------------//

            //  Pseud Ids using STI model @@@ 081110 //
            Vgssti = Vgpsub ;
            costi0 = sqrt(2.0e0 * `C_QE * `N_sub_SOI * `C_ESI / beta) ;
            costi1 = Nin * Nin / `N_sub_SOI / `N_sub_SOI ;
            costi3 = costi0 * costi0 / C_fox / C_fox ;
            costi4 = costi3 * beta / 2.0e0 ;
            costi5 = costi4 * beta * 2.0e0 ;
            costi6 = sqrt(1.0e0 + 4.0e0 * (beta * Vgssti - 1.0e0) / costi5) ;
            Psasti = Vgssti + costi4 * (1.0e0 - costi6) ;
            Asti = 1.0e0 / costi1 / costi3 ;
            Psbsti = ln (Asti * (Vgssti * Vgssti)) / (beta + 2.0e0 / Vgssti) ;
            Psab = Psbsti - Psasti - sti2_dlt ;
            Psti = Psbsti - 0.5e0 * (Psab + sqrt(Psab * Psab + 4.0e0 * sti2_dlt * Psbsti)) ;

            expsti = exp(beta * Psti) ;
            sq1sti = (beta * Psti - 1.0e0 + costi1 * expsti) ;
            sq2sti = (beta * Psti - 1.0e0) ;
            if (sq1sti > 0 && sq2sti > 0) begin
                sq1sti = sqrt(beta * Psti - 1.0e0 + costi1 * expsti) ;
                sq2sti = sqrt(beta * Psti - 1.0e0) ;
                Qn0sti = costi0 * (sq1sti - sq2sti) ;
                costi7 = 2.0e0 * Weff / beta ;
                Mu = 300.0 * `C_cm2m_p2;
                Lred = 0.0 ;
                T1 = -expm1(-beta * Vdsz) ;    // expm1(x) = exp(x) - 1 //
                T2 = 1.0 / (Leff - Lred) ;
                Idssti = costi7 * Mu * Qn0sti * T1 * T2 ;
                Ids_isub = Idssti ;
                Ps0_isub = Psti ;

                //---------------------------------------------------*
                //* Pds calculation for Psl
                //*-----------------//
                TX = 1.0e0 + 4.0e0 * (beta * Vgpz - 1.0e0) / (fac1p2 * beta2) ;
                if ( TX < `epsm10 ) begin
                    TX = `epsm10 ;
                end
                Ps0_iniA = Vgpz + fac1p2 * beta * 0.5 * (1.0e0 - sqrt(TX)) ;
                Psl_lim = Ps0_iniA ;

                //---------------------------------------------------*
                //* Analytical initial guess.
                //*-----------------//
                Pds_max = Ps0_iniA - Ps0_isub ;
                if ( Pds_max < 0.0e0 ) begin
                    Pds_max = 0.0 ;
                end
                T5 = (1.0e0 + `c_pslini_1) * Pds_max ;
                T6 = T5 - Vdsz - `c_pslini_2 ;
                T7 = sqrt ( T6 *  T6 + 4.0 * ( T5 ) * ( `c_pslini_2 ) ) ;
                Pds_ini = ( T5 ) - 0.5 * ( T6 + T7 ) ;
                if (Pds_ini > Pds_max ) begin
                    Pds_ini = Pds_max ;
                end
                Pds_qwe = Pds_ini ;

                begin : COIEVB_model
                    real EVB1_QE_WL , EVB1_QE_WL_p_Egp12 , Eevb_wo_Vox ;
                    real reali, realN, r, Vox, d0, T0, T1, T2, T3, T4, T5, T6, T7, T8 ;
                    real CGS_Tfox0, CGS_weff_nf, CGS_Leff;

                    CGS_Tfox0 = Tfox0 * `C_m2cm;
                    CGS_weff_nf = weff_nf * `C_m2cm;
                    CGS_Leff = Leff * `C_m2cm;
                    //---------------------------------------------------*
                    //* Ievb induced by Fowler-Nordheim tunneling and direct tunneling
                    //*------------------//
                    if (COIEVB == 0) begin
                        Ievb = 0e0 ;
                    end else begin
                        phib = 4.12 ;
                        // = sqrt( phib ) //
                        // = phib^(3/2) //
                        EVB1_QE_WL = EVB1 * `C_QE * CGS_weff_nf * CGS_Leff ;
                        EVB1_QE_WL_p_Egp12 = EVB1_QE_WL / Egp12 ;
                        Eevb_wo_Vox = -(FVBS * Vbspz + dVthSC + dVthLP + Eg + EVB3) / CGS_Tfox0 ;
                        for (i = 0 ; i <= `N - 1 ; i= i + 1) begin
                            reali = i ;  realN = `N ; r =  reali / realN ;
                            Vox = Vgp + Vzadd - (Pds_qwe * r + Ps0_isub) ;
                            d0 = 1.0 - Vox / phib ;

                            // T2 = Eevb //
                            T2 = Eevb_wo_Vox + Vox / CGS_Tfox0 ;
                            T0 = T2 * T2 ;
                            `Fn_SZtemp(d0, d0, 1.0e-3)
                            T1 = EVB2 * (1.0 - sqrt(d0) * d0) ;
                            T3 = -T1 / T2 ;
                            if (T3 < -`EXP_THR) begin
                                T5 = 0.0 ;
                            end else begin
                                T5 = exp(T3) ;
                            end
                            T6 = EVB1_QE_WL_p_Egp12 ;
                            T7 = 0.25e0 * T6 * T1 * T1 * `c_exp_2 ;
                            if (2e0 * T2 + T1 < 0e0) begin
                                Ievb0 = T7 ;     // = 0.25e0 * T6 * T1 * T1 * c_exp_2 ; // minimum value //
                            end else begin
                                T4 = EVB1_QE_WL ;
                                T8 = T4 * T0 * T5 ;
                                if (T8 < T7 || T2 < 0e0) begin
                                    Ievb0 = T7 ;   // 0.25e0 * T6 * T1 * T1 * c_exp_2 ; ///* minimum value */
                                end else begin
                                    Ievb0 = T8 ;   // T4_0 * T0_0 * T5_0 ; //
                                end
                            end
                            Ievb = Ievb + Ievb0 ; // = Ievb + Ievb_0 ; //
                            if ( Ievb0 < `Ievb_min ) begin
                                i = `N ;  // break
                                lp_s0 = lp_s0_max ;
                            end
                        end
                    end // End of COIEVB_model }
                end
                //---------------------------------------------------------//

                //-------------------------------------------*
                //* Conductive case.
                //*-----------------//
                begin : IsubModel2
                    real T1, T2, T3, T4, T5, T6,T6w, T7, T8, T9;
                    real Psislsat, Psisubsat;

                    if (SUB1 <= 0.0 || MKS_VMAX <= 0.0) begin
                        Isub = 0.0 ;
                    end else begin
                        // still compatible //
                        T1 = Vgpsub ;       //ina_fin //
                        T7 = C_fox * C_fox ;
                        T8 = qnsub_esi ;
                        T3 = T8 / T7 ;
                        T9 = 2.0 / T8 ;
                        T4 = 1.0 + T9 * T7 ;
                        T5 = T1 - beta_inv - `X_vbs * Vbspz ;
                        T6w = T4 * T5 ;
                        `Fn_SZtemp(T6, T6w, 1.0e-3)
                        T6 = T6 + `Small ;
                        T6 = sqrt(T6) ;
                        Psislsat = T1 * `X_vgs + T3 * (1.0 - T6) ;
                        Psisubsat = `X_vds * Vdsz + Ps0_isub - `X_slg * `Z_vgs * Psislsat ;  //ina_fin //
                        `Fn_SZtemp(Psisubsat, Psisubsat, 1.0e-2)     // @@@ //
                        Psisubsat = Psisubsat + `Small ; // @@@ //
                        T2 = exp(-`X_sub2 / Psisubsat) ;
                        Isub = `X_sub1 * Psisubsat * Ids_isub * T2 ;
                    end            // end of !if( sub1 < 0 || vmax < 0 )  //
                end //
                // @@@  Qh vs Isub Calculation //
                begin : FBEmodel
                    real T1, T2, T4, T5, T6, T7, T8;

                    if (COFBE == 1) begin
                        // The following values should not be hard-coded. //
                        T1 = `C_QE * t_SOI * weff_nf * exp(-beta * QHE2) ;  // Vbi => qhe2
                        T2 = `Lp * `Dn * `Nd + `Ln * `Dp * `N_sub_SOI ;
                        T4 = `Lp * `Ln / (T1 * T2) ;
                        nume = (Isub + Ievb) * T4 ;
                        T5 = QHE1 * beta_inv * log1p(nume) ; // qhe1 : fitting param
                        // Qb(Vb=Vbody) - Qb(Vb=0) //
                        T6 = sqrt(2 * `C_ESI * `C_QE * `N_sub_SOI * beta_inv) ;
                        T7 = sqrt(expm1(-beta * (Ps0_isub - T5)) + beta * (Ps0_isub - T5)) ;
                        T8 = sqrt(expm1(-beta * Ps0_isub) + beta * Ps0_isub) ;
                        Qhs = -T6 * (T7 - T8) ;
                        if (COHIST) begin
                            Rsb = HIST1 / (Isub + HIST2) ;
                            tauh = Rsb * C_fox ;
                            Qhs_prev = Qhs ;
                            Qhs_hist = `NQS_CAP * V(nqs_qhs) ;
                            Qhs      =  Qhs_hist ;
                            Iqh_nqs  = (Qhs_hist - Qhs_prev) / tauh ;
                        end //
                    end else begin // Case for  W/O FBE //
                        Qhs = 0 ;
                    end //
                end // FBEmodel
            end else begin   // sq1sti,sq2sti < 0 //
                Isub = 0.0 ;
                Qhs = 0 ;
            end

        end else begin      //  coisub==0 || Vgs > Vgs_fb + 0.2 //
            Isub = 0.0 ;
            Qhs = 0 ;
        end
        // End of Qh Calculation  //

        begin : Ps0_3_var_NewtonLoop
            real e0, T1, T2, T3, T4, T5 ;
            real Q_n0_dPss, Q_s0_bulk_dPsb ;
            real dPss, dPbs, dPsb, PF1,PF11,PF12,PF13, PF2,PF21,PF22,PF23, PF3,PF32,PF33;
            real PDJ, PDJI, PJI11,PJI12,PJI13,PJI21,PJI22,PJI23,PJI31,PJI32,PJI33;
            real TMF0 , T4_dPss ;

            //-----------------------------------------------------------*
            //*  Solve Poisson's equation for Ps0. (start)
            //*-----------------//
            // save the initial guesses for nonconverged cases //
            phi_s0_SOI_ini = phi_s0_SOI ;
            phi_b0_SOI_ini = phi_b0_SOI ;
            phi_s0_bulk_ini = phi_s0_bulk ;
            flg_conv = 0 ; flg_brk8 = 0 ;

            for (lp_s0 = 1 ; lp_s0 <= lp_s0_max ;  lp_s0 = lp_s0 + 1 ) begin

                T1 = phi_s0_bulk - (Vbsbiz) ;
                e0 = beta * (T1) ;
                T0 = exp(-e0) ;
                if (T1 < -`C_PHI_1_MINIMUM) begin
                    Q_s0_bulk = cnst0bulk * sqrt(T0 + e0 - 1.0) ;
                    Q_s0_bulk_dPsb = c0bulk * (-T0 + 1.0) / Q_s0_bulk ;
                end else if (T1 > `C_PHI_1_MINIMUM) begin
                    T2 = exp(e0) ;
                    Q_s0_bulk = -cnst0bulk * sqrt(T0 + e0 - 1.0 + cnst1bulk * (T2 + e0 - 1.0)) ;
                    Q_s0_bulk_dPsb = c0bulk * (-T0 + 1.0 + cnst1bulk * (T2 + 1) ) / Q_s0_bulk ;
                end else begin
                    Q_s0_bulk = -cnst0bulk* e0 ;
                    Q_s0_bulk_dPsb = -cnst0bulk * beta ;
                end

                // Eval_calc_Q_n0 (begin)
                Q_s0_dep = Q_s0_dep_ini ;
                e0 = beta * phi_s0_SOI ;
                T5 = exp(beta * phi_s0_SOI) ;
                T3 = 1.0 ; // = exp(beta * phi_b0_SOI) ;
                T4 = sqrt(Q_s0_dep * Q_s0_dep /(cnst0SOI * cnst0SOI) + 2 * cnst1SOI * (T5 + e0 - T3)) ;
                T4_dPss = (   2 * beta * cnst1SOI * (T5 + 1) )/( 2 * T4 ) ;
                Q_n0 = -cnst0SOI * T4 - Q_s0_dep ;
                Q_n0_dPss = - cnst0SOI * T4_dPss ;

                // Eval_calc_Q_b0_dep (begin)
                T1 = (phi_b0_SOI - phi_s0_SOI) /QDEPB_DLT ;
                e0 = beta * (T1) ;
                `Fn_DExp(T0, -e0, T6)
                T0 = exp(-e0) ;
                T2 = sqrt(T0 + e0 - 1.0) ;
                if (T1 < -`C_PHI_1_MINIMUM) begin
                    Q_b0_dep = cnst0SOI * T2 ;
                    Q_b0_dep_dPbs = cnst0SOI * beta * (-T6 + 1.0) / (2 * T2) /QDEPB_DLT ;
                    Q_b0_dep_dPss = - Q_b0_dep_dPbs ;
                end else if (T1 > `C_PHI_1_MINIMUM) begin
                    Q_b0_dep = -cnst0SOI * T2 ;
                    Q_b0_dep_dPbs = -cnst0SOI * beta * (-T6 + 1.0) / (2 * T2) /QDEPB_DLT ;
                    Q_b0_dep_dPss = - Q_b0_dep_dPbs ;
                end else begin
                    Q_b0_dep = -cnst0SOI * e0 / `C_SQRT_2 ;
                    Q_b0_dep_dPbs = -cnst0SOI *  beta / `C_SQRT_2 ;
                    Q_b0_dep_dPss = - Q_b0_dep_dPbs ;
                end
                `Fn_SU_CP_DX(Q_b0_dep, Q_b0_dep , 0, -Q_WdSOI_max*`QDEP_DLT2 , `QDEP_PW , T0)
                Q_b0_dep_dPbs = Q_b0_dep_dPbs * T0 ;
                Q_b0_dep_dPss = Q_b0_dep_dPss * T0 ;
                `Fn_SL_CP_DX(Q_b0_dep, Q_b0_dep , (Q_FD_SOI-Q_s0_dep), -(Q_FD_SOI-Q_s0_dep)*`QDEP_DLT2 , `QDEP_PW , T0)
                Q_b0_dep_dPss = Q_b0_dep_dPss * T0 ;
                Q_b0_dep_dPbs = Q_b0_dep_dPbs * T0 ;

                // Eval_calc_Q_b0_dep (end)

                Q_dep0 = Q_s0_dep + Q_b0_dep ;

                if ( flg_conv == 1 ) begin
                    flg_brk8 = lp_s0; lp_s0 = lp_s0_max ;
                end else begin

                    PF1 = phi_s0_SOI - Vgpz - C_fox_inv * (Q_s0_bulk + Q_s0_dep + Q_n0 + Q_b0_dep + Qhs) ;       // @@@ //
                    PF11 = 1.0 - C_fox_inv * (Q_n0_dPss + Q_b0_dep_dPss ) ;
                    PF12 =     - C_fox_inv * (          + Q_b0_dep_dPbs ) ;
                    PF13 =     - C_fox_inv * (Q_s0_bulk_dPsb ) ;

                    T1 = phi_s0_SOI + C_soi_inv * (0.5 * Q_FD_SOI + Q_s0_bulk ) ;
                    T3 = C_soi_inv * Q_s0_bulk_dPsb ;
                    PF2 = phi_b0_SOI - T1 ;
                    PF21 = -1.0 ;
                    PF22 =  1.0 ;
                    PF23 = -T3 ;

                    PF3 = phi_s0_bulk - phi_b0_SOI - C_box_inv * Q_s0_bulk ;
                    PF32 = -1.0 ;
                    PF33 = 1.0 - C_box_inv * Q_s0_bulk_dPsb ;

                    // assuming PF31=0 //
                    PDJ = PF11 * PF22 * PF33 - PF11 * PF23 * PF32 - PF12 * PF21 * PF33 + PF13 * PF21 * PF32 ;
                    PDJI = 1.0 / (PDJ + `Small) ;
                    PJI11 = PF22 * PF33 - PF23 * PF32 ;
                    PJI12 = PF13 * PF32 - PF12 * PF33 ;
                    PJI13 = PF12 * PF23 - PF13 * PF22 ;
                    PJI21 = -PF21 * PF33 ;
                    PJI22 = PF11 * PF33 ;
                    PJI23 = PF13 * PF21 - PF11 * PF23 ;
                    PJI31 = PF21 * PF32 ;
                    PJI32 = -PF11 * PF32 ;
                    PJI33 = PF11 * PF22 - PF12 * PF21 ;

                    dPss = -PDJI * (PJI11 * PF1 + PJI12 * PF2 + PJI13 * PF3) ;
                    dPbs = -PDJI * (PJI21 * PF1 + PJI22 * PF2 + PJI23 * PF3) ;
                    dPsb = -PDJI * (PJI31 * PF1 + PJI32 * PF2 + PJI33 * PF3) ;

                    /* New PS convergence method */
                    T1 = abs(dPss) ;
                    if (T1 < abs(dPbs)) T1 = abs(dPbs) ;
                    if (T1 < abs(dPsb)) T1 = abs(dPsb) ;
                    scale_fac=1.0 ;
                    if (lp_s0 > 80) begin
                        scale_fac = 125.0 ;
                    end else if (lp_s0 > 40) begin
                        scale_fac = 125.0 ;
                    end else if (lp_s0 > 20) begin
                        scale_fac = 25.0 ;
                    end else if (lp_s0 > 10) begin
                        scale_fac = 5.0 ;
                    end

                    if (T1 > `dP_max/scale_fac) begin
                        dPss = dPss * ( `dP_max/scale_fac / T1 ) ;
                        dPbs = dPbs * ( `dP_max/scale_fac / T1 ) ;
                        dPsb = dPsb * ( `dP_max/scale_fac / T1 ) ;
                    end
                    phi_s0_SOI = phi_s0_SOI + dPss ;
                    phi_b0_SOI = phi_b0_SOI + dPbs ;
                    phi_s0_bulk = phi_s0_bulk + dPsb ;

                    PSCONV_3D = `ps_conv * scale_fac * `PSCONVFAC ;
                    if (T1 < PSCONV_3D) begin
                        flg_conv = 1 ;
                    end

                end  // End of flg_brk8

            end // end of Ps0 3Newton loop with lp_s0   //

            lp_s0 = (flg_brk8 > 0) ? flg_brk8 : lp_s0 ;

            //  Solve Poisson's equation for Ps0. (end) //

            if (flg_conv == 0) begin    // reset to the initial guesses in nonconvergent cases //
                phi_s0_SOI = phi_s0_SOI_ini ;
                phi_b0_SOI = phi_b0_SOI_ini ;
                phi_s0_bulk = phi_s0_bulk_ini ;
            end

            //-------------------------------------------*
            //Procedure for diverged case.
            //----------------//
            Ps0 = phi_s0_SOI ;
            Qn0 = -Q_n0 ;
            if (Qn0 <= `Small) begin
                Qn0 = `Small ;
            end

            flg_conv_0 = flg_conv ; // for Ps0 only.

        end // Ps0_3_var_NewtonLoop


        //---------------------------------------------------*
        //    VgVt : Vgp - Vth_qi. ( Vth_qi is Vth for Qi evaluation. )
        //    ----------------//
        VgVt = Qn0 * C_fox_inv ;

        //-----------------------------------------------------------*
        //make Qi=Qd=Ids=0 if VgVt <= VgVt_Small
        //N.B.: Out of consideration.
        //----------------//
        if (phi_s0_SOI <= 0.0 && flg_skipAcc) begin
            // Accumulation Zone(start) //
            flg_depmode_d = flg_depmode ;
            T0 = -weffcv_nf * Leff_cv ; // 20180718
            Q_sL_dep = Q_s0_dep_ini ;
            Q_bL_dep = Q_b0_dep ;
            Q_depL = Q_sL_dep + Q_bL_dep ;
            Qbu = - 0.5 * (Q_depL + Q_dep0);
            Qb = T0 * Qbu ;
            Qd_FB = Qb * `C_QBRAT ;
            Qs_FB = Qb * (1.0 - `C_QBRAT) ;

            Qi = 0.0 ;
            Qsub = Q_s0_bulk * Leff_cv * weffcv_nf ; // 20180718
            Qd = 0.0 ;
            Ids = 0.0 ;
            VgVt = 0.0 ;
            flg_noqi = 1 ;
            phi_sL_SOI = phi_s0_SOI ;
            phi_bL_SOI = phi_b0_SOI ;
            phi_sL_bulk = phi_s0_bulk ;
            Q_sL_bulk = Q_s0_bulk ;
            Psl = Ps0 ;
            Psdl = Psl ;
            flg_conv_L = 0 ;
        end
        else begin

            // Vdseff(begin) //
            begin : SetVdseffFB
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

            //---------------------------------------------------*
            //* Skip Psl calculation when Vds is very Small.
            //*-----------------//
            if (Vds < 0.0) begin
                Psl = Ps0 ;
                Pds = Psl - Ps0 ;
                phi_sL_SOI = Psl ;
                phi_bL_SOI = phi_b0_SOI ;
                phi_sL_bulk = phi_s0_bulk ;
                flg_conv = 1 ;
                flg_depmode_d = flg_depmode ;
            end else begin

                //-----------------------------------------------------------*
                //* Initial Guess for Drain Side.
                //*-----------------//
                if ( flg_pprv >= 1 ) begin
                    phi_sL_SOI  = Pssl_ini ;
                    phi_bL_SOI  = Pbsl_ini ;
                    phi_sL_bulk = Psbl_ini ;
                    flg_depmode_d = (phi_sL_SOI < FD_end) ? 1 : 2 ;
                end else begin

                    //-----------------------------------------------------------*
                    //* Initial guess of  Psl(start)
                    //*-----------------//

                    //---------------------------------------------------*
                    //* Analytical initial guess.
                    //*-----------------//
                    Pds_max = `Fn_Max(Psl_lim - phi_s0_SOI, 0.0) ;
                    `Fn_SUtemp(Pds_ini, Vds, (1.0e0 + `c_pslini_1) * Pds_max, `c_pslini_2)
                    Pds_ini = `Fn_Min(Pds_ini, Pds_max) ;
                    if (Pds_ini < 0.0) Pds_ini = 0.0 ;
                    else if (Pds_ini > Vds) Pds_ini = Vds ;

                    //---------------------------------------------------*
                    //* Assign initial guess.
                    //*-----------------//
                    Pds = Pds_ini ;
                    Psl = phi_s0_SOI + Pds ;
                    phi_sL_SOI = Psl ;

                    // Initial guess of  Psl(end) //

                    // initial value for phi_sL_bulk(start) //
                    begin : InitialValueForPhiSLBulk
                        real T0, T1, T2, T3, psb_iniA, psb_iniB;

                        phi_b_dep = phi_b_dep0 ;
                        T0 = cnst0bulk * cnst0bulk * C_box_FD_inv * C_box_FD_inv ;
                        if (phi_sL_SOI < FD_end) begin
                            T1 = -(Vbsbiz) ;
                            T2 = (2 * T1 + T0 * beta) * (2 * T1 + T0 * beta) - 4 * (T1 * T1 + T0) ;
                            T2 = `Fn_Max(T2, `epsm10) ;
                            T2 = sqrt(T2) ;
                            T3 = 2 * T1 + T0 * beta ;
                            psb_iniA = (T3 - T2) / 2 ;
                            psb_iniB = ln (T1 * T1 / T0 / cnst1bulk) / (beta + 2.0 / T1) ;
                            if (psb_iniA < Pb2_bulk) begin
                                phi_sL_bulk = psb_iniA ;
                            end else begin
                                `Fn_SUtemp(phi_sL_bulk, psb_iniA, psb_iniB, `c_ps0ini_2)
                            end
                        end else begin
                            T1 = -(Vbsbiz - phi_sL_SOI - Q_FD_SOI / 2 * t_SOI / `C_ESI) ;
                            T2 = (2 * T1 + T0 * beta) * (2 * T1 + T0 * beta) - 4 * (T1 * T1 + T0) ;
                            T2 = `Fn_Max(T2, `epsm10) ;
                            T2 = sqrt(T2) ;
                            T3 = 2 * T1 + T0 * beta ;
                            psb_iniA = (T3 - T2) / 2 ;
                            psb_iniB = ln (T1 * T1 / T0 / cnst1bulk) / (beta + 2.0 / T1) ;
                            if (psb_iniA < Pb2_bulk) begin
                                phi_sL_bulk = psb_iniA ;
                            end else begin
                                `Fn_SUtemp(phi_sL_bulk, psb_iniA, psb_iniB, `c_ps0ini_2)
                            end
                        end
                    end // InitialValueForPhiSLBulk
                    // initial value for phi_sL_bulk(end) //

                    // newton loop for phi_sL_bulk(start) //
                    begin : NewtonLoopForPhiSLBulk
                        real T0, T1, T2, T3, T4, T5, T6, T7;
                        T0 = `cnst_2esi_q * phi_sL_SOI / `N_sub_SOI;
                        if (T0 > 0) begin
                            WdSOI = sqrt(`cnst_2esi_q * phi_sL_SOI / `N_sub_SOI) ;
                        end else begin
                            WdSOI = 0;
                        end
                        if (phi_sL_SOI < FD_end && 0) begin
                            flg_depmode_d = 1 ;      // PD //
                            for (lp_sl = 0 ; lp_sl < lp_sl_max ; lp_sl= lp_sl + 1) begin
                                T1 = cnst0bulk ;
                                T2 = beta * phi_sL_bulk ;
                                T3 = exp(-T2) ;
                                if (phi_sL_bulk > `C_PHI_1_MINIMUM) begin
                                    T0 = exp(beta * phi_sL_bulk) ;
                                    T4 = -T1 * sqrt(T3 + T2 - 1 + cnst1bulk * (T0 - 1)) ;
                                    T5 = c0bulk / T4 * (-T3 + 1 + cnst1bulk * (T0)) ;
                                end else if (phi_sL_bulk < -`C_PHI_1_MINIMUM) begin
                                    T4 = T1 * sqrt(T3 + T2 - 1) ;
                                    T5 = c0bulk / T4 * (-T3 + 1) ;
                                end else begin
                                    T4 = -sqrt(c0bulk / beta) * beta * phi_sL_bulk ;
                                    T5 = -sqrt(c0bulk * beta) ;
                                end
                                `Fn_SZ_DX(T6, T4, Q_FD_dlt1, T7)
                                `Fn_SU_DX(T6, T6, (-Q_FD_SOI), Q_FD_dlt2, T8)
                                T7 = T7 * ( T5 * T8 ) ;
                                phi_b_dep = T6 * T6 / 2.0 / `C_ESI / `C_QE / `N_sub_SOI ;
                                phi_b_dep_dPsb = 2 * phi_b_dep * T7 / T6 ;

                                T6 = phi_sL_bulk - ((-phi_sL_bulk + T4 / C_box - Vbsbiz + phi_b_dep)
                                / (-1 + T5 / C_box + phi_b_dep_dPsb)) ;
                                if (abs(T6 - phi_sL_bulk) < `ps_conv) begin
                                    lp_sl = lp_sl_max ;
                                end
                                phi_sL_bulk = T6 ;
                                Q_sL_bulk = T4 ;
                            end
                            phi_sL_bulk = Vbsbiz + phi_sL_bulk ;
                            phi_bL_SOI = phi_sL_bulk - Q_sL_bulk / C_box ;
                        end else begin
                            flg_depmode_d = 2 ;      // FD //
                            for (lp_sl = 0 ; lp_sl < lp_sl_max ; lp_sl= lp_sl + 1) begin
                                T1 = cnst0bulk ;
                                T2 = beta * phi_sL_bulk ;
                                T3 = exp(-T2) ;
                                if (phi_sL_bulk > `C_PHI_1_MINIMUM) begin
                                    T0 = exp(beta * phi_sL_bulk) ;
                                    T4 = -T1 * sqrt(T3 + T2 - 1 + cnst1bulk * (T0 - 1)) ;
                                    T5 = c0bulk / T4 * (-T3 + 1 + cnst1bulk * (T0)) ;
                                end else if (phi_sL_bulk < -`C_PHI_1_MINIMUM) begin
                                    T4 = T1 * sqrt(T3 + T2 - 1) ;
                                    T5 = c0bulk / T4 * (-T3 + 1) ;
                                end else begin
                                    T4 = -sqrt(c0bulk / beta) * beta * phi_sL_bulk ;
                                    T5 = -sqrt(c0bulk * beta) ;
                                end
                                `Fn_SZ_DX(T6, T4, Q_FD_dlt1, T7)
                                `Fn_SU_DX(T6, T6, (-Q_FD_SOI), Q_FD_dlt2, T8)
                                T7 = T7 * ( T5 * T8 ) ;
                                phi_b_dep = T6 * T6 / 2.0 / `C_ESI / `C_QE / `N_sub_SOI ;
                                phi_b_dep_dPsb = 2 * phi_b_dep * T7 / T6 ;

                                T6 = (phi_sL_bulk -
                                (phi_sL_SOI - phi_sL_bulk + T4 / C_box + (T4 + Q_FD_SOI / 2) * t_SOI / `C_ESI - Vbsbiz +
                                phi_b_dep) / (-1 + T5 / C_box + T5 * t_SOI / `C_ESI + phi_b_dep_dPsb)) ;
                                if (abs(T6 - phi_sL_bulk) < `ps_conv) begin
                                    lp_sl = lp_sl_max ;
                                end
                                phi_sL_bulk = T6 ;
                                Q_sL_bulk = T4 ;
                            end
                            phi_sL_bulk = Vbsbiz + phi_sL_bulk ;
                            phi_bL_SOI = phi_sL_bulk - Q_sL_bulk / C_box ;
                        end // else: !if(phi_sL_SOI < FD_end)
                    end // NewtonLoopForPhiSLBulk
                    if (phi_bL_SOI < 0) begin
                        phi_bL_SOI = 0 ;
                    end

                end // End of Initial guess For Psls
                //-----------------------------------------------------------*

                // newton loop for phi_sL_bulk(end) //
            end // end of start_of_loopl;

            begin : Psl_3_var_NewtonLoop
                real eL, T1, T2, T3, T4, T5 ;
                real Q_nL_dPss, Q_sL_bulk_dPsb ;
                real dPss, dPbs, dPsb, PF1,PF11,PF12,PF13, PF2,PF21,PF22,PF23, PF3,PF32,PF33;
                real PDJ, PDJI, PJI11,PJI12,PJI13,PJI21,PJI22,PJI23,PJI31,PJI32,PJI33;
                real TMF0 , T4_dPss ;

                //-----------------------------------------------------------*
                //*  Solve Poisson's equation for Psl. (start)
                //*-----------------//

                if (phi_s0_SOI < 0.0 ) begin
                    phi_sL_SOI = phi_s0_SOI ;
                end
                if (phi_bL_SOI < 0.01 ) begin
                    phi_bL_SOI = phi_sL_SOI + C_soi_inv * ( 0.5 * Q_FD_SOI + Q_s0_bulk ) ;
                end

                //
                // start_of_sL_loop:
                // save the initial guesses for nonconverged cases //
                phi_sL_SOI_ini = phi_sL_SOI ;
                phi_bL_SOI_ini = phi_bL_SOI ;
                phi_sL_bulk_ini = phi_sL_bulk ;
                flg_conv = 0 ; flg_brk8 = 0 ;

                for (lp_sl = 1 ; lp_sl <= lp_sl_max ;  lp_sl = lp_sl + 1 ) begin

                    T1 = phi_sL_bulk - (Vbsbiz) ;
                    eL = beta * (T1) ;
                    T0 = exp(-eL) ;
                    if (T1 < -`C_PHI_1_MINIMUM) begin
                        Q_sL_bulk = cnst0bulk * sqrt(T0 + eL - 1.0) ;
                        Q_sL_bulk_dPsb = c0bulk * (-T0 + 1.0) / Q_sL_bulk ;
                    end else if (T1 > `C_PHI_1_MINIMUM) begin
                        T2 = exp(eL) ;
                        Q_sL_bulk = -cnst0bulk * sqrt(T0 + eL - 1.0 + cnst1bulk * (T2 + eL - 1.0)) ;
                        Q_sL_bulk_dPsb = c0bulk * (-T0 + 1.0 + cnst1bulk * (T2 + 1)) / Q_sL_bulk ;
                    end else begin
                        Q_sL_bulk = -cnst0bulk* eL ;
                        Q_sL_bulk_dPsb = -cnst0bulk *  beta ;  // minor bug-fix //
                    end

                    // Eval_calc_Q_nL (begin)
                    Q_sL_dep = Q_s0_dep_ini ;
                    T5 = exp(beta * (phi_sL_SOI - Vds)) ;
                    T3 = 1.0 ; // = exp(beta * (phi_bL_SOI - Vds)) ;
                    T4 = sqrt(Q_sL_dep * Q_sL_dep /(cnst0SOI * cnst0SOI) + 2 * cnst1SOI * (T5 + eL - T3)) ;
                    T4_dPss = (   2 * beta * cnst1SOI * (T5 +1) )/( 2 * T4 ) ;
                    Q_nL = -cnst0SOI * T4 - Q_sL_dep ;
                    Q_nL_dPss = - cnst0SOI * T4_dPss ;
                    // Eval_calc_Q_nL (end)

                    // Eval_calc_Q_bL_dep (begin)
                    T1 = (phi_bL_SOI - phi_sL_SOI) /QDEPB_DLT ;
                    eL = beta * (T1) ;
                    `Fn_DExp(T0, -eL, T6)
                    T2 = sqrt(T0 + eL - 1.0) ;
                    if (T1 < -`C_PHI_1_MINIMUM) begin
                        Q_bL_dep = cnst0SOI * T2 ;
                        Q_bL_dep_dPbs = cnst0SOI * beta * (-T6 + 1.0) / (2 * T2) /QDEPB_DLT ;
                        Q_bL_dep_dPss = - Q_bL_dep_dPbs ;
                    end else if (T1 > `C_PHI_1_MINIMUM) begin
                        Q_bL_dep = -cnst0SOI * T2 ;
                        Q_bL_dep_dPbs = -cnst0SOI * beta * (-T6 + 1.0) / (2 * T2) /QDEPB_DLT ;
                        Q_bL_dep_dPss = - Q_bL_dep_dPbs ;
                    end else begin
                        Q_bL_dep = -cnst0SOI * eL / `C_SQRT_2 ;
                        Q_bL_dep_dPbs = -cnst0SOI *  beta / `C_SQRT_2 ;
                        Q_bL_dep_dPss = - Q_bL_dep_dPbs ;
                    end
                    `Fn_SU_CP_DX(Q_bL_dep,  Q_bL_dep , 0, -Q_WdSOI_max*`QDEP_DLT2 , `QDEP_PW , T0)
                    Q_bL_dep_dPbs = Q_bL_dep_dPbs * T0 ;
                    Q_bL_dep_dPss = Q_bL_dep_dPss * T0 ;
                    `Fn_SL_CP_DX(Q_bL_dep, Q_bL_dep , (Q_FD_SOI-Q_sL_dep), -(Q_FD_SOI-Q_sL_dep)*`QDEP_DLT2 , `QDEP_PW , T0)
                    Q_bL_dep_dPss = Q_bL_dep_dPss * T0 ;
                    Q_bL_dep_dPbs = Q_bL_dep_dPbs * T0 ;
                    // Eval_calc_Q_bL_dep (end)

                    Q_depL = Q_sL_dep + Q_bL_dep ;

                    if ( flg_conv == 1 && lp_sl > 3) begin
                        flg_brk8 = lp_sl; lp_sl = lp_sl_max ;
                    end else begin

                        PF1 = phi_sL_SOI - Vgpz - C_fox_inv * (Q_sL_bulk + Q_sL_dep + Q_nL + Q_bL_dep + Qhs) ;       // @@@ //
                        PF11 = 1.0 - C_fox_inv * (Q_nL_dPss + Q_bL_dep_dPss) ;
                        PF12 =     - C_fox_inv * (            Q_bL_dep_dPbs) ;
                        PF13 =     - C_fox_inv * (Q_sL_bulk_dPsb ) ;

                        T1 = phi_sL_SOI + C_soi_inv * (0.5 * Q_FD_SOI + Q_sL_bulk ) ;
                        T3 = C_soi_inv * Q_sL_bulk_dPsb ;
                        PF2 = phi_bL_SOI - T1 ;
                        PF21 = -1.0 ;
                        PF22 =  1.0 ;
                        PF23 = -T3 ;

                        PF3 = phi_sL_bulk - phi_bL_SOI - C_box_inv * Q_sL_bulk ;
                        PF32 = -1.0 ;
                        PF33 = 1.0 - C_box_inv * Q_sL_bulk_dPsb ;

                        // assuming PF31=0 //
                        PDJ = PF11 * PF22 * PF33 - PF11 * PF23 * PF32 - PF12 * PF21 * PF33 + PF13 * PF21 * PF32 ;
                        PDJI = 1.0 / (PDJ + `Small) ;
                        PJI11 = PF22 * PF33 - PF23 * PF32 ;
                        PJI12 = PF13 * PF32 - PF12 * PF33 ;
                        PJI13 = PF12 * PF23 - PF13 * PF22 ;
                        PJI21 = -PF21 * PF33 ;
                        PJI22 = PF11 * PF33 ;
                        PJI23 = PF13 * PF21 - PF11 * PF23 ;
                        PJI31 = PF21 * PF32 ;
                        PJI32 = -PF11 * PF32 ;
                        PJI33 = PF11 * PF22 - PF12 * PF21 ;

                        dPss = -PDJI * (PJI11 * PF1 + PJI12 * PF2 + PJI13 * PF3) ;
                        dPbs = -PDJI * (PJI21 * PF1 + PJI22 * PF2 + PJI23 * PF3) ;
                        dPsb = -PDJI * (PJI31 * PF1 + PJI32 * PF2 + PJI33 * PF3) ;

                        /* New PS convergence method */
                        T1 = abs(dPss) ;
                        if (T1 < abs(dPbs)) T1 = abs(dPbs) ;
                        if (T1 < abs(dPsb)) T1 = abs(dPsb) ;
                        scale_fac=1.0 ;
                        if (lp_sl > 80) begin
                            scale_fac = 125.0 ;
                        end else if (lp_sl > 40) begin
                            scale_fac = 125.0 ;
                        end else if (lp_sl > 20) begin
                            scale_fac = 25.0 ;
                        end else if (lp_sl > 10) begin
                            scale_fac = 5.0 ;
                        end

                        if (T1 > `dP_max/scale_fac) begin
                            dPss = dPss * ( `dP_max/scale_fac / T1 ) ;
                            dPbs = dPbs * ( `dP_max/scale_fac / T1 ) ;
                            dPsb = dPsb * ( `dP_max/scale_fac / T1 ) ;
                        end
                        phi_sL_SOI = phi_sL_SOI + dPss ;
                        phi_bL_SOI = phi_bL_SOI + dPbs ;
                        phi_sL_bulk = phi_sL_bulk + dPsb ;

                        PSCONV_3D = `ps_conv * scale_fac * `PSCONVFAC ;
                        if (T1 < PSCONV_3D) begin
                            flg_conv = 1 ;
                        end

                    end  // End of flg_brk8

                end // end of Psl 3Newton loop with lp_sl   //

                lp_sl = (flg_brk8 > 0) ? flg_brk8 : lp_sl ;

                //  Solve Poisson's equation for Psl. (end) //
                if (flg_conv == 0) begin    // reset to the initial guesses in nonconvergent cases //
                    phi_sL_SOI = phi_sL_SOI_ini ;
                    phi_bL_SOI = phi_bL_SOI_ini ;
                    phi_sL_bulk = phi_sL_bulk_ini ;
                end

                //-------------------------------------------*
                //Procedure for diverged case.
                //----------------//
                Psl = phi_sL_SOI ;

                flg_conv_L = flg_conv ; // for Psl only.

            end // Psl_3_var_NewtonLoop

            // Vdseff //
            Vds = Vdsorg ;

`ifdef DISABLE_COPPRV
`else
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
                    // Surface potentials //
                    pss0_prv = phi_s0_SOI ;
                    pbs0_prv = phi_b0_SOI ;
                    psb0_prv = phi_s0_bulk ;
                    pssl_prv = phi_sL_SOI ;
                    pbsl_prv = phi_bL_SOI ;
                    psbl_prv = phi_sL_bulk ;
                end // (COPPRV)
`endif // COPPRV

            if ( phi_s0_SOI < 0.0 ) begin
                flg_noqi = 1 ;
            end

            // start_of_calIdd:
            //---------------------------------------------------*
            //----------------//
            Ps0s = phi_s0_SOI  ;
            PsLs = phi_sL_SOI  ;
            Pds  = PsLs - Ps0s ;
            Ps0b = phi_s0_bulk ;
            C_S_inv = WdSOI / `C_ESI ;    // C_S_inv=1/C_SOI and except infinity of C_SOI. //

            begin : newIddModel

                //---------------------------------------------------*
                //*  Idd(Front)
                //*-----------------//
                //-------------- Idd by front carrier --------------*
                // the 1st term of Iddf //
                Idd  = (Q_nL - Q_n0) - beta * (Q_nL + Q_n0) * (PsLs - Ps0s) * 0.5 ;
                if (Idd < 0.0 || Vds == 0.0) Idd = 0.0 ;
                //---------- End of Idd by front carrier -----------*

            end // newIddModel

            //---------------------------------------------------*
            //* Qbu : -Qb in unit area.
            //*-----------------//
            Qbu = -0.5 * (Q_depL + Q_dep0) ;

            //-----------------------------------------------------------*
            //* Alpha(=eta) : parameter to evaluate charges.
            //*-----------------//
            RRR_P0 = phi_sL_SOI - phi_s0_SOI ;
            RRR_P0 = RRR_P0 + `ps_conv ;
            RRR_CSOI_Cbox = C_box / (C_box * C_S_inv + 1.0) ;
            RRR_B = ((Q_sL_bulk) * (Q_sL_bulk) - (Q_s0_bulk) * (Q_s0_bulk)) / (RRR_CSOI_Cbox) ;
            `Fn_SL_CP(T1, -RRR_B, 0, Q_FD_SOI * 1e-5 , `QDEP_PW )
            RRR_B = -T1 ;

            if (beta *(Ps0b) - 1.0 > 0.0) begin
                T1 = sqrt(beta * (Ps0b) - 1.0) ;
            end
            RRR_CC = -(Q_nL - Q_n0) ;
            `Fn_SL_CP(RRR_CC, RRR_CC, 0, Q_FD_SOI * 1e-5 , `QDEP_PW )

            RRR_alpha_SOI = 1.0 + 2.0 * (-RRR_CC) / (beta * C_fox * RRR_P0 * RRR_P0) ;
            T1 = RRR_P0 * RRR_P0 * RRR_P0 * RRR_P0 ;
            RRR_DD = RRR_alpha_SOI * RRR_P0 ;
            RRR_eta = 1.0 - RRR_DD / VgVt ;
            `Fn_SL_CP(RRR_eta, RRR_eta, 0, 1e-5 , `QDEP_PW )
            Alpha = RRR_eta ;

            // start_of_charges:

            //-----------------------------------------------------------*
            //* Qiu : -Qi in unit area.
            //*-----------------//
            Qinm = 1.0 + Alpha * (1.0 + Alpha) ;
            Qidn = `Fn_Max(1.0 + Alpha, `epsm10) ;

            Qiu  = - 0.5 * (Q_n0 + Q_nL) ;

        end // end if(end_of_part_1==0)

        if (flg_info >= 1) begin
            if (flg_depmode == 1 && flg_depmode_d == 2) begin
                $write("Note: source is PD, but drain is FD.\n") ;
            end
            if (flg_depmode == 2 && flg_depmode_d == 1) begin
                $write("Warning: source is FD, but drain is PD!\n") ;
            end
        end

    end //  HSOI_calc_Phis_FB

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
