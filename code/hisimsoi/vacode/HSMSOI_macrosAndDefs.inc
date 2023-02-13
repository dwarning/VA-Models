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
 FILE : HSMSOI_macrosAndDefs.inc

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

//File-name: HSMSOI_macrosAndDefs.inc
//
// General definitions
//
//  Definitions of the ADMS Mark-up
//
//  MPRxx    model    parameter real
//  MPIxx    model    parameter integer
//  IPRxx    instance parameter real
//  IPIxx    instance parameter integer
//     ||
//     cc    closed lower bound, closed upper bound bounds
//     nb    no bounds
//     sw    switch(integer only, values  0=false  and  1=true)
//     ty    switch(integer only, values -1=p-type and +1=n-type)
//
//  IPM   instance parameter mFactor(multiplicity, implicit for LRM2.2)
//  OPP   operating point parameter, includes units and description for printing
//
`define ALIAS(alias,paramName) aliasparam alias = paramName ;
`define OPP(nam,uni,des)               (*units=uni,                   desc=des*)           real    nam ;
`define MPRnb(nam,def,uni,        des) (*units=uni,                   desc=des*) parameter real    nam=def ;
`define MPRoo(nam,def,uni,lwr,upr,des) (*units=uni,                   desc=des*) parameter real    nam=def from(lwr:upr) ;
`define MPRco(nam,def,uni,lwr,upr,des) (*units=uni,                   desc=des*) parameter real    nam=def from[lwr:upr) ;
`define MPRcc(nam,def,uni,lwr,upr,des) (*units=uni,                   desc=des*) parameter real    nam=def from[lwr:upr] ;
`define MPRoc(nam,def,uni,lwr,upr,des) (*units=uni,                   desc=des*) parameter real    nam=def from(lwr:upr] ;
`define MPIcc(nam,def,uni,lwr,upr,des) (*units=uni,                   desc=des*) parameter integer nam=def from[lwr:upr] ;
`define MPInb(nam,def,uni,        des) (*units=uni,                   desc=des*) parameter integer nam=def ;
`define MPIsw(nam,def,uni,        des) (*units=uni,                   desc=des*) parameter integer nam=def from[  0:  1] ;
`define MPIty(nam,def,uni,        des) (*units=uni,                   desc=des*) parameter integer nam=def from[ -1:  1] exclude 0 ;
`define BPRnb(nam,def,uni,        des) (*units=uni, type="instance",  desc=des*) parameter real    nam=def ;
`define BPRoo(nam,def,uni,lwr,upr,des) (*units=uni, type="instance",  desc=des*) parameter real    nam=def from(lwr:upr) ;
`define BPRco(nam,def,uni,lwr,upr,des) (*units=uni, type="instance",  desc=des*) parameter real    nam=def from[lwr:upr) ;
`define BPRcc(nam,def,uni,lwr,upr,des) (*units=uni, type="instance",  desc=des*) parameter real    nam=def from[lwr:upr] ;
`define BPRoc(nam,def,uni,lwr,upr,des) (*units=uni, type="instance",  desc=des*) parameter real    nam=def from(lwr:upr] ;
`define BPInb(nam,def,uni,        des) (*units=uni, type="instance",  desc=des*) parameter integer nam=def ;
`define IPRnb(nam,def,uni,        des) (*units=uni, type="instance",  desc=des*) parameter real    nam=def ;
`define IPRoo(nam,def,uni,lwr,upr,des) (*units=uni, type="instance",  desc=des*) parameter real    nam=def from(lwr:upr) ;
`define IPRco(nam,def,uni,lwr,upr,des) (*units=uni, type="instance",  desc=des*) parameter real    nam=def from[lwr:upr) ;
`define IPRcc(nam,def,uni,lwr,upr,des) (*units=uni, type="instance",  desc=des*) parameter real    nam=def from[lwr:upr] ;
`define IPRoc(nam,def,uni,lwr,upr,des) (*units=uni, type="instance",  desc=des*) parameter real    nam=def from(lwr:upr] ;
`define IPInb(nam,def,uni,        des) (*units=uni, type="instance",  desc=des*) parameter integer nam=def ;
`ifdef insideADMS
    `define IPM                        (*units="" , type="instance",  desc="multiplicity factor"*) parameter real m=1.0 from(0.0:inf) ;
`else // notInsideADMS
    `ifdef __OPENVAF__
        `define IPM (*units="" , type="instance", ask="yes", desc="multiplicity factor"*) parameter real m=1.0 from(0.0:inf);
    `else
        `define IPM
    `endif
`endif
`define MFACTOR_USE 1.0

`define Gnqsmin       1e-12
`define Ievb_min      1e-9
`define C_RTH_MIN     0.0001
`define Kflic         1
`define Kwhite        1
`define IGNFPH        -2

// For Debugging print
//`define DEBUG
`ifdef DEBUG
    `define DEBUG_PRINT(xName, x) $strobe("%s = %g", xName, 1.0*x)
`else
    `define DEBUG_PRINT(xName, x)
`endif

`ifdef OK
    `define HiSIM_OK                  OK
    `define HiSIM_ERROR               E_PANIC
`else
    `define HiSIM_OK                  0
    `define HiSIM_ERROR               1
`endif
`define NMOS                      1                     // MOS type
`define PMOS                      -1
`ifdef CMI_NORMAL_MODE
    `define HiSIM_NORMAL_MODE    CMI_NORMAL_MODE
    `define HiSIM_REVERSE_MODE   CMI_REVERSE_MODE
`else
    `define HiSIM_NORMAL_MODE    1                  // device working mode
    `define HiSIM_REVERSE_MODE   -1
`endif
`define NULL                      0                     // others
`define HiSIM_FALSE               0
`define HiSIM_TRUE                1

`define SUBVERSION ( VERSION *  10 % 10 )
`define REVISION   ( VERSION * 100 % 10 )

//---------------------------------------------------*
//* Numerical constants. (macro)
//*-----------------*/
`ifdef  _FLOAT_H
    `define C_EPS_M                   (DBL_EPSILON)         // machine epsilon
`else
    `define C_EPS_M                   (2.2204460492503131e-16)
`endif
`define C_SQRT_2                  (1.414213562373095e+00)       // sqrt(2)
`define C_1o3                     (3.333333333333333e-01)       // 1/3
`define C_2o3                     (6.666666666666667e-01)       // 2/3
`define C_2p_1o3                  (1.259921049894873e+00)       // 2^(1/3)
`define C_Pi                      (3.141592653589793)   // Pi
`define C_Pio2                    (1.570796326794897)
`define C_m2cm                    (1.0e2)               // Unit change
`define C_m2cm_p2                 (1.0e4)
`define C_m2cm_p1o2               (1.0e1)
`define C_m2um                    (1.0e6)
`define C_cm2m                    (1.0e-2)               // Unit change
`define C_cm2m_p2                 (1.0e-4)
`define C_cm2m_p3                 (1.0e-6)
`define C_cm2m_p1o2               (1.0e-1)
//---------------------------------------------------*
//* Physical constants/properties. (macro)
//*-----------------*/
`define C_QE                      (1.6021918e-19)       // Elemental charge
`define C_KB                      (1.3806226e-23)       // Boltzmann constant
`define C_ESI                     (1.034943e-10 )        // Permittivity of Si, SiO2 and vacuum
`define C_EOX                     (3.453133e-11 )
`define C_VAC                     (8.8541878e-12)
`define C_T300                    (300e+00)             // Room temperature constants
`define C_b300                    (3.868283e+01)
`define C_Eg0                     (1.1785e0)
`define C_Vbi                     (1.0e0)               // Build-in potential
`define C_Nin0                    (1.04e+10 / `C_cm2m_p3)            // Intrinsic carrier density at 300K
//---------------------------------------------------*
//* Inline functions
//*-----------------*/
//---------------------------------------------------*
//* smoothZero: flooring to zero.
//*      y = 0.5 ( x + sqrt( x^2 + 4 delta^2 ) )
//*-----------------*/
//    *dx = 0.5 * (1.0 + x / TMF2) ;
//    *y = 0.5 * (x + TMF2) ;

`define t_fox                     (TFOX)
`define t_SOI                     (TSOI)
`define t_box                     (TBOX)
`define N_sub_SOI                 (UC_NSUBS)
`define N_sub_bulk                (MKS_NSUBB)
`define C_VGS_MAX_ERROE           (1e-11)
`define C_PHI_1_MINIMUM           (1e-9)
`define C_PHI_2_MINIMUM           (1e-9)
`define C_PHI_SDL0_MINIMUM        (1e-15)
`define C_PHI_S0_BULK_MIN         (2.3/beta)
`define EXP_THR                   34.0
`define C_gidl_delta              0.5
`define C_QBRAT                   0.5
`define C_IDD_MIN                 1E-15

`define lp_s0_max    20
`define lp_sl_max    20

`define Vds_max       ( 20.0 )
`define Vgs_max       ( 20.0 )
`define dP_max        ( 0.1 )
`define ps_conv       ( 5.0e-12 )
`define PSCONVFAC     ( 1.0 )
`define znbd3         ( 3.0 )
`define znbd5         ( 5.0 )
`define cn_nc3        ( `C_SQRT_2 / 108.0 )
`define cn_nc51       ( 0.707106781186548 )  // sqrt(2)/2 */
`define cn_nc52       ( -0.117851130197758 )  // -sqrt(2)/12 */
`define cn_nc53       ( 0.0178800506338833 )  // (187 - 112*sqrt(2))/1600 */
`define cn_nc54       ( -0.00163730162779191 )  // (-131 + 88*sqrt(2))/4000 */
`define cn_nc55       ( 6.36964918866352e-5 )  //(1509-1040*sqrt(2))/600000 */
`define cn_ac1        ( 0.7071067811865475244008 )
`define cn_ac2        ( -0.1178511301977579207335 )
`define cn_ac3        ( 0.1966881562799040361016e-1 )
`define cn_ac4        ( -0.2539763438742807392019e-2 )
`define cn_ac5        ( 0.3485999509229981384212e-3 )
`define c_ps0ini_2    ( 8.0e-4 )
`define c_pslini_1    ( 0.3 )
`define c_pslini_2    ( 3.0e-2 )
`define VgVt_Small    ( 1.0e-12 )
`define epsm10        ( 10.0 * `C_EPS_M )
`define Small         ( 1.0e-50 )
`define Small2        ( 1.0e-12 )    //for Qover */
`define cclmmdf       ( 1.0e-1 )
`define qme_dlt       ( 1.0e-4 )
`define eef_dlt       ( 1.0e-2 )
`define sti2_dlt      ( 2.0e-3 )
`define psisti_dlt    ( 5.0e-3 )
`define c_exp_2       ( 7.38905609893065 )     // exp(2)
`define c_expm3       ( 0.049787068367863944 ) // exp(-3)
`define c_sqrt_15     ( 3.872983346207417e0 )  // sqrt(15) */
`define C_fox_Small   ( 1.0e-6 )
`define c_16o135      ( 1.185185185185185e-1 )  // 16/135 */
`define igate_dlt     ( 1.0e-2 )
`define vth_dlt       ( 1.0e-3 )
`define qme2_dlt      ( 5.0e-2 )
`define pol_dlt       ( 5.0e-2 )
`define pol_b         ( 1.0 )
`define dQdrat        ( 1.0e-8 )
`define cn_im53       ( 2.9693154855770998e-1 )
`define cn_im54       ( -7.0536542840097616e-2 )
`define cn_im55       ( 6.1152888951331797e-3 )
`define large_arg     ( 80 )    // Old value = ( ln(1.0e100) )
`define delta_Vdseff  ( `epsm10 )
`define gs_conv       ( 1.0e-8 )
`define cnst_2esi_q   ( 2 * `C_ESI / `C_QE )
`define N             ( 100 )
`define r             (  i /  `N )
`define X_vbs         ( xvbs )
`define X_sub1        ( xsub1 )
`define X_sub2        ( xsub2 )
`define X_vgs         ( UC_SVGS )
`define Z_vgs         ( zvgs )
`define X_vds         ( SVDS )
`define X_slg         ( xgate )
`define Nd            ( 1e20 / `C_cm2m_p3)
`define Dn            ( 36.0 )
`define Dp            ( 13.0 )
`define Ln            ( sqrt(`Dn * 1e-7 / `C_cm2m_p2) )
`define Lp            ( sqrt(`Dp * 1e-7 / `C_cm2m_p2) )
`define Vds_mod_max   ( 0.5 )
`define W_diod        ( weff_nf + (NF * UC_PDBCP) )
`define W_dios        ( weff_nf + (NF * UC_PSBCP) )

`define tau_min       ( 1e-15 / `C_cm2m_p2)
`define NQS_CAP       ( 1e-9 / `C_cm2m_p2)

`define EXP_THRES     (80)
`define MAX_EXP       (5.540622384e+34)

`define Vbs_bnd 0.8
`define Vbs_max 1.2

//End of File: HSMSOI_macrosAndDefs.inc

//===========================================================*
//* pow
//*=================*/
`ifdef  POW_TO_EXP_AND_LOG
    `define Fn_Pow( x , y )  exp( y * ln( x )  )
`else
    `define Fn_Pow( x , y )  pow( x , y )
`endif
//===========================================================*
//* Exp() for PGD.
//* - ExpLim(-3)=0
//*=================*/
`define Fn_ExpLim( y , x ) begin \
    if ((x) < -3.0 ) begin \
        y = 0.0 ; \
    end else if ((x) < 0.0 ) begin \
        y = 1.0 + (x) * ( 1.0 + (x) * ( (1.0/3.0) + (x) * (1.0/27.0) ) ) ; \
    end else begin \
        y = 1.0 + (x) * ( 1.0 + (x) * ( (1.0/3.0) + (x) * ( 0.0402052934513951 \
              + (x) * 0.148148111111111 ) ) ) ; \
    end \
end
//===========================================================*
//* Macro Functions for ceiling/flooring/symmetrization.
//*=================*/
//---------------------------------------------------*
//* smoothUpper: ceiling.
//*      y = xmax - 0.5 ( arg + sqrt( arg^2 + 4 xmax delta ) )
//*    arg = xmax - x - delta
//*-----------------*/
`define Fn_SU_DX( y , x , xmax , delta , dx ) begin \
    TMF1 = ( xmax ) - ( x ) - ( delta ) ; \
    TMF2 = 4.0 * ( xmax ) * ( delta) ; \
    TMF2 = TMF2 > 0.0 ?  TMF2 : - ( TMF2 ) ; \
    TMF2 = sqrt ( TMF1 * TMF1 + TMF2 ) ; \
    dx = 0.5 * ( 1.0 + TMF1 / TMF2 ) ; \
    y = ( xmax ) - 0.5 * ( TMF1 + TMF2 ) ; \
end
`define Fn_SU2( y , x , xmax , delta , dy_dx , dy_dxmax ) begin \
    TMF1 = ( xmax ) - ( x ) - ( delta ) ; \
    TMF2 = 4.0 * ( xmax ) * ( delta) ; \
    TMF2 = TMF2 > 0.0 ?  TMF2 : - ( TMF2 ) ; \
    TMF2 = sqrt ( TMF1 * TMF1 + TMF2 ) ; \
    dy_dx = 0.5 * ( 1.0 + TMF1 / TMF2 ) ; \
    dy_dxmax = 0.5 * ( 1.0 - ( TMF1 + 2.0 * delta ) / TMF2 ) ; \
    y = ( xmax ) - 0.5 * ( TMF1 + TMF2 ) ; \
end
//---------------------------------------------------*
//* smoothLower: flooring.
//*      y = xmin + 0.5 ( arg + sqrt( arg^2 + 4 xmin delta ) )
//*    arg = x - xmin - delta
//*-----------------*/
`define Fn_SL( y , x , xmin , delta , dx ) begin \
    TMF1 = ( x ) - ( xmin ) - ( delta ) ; \
    TMF2 = 4.0 * ( xmin ) * ( delta ) ; \
    TMF2 = TMF2 > 0.0 ?  TMF2 : - ( TMF2 ) ; \
    TMF2 = sqrt ( TMF1 * TMF1 + TMF2 ) ; \
    dx = 0.5 * ( 1.0 + TMF1 / TMF2 ) ; \
    y = ( xmin ) + 0.5 * ( TMF1 + TMF2 ) ; \
end
`define Fn_SL2( y , x , xmin , delta , dy_dx, dy_dxmin ) begin \
    TMF1 = ( x ) - ( xmin ) - ( delta ) ; \
    TMF2 = 4.0 * ( xmin ) * ( delta ) ; \
    TMF2 = TMF2 > 0.0 ?  TMF2 : - ( TMF2 ) ; \
    TMF2 = sqrt ( TMF1 * TMF1 + TMF2 ) ; \
    dy_dx = 0.5 * ( 1.0 + TMF1 / TMF2 ) ; \
    dy_dxmin = 0.5 * ( 1.0 - ( TMF1 - 2.0 * delta ) / TMF2 ) ; \
    y = ( xmin ) + 0.5 * ( TMF1 + TMF2 ) ; \
end
//* smoothZero: flooring to zero.
//*      y = 0.5 ( x + sqrt( x^2 + 4 delta^2 ) )
//*-----------------*/
`define Fn_SZ_DX( y , x , delta , dx ) begin \
    TMF2 = sqrt ( ( x ) *  ( x ) + 4.0 * ( delta ) * ( delta) ) ; \
    dx = 0.5 * ( 1.0 + ( x ) / TMF2 ) ; \
    y = 0.5 * ( ( x ) + TMF2 ) + 1e-10 * delta ; \
    if ( y < 0.0 ) begin y=0.0; dx=0.0; end \
end
//---------------------------------------------------*
//* CeilingPow: ceiling for positive x, flooring for negative x.
//*      y = x * xmax / ( x^{2m} + xmax^{2m} )^{1/(2m)}
//* note:
//*   - xmax has to be positive.
//*   - -xmax < y < xmax.
//*   - dy/dx|_beginx=0end = 1.
//*-----------------*/
`define Fn_CP( y , x , xmax , pw ) begin \
    x2 = (x) * (x) ; \
    xmax2 = (xmax) * (xmax) ; \
    xp = 1.0  ; \
    xmp = 1.0 ; \
    m0 = 0 ; \
    mm =0 ; \
    arg = 0.0 ; \
    dnm =0.0 ; \
    for ( m0 = 0 ; m0 < pw ; m0 = m0 + 1 ) begin xp = xp * x2 ; xmp = xmp * xmax2 ; end \
    arg = xp + xmp ; \
    dnm = arg ; \
    if ( pw == 1 || pw == 2 || pw == 4 || pw == 8 ) begin \
        if ( pw == 1 ) begin mm = 1 ; \
        end else if ( pw == 2 ) begin mm = 2 ; \
        end else if ( pw == 4 ) begin mm = 3 ; \
        end else if ( pw == 8 ) begin mm = 4 ; end \
            for ( m0 = 0 ; m0 < mm ; m0 = m0 + 1 ) begin dnm = sqrt( dnm ) ; end \
        end else begin dnm = `Fn_Pow( dnm , 1.0 / ( 2.0 * pw ) ) ; end \
    dnm = 1.0 / dnm ; \
    y = (x) * (xmax) * dnm ; \
end

`define Fn_CP_DX( y , x , xmax , pw , dx ) begin \
    x2 = (x) * (x) ; \
    xmax2 = (xmax) * (xmax) ; \
    xp = 1.0  ; \
    xmp = 1.0 ; \
    m0 = 0 ; \
    mm =0 ; \
    arg = 0.0 ; \
    dnm =0.0 ; \
    for ( m0 = 0 ; m0 < pw ; m0 = m0 + 1 ) begin xp = xp * x2 ; xmp = xmp * xmax2 ; end \
    arg = xp + xmp ; \
    dnm = arg ; \
    if ( pw == 1 || pw == 2 || pw == 4 || pw == 8 ) begin \
        if ( pw == 1 ) begin mm = 1 ; \
        end else if ( pw == 2 ) begin mm = 2 ; \
        end else if ( pw == 4 ) begin mm = 3 ; \
        end else if ( pw == 8 ) begin mm = 4 ; end \
            for ( m0 = 0 ; m0 < mm ; m0 = m0 + 1 ) begin dnm = sqrt( dnm ) ; end \
        end else begin dnm = `Fn_Pow( dnm , 1.0 / ( 2.0 * pw ) ) ; end \
    dnm = 1.0 / dnm ; \
    y = (x) * (xmax) * dnm ; \
    dx = (xmax) * xmp * dnm / arg ; \
end

`define Fn_SU_CP( y , x , xmax , delta , pw ) begin \
    if (x > (xmax) - (delta) && (delta) >= 0.0) begin \
        TMF1 = (x) - (xmax) + (delta) ; \
        `Fn_CP( TMF0 , TMF1 , (delta) , (pw) )  \
        y = (xmax) - (delta) + TMF0 ; \
    end else begin \
        y = x ; \
    end \
end


`define Fn_SU_CP_DX( y , x , xmax , delta , pw , dx ) begin \
    if (x > (xmax) - (delta) && (delta) >= 0.0) begin \
        TMF1 = (x) - (xmax) + (delta) ; \
        `Fn_CP_DX( TMF0 , TMF1 , (delta) , (pw) , dx )  \
        y = (xmax) - (delta) + TMF0 ; \
        dx = dx ; \
    end else begin \
        y = x ; \
        dx = 1.0 ; \
    end \
end

`define Fn_SL_CP( y , x , xmin , delta , pw ) begin \
    if ( (x) < (xmin) + (delta) && (delta) >= 0.0) begin \
        TMF1 = (xmin) +(delta) - (x) ; \
        `Fn_CP( TMF0 , TMF1 , (delta) , (pw) )  \
        y = (xmin) + (delta) - TMF0 ; \
    end else begin \
        y = x ; \
    end \
end

`define Fn_SL_CP_DX( y , x , xmin , delta , pw , dx ) begin \
    if ( (x) < (xmin) + (delta) && (delta) >= 0.0) begin \
        TMF1 = (xmin) +(delta) - (x) ; \
        `Fn_CP_DX( TMF0 , TMF1 , (delta) , (pw) , dx )  \
        y = (xmin) + (delta) - TMF0 ; \
        dx = dx ; \
    end else begin \
        y = x ; \
        dx = 1.0 ; \
    end \
end


//---------------------------------------------------*
//* "smoothUpper" using a polynomial
//*-----------------*/
//`Fn_DclPoly4( y , TMF1 , dx ) ;
`define Fn_SUPoly4( y , x , xmax , dx ) begin \
    TMF1 = (x) / xmax ; \
    TMF2 = TMF1 * TMF1 ; \
    TMF3 = TMF2 * TMF1 ; \
    TMF4 = TMF2 * TMF2 ; \
    y = 1.0 / ( 1.0 + (TMF1) + TMF2 + TMF3 + TMF4 ) ; \
    dx = - ( 1.0 + 2.0 * (TMF1) + 3.0 * TMF2 + 4.0 * TMF3 )  * y * y  ; \
    y = xmax * ( 1.0 - y ) ; \
    dx = - dx ; \
end
//---------------------------------------------------*
//* SymAdd: evaluate additional term for symmetry.
//*-----------------*/
`define Fn_SymAdd( y , x , add0 ) begin \
    TMF1 = 2.0 * ( x ) / ( add0 ) ; \
    TMF2 = 1.0 + TMF1 * ( (1.0/2) + TMF1 * ( (1.0/6) \
             + TMF1 * ( (1.0/24) + TMF1 * ( (1.0/120) \
             + TMF1 * ( (1.0/720) + TMF1 * (1.0/5040) ) ) ) ) ) ; \
    y = add0 / TMF2 ; \
end

`define Fn_Sqr(x)   ( (x)*(x) ) // x^2 */
`define Fn_Max(x,y) ( (x) >= (y) ? (x) : (y) ) // max[x,y] */
`define Fn_Min(x,y) ( (x) <= (y) ? (x) : (y) ) // min[x,y] */
`define Fn_Sgn(x)   ( (x) >= 0  ?  (1) : (-1) )    // sign[x] */

//===========================================================*
//* Exp() for large input value.
//*=================*/
`define D_EXP_THRESHOLD (500.0)                //exp(710)=inf
`define D_MAX_EXP       (1.403592217853e+217)  //exp(500.0)
`define C_UNIT_EXP_ARG  (60.0)                 //exp(60.0) may touch the Verilog-A limit
`define C_UNIT_EXP_RES  (1.14200738981568e+26) //exp(60.0)
`define Fn_DExp( y , x , dx) begin \
    if ((x) >= `D_EXP_THRESHOLD) begin \
        y  = `D_MAX_EXP * (1 + (x) - `D_EXP_THRESHOLD); \
        dx = `D_MAX_EXP ; \
    end else begin \
        TMF1 = (x); \
        y = 1.0; \
        while (TMF1 >= `C_UNIT_EXP_ARG ) begin \
            y = y * `C_UNIT_EXP_RES; \
            TMF1 = TMF1 - `C_UNIT_EXP_ARG; \
        end \
        y = y * exp(TMF1); dx = y; \
    end \
end


// End of src/lib/dev/hisimsoi/hsmsoieval.c for definition

// Begin: src/lib/dev/hisimsoi/hsmsoitemp.c for definition
`define BINNING(UC_PARAM, PARAM, LPARAM, WPARAM, PPARAM) UC_PARAM = PARAM \
    + LPARAM / Lbin + WPARAM / Wbin \
    + PPARAM / LWbin ;
`define RANGECHECK(param, min, max, pname) begin \
    if ((param) <(min) ||(param) >(max) ) begin \
        $write("warning(HiSIM_SOI): (%M) The model/instance parameter %s (= %e) must be in the range [%e , %e].\n", \
           pname, (param), (min), (max) ) ; \
    end \
end
`define RANGERESET(param, min, max, pname)              \
    if ( ((param) >(max)) ) begin   \
        $write("reset(HiSIM_SOI(%m)): (%s = %g to %g) range [%g , %g].\n", \
           pname, (param), (max*1.0), (min*1.0), (max*1.0) );     \
    end \
    if ( ((param) <(min)) ) begin   \
        $write("reset(HiSIM_SOI(%m)): (%s = %g to %g) range [%g , %g].\n", \
           pname, (param), (min*1.0), (min*1.0), (max*1.0) );     \
    end \
    if ((param) <(min) ) begin  param  =(min); end    \
    if ((param) >(max) ) begin  param  =(max); end
`define MINCHECK(param, min, pname) \
    if ((param) <(min) ) begin \
        $write("warning(HiSIM_SOI): (%M) The model/instance parameter %s (= %e) must be greater than %e.\n", \
           pname, (param), (min) ) ;                     \
    end
`define PMINCHECK(param, min, mesg) \
    if ( (param) <(min) ) begin \
        $write(" *** Fatal(HiSIM_SOI): (%M) %s\n",mesg ); \
        FATAL_flag = 1; \
    end

//---------------------------------------------------*
//* smoothZero: flooring to zero.
//*      y = 0.5 ( x + sqrt( x^2 + 4 delta^2 ) )
//*-----------------*/
`define Fn_SZtemp( y , x , delta ) begin \
    TMF1 = sqrt ( ( x ) *  ( x ) + 4.0 * ( delta ) * ( delta) ) ; \
    y = 0.5 * ( ( x ) + TMF1 ) + 1e-10 * delta ; \
    if ( y < 0.0 ) begin y=0.0; end \
end
`define Fn_SUtemp( y , x , xmax , delta ) begin \
    TMF1 = ( xmax ) - ( x ) - ( delta ) ; \
    TMF2 = 4.0 * ( xmax ) * ( delta) ; \
    TMF2 = TMF2 > 0.0 ?  TMF2 : - ( TMF2 ) ; \
    TMF2 = sqrt ( TMF1 * TMF1 + TMF2 ) ; \
    y = ( xmax ) - 0.5 * ( TMF1 + TMF2 ) ; \
end
`define Fn_SLtemp( y , x , xmin , delta ) begin \
    TMF1 = ( x ) - ( xmin ) - ( delta ) ; \
    TMF2 = 4.0 * ( xmin ) * ( delta ) ; \
    TMF2 = TMF2 > 0.0 ?  TMF2 : - ( TMF2 ) ; \
    TMF2 = sqrt ( TMF1 * TMF1 + TMF2 ) ; \
    y = ( xmin ) + 0.5 * ( TMF1 + TMF2 ) ; \
end

// End of src/lib/dev/hisimsoi/hsmsoitemp.c for definition
