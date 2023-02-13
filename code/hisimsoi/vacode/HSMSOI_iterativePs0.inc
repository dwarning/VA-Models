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
 FILE : HSMSOI_iterativePs0.inc

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

begin : HSMSOI_iterativePs0

    real Vbcs_cl , phi_s0_SOI ;

    //-----------------------------------------------------------*
    //Solve Poisson's equation for BT devices
    //----------------//
    Vbcs_cl = dphi_vds ;

    // Start of hsmsoieval_btsolps.h //

    //-----------------------------------------------------------*
    //* Accumulation zone. (zone-A)
    //* - evaluate basic characteristics and exit from this part.
    //*-----------------//
    Vgs_fb = Vfb - dVth + dPpg + Vbcs_cl + VFBPT ; // for BTSOI //
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

        //---------------------------------------------------*
        //* Calculation of Ps0. (beginning of Newton loop)
        //* - Fs0 : Fs0 = 0 is the equation to be solved.
        //* - dPs0 : correction value.
        //*-----------------//
        exp_bVbsVds = exp( beta * ( Vbcs_cl - PSLIMPT ) ) ;
        flg_conv = 0 ;

        phi_s0_SOI = Ps0_ini ;

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

            if (Chi < 0) begin
                fs02 = -fb ;
                fs02_dPs0 = -fb_dPss ;
            end else if (Chi < 1E-7) begin
                fs02 = fb ;
                fs02_dPs0 = fb_dPss ;
            end else begin
                Rho = beta * ( phi_s0_SOI - PSLIMPT ) ;
                exp_Rho = exp( Rho ) ;
                fs01 = cnst1SOI * ( exp_Rho - exp_bVbsVds * (Chi + 1) ) ;
                fs01_dPs0 = cnst1SOI * beta * ( exp_Rho - exp_bVbsVds ) ;
                fs02 = sqrt(fb * fb + fs01) ;
                fs02_dPs0 = 0.5 * (2 * fb_dPss * fb + fs01_dPs0) / fs02 ;
            end

            // Revised Fs0 //
            Fs0 = - Vgp + phi_s0_SOI + fac1 * fs02 ;
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

        Ps0 = phi_s0_SOI ;
        //     $write("Ps0_ini %g Vbcs_cl %g flg_conv %d Ps0 %g \n",
        //     Ps0_ini,Vbcs_cl,flg_conv,Ps0);

    end // end of if( Vgs < Vgs_fb )

end //  Ps0_newPT
