/***********************************************************************

 HiSIM (Hiroshima University STARC IGFET Model)
 Copyright (C) 2000-2016 Hiroshima University and STARC
 Copyright (C) 2016-2023 Hiroshima University
 HiSIM_HV (High-Voltage Model)
 Copyright (C) 2007-2016 Hiroshima University and STARC
 Copyright (C) 2016-2023 Hiroshima University

 MODEL NAME : HiSIM_HV
 ( VERSION : 2  SUBVERSION : 5  REVISION : 1 )
 Model Parameter 'VERSION' : 2.51
 FILE : HSMHV_eval_qover.inc

 Date : 2023.02.09

 released by Hiroshima University

***********************************************************************/
//
////////////////////////////////////////////////////////////////
//
//
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
//The HiSIM_HV standard has been supported by the members of
//Silicon Integration Initiative's Compact Model Coalition. A
//link to the most recent version of this standard can be found
//at:
//
//http://www.si2.org/cmc
//
////////////////////////////////////////////////////////////////
//


// begin : HSMHVevalQover //
real WdLD , Q_dep_LD , q_NsubLD ;
real Vx; // auxiliary
integer flg_ovzone_intheloop;
real Pb2over, Vbs_max_over, Vbs_bnd_over;
`ifdef _COFDISPLAY_
    real QsuLD_ini , QbuLD_ini ;
    integer probe_lp_s0;
`endif
integer flg_FD_mode;
real Ps0LD_ini; //for fully iterative Ps0LD (COQOVSM=4)
real fbsq, fbsq_dPss; //for fully iterative Ps0LD (COQOVSM=4)
Vbs_bnd_over = 0.4; //necessary initial value
flg_ovzone_intheloop = 0;
`ifdef _COFDISPLAY_
    probe_lp_s0 = 0; //initialized for debug printing
`endif
flg_FD_mode = 0; //necessary initial value
fb = 0.0 ; fs01 = 0.0 ; fs02 = 0.0 ; //initialized for debug printing
Fs0 =0.0; dPs0=0.0; //initialized for debug printing
Fs0_dPs0 = 0.0; fs02_dPs0 = 0.0; fb_dPss = 0.0; fs01_dPs0 = 0.0; //initialized for debug printing
Chi_1 = 0.0 ; Chi_A = 0.0 ; Chi_B = 0.0 ; //initialized for debug printing
flg_conv = -1 ; //initialized for debug printing
Ps0LD_ini = 0; //for fully iterative Ps0LD (COQOVSM=4)
fbsq = 0; //for fully iterative Ps0LD (COQOVSM=4)

//---------------------------------------------------*
//* Determine clamping limits for too large bulk bias for parasitic PMOS capacitor (-Vxbgmt).
//*-----------------//
Pb2over =  2.0e0 * beta_inv * ln (Nover_func / Nin) ;
`Fn_SU( Vbs_max_over , Pb2over , 0.8 , 0.1 , T0 )
if ( Vbs_bnd_over > Vbs_max_over * 0.5 ) begin
    Vbs_bnd_over = 0.5 * Vbs_max_over ;
end

//updates when VBFWDMX and VBFWDBND are given:
if ($param_given(VBFWDMX)) begin
    Vbs_max_over = VBFWDMX; //user-defined value
end
if ($param_given(VBFWDBND)) begin
    Vbs_bnd_over = VBFWDBND; //user-defined value
end else begin
    if ($param_given(VBFWDMX)) begin
        Vbs_bnd_over = 0.5 * Vbs_max_over; //based on the user-defined value
    end
end
if ( Vbs_bnd_over > Vbs_max_over * 0.5 ) begin
    Vbs_bnd_over = 0.5 * Vbs_max_over ;
end

//---------------------------------------------------*
//* Clamp -Vxbgmt.
//*-----------------//
if ( COQOVCL == 1) begin
    T0 = - Vxbgmt;
    if ( T0 > Vbs_bnd_over ) begin
        T1 =    T0   - Vbs_bnd_over;
        T2 =    Vbs_max_over    - Vbs_bnd_over;
        `Fn_SUPoly4m( TY, T1, T2, T11, T0 )
        T10 = Vbs_bnd_over + TY ;
    end  else begin
        T10 = T0 ;
    end
    Vxbgmtcl = - T10  ;
end // if ( COQOVCL == 1)
else begin
    Vxbgmtcl = Vxbgmt;  // no clamp
end // else: !if( COQOVCL == 1)


fac1 = cnst0over_func / Cox0_func ;
fac1p2 = fac1 * fac1 ;
VgpLD = - Vgbgmt + UC_VFBOVER;
Vgb_fb_LD =  - Vxbgmtcl + `epsm10 ;
Q_dep_LD  =  0.0 ;
q_NsubLD = `C_QE * Nover_func ;

T0 = Nin / Nover_func;
cnst1over = T0 * T0;                 //moved from the case ( COQOVSM > 0 ) below
//exp_bVbs = exp( beta * -Vxbgmtcl ) ; //moved from the case ( COQOVSM > 0 ) below
`Fn_DExp( exp_bVbs , ( beta * -Vxbgmtcl ) , T0)

if ( flg_never_reach_vfbover ) begin
    // ceiling (VgpLD + Vxbgmtcl) less than 0 and feed back to Vxbgmtcl:
    //--> never enters the depletion region.
    `Fn_SL(T1, (-VgpLD*`VXBGMTDLT)  , 0.5, 1 , T0 )
    `Fn_SU_CP(T1, (VgpLD + Vxbgmtcl), 0.0, T1, 1, T0)
    Vxbgmtcl = T1 - VgpLD;
    Vgb_fb_LD =  - Vxbgmtcl + `epsm10 ;
end

//-----------------------------------*
//* QsuLD: total charge = Accumulation | Depletion+inversion
//*-----------------//
if ( VgpLD  < Vgb_fb_LD ) begin
    //---------------------------*
    //* Accumulation
    //*-----------------//
    flg_ovzone = -1 ;
    Ps0_min = 2.0 * beta_inv * ln (-Vgs_min/fac1) ;
    TX = beta * ( VgpLD + Vxbgmtcl ) ;

    T1 = 1.0 / ( beta * cnst0over_func ) ;
    TY = T1 * Cox0_func ;
    Ac41 = 2.0 + 3.0 * `C_SQRT_2 * TY ;
    Ac4 = 8.0 * Ac41 * Ac41 * Ac41 ;
    Ac31 = 7.0 * `C_SQRT_2 - 9.0 * TY * ( TX - 2.0 ) ;
    Ac3 = Ac31 * Ac31 ;
    if ( Ac4 < Ac3*1.0e-8 ) begin
        flg_ovzone = -2 ;
        Ac1 = 0.5 * Ac4 / Ac31 ;
    end else begin
        Ac2 = sqrt( Ac4 + Ac3 ) ;
        Ac1 = -Ac31 + Ac2 ;
    end
    Acd = pow( Ac1 , `C_1o3 ) ;
    Acn = -4.0 * `C_SQRT_2 - 12.0 * TY + 2.0 * Acd + `C_SQRT_2 * Acd * Acd ;
    Chi = Acn / Acd ;

    T1 = Chi * beta_inv ;
    T2 = T1 / Ps0_min ;
    T3 = sqrt( 1.0 + ( T2 * T2 ) ) ;
    Ps0LD = T1 / T3 - Vxbgmtcl ;
    T2 = ( VgpLD - Ps0LD ) ;
    QsuLD = Cox0_func * T2 ;

    QbuLD = QsuLD ;

`ifdef _COFDISPLAY_
        QsuLD_ini = QsuLD ;
        QbuLD_ini = QbuLD ;
`endif
    Ps0LD_ini = Ps0LD ; //for fully iterative Ps0LD (COQOVSM=4)

end else begin

    //---------------------------*
    //* Depletion and inversion
    //*-----------------//

    // initial value for a few fixpoint iterations
    //to get Ps0_iniA from simplified Poisson equation: //
    if ( beta * ( VgpLD + Vxbgmtcl ) < 1.0e0 + ( `epsm10 - 1.0e0 ) * fac1p2 * beta2 / 4.0e0 ) begin //equivalent to (TX < `epsm10)
        Ps0_iniA = VgpLD + fac1p2 * beta / 2.0e0  ;
    end else begin
        TX = 1.0e0 + 4.0e0 * ( beta * ( VgpLD + Vxbgmtcl ) - 1.0e0 ) / ( fac1p2 * beta2 ) ;
        Ps0_iniA = VgpLD + fac1p2 * beta / 2.0e0 * ( 1.0e0 - sqrt( TX ) ) ;
    end
    Chi = beta * ( Ps0_iniA + Vxbgmtcl ) ;

    if ( Chi >= `znbd3 ) begin
        flg_ovzone = 2 ;
        // 1 .. 2 relaxation steps should be sufficient //
        for ( lp_ld = 1; lp_ld <= 2; lp_ld = lp_ld + 1 ) begin
            TY = exp(-Chi);
            TX = 1.0e0 + 4.0e0 * ( beta * ( VgpLD + Vxbgmtcl ) - 1.0e0 + TY ) / ( fac1p2 * beta2 ) ;
            Ps0_iniA = VgpLD + fac1p2 * beta / 2.0e0 * ( 1.0e0 - sqrt( TX ) ) ;
            Chi = beta * ( Ps0_iniA + Vxbgmtcl ) ;
        end // End of iteration //
    end else begin
        flg_ovzone = 1 ;

        //-----------------------------------*
        //* zone-D1
        //* - Ps0_iniA is the analytical solution of QovLD=Qb0 with
        //*   Qb0 being approximated by 3-degree polynomial.
        //*
        //*   new: Inclusion of exp(-Chi) term at right border
        //*-----------------//
        Ta =  1.0/(9.0*sqrt(2.0)) - (5.0+7.0*exp(-3.0)) / (54.0*sqrt(2.0+exp(-3.0)));
        Tb = (1.0+exp(-3.0)) / (2.0*sqrt(2.0+exp(-3.0))) - sqrt(2.0) / 3.0;
        Tc =  1.0/sqrt(2.0) + 1.0/(beta*fac1);
        Td = - (VgpLD + Vxbgmtcl) / fac1;
        Tq = Tb*Tb*Tb / (27.0*Ta*Ta*Ta) - Tb*Tc/(6.0*Ta*Ta) + Td/(2.0*Ta);
        Tp = (3.0*Ta*Tc-Tb*Tb)/(9.0*Ta*Ta);
        T5 = sqrt(Tq*Tq + Tp*Tp*Tp);
        Tu = pow(-Tq + T5,`C_1o3);
        Tv = -pow(Tq + T5,`C_1o3);
        Chi = Tu + Tv - Tb/(3.0*Ta);
        Ps0_iniA = Chi * beta_inv - Vxbgmtcl ;
    end

    if ( COQOVSM > 0 ) begin
        //-----------------------------------*
        //* - Ps0_iniB : upper bound.
        //*-----------------//
        VgpLD_shift = VgpLD + Vxbgmtcl + 0.1;
        //

        cfs1 = cnst1over * exp_bVbs ;
        gammaChi = cnst1over * exp_bVbs;
        T0  = beta2 * fac1p2;
        psi = beta*VgpLD_shift;
        Chi_1 = ln (gammaChi*T0 + psi*psi) - ln (cnst1over*T0) + beta*Vxbgmtcl;
        if ( COQOVSM == 2 ) begin
            `Fn_SU( Chi_1, Chi_1, psi, 1.0, T1 )
        end else begin
            Chi_1 = `Fn_Min( Chi_1, psi ); // clipping to keep the original curve (Initial guess doesn't need to be continuous.)
        end
        Chi_1 = `Fn_Max( Chi_1, 0.0 ); // protection for the unclamped beta*Vxbgmtcl when COQOVCL=0

        // 1 fixpoint step for getting more accurate Chi_B //
        psi = psi - Chi_1 ;
        psi = psi + beta*0.1 ;
        T1 = ln (gammaChi*T0 + psi*psi) - ln (cnst1over*T0) ;
        Chi_B = T1 + beta*Vxbgmtcl ;
        Chi_B = `Fn_Max( Chi_B, 0.0 ); // protection for the unclamped beta*Vxbgmtcl when COQOVCL=0

        // construction of Ps0LD by taking Ps0_iniB as an upper limit of Ps0_iniA
        //*
        //* Limiting is done for Chi rather than for Ps0LD, to avoid shifting
        //* for Fn_SU //
        Chi_A = Chi;
        if ( COQOVSM == 2 ) begin
            `Fn_SU_CP( Chi, Chi_A, Chi_B, 0.2*Chi_B, 2, T1 )
        end else begin
            Chi = `Fn_Min( Chi_A, Chi_B ); // clipping to keep the original curve (Initial guess doesn't need to be continuous.)
        end

    end

    // update_of_initial_guess_for_FD_mode
    if ( COQOVSM == 1 ) begin
        //----------------------------//
        // temporary_Chib_for_FD_mode //
        //----------------------------//

        Ps0LD = Chi* beta_inv - Vxbgmtcl ; // updating Ps0LD //

        // calc. effective DDRIFT with p-n junction
        if ( Wdep_func > 0.0 ) begin
            T2 = `DDRIFT - Wdep_func ;
        end else begin
            `Fn_SZ( T2 , (Vdsi + VBI) , 0.1 , T9 )
            Wjunc0 = sqrt ( kjunc * T2 ) * QOVJUNC ;
            T2 = `DDRIFT - Wjunc0 ;
        end
        `Fn_SZ( T2 , T2 , `DDRIFT * 0.01 , T9 )
        ddriftldc = T2 ;

        dphi_sb = q_NsubLD * ddriftldc * ddriftldc / 2.0 / `C_ESI ;
        T0 = sqrt(2.0 * beta * dphi_sb) ;
        T1 = (lexp(T0) + lexp(-T0)) / 2 ;
        c_sb = ln(T1) / dphi_sb ;

        Ps0LD_Vxb = Ps0LD + Vxbgmtcl ;
        TY = c_sb * ( Ps0LD_Vxb - dphi_sb ) ;
        if ( TY  < `large_arg ) begin
            T1 = exp(TY) ;
            T0 = exp(- c_sb * dphi_sb) ;
            T2 = T1 - T0 ;
            phi_b = ln(1 + T2) / c_sb ;
        end else begin
            phi_b = Ps0LD_Vxb - dphi_sb ;
        end
        Chib = beta * phi_b ;

        if ( Chib > Chi/100 && Chib > 0 ) begin //FD-mode correction for Vgs dependence:
            flg_FD_mode = flg_FD_mode + 1; // FD mode
            Chi = Chi_1;
        end
    end // if ( COQOVSM == 1 )


    // updating Ps0LD //
    Ps0LD = Chi* beta_inv - Vxbgmtcl ;


    if (abs(Chi)> 1e-6) begin   // 20161012
        T1 = Chi - 1.0 + exp(-Chi);
        T2 = sqrt(T1);
    end else begin
        flg_ovzone = flg_ovzone + 4; //very close to flatband
        // T2 = `C_1oSQRT2*Chi;
        // further alternative:
        //  // Chi - 1.0 + exp(-Chi) = (1/2)*Chi*Chi*(1- (1/3)*Chi)
        //  u = 1.0 - Chi * `C_1to3;
        //  T2 = `C_1oSQRT2* Chi* sqrt(u);
        T2 =`C_1oSQRT2* Chi* sqrt( 1.0 - Chi * `C_1o3); // 20200727
    end
    QbuLD = cnst0over_func * T2 ;

    //-----------------------------------------------------------*
    //* QsuLD : Qovs or Qovd in unit area.
    //* note: QsuLD = Qdep+Qinv.
    //*-----------------//
    QsuLD = Cox0_func * ( VgpLD - Ps0LD ) ;


    // 2nd_update_of_initial_guess_for_FD_mode
    begin : FD_mode
        real WdLD0, Ps0LD_bef1;

        WdLD0 = QbuLD / q_NsubLD ;
        if ( COQOVSM == 2 ) begin
            `Fn_SU_CP( T1 , WdLD0 , ddriftldc , ddriftldc*0.1 , 2 , T0 )
            if ( T0 < 1.0) begin
                flg_FD_mode = flg_FD_mode + 2; // FD mode
            end
        end else begin
            T1 = `Fn_Min( WdLD0, ddriftldc );
            if ( WdLD0 >= ddriftldc ) begin
                flg_FD_mode = flg_FD_mode + 2; // FD mode
            end
        end

        if ( flg_FD_mode >= 2 ) begin // FD-mode correction for large Vds:
            Ps0LD_bef1 = Ps0LD;
            QbuLD = T1 * q_NsubLD ;
            Ps0LD = VgpLD - QbuLD / Cox0_func ; // QsuLD = QbuLD w/o Qinv
            if ( COQOVSM == 2 ) begin
                `Fn_SU_CP( Ps0LD , Ps0LD, Ps0LD_bef1 , 0.1 , 2 , T0 )
            end else begin
                Ps0LD = `Fn_Min( Ps0LD, Ps0LD_bef1 );
            end
        end

    end // block: FD_mode


`ifdef _COFDISPLAY_
        QsuLD_ini = QsuLD ;
        QbuLD_ini = QbuLD ;
`endif
    Ps0LD_ini = Ps0LD ; //for fully iterative Ps0LD (COQOVSM=4)



    if ( COQOVSM == 1 ) begin // Dynamic Depletion Model //

        //---------------------------------------------------*
        //* Calculation of Ps0. (beginning of Newton loop)
        //* - Fs0 : Fs0 = 0 is the equation to be solved.
        //* - dPs0 : correction value.
        //*-----------------//
        flg_conv = 0 ;
        C_W_LD = sqrt(2.0 * (`C_ESI / q_NsubLD * beta_inv)) ;
        // calc. effective DDRIFT with p-n junction
        if ( Wdep_func > 0.0 ) begin
            T2 = `DDRIFT - Wdep_func ;
        end else begin
            `Fn_SZ( T2 , (Vdsi + VBI) , 0.1 , T9 )
            Wjunc0 = sqrt ( kjunc * T2 ) * QOVJUNC ;
            T2 = `DDRIFT - Wjunc0 ;
        end
        `Fn_SZ( T2 , T2 , `DDRIFT * 0.01 , T9 )
        ddriftldc = T2 ;

        dphi_sb = q_NsubLD * ddriftldc * ddriftldc / 2.0 / `C_ESI ;
        T0 = sqrt(2.0 * beta * dphi_sb) ;
        T1 = (lexp(T0) + lexp(-T0)) / 2 ;
        c_sb = ln(T1) / dphi_sb ;

        for ( lp_s0 = 1 ; lp_s0 <= lp_s0_max + 1 ; lp_s0 = lp_s0 + 1 ) begin
            if ( i_over == 3 ) begin
                OP_lp_ld = lp_s0 - 1 ;
            end
`ifdef _COFDISPLAY_
                probe_lp_s0 = lp_s0 - 1; // -1 is necessary to correct the counts
`endif
            flg_ovzone_intheloop = 0;

            Ps0LD_Vxb = Ps0LD + Vxbgmtcl ;
            Chi = beta * Ps0LD_Vxb ;


            TY = c_sb * ( Ps0LD_Vxb - dphi_sb ) ;
            if ( TY  < `large_arg ) begin
                T1 = exp(TY) ;
                T0 = exp(- c_sb * dphi_sb) ;
                T2 = T1 - T0 ;
                phi_b = ln(1 + T2) / c_sb ;
                phi_b_dPss = T1 / (1 + T2) ;
            end else begin
                flg_ovzone_intheloop = flg_ovzone_intheloop + 8 ; //possible case
                phi_b = Ps0LD_Vxb - dphi_sb ;
                phi_b_dPss = 1 ;
            end
            Chib = beta * phi_b ;

            if (Chi < 0) begin
                flg_ovzone_intheloop = flg_ovzone_intheloop + 64 ; //unexpected case
                T0 = - `C_1oSQRT2 ; //derived with 2nd-order Maclaurin series
                fb = Chi * T0 ;
                fb_dPss = beta * T0 ;
            end else if (Chi < 1E-6) begin
                flg_ovzone_intheloop = flg_ovzone_intheloop + 32 ; //rare case
                T0 = Chi * Chi / 2 * (1 - Chi / 3 * (1 - Chi / 4 * (1 - Chi / 5))) ;
                T1 = Chi * (1 - Chi / 2 * (1 - Chi / 3 * (1 - Chi / 4))) ;
                T2 = Chib * Chib / 2 * (1 - Chib / 3 * (1 - Chib / 4 * (1 - Chib / 5))) ;
                T3 = Chib * (1 - Chib / 2 * (1 - Chib / 3 * (1 - Chib / 4))) ;
                T4 = T0 - T2 ;
                if ( T4 > 0.0 ) begin
                    fb = sqrt(T4) ;
                    fb_dPss = beta * 0.5 * (T1 - phi_b_dPss * T3) / fb ;
                end else begin
                    flg_ovzone_intheloop = flg_ovzone_intheloop + 256 ; //FPE case
                    fb = 0.0 ;
                    fb_dPss = 0.0 ;
                end
            end else begin
                //-------------------------------------------*
                //* zone-D3.  (Ps0LD)
                //*-----------------//
                T0 = exp(-Chi) ;
                T1 = exp(-Chib) ;
                T4 = Chi - Chib + (T0 - T1) ;
                if ( T4 > 0.0 ) begin
                    fb = sqrt(T4) ;
                    fb_dPss = beta * 0.5 * (1 - T0 - phi_b_dPss * (1 - T1)) / fb ;
                end else begin
                    flg_ovzone_intheloop = flg_ovzone_intheloop + 512 ; //FPE case
                    fb = 0.0 ;
                    fb_dPss = 0.0 ;
                end
            end //

            if (Chi < 0) begin
                flg_ovzone_intheloop = flg_ovzone_intheloop + 128 ; //unexpected case
                fs01 = 0.0 ;
                fs01_dPs0 = 0.0 ;
                fs02 = -fb ;
                fs02_dPs0 = -fb_dPss ;
            end else begin
                if ( Chi < `large_arg ) begin // avoid exp_Chi to become extremely large
                    if ( Chi < 5.0e-5 ) begin
                        T0 = Chi * Chi / 2 * (1 + Chi / 3 * (1 + Chi / 4 * (1 + Chi / 5))) ;
                        T1 = Chi * (1 + Chi / 2 * (1 + Chi / 3 * (1 + Chi / 4))) ;
                        fs01 = cfs1 * T0 ;
                        fs01_dPs0 = cfs1 * T1 * beta ;
                    end else begin
                        exp_Chi = exp( Chi ) ;
                        T1 = exp_Chi - 1 ;
                        fs01 = cfs1 * ( T1 - Chi ) ;
                        fs01_dPs0 = cfs1 * beta * ( T1 ) ;
                    end
                end else begin
                    flg_ovzone_intheloop = flg_ovzone_intheloop + 16 ; //possible case
                    exp_bPs0 = exp( beta*Ps0LD ) ;
                    fs01 = cnst1over * ( exp_bPs0 - exp_bVbs * (Chi + 1) ) ;
                    fs01_dPs0 = cnst1over * beta * ( exp_bPs0 - exp_bVbs ) ;
                end
                if ( fs01 > 0.0 ) begin //original:
                    fs02 = sqrt(fb * fb + fs01) ;
                    fs02_dPs0 = 0.5 * (2 * fb_dPss * fb + fs01_dPs0) / fs02 ;
                end else begin //simplified to avoid division by zero:
                    flg_ovzone_intheloop = flg_ovzone_intheloop + 1024 ; //simplified case
                    fs02 = fb ;
                    fs02_dPs0 = fb_dPss ;
                end
            end


            // Revised Fs0 //
            Fs0 = - VgpLD + Ps0LD + fac1 * fs02 ;
            Fs0_dPs0 = 1.0 + fac1 * fs02_dPs0 ;
            //          lp_s0_LD = lp_s0 ;
            if ( flg_conv == 1 ) begin
                lp_s0 = lp_s0_max+1 ; // break
            end else begin
                dPs0 = - Fs0 / Fs0_dPs0 ;

                //-------------------------------------------*
                //* Update Ps0 .
                //* - clamped to Vbcs_cl if Ps0 < Vbcs_cl .
                //*-----------------//
                dPlim = 0.5*`dP_max*(1.0 + `Fn_Max(1.0e0,abs(Ps0LD))) ;
                if ( abs( dPs0 ) > dPlim ) dPs0 = dPlim * `Fn_Sgn( dPs0 ) ;
                Ps0LD = Ps0LD + dPs0 ;

                //-------------------------------------------*
                //* Check convergence.
                //* NOTE: This condition may be too rigid.
                //*-----------------//
                if ( abs( dPs0 ) <= `ps_conv && abs( Fs0 ) <= `gs_conv ) begin
                    flg_conv = 1 ;
                end

            end

        end // end of Ps0LD Newton loop //

        //-------------------------------------------*
        //* Procedure for diverged case.
        //*-----------------//
        if ( flg_conv == 0 ) begin
            $write( "*** warning(HiSIM_HV(%m)): Went Over Iteration Maximum(Ps0LD)\n" ) ;
            $write(" -Vxbgmtcl = %e   Vgbgmt = %e\n" , -Vxbgmtcl , Vgbgmt ) ;
        end

        //-----------------------------------*
        //* Xi0p12
        //*-----------------//
        WdLD = C_W_LD * fb ;
        Q_dep_LD = q_NsubLD * WdLD ;
        Xi0p12 = Q_dep_LD / cnst0over_func + `epsm10 ;

        //-----------------------------------------------------------*
        //* QbuLD and QiuLD
        //*-----------------//
        QbuLD = cnst0over_func * Xi0p12 ;
        T1 = 1.0 / ( fs02 + Xi0p12 ) ;
        QiuLD = cnst0over_func * fs01 * T1 ;

        //-----------------------------------------------------------*
        //* Total overlap charge
        //*-----------------//
        QsuLD = QbuLD + QiuLD;

    end // COQOVSM=1 //
end // end of Vgbgmt region blocks //












if ( COQOVSM == 4 ) begin : FULLY_ITERATIVE_PS0LD

    exp_bVbs = exp( beta * -Vxbgmtcl ) ;
    T0 = Nin / Nover_func;
    cnst1over = T0 * T0;
    cfs1 = cnst1over * exp_bVbs ;


    Ps0LD = Ps0LD_ini ;


    //---------------------------------------------------*
    //* Calculation of Ps0. (beginning of Newton loop)
    //* - Fs0 : Fs0 = 0 is the equation to be solved.
    //* - dPs0 : correction value.
    //*-----------------//
    flg_conv = 0 ;
    C_W_LD = sqrt(2.0 * (`C_ESI / q_NsubLD * beta_inv)) ;
    // calc. effective DDRIFT with p-n junction
    if ( Wdep_func > 0.0 ) begin
        T2 = `DDRIFT - Wdep_func ;
    end else begin
        `Fn_SZ( T2 , (Vdsi + VBI) , 0.1 , T9 )
        Wjunc0 = sqrt ( kjunc * T2 ) * QOVJUNC ;
        T2 = `DDRIFT - Wjunc0 ;
    end
    `Fn_SZ( T2 , T2 , `DDRIFT * 0.01 , T9 )
    ddriftldc = T2 ;

    dphi_sb = q_NsubLD * ddriftldc * ddriftldc / 2.0 / `C_ESI ;
    T0 = sqrt(2.0 * beta * dphi_sb) ;
    T1 = (lexp(T0) + lexp(-T0)) / 2 ;
    c_sb = ln(T1) / dphi_sb ;

    for ( lp_s0 = 1 ; lp_s0 <= lp_s0_max + 1 ; lp_s0 = lp_s0 + 1 ) begin
        if ( i_over == 3 ) begin
            OP_lp_ld = lp_s0 - 1 ;
        end
`ifdef _COFDISPLAY_
            probe_lp_s0 = lp_s0 - 1; // -1 is necessary to correct the counts
`endif
        flg_ovzone_intheloop = 0;

        Ps0LD_Vxb = Ps0LD + Vxbgmtcl ;
        Chi = beta * Ps0LD_Vxb ;


        TY = c_sb * ( Ps0LD_Vxb - dphi_sb ) ;
        if ( TY  < `large_arg ) begin
            T1 = exp(TY) ;
            T0 = exp(- c_sb * dphi_sb) ;
            T2 = T1 - T0 ;
            phi_b = ln(1 + T2) / c_sb ;
            phi_b_dPss = T1 / (1 + T2) ;
        end else begin
            phi_b = Ps0LD_Vxb - dphi_sb ;
            phi_b_dPss = 1 ;
        end
        Chib = beta * phi_b ;

        if ( abs(Chi) < 1.0e-6 ) begin
            flg_ovzone_intheloop = `Fn_Sgn(Chi)*1;
            T0 = Chi * Chi / 2 * (1 - Chi / 3 * (1 - Chi / 4 * (1 - Chi / 5))) ;
            T1 = Chi * (1 - Chi / 2 * (1 - Chi / 3 * (1 - Chi / 4))) ;
            T2 = Chib * Chib / 2 * (1 - Chib / 3 * (1 - Chib / 4 * (1 - Chib / 5))) ;
            T3 = Chib * (1 - Chib / 2 * (1 - Chib / 3 * (1 - Chib / 4))) ;
            fbsq = T0 - T2 ;
            fbsq_dPss = beta * (T1 - phi_b_dPss * T3) ;
        end else begin
            flg_ovzone_intheloop = `Fn_Sgn(Chi)*2;
            T0 = exp(-Chi) ;
            T1 = exp(-Chib) ;
            fbsq = (Chi - Chib + (T0 - T1)) ;  // main equation of fbsq
            fbsq_dPss = beta * (1 - T0 - phi_b_dPss * (1 - T1)) ;
        end

        if ( abs(Chi) < 5.0e-5 ) begin
            T0 = Chi * Chi / 2 * (1 + Chi / 3 * (1 + Chi / 4 * (1 + Chi / 5))) ;
            T1 = Chi * (1 + Chi / 2 * (1 + Chi / 3 * (1 + Chi / 4))) ;
            fs01 = cfs1 * T0 ;
            fs01_dPs0 = cfs1 * T1 * beta ;
        end else begin // if ( abs(Chi) < 5.0e-5 )

            if ( abs(Chi) < `large_arg ) begin
                flg_ovzone_intheloop = `Fn_Sgn(Chi)*3;
                exp_Chi = exp( Chi ) ;
                T1 = exp_Chi - 1 ;
                fs01 = cfs1 * ( T1 - Chi ) ;  // main equation of fs01
                fs01_dPs0 = cfs1 * beta * ( T1 ) ;
            end else begin
                flg_ovzone_intheloop = `Fn_Sgn(Chi)*4;
                exp_bPs0 = exp( beta*Ps0LD ) ;
                fs01 = cnst1over * ( exp_bPs0 - exp_bVbs * (Chi + 1) ) ;
                fs01_dPs0 = cnst1over * beta * ( exp_bPs0 - exp_bVbs ) ;
            end


        end // else: !if( abs(Chi) < 5.0e-5 )

        if (fs01 > 0.0) begin
            fs02 = sqrt(fbsq + fs01) ;  // main equation of fs02
            fs02_dPs0 = 0.5 * (fbsq_dPss + fs01_dPs0) / fs02 ;
        end else begin
            if (fbsq > 0.0) begin
                fs02 = sqrt(fbsq) ;
                fs02_dPs0 = 0.5 * (fbsq_dPss) / fs02 ;
            end else begin
                fs02 = 0.0 ;
                fs02_dPs0 = 0.0 ;
            end
        end

        fs02 =      `Fn_Sgn(Chi) * fs02 ;
        fs02_dPs0 = `Fn_Sgn(Chi) * fs02_dPs0 ;

        // Revised Fs0 //
        Fs0 = - VgpLD + Ps0LD + fac1 * fs02 ;
        Fs0_dPs0 = 1.0 + fac1 * fs02_dPs0 ;
        if ( flg_conv > 0 ) begin
            lp_s0 = lp_s0_max+1 ; // break
        end else begin
            dPs0 = - Fs0 / Fs0_dPs0 ;

            //-------------------------------------------*
            //* Update Ps0 .
            //* - clamped to Vbcs_cl if Ps0 < Vbcs_cl .
            //*-----------------//
            dPlim = 0.5*`dP_max*(1.0 + `Fn_Max(1.0e0,abs(Ps0LD))) ;
            if ( abs( dPs0 ) > dPlim ) dPs0 = dPlim * `Fn_Sgn( dPs0 ) ;
            Ps0LD = Ps0LD + dPs0 ;

            //-------------------------------------------*
            //* Check convergence.
            //* NOTE: This condition may be too rigid.
            //*-----------------//
            if ( abs( dPs0 ) <= `ps_conv && abs( Fs0 ) <= `gs_conv ) begin
                flg_conv = flg_conv + 2 ; //conventional criterion
            end

        end

    end // end of Ps0LD Newton loop //

    //-------------------------------------------*
    //* Procedure for diverged case.
    //*-----------------//
    if ( flg_conv == 0 ) begin
        $write( "*** warning(HiSIM_HV(%m)): Went Over Iteration Maximum(Ps0LD fully iterative)\n" ) ;
        $write(" -Vxbgmtcl = %e   Vgbgmt = %e\n" , -Vxbgmtcl , Vgbgmt ) ;
    end

    //-----------------------------------*
    //* Xi0p12
    //*-----------------//
    fb = (fbsq>=0)? `Fn_Sgn(Chi)*sqrt(fbsq) : 0 ;
    WdLD = C_W_LD * fb ;
    Q_dep_LD = q_NsubLD * WdLD ;
    Xi0p12 = Q_dep_LD / cnst0over_func + `epsm10 ;

    //-----------------------------------------------------------*
    //* QbuLD and QiuLD
    //*-----------------//
    QbuLD = cnst0over_func * Xi0p12 ;
    T1 = 1.0 / ( fs02 + Xi0p12 ) ;
    QiuLD = cnst0over_func * fs01 * T1 ;

    //-----------------------------------------------------------*
    //* Total overlap charge
    //*-----------------//
    QsuLD = QbuLD + QiuLD;

end // block: FULLY_ITERATIVE_PS0LD








// inversion charge = total - depletion //
QiuLD = QsuLD - QbuLD  ;

// calc. bias dependent Lover
// 2.4.0's codes reside in HSMHV_LoverLim.inc 20170825
if ( Lover_func < 0.0 ) begin
    Lover_func = - Lover_func ; // now, Lover_func positive
    if (COTRENCH == 0) begin  // COTRENCH=0 only
        if ( COOVJUNC == 0 ) begin
            Vx = -Ps0LD; // original implementation
        end else begin
            Vx = Vxbgmt; // more correct implementation (2.4.0)
        end
        `Fn_SZ( T2 , ( Vx + VBI) , 0.1 , T9 )
        Wjunc0 = sqrt ( kjunc * T2 ) * QOVJUNC ;
        `Fn_SU( Wjuncld, Wjunc0, Lover_func, 0.1 * Lover_func, T0 )
        Lover_func = Lover_func - Wjuncld ;
    end
end
// end of HSMHVevalQover //
