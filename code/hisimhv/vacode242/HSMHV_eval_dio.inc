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
 FILE : HSMHV_eval_dio.inc

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


//-----------------------------------------------------------*
//* Temperature dependent constants.
//*-----------------//
if ( COSELFHEAT > 0 && UC_RTH0 != 0.0 ) begin

`include "HSMHV_temp_eval_dio.inc"
end else begin
    TTEMP = $temperature + DTEMP;
end

//-----------------------------------------------------------*
//* Cbsj, Cbdj: node-base S/D biases.
//*-----------------//

// ibd //
T10 = CVBD * jd_nvtm_invd ;
T9 = CISBD * exptempd ;
`HSMHV_Idio(Ibd_btm, vbd_jct,  isbd_btm, isbd2_btm,  vbdt, jd_expcd,  T10, T9, jd_nvtm_invd, UC_CISBKD, DIVXD)
`HSMHV_Idio(Ibd_sws, vbd_jct,  isbd_sws, isbd2_sws,  vbdt, jd_expcd,  T10, T9, jd_nvtm_invd, UC_CISBKD, DIVXD)
if ( CODIO > 0 ) begin //new model:
    `HSMHV_Idio(Ibd_swg, vbdi_jct, isbd_swg, isbd2_swg,  vbdt, jd_expcd,  T10, T9, jd_nvtm_invd, UC_CISBKD, DIVXD)
end else begin //backward compatible:
    Ibd_swg = 0.0 ;
end

// ibs //
T10 = CVBS * jd_nvtm_invs ;
T9 = CISBS * exptemps ;
`HSMHV_Idio(Ibs_btm, vbs_jct,  isbs_btm, isbs2_btm,  vbst, jd_expcs,  T10, T9, jd_nvtm_invs, UC_CISBKS, DIVXS)
`HSMHV_Idio(Ibs_sws, vbs_jct,  isbs_sws, isbs2_sws,  vbst, jd_expcs,  T10, T9, jd_nvtm_invs, UC_CISBKS, DIVXS)
if ( CODIO > 0 ) begin //new model:
    `HSMHV_Idio(Ibs_swg, vbsi_jct, isbs_swg, isbs2_swg,  vbst, jd_expcs,  T10, T9, jd_nvtm_invs, UC_CISBKS, DIVXS)
end else begin //backward compatible:
    Ibs_swg = 0.0 ;
end

//-----------------------------------------------------------*
//* Charges and Capacitances.
//*-----------------//
//  charge storage elements
//*  bulk-drain and bulk-source depletion capacitances
//*  czbd : zero bias drain junction capacitance
//*  czbs : zero bias source junction capacitance
//*  czbdsw:zero bias drain junction sidewall capacitance
//*  czbssw:zero bias source junction sidewall capacitance
////

// Drain Bulk Junction //
`HSMHV_Qdio(Qbd_btm, Capbd_btm, vbd_jct,  czbd,    PBD,    MJD)
`HSMHV_Qdio(Qbd_sws, Capbd_sws, vbd_jct,  czbdsw,  PBSWD,  MJSWD)
if ( CODIO > 0 ) begin //new model:
    `HSMHV_Qdio(Qbd_swg, Capbd_swg, vbdi_jct, czbdswg, PBSWGD, MJSWGD)
end else begin //backward compatible:
    `HSMHV_Qdio(Qbd_swg, Capbd_swg, vbd_jct, czbdswg, PBSWGD, MJSWGD)
end

// Source Bulk Junction //
`HSMHV_Qdio(Qbs_btm, Capbs_btm, vbs_jct,  czbs,    PBS,    MJS)
`HSMHV_Qdio(Qbs_sws, Capbs_sws, vbs_jct,  czbssw,  PBSWS,  MJSWS)
if ( CODIO > 0 ) begin //new model:
    `HSMHV_Qdio(Qbs_swg, Capbs_swg, vbsi_jct, czbsswg, PBSWGS, MJSWGS)
end else begin //backward compatible:
    `HSMHV_Qdio(Qbs_swg, Capbs_swg, vbs_jct, czbsswg, PBSWGS, MJSWGS)
end


//---------------------------------------------------*
//* Junction diode.
//*-----------------//
Ibs = Mfactor * (Ibs_btm + Ibs_sws) ;
Ibd = Mfactor * (Ibd_btm + Ibd_sws) ;
if ( CODIO > 0 ) begin //new model:
    Ibsi = Mfactor * Ibs_swg ;
    Ibdi = Mfactor * Ibd_swg ;
    Qbs = Mfactor * (Qbs_btm + Qbs_sws) ;
    Qbd = Mfactor * (Qbd_btm + Qbd_sws) ;
    Qbsi = Mfactor * Qbs_swg ;
    Qbdi = Mfactor * Qbd_swg ;
    Capbs = Mfactor * (Capbs_btm + Capbs_sws) ;
    Capbd = Mfactor * (Capbd_btm + Capbd_sws) ;
    Capbsi = Mfactor * Capbs_swg ;
    Capbdi = Mfactor * Capbd_swg ;
end else begin //backward compatible:
    Ibsi = 0.0 ;
    Ibdi = 0.0 ;
    Qbs = Mfactor * (Qbs_btm + Qbs_sws + Qbs_swg) ;
    Qbd = Mfactor * (Qbd_btm + Qbd_sws + Qbd_swg) ;
    Capbs = Mfactor * (Capbs_btm + Capbs_sws + Capbs_swg) ;
    Capbd = Mfactor * (Capbd_btm + Capbd_sws + Capbd_swg) ;
    Qbsi = 0.0 ;
    Qbdi = 0.0 ;
    Capbsi = 0.0 ;
    Capbdi = 0.0 ;
end

//  End of HSMHVevalDio //
