/***********************************************************************

 HiSIM (Hiroshima University STARC IGFET Model)
 Copyright (C) 2000-2016 Hiroshima University and STARC
 Copyright (C) 2016-2019 Hiroshima University
 HiSIM_HV (High-Voltage Model)
 Copyright (C) 2007-2016 Hiroshima University and STARC
 Copyright (C) 2016-2019 Hiroshima University

 MODEL NAME : HiSIM_HV
 ( VERSION : 2  SUBVERSION : 4  REVISION : 2 )
 Model Parameter 'VERSION' : 2.42
 FILE : HSMHV_eval_qover.inc

 Date : 2019.04.09

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
//---------------------------------------------------*
//* Clamp -Vxbgmt.
//*-----------------//
T0 = - Vxbgmt;
if ( T0 > Vbs_bnd ) begin
    T1 =    T0   - Vbs_bnd;
    T2 =    Vbs_max    - Vbs_bnd;
    `Fn_SUPoly4m( TY, T1, T2, T11, T0 )
    T10 = Vbs_bnd + TY ;
end  else begin
    T10 = T0 ;
end
Vxbgmtcl = - T10  ;

fac1 = cnst0over_func * Cox0_inv ;
fac1p2 = fac1 * fac1 ;
VgpLD = - Vgbgmt + UC_VFBOVER;
T0 = Nover_func / Nin ;
Pb2over = 2.0 * beta_inv * ln ( T0 ) ;
Vgb_fb_LD =  - Vxbgmtcl + `epsm10 ;
Q_dep_LD  =  0.0 ;
q_NsubLD = `C_QE * Nover_func ;

//-----------------------------------*
//* QsuLD: total charge = Accumulation | Depletion+inversion
//*-----------------//
if ( VgpLD  < Vgb_fb_LD ) begin
    //---------------------------*
    //* Accumulation
    //*-----------------//
    flg_ovzone = -1 ;
    T1 = 1.0 / ( beta * cnst0over_func ) ;
    TY = T1 * Cox0 ;
    Ac41 = 2.0 + 3.0 * `C_SQRT_2 * TY ;
    Ac4 = 8.0 * Ac41 * Ac41 * Ac41 ;
    Ps0_min = Eg - Pb2over ;
    TX = beta * ( VgpLD + Vxbgmtcl ) ;
    Ac31 = 7.0 * `C_SQRT_2 - 9.0 * TY * ( TX - 2.0 ) ;
    Ac3 = Ac31 * Ac31 ;
    if ( Ac4 < Ac3*1.0e-8 ) begin
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
    QsuLD = Cox0 * T2 ;
    QbuLD = QsuLD ;

end else begin

    //---------------------------*
    //* Depletion and inversion
    //*-----------------//

    // initial value for a few fixpoint iterations
    //to get Ps0_iniA from simplified Poisson equation: //
    flg_ovzone = 2 ;
    if ( beta * ( VgpLD + Vxbgmtcl ) < 1.0e0 + ( `epsm10 - 1.0e0 ) * fac1p2 * beta2 / 4.0e0 ) begin //equivalent to (TX < `epsm10)
        Ps0_iniA = VgpLD + fac1p2 * beta / 2.0e0  ;
    end else begin
        TX = 1.0e0 + 4.0e0 * ( beta * ( VgpLD + Vxbgmtcl ) - 1.0e0 ) / ( fac1p2 * beta2 ) ;
        Ps0_iniA = VgpLD + fac1p2 * beta / 2.0e0 * ( 1.0e0 - sqrt( TX ) ) ;
    end
    Chi = beta * ( Ps0_iniA + Vxbgmtcl ) ;

    if ( Chi >= `znbd3 ) begin
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
        flg_ovzone = flg_ovzone + 2;
        VgpLD_shift = VgpLD + Vxbgmtcl + 0.1;
        exp_bVbs = exp( beta * - Vxbgmtcl ) ;
        T0 = Nin / Nover_func;
        cnst1over = T0 * T0;
        cfs1 = cnst1over * exp_bVbs ;
        gammaChi = cnst1over * exp_bVbs;
        T0  = beta2 * fac1p2;
        psi = beta*VgpLD_shift;
        Chi_1 = ln (gammaChi*T0 + psi*psi) - ln (cnst1over*T0) + beta*Vxbgmtcl;
        `Fn_SU( Chi_1, Chi_1, psi, 1.0, T1 )

        // 1 fixpoint step for getting more accurate Chi_B //
        psi = psi - Chi_1 ;
        psi = psi + beta*0.1 ;
        T1 = ln (gammaChi*T0 + psi*psi) - ln (cnst1over*T0) ;
        Chi_B = T1 + beta*Vxbgmtcl ;

        // construction of Ps0LD by taking Ps0_iniB as an upper limit of Ps0_iniA
        //*
        //* Limiting is done for Chi rather than for Ps0LD, to avoid shifting
        //* for Fn_SU //
        Chi_A = Chi;
        `Fn_SU( Chi, Chi_A, Chi_B, `c_ps0ini_2*75.00, T1 )
    end

    // updating Ps0LD //
    Ps0LD = Chi* beta_inv - Vxbgmtcl ;

    if (abs(Chi)> 1e-6) begin   // 20161012
        T1 = Chi - 1.0 + exp(-Chi);
        T2 = sqrt(T1);
    end else begin
        // T2 = `C_1oSQRT2*Chi;
        // further alternative:
        //  // Chi - 1.0 + exp(-Chi) = (1/2)*Chi*Chi*(1+ (1/3)*Chi)
        //  u = 1.0 + Chi * `C_1to3;
        //  T2 = `C_1oSQRT2* Chi* sqrt(u);
        T2 =`C_1oSQRT2* Chi* sqrt( 1.0 + Chi * `C_1o3);
    end
    QbuLD = cnst0over_func * T2 ;

    //-----------------------------------------------------------*
    //* QsuLD : Qovs or Qovd in unit area.
    //* note: QsuLD = Qdep+Qinv.
    //*-----------------//
    QsuLD = Cox0 * ( VgpLD - Ps0LD ) ;

    if ( COQOVSM == 1 ) begin // Dynamic Depletion Model //

        //---------------------------------------------------*
        //* Calculation of Ps0. (beginning of Newton loop)
        //* - Fs0 : Fs0 = 0 is the equation to be solved.
        //* - dPs0 : correction value.
        //*-----------------//
        flg_conv = 0 ;
        C_W_LD = sqrt(2.0 * (`C_ESI / q_NsubLD * beta_inv)) ;
        if ( SUBVERSION > 2 || (SUBVERSION > 3 && COTRENCH != 1) ) begin  // Version 2.30 or "2.40 with COTRENCH=0"
            // calc. effective DDRIFT with p-n junction
            Ps0LD_Vxb = Ps0LD + Vxbgmtcl ;
            `Fn_SZ( Ps0LD_Vxb , Ps0LD_Vxb , 1 , T0 )
            T1 = sqrt(2.0 * `C_ESI * Ps0LD_Vxb / q_NsubLD ) ;
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
        end else begin
            dphi_sb = 0.0 ; c_sb = 0.0 ;
        end

        for ( lp_s0 = 1 ; lp_s0 <= lp_s0_max + 1 ; lp_s0 = lp_s0 + 1 ) begin

            Ps0LD_Vxb = Ps0LD + Vxbgmtcl ;
            Chi = beta * Ps0LD_Vxb ;

            if ( SUBVERSION < 3 ) begin  // Version 2.20
                if ( Chi < `znbd5 ) begin
                    //-------------------------------------------*
                    //* zone-D1/D2. (Ps0LD)
                    //*-----------------//
                    fi = Chi * Chi * Chi
                    * ( `cn_im53 + Chi * ( `cn_im54 + Chi * `cn_im55 ) ) ;
                    fi_dChi = Chi * Chi
                      * ( 3 * `cn_im53 + Chi * ( 4 * `cn_im54 + Chi * 5 * `cn_im55 ) ) ;
                    fs01 = cfs1 * fi * fi ;
                    fs01_dPs0 = cfs1 * beta * 2 * fi * fi_dChi ;

                    fb = Chi * ( `cn_nc51
                    + Chi * ( `cn_nc52
                    + Chi * ( `cn_nc53
                    + Chi * ( `cn_nc54 + Chi * `cn_nc55 ) ) ) ) ;
                    fb_dChi = `cn_nc51
                      + Chi * ( 2 * `cn_nc52
                      + Chi * ( 3 * `cn_nc53
                      + Chi * ( 4 * `cn_nc54 + Chi * 5 * `cn_nc55 ) ) ) ;
                    fs02 = sqrt( fb * fb + fs01 ) ;
                    fs02_dPs0 = ( beta * fb_dChi * 2 * fb + fs01_dPs0 ) / ( fs02 + fs02 ) ;
                end else begin
                    //-------------------------------------------*
                    //* zone-D3. (Ps0LD)
                    //*-----------------//
                    if ( Chi < `large_arg ) begin // avoid exp_Chi to become extremely large //
                        exp_Chi = exp( Chi ) ;
                        fs01 = cfs1 * ( exp_Chi - 1.0e0 ) ;
                        fs01_dPs0 = cfs1 * beta * ( exp_Chi ) ;
                    end else begin
                        exp_bPs0 = exp( beta*Ps0LD ) ;
                        fs01     = cnst1over * ( exp_bPs0 - exp_bVbs ) ;
                        fs01_dPs0 = cnst1over * beta * exp_bPs0 ;
                    end
                    fs02 = sqrt( Chi - 1.0 + fs01 ) ;
                    fs02_dPs0 = ( beta + fs01_dPs0 ) / fs02 * 0.5 ;
                end // end of if( Chi  ... ) block //

            end else begin // Version 2.30

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

                if (Chi < 0) begin
                    T0 = - sqrt((1 - phi_b_dPss * phi_b_dPss) / 2) ;
                    fb = Chi * T0 ;
                    fb_dPss = beta * T0 ;
                end else if (Chi < 1E-8) begin
                    T0 = Chi * Chi / 2 * (1 - Chi / 3 * (1 - Chi / 4 * (1 - Chi / 5))) ;
                    T1 = Chi * (1 - Chi / 2 * (1 - Chi / 3 * (1 - Chi / 4))) ;
                    T2 = Chib * Chib / 2 * (1 - Chib / 3 * (1 - Chib / 4 * (1 - Chib / 5))) ;
                    T3 = Chib * (1 - Chib / 2 * (1 - Chib / 3 * (1 - Chib / 4))) ;
                    fb = sqrt(T0 - T2) ;
                    fb_dPss = beta * 0.5 * (T1 - phi_b_dPss * T3) / fb ;
                end else begin
                    //-------------------------------------------*
                    //* zone-D3.  (Ps0LD)
                    //*-----------------//
                    T0 = exp(-Chi) ;
                    T1 = exp(-Chib) ;
                    fb = sqrt(Chi - Chib + (T0 - T1)) ;
                    fb_dPss = beta * 0.5 * (1 - T0 - phi_b_dPss * (1 - T1)) / fb ;
                end //

                if (Chi < 0) begin
                    fs02 = -fb ;
                    fs02_dPs0 = -fb_dPss ;
                end else begin
                    if ( Chi < `large_arg ) begin // avoid exp_Chi to become extremely large
                        exp_Chi = exp( Chi ) ;
                        fs01 = cfs1 * ( exp_Chi - (Chi + 1) ) ;
                        fs01_dPs0 = cfs1 * beta * ( exp_Chi - 1 ) ;
                    end else begin
                        exp_bPs0 = exp( beta*Ps0LD ) ;
                        fs01 = cnst1over * ( exp_bPs0 - exp_bVbs * (Chi + 1) ) ;
                        fs01_dPs0 = cnst1over * beta * ( exp_bPs0 - exp_bVbs ) ;
                    end
                    fs02 = sqrt(fb * fb + fs01) ;
                    fs02_dPs0 = 0.5 * (2 * fb_dPss * fb + fs01_dPs0) / fs02 ;
                end

            end // Version 2.30

            // Revised Fs0 //
            Fs0 = - VgpLD + Ps0LD + fac1 * fs02 ;
            Fs0_dPs0 = 1.0 + fac1 * fs02_dPs0 ;
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
        if ( SUBVERSION > 2 ) begin // Version 2.30
            Xi0p12 = Q_dep_LD / cnst0over_func + `epsm10 ;
        end else begin
            if ( Chi < `znbd5 ) begin
                //-------------------------------------------*
                //* zone-D1/D2. (Ps0LD)
                //*-----------------//
                flg_ovzone = ( Chi < `znbd3 ) ? 1 : 2 ;
                Xi0p12 = fb + `epsm10 ;
            end else begin
                //-------------------------------------------*
                //* zone-D3. (Ps0LD)
                //*-----------------//
                flg_ovzone = 3 ;
                Xi0p12 = sqrt( Chi - 1.0e0 ) ;
            end // end of if( Chi  ... ) block //
        end

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

// inversion charge = total - depletion //
QiuLD = QsuLD - QbuLD  ;

// calc. bias dependent Lover
// 2.4.0's codes reside in HSMHV_LoverLim.inc 20170825
if ( Lover_func < 0.0 ) begin
    Lover_func = - Lover_func ; // now, Lover_func positive
    if ( SUBVERSION > 2 && COTRENCH == 0) begin  // Version 2.30 or later; and COTRENCH=0 only
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
