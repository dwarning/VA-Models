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
 FILE : HSMHV_temp_eval_dio.inc

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


//`define HSMHV_Idio_args1(js, JS0, XTI, NJ) begin \
//    js = JS0 * exp((egtnom * betatnom - Eg * beta + XTI * log_Tratio) / NJ) ; \
//end
//
//`define HSMHV_Idio_args2(is_btm, is2_btm, is_sws, is2_sws, is_swg, is2_swg, PD, AD) begin \
//    if ( PD > weff_nf ) begin \
//        is_btm  = AD * js  ; \
//        is2_btm = AD * js2 ; \
//        is_sws  = (PD - weff_nf) * jssw  ; \
//        is2_sws = (PD - weff_nf) * jssw2 ; \
//        is_swg  = weff_nf * jsswg ; \
//        is2_swg = weff_nf * jsswg2 ; \
//    end else begin \
//        is_btm  = AD * js  ; \
//        is2_btm = AD * js2 ; \
//        is_sws  = 0.0 ; \
//        is2_sws = 0.0 ; \
//        is_swg  = PD * jsswg ; \
//        is2_swg = PD * jsswg2 ; \
//    end \
//end
//`define HSMHV_Idio_args2_compat(is_btm, is2_btm, is_sws, is2_sws, is_swg, is2_swg, PD, AD) begin \
//    is_btm  = AD * js  ; \
//    is2_btm = AD * js2 ; \
//    is_sws  = PD * jssw  ; \
//    is2_sws = PD * jssw2 ; \
//    is_swg  = 0.0 ; \
//    is2_swg = 0.0 ; \
//end
//
//`define HSMHV_Qdio_args1(czbd, czbdsw, czbdswg, PD, AD, CJD, TCJBD, CJSWD, TCJBDSW, CJSWGD, TCJBDSWG) begin \
//    czbd = CJD * AD * ( 1.0 + TCJBD * Tdiff) ; \
//    if (PD > weff_nf) begin \
//        czbdsw  = CJSWD  * ( PD - weff_nf ) * ( 1.0 + TCJBDSW  * Tdiff) ; \
//        czbdswg = CJSWGD *        weff_nf   * ( 1.0 + TCJBDSWG * Tdiff) ; \
//    end else begin \
//        czbdsw  = 0.0 ; \
//        czbdswg = CJSWGD *   PD             * ( 1.0 + TCJBDSWG * Tdiff) ; \
//    end \
//end


T0 = Tratio * Tratio ;


// for substrate-drain junction diode. //
`HSMHV_Idio_args1(js,     UC_JS0D,    XTID,  UC_NJD)
`HSMHV_Idio_args1(jssw,   UC_JS0SWD,  XTID,  NJSWD)
`HSMHV_Idio_args1(jsswg,  JS0SWGD,    XTID,  NJSWGD)
`HSMHV_Idio_args1(js2,    UC_JS0D,    XTI2D, UC_NJD)
`HSMHV_Idio_args1(jssw2,  UC_JS0SWD,  XTI2D, NJSWD)
`HSMHV_Idio_args1(jsswg2, JS0SWGD,    XTI2D, NJSWGD)

if ( CODIO > 0 ) begin //new model:
    `HSMHV_Idio_args2(isbd_btm, isbd2_btm, isbd_sws, isbd2_sws, isbd_swg, isbd2_swg, PD, AD)
end else begin //backward compatible:
    `HSMHV_Idio_args2_compat(isbd_btm, isbd2_btm, isbd_sws, isbd2_sws, isbd_swg, isbd2_swg, PD, AD)
end
isbd = isbd_btm + isbd_sws + isbd_swg ;

if ( isbd > 0 ) begin
    T2 = isbd + `Small ; //once removed in Geoffrey01_Small_20160309, but necessary for backward compatibility
    vbdt = UC_NJD / beta * ln( UC_VDIFFJD * T0 / T2 + 1.0 ) ;
    exptempd = exp (( Tratio - 1.0 ) * CTEMPD ) ;
    jd_nvtm_invd = 1.0 / ( UC_NJD / beta ) ;
    jd_expcd = exp (vbdt * jd_nvtm_invd ) ;
end


// for substrate-source junction diode. //
`HSMHV_Idio_args1(js,     UC_JS0S,    XTIS,  UC_NJS)
`HSMHV_Idio_args1(jssw,   UC_JS0SWS,  XTIS,  NJSWS)
`HSMHV_Idio_args1(jsswg,  JS0SWGS,    XTIS,  NJSWGS)
`HSMHV_Idio_args1(js2,    UC_JS0S,    XTI2S, UC_NJS)
`HSMHV_Idio_args1(jssw2,  UC_JS0SWS,  XTI2S, NJSWS)
`HSMHV_Idio_args1(jsswg2, JS0SWGS,    XTI2S, NJSWGS)

if ( CODIO > 0 ) begin //new model:
    `HSMHV_Idio_args2(isbs_btm, isbs2_btm, isbs_sws, isbs2_sws, isbs_swg, isbs2_swg, PS, AS)
end else begin //backward compatible:
    `HSMHV_Idio_args2_compat(isbs_btm, isbs2_btm, isbs_sws, isbs2_sws, isbs_swg, isbs2_swg, PS, AS)
end
isbs = isbs_btm + isbs_sws + isbs_swg ;

if ( isbs > 0 ) begin
    T3 = isbs + `Small ; //once removed in Geoffrey01_Small_20160309, but necessary for backward compatibility
    vbst = UC_NJS / beta * ln( UC_VDIFFJS * T0 / T3 + 1.0 ) ;
    exptemps = exp (( Tratio - 1.0 ) * CTEMPS ) ;
    jd_nvtm_invs = 1.0 / ( UC_NJS / beta ) ;
    jd_expcs = exp (vbst * jd_nvtm_invs ) ;
end


//-----------------------------------------------------------*
//* Charges and Capacitances.
//*-----------------//

// Drain Bulk Junction //
`HSMHV_Qdio_args1(czbd, czbdsw, czbdswg, PD, AD, CJD, TCJBD, CJSWD, TCJBDSW, CJSWGD, TCJBDSWG)

// Source Bulk Junction //
`HSMHV_Qdio_args1(czbs, czbssw, czbsswg, PS, AS, CJS, TCJBS, CJSWS, TCJBSSW, CJSWGS, TCJBSSWG)

// end of HSMHVtemp_eval_dio.h //
