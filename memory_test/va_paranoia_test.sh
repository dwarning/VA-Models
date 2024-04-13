#!/bin/bash

# Copyright 2020 The ngspice team
# Authors: Jim Monte, Holger Vogt, Dietmar Warning
# License: New BSD

if test "$1" = "?"; then
    echo "VA ngspice \"paranoia\" test suite"
    echo "Format: $0 [ngspice executable]"
    echo "The ngspice executable must be independent of the current directory."
    exit 1
fi

SECONDS=0

NGSPICE="$1"
NGSPICE="${NGSPICE:-ngspice}"
VALGRIND="valgrind --leak-check=full --suppressions=$(pwd)/ignore_shared_libs.supp"

# The following three take much time. They are started in the background and may be skipped after being run once.

cd ../examples/ASMHEMT
cp nfet_id_vd_vg.sp     nfet_id_vd_vg.spv
cp nfet_id_vd_vg_gummel.sp nfet_id_vd_vg_gummel.spv
sed -i 's/.endc/quit\n.endc/g' nfet_id_vd_vg.spv
sed -i 's/.endc/quit\n.endc/g' nfet_id_vd_vg_gummel.spv
$VALGRIND --log-file=../../memory_test/asmhemt_nfet_id_vd_vg.vlog        $NGSPICE nfet_id_vd_vg.spv
$VALGRIND --log-file=../../memory_test/asmhemt_nfet_id_vd_vg_gummel.vlog $NGSPICE nfet_id_vd_vg_gummel.spv
rm *.spv
cd ../../memory_test

cd ../examples/ngspice/bsim6
cp ringosc_17.sp         ringosc_17.spv
sed -i 's/10us/1us/g'    ringosc_17.spv
cp inverter_transient.sp inverter_transient.spv
cp inv_dc.sp             inv_dc.spv
cp pmos_id_vd_vg.sp      pmos_id_vd_vg.spv
cp nmos_id_vd_vg.sp      nmos_id_vd_vg.spv
cp pmos_id_vd_vg_gummel.sp        pmos_id_vd_vg_gummel.spv
cp nmos_id_vd_vg_gummel.sp        nmos_id_vd_vg_gummel.spv
sed -i 's/.endc/quit\n.endc/g' ringosc_17.spv
sed -i 's/.endc/quit\n.endc/g' inverter_transient.spv
sed -i 's/.endc/quit\n.endc/g' inv_dc.spv
sed -i 's/.endc/quit\n.endc/g' pmos_id_vd_vg.spv
sed -i 's/.endc/quit\n.endc/g' nmos_id_vd_vg.spv
sed -i 's/.endc/quit\n.endc/g' pmos_id_vd_vg_gummel.spv
sed -i 's/.endc/quit\n.endc/g' nmos_id_vd_vg_gummel.spv
$VALGRIND --log-file=../../../memory_test/bsim6_ringosc_17.vlog         $NGSPICE ringosc_17.spv
$VALGRIND --log-file=../../../memory_test/bsim6_inverter_transient.vlog $NGSPICE inverter_transient.spv
$VALGRIND --log-file=../../../memory_test/bsim6_inv_dc.vlog             $NGSPICE inv_dc.spv
$VALGRIND --log-file=../../../memory_test/bsim6_id_pmos.vlog            $NGSPICE pmos_id_vd_vg.spv
$VALGRIND --log-file=../../../memory_test/bsim6_id_nmos.vlog            $NGSPICE nmos_id_vd_vg.spv
$VALGRIND --log-file=../../../memory_test/bsim6_pmos_id_vd_vg_gummel.vlog        $NGSPICE pmos_id_vd_vg_gummel.spv
$VALGRIND --log-file=../../../memory_test/bsim6_nmos_id_vd_vg_gummel.vlog        $NGSPICE nmos_id_vd_vg_gummel.spv
rm *.spv
cd ../../../memory_test

cd ../examples/ngspice/bsimbulk
cp ring_osc.sp             ring_osc.spv
sed -i 's/10us/1us/g'      ring_osc.spv
cp inv_tran.sp             inv_tran.spv
cp inv_dc.sp               inv_dc.spv
cp nmos_id_vd_vg.sp              nmos_id_vd_vg.spv
cp nmos_pmos_id_vd_vg_temp.sp            nmos_pmos_id_vd_vg_temp.spv
cp pmos_id_vd_vg_gummel.sp          pmos_id_vd_vg_gummel.spv
cp nmos_id_vd_vg_gummel.sp          nmos_id_vd_vg_gummel.spv
cp bsimbulk_ro.sp          bsimbulk_ro.spv
cp bsimbulk_inverter.sp    simbulk_inverter.spv
cp c7552_ann_bsimbulk.net  c7552_ann_bsimbulk.spv
sed -i 's/.endc/quit\n.endc/g' ring_osc.spv
sed -i 's/.endc/quit\n.endc/g' inv_tran.spv
sed -i 's/.endc/quit\n.endc/g' inv_dc.spv
sed -i 's/.endc/quit\n.endc/g' nmos_id_vd_vg.spv
sed -i 's/.endc/quit\n.endc/g' nmos_pmos_id_vd_vg_temp.spv
sed -i 's/.endc/quit\n.endc/g' pmos_id_vd_vg_gummel.spv
sed -i 's/.endc/quit\n.endc/g' nmos_id_vd_vg_gummel.spv
sed -i 's/.endc/quit\n.endc/g' bsimbulk_ro.spv
sed -i 's/.endc/quit\n.endc/g' simbulk_inverter.spv
sed -i 's/.endc/quit\n.endc/g' c7552_ann_bsimbulk.spv
sed -i 's/1ns/0.1ns/g' c7552_ann_bsimbulk.spv
$VALGRIND --log-file=../../../memory_test/bsimbulk_ring_osc.vlog           $NGSPICE ring_osc.spv
$VALGRIND --log-file=../../../memory_test/bsimbulk_inv_tran.vlog           $NGSPICE inv_tran.spv
$VALGRIND --log-file=../../../memory_test/bsimbulk_inv_dc.vlog             $NGSPICE inv_dc.spv
$VALGRIND --log-file=../../../memory_test/bsimbulk_nmos_id_vd_vg.vlog            $NGSPICE nmos_id_vd_vg.spv
$VALGRIND --log-file=../../../memory_test/bsimbulk_nmos_pmos_id_vd_vg_temp.vlog          $NGSPICE nmos_pmos_id_vd_vg_temp.spv
$VALGRIND --log-file=../../../memory_test/bsimbulk_pmos_id_vd_vg_gummel.vlog        $NGSPICE pmos_id_vd_vg_gummel.spv
$VALGRIND --log-file=../../../memory_test/bsimbulk_nmos_id_vd_vg_gummel.vlog        $NGSPICE nmos_id_vd_vg_gummel.spv
$VALGRIND --log-file=../../../memory_test/bsimbulk_bsimbulk_ro.vlog        $NGSPICE bsimbulk_ro.spv
$VALGRIND --log-file=../../../memory_test/bsimbulk_simbulk_inverter.vlog   $NGSPICE simbulk_inverter.spv
$VALGRIND --log-file=../../../memory_test/bsimbulk_c7552_ann_bsimbulk.vlog $NGSPICE c7552_ann_bsimbulk.spv
rm *.spv
cd ../../../memory_test

cd ../examples/ngspice/bsimcmg
cp simple_inverter_dc.sp simple_inverter_dc.spv
cp ringosc_17stg.sp      ringosc_17stg.spv
cp NuV-memory_test.sp          NuV-memory_test.spv
cp inverter_transient.sp inverter_transient.spv
cp inverter_ro.sp        inverter_ro.spv
cp pmos_id_vd_vg.sp            pmos_id_vd_vg.spv
cp nmos_id_vd_vg.sp            nmos_id_vd_vg.spv
cp ac.sp                 ac.spv
sed -i 's/.endc/quit\n.endc/g' simple_inverter_dc.spv
sed -i 's/.endc/quit\n.endc/g' ringosc_17stg.spv
sed -i 's/.endc/quit\n.endc/g' NuV-memory_test.spv
sed -i 's/1.2ns/0.2ns/g' NuV-memory_test.spv
sed -i 's/.endc/quit\n.endc/g' inverter_transient.spv
sed -i 's/.endc/quit\n.endc/g' inverter_ro.spv
sed -i 's/.endc/quit\n.endc/g' pmos_id_vd_vg.spv
sed -i 's/.endc/quit\n.endc/g' nmos_id_vd_vg.spv
sed -i 's/.endc/quit\n.endc/g' ac.spv
$VALGRIND --log-file=../../../memory_test/bsimcmg_simple_inverter_dc.vlog $NGSPICE simple_inverter_dc.spv
$VALGRIND --log-file=../../../memory_test/bsimcmg_ringosc_17stg.vlog      $NGSPICE ringosc_17stg.spv
$VALGRIND --log-file=../../../memory_test/bsimcmg_NuV-memory_test.vlog           $NGSPICE NuV-memory_test.spv
$VALGRIND --log-file=../../../memory_test/bsimcmg_inverter_transient.vlog $NGSPICE inverter_transient.spv
$VALGRIND --log-file=../../../memory_test/bsimcmg_inverter_ro.vlog        $NGSPICE inverter_ro.spv
$VALGRIND --log-file=../../../memory_test/bsimcmg_pmos_id_vd_vg.vlog            $NGSPICE pmos_id_vd_vg.spv
$VALGRIND --log-file=../../../memory_test/bsimcmg_nmos_id_vd_vg.vlog            $NGSPICE nmos_id_vd_vg.spv
$VALGRIND --log-file=../../../memory_test/bsimcmg_ac.vlog                 $NGSPICE ac.spv
rm *.spv
cd ../../../memory_test

cd ../examples/ngspice/bsimimg
cp pmos_id_vd_vg.sp            pmos_id_vd_vg.spv
cp nmos_id_vd_vg.sp            nmos_id_vd_vg.spv
sed -i 's/.endc/quit\n.endc/g' pmos_id_vd_vg.spv
sed -i 's/.endc/quit\n.endc/g' nmos_id_vd_vg.spv
$VALGRIND --log-file=../../../memory_test/bsimimg_pmos_id_vd_vg.vlog            $NGSPICE pmos_id_vd_vg.spv
$VALGRIND --log-file=../../../memory_test/bsimimg_nmos_id_vd_vg.vlog            $NGSPICE nmos_id_vd_vg.spv
rm *.spv
cd ../../../memory_test

cd ../examples/ngspice/bsimsoi
cp ring_osc.sp           ring_osc.spv
cp inverter_tr.sp        inverter_tr.spv
cp inverter_dc.sp        inverter_dc.spv
cp pmos_id_vd_vg.sp            pmos_id_vd_vg.spv
cp nmos_id_vd_vg.sp            nmos_id_vd_vg.spv
sed -i 's/.endc/quit\n.endc/g' ring_osc.spv
sed -i 's/.endc/quit\n.endc/g' inverter_tr.spv
sed -i 's/.endc/quit\n.endc/g' inverter_dc.spv
sed -i 's/.endc/quit\n.endc/g' pmos_id_vd_vg.spv
sed -i 's/.endc/quit\n.endc/g' nmos_id_vd_vg.spv
$VALGRIND --log-file=../../../memory_test/bsimsoi_ring_osc.vlog           $NGSPICE ring_osc.spv
$VALGRIND --log-file=../../../memory_test/bsimsoi_inverter_tr.vlog        $NGSPICE inverter_tr.spv
$VALGRIND --log-file=../../../memory_test/bsimsoi_inverter_dc.vlog        $NGSPICE inverter_dc.spv
$VALGRIND --log-file=../../../memory_test/bsimsoi_pmos_id_vd_vg.vlog            $NGSPICE pmos_id_vd_vg.spv
$VALGRIND --log-file=../../../memory_test/bsimsoi_nmos_id_vd_vg.vlog            $NGSPICE nmos_id_vd_vg.spv
rm *.spv
cd ../../../memory_test

cd ../examples/ngspice/diode_cmc
cp id_trr_vp_tran.sp           id_trr_vp_tran.spv
cp id_vd_temp.sp           id_vd_temp.spv
sed -i 's/.endc/quit\n.endc/g' id_trr_vp_tran.spv
sed -i 's/.endc/quit\n.endc/g' id_vd_temp.spv
$VALGRIND --log-file=../../../memory_test/diode_cmc_id_trr_vp_tran.vlog       $NGSPICE id_trr_vp_tran.spv
$VALGRIND --log-file=../../../memory_test/diode_cmc_id_vd_temp.vlog       $NGSPICE id_vd_temp.spv
rm *.spv
cd ../../../memory_test

cd ../examples/ngspice/ekv
cp oneshot.sp    oneshot.spv
cp mosamp2.sp    mosamp2.spv
cp inverter.sp   inverter.spv
cp pmos_id_vd_vg.sp    pmos_id_vd_vg.spv
cp nmos_id_vd_vg.sp    nmos_id_vd_vg.spv
cp dio_test.sp   dio_test.spv
cp comparator.sp comparator.spv
sed -i 's/.endc/quit\n.endc/g' oneshot.spv
sed -i 's/.endc/quit\n.endc/g' mosamp2.spv
sed -i 's/.endc/quit\n.endc/g' inverter.spv
sed -i 's/.endc/quit\n.endc/g' pmos_id_vd_vg.spv
sed -i 's/.endc/quit\n.endc/g' nmos_id_vd_vg.spv
sed -i 's/.endc/quit\n.endc/g' dio_test.spv
sed -i 's/.endc/quit\n.endc/g' comparator.spv
$VALGRIND --log-file=../../../memory_test/ekv_oneshot.vlog    $NGSPICE oneshot.spv
$VALGRIND --log-file=../../../memory_test/ekv_mosamp2.vlog    $NGSPICE mosamp2.spv
$VALGRIND --log-file=../../../memory_test/ekv_inverter.vlog   $NGSPICE inverter.spv
$VALGRIND --log-file=../../../memory_test/ekv_pmos_id_vd_vg.vlog    $NGSPICE pmos_id_vd_vg.spv
$VALGRIND --log-file=../../../memory_test/ekv_nmos_id_vd_vg.vlog    $NGSPICE nmos_id_vd_vg.spv
$VALGRIND --log-file=../../../memory_test/ekv_dio_test.vlog   $NGSPICE dio_test.spv
$VALGRIND --log-file=../../../memory_test/ekv_comparator.vlog $NGSPICE comparator.spv
rm *.spv
cd ../../../memory_test

cd ../examples/EPFL-HEMT
cp nfet_id_vd_vg.sp           nfet_id_vd_vg.spv
sed -i 's/.endc/quit\n.endc/g' nfet_id_vd_vg.spv
$VALGRIND --log-file=../../memory_test/EPFL-HEMT_nfet_id_vd_vg.vlog     $NGSPICE nfet_id_vd_vg.spv
rm *.spv
cd ../../memory_test

cd ../examples/fbh_hbt
cp hbt_ic_vd.sp           hbt_ic_vd.spv
cp hbt_ic_ib_vb.sp           hbt_ic_ib_vb.spv
sed -i 's/.endc/quit\n.endc/g' hbt_ic_vd.spv
sed -i 's/.endc/quit\n.endc/g' hbt_ic_ib_vb.spv
$VALGRIND --log-file=../../memory_test/fbh_hbt_hbt_ic_vd.vlog       $NGSPICE hbt_ic_vd.spv
$VALGRIND --log-file=../../memory_test/fbh_hbt_hbt_ic_ib_vb.vlog       $NGSPICE hbt_ic_ib_vb.spv
rm *.spv
cd ../../memory_test

cd ../examples/ngspice/hicum0
cp npn_ic_vc_ib.sp        npn_ic_vc_ib.spv
cp npn_ic_ib_vb.sp        npn_ic_ib_vb.spv
cp ECL-RO.sp         ECL-RO.spv
cp ECL-RO-5.sp       ECL-RO-5.spv
cp DFF_Y_ECL_HICUM.sp DFF_Y_ECL_HICUM.spv
cp npn_noise.sp     npn_noise.spv
sed -i 's/.endc/quit\n.endc/g' npn_ic_vc_ib.spv
sed -i 's/.endc/quit\n.endc/g' npn_ic_ib_vb.spv
sed -i 's/.endc/quit\n.endc/g' ECL-RO.spv
sed -i 's/100u/1u/g' ECL-RO.spv
sed -i 's/.endc/quit\n.endc/g' ECL-RO-5.spv
sed -i 's/.endc/quit\n.endc/g' DFF_Y_ECL_HICUM.spv
sed -i 's/.endc/quit\n.endc/g' npn_noise.spv
$VALGRIND --log-file=../../../memory_test/hicum0_npn_ic_vc_ib.vlog         $NGSPICE npn_ic_vc_ib.spv
$VALGRIND --log-file=../../../memory_test/hicum0_npn_ic_ib_vb.vlog         $NGSPICE npn_ic_ib_vb.spv
$VALGRIND --log-file=../../../memory_test/hicum0_ECL-RO.vlog           $NGSPICE ECL-RO.spv
$VALGRIND --log-file=../../../memory_test/hicum0_ECL-RO-5.vlog         $NGSPICE ECL-RO-5.spv
$VALGRIND --log-file=../../../memory_test/hicum0_DFF_Y_ECL_HICUM.vlog  $NGSPICE DFF_Y_ECL_HICUM.spv
$VALGRIND --log-file=../../../memory_test/hicum0_npn_noise.vlog      $NGSPICE npn_noise.spv
rm *.spv
cd ../../../memory_test

cd ../examples/ngspice/hicum2
cp npn_amp_tran.sp    npn_amp_tran.spv
cp npn_ic_vc_ib.sp     npn_ic_vc_ib.spv
cp npn_ic_ib_vb.sp     npn_ic_ib_vb.spv
cp npn_ic_ib_vb_inv.sp npn_ic_ib_vb_inv.spv
cp npn_gain_ic.sp    npn_gain_ic.spv
cp npn_ft_ic.sp      npn_ft_ic.spv
sed -i 's/.endc/quit\n.endc/g' npn_amp_tran.spv
sed -i 's/.endc/quit\n.endc/g' npn_ic_vc_ib.spv
sed -i 's/.endc/quit\n.endc/g' npn_ic_ib_vb.spv
sed -i 's/.endc/quit\n.endc/g' npn_ic_ib_vb_inv.spv
sed -i 's/.endc/quit\n.endc/g' npn_gain_ic.spv
sed -i 's/.endc/quit\n.endc/g' npn_ft_ic.spv
$VALGRIND --log-file=../../../memory_test/hicum2_npn_amp_tran.vlog    $NGSPICE npn_amp_tran.spv
$VALGRIND --log-file=../../../memory_test/hicum2_npn_ic_vc_ib.vlog     $NGSPICE npn_ic_vc_ib.spv
$VALGRIND --log-file=../../../memory_test/hicum2_npn_ic_ib_vb.vlog     $NGSPICE npn_ic_ib_vb.spv
$VALGRIND --log-file=../../../memory_test/hicum2_npn_ic_ib_vb_inv.vlog $NGSPICE npn_ic_ib_vb_inv.spv
$VALGRIND --log-file=../../../memory_test/hicum2_npn_gain_ic.vlog    $NGSPICE npn_gain_ic.spv
$VALGRIND --log-file=../../../memory_test/hicum2_npn_ft_ic.vlog      $NGSPICE npn_ft_ic.spv
rm *.spv
cd ../../../memory_test

cd ../examples/hisim2
cp HiSIM2_TRTest_Netlist.sp HiSIM2_TRTest_Netlist.spv
cp HiSIM2_DCTest_Netlist.sp HiSIM2_DCTest_Netlist.spv
cp HiSIM2_ACTest_Netlist.sp HiSIM2_ACTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM2_TRTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM2_DCTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM2_ACTest_Netlist.spv
$VALGRIND --log-file=../../memory_test/HiSIM2_TRTest_Netlist.vlog $NGSPICE HiSIM2_TRTest_Netlist.spv
$VALGRIND --log-file=../../memory_test/HiSIM2_DCTest_Netlist.vlog $NGSPICE HiSIM2_DCTest_Netlist.spv
$VALGRIND --log-file=../../memory_test/HiSIM2_ACTest_Netlist.vlog $NGSPICE HiSIM2_ACTest_Netlist.spv
rm *.spv
cd ../../memory_test

cd ../examples/hisimhv
cp HiSIM_HV_TRTest_Netlist.sp HiSIM_HV_TRTest_Netlist.spv
cp HiSIM_HV_DCTest_Netlist.sp HiSIM_HV_DCTest_Netlist.spv
cp HiSIM_HV_ACTest_Netlist.sp HiSIM_HV_ACTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM_HV_TRTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM_HV_DCTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM_HV_ACTest_Netlist.spv
$VALGRIND --log-file=../../memory_test/HiSIM_HV_TRTest_Netlist.vlog $NGSPICE HiSIM_HV_TRTest_Netlist.spv
$VALGRIND --log-file=../../memory_test/HiSIM_HV_DCTest_Netlist.vlog $NGSPICE HiSIM_HV_DCTest_Netlist.spv
$VALGRIND --log-file=../../memory_test/HiSIM_HV_ACTest_Netlist.vlog $NGSPICE HiSIM_HV_ACTest_Netlist.spv
rm *.spv
cd ../../memory_test

cd ../examples/hisimsoi
cp HiSIM_SOI_TRTest_Netlist.sp HiSIM_SOI_TRTest_Netlist.spv
cp HiSIM_SOI_DCTest_Netlist.sp HiSIM_SOI_DCTest_Netlist.spv
cp HiSIM_SOI_ACTest_Netlist.sp HiSIM_SOI_ACTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM_SOI_TRTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM_SOI_DCTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM_SOI_ACTest_Netlist.spv
$VALGRIND --log-file=../../memory_test/HiSIM_SOI_TRTest_Netlist.vlog $NGSPICE HiSIM_SOI_TRTest_Netlist.spv
$VALGRIND --log-file=../../memory_test/HiSIM_SOI_DCTest_Netlist.vlog $NGSPICE HiSIM_SOI_DCTest_Netlist.spv
$VALGRIND --log-file=../../memory_test/HiSIM_SOI_ACTest_Netlist.vlog $NGSPICE HiSIM_SOI_ACTest_Netlist.spv
rm *.spv
cd ../../memory_test

cd ../examples/hisimsotb
cp HiSIM_SOTB_TRTest_Netlist.sp HiSIM_SOTB_TRTest_Netlist.spv
cp HiSIM_SOTB_DCTest_Netlist.sp HiSIM_SOTB_DCTest_Netlist.spv
cp HiSIM_SOTB_ACTest_Netlist.sp HiSIM_SOTB_ACTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM_SOTB_TRTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM_SOTB_DCTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM_SOTB_ACTest_Netlist.spv
$VALGRIND --log-file=../../memory_test/HiSIM_SOTB_TRTest_Netlist.vlog $NGSPICE HiSIM_SOTB_TRTest_Netlist.spv
$VALGRIND --log-file=../../memory_test/HiSIM_SOTB_DCTest_Netlist.vlog $NGSPICE HiSIM_SOTB_DCTest_Netlist.spv
$VALGRIND --log-file=../../memory_test/HiSIM_SOTB_ACTest_Netlist.vlog $NGSPICE HiSIM_SOTB_ACTest_Netlist.spv
rm *.spv
cd ../../memory_test

cd ../examples/ngspice/L-UTSOI
cp pmos_id_vd_vg_vb.sp            pmos_id_vd_vg_vb.spv
cp nmos_id_vd_vg_vb.sp            nmos_id_vd_vg_vb.spv
sed -i 's/.endc/quit\n.endc/g' pmos_id_vd_vg_vb.spv
sed -i 's/.endc/quit\n.endc/g' nmos_id_vd_vg_vb.spv
$VALGRIND --log-file=../../../memory_test/L-UTSOI_pmos_id_vd_vg_vb.vlog            $NGSPICE pmos_id_vd_vg_vb.spv
$VALGRIND --log-file=../../../memory_test/L-UTSOI_nmos_id_vd_vg_vb.vlog            $NGSPICE nmos_id_vd_vg_vb.spv
rm *.spv
cd ../../../memory_test

cd ../examples/ngspice/mextram
cp npn_ic_vc_ib.sp            npn_ic_vc_ib.spv
cp npn_ic_ib_is_vb.sp            npn_ic_ib_is_vb.spv
cp meclgate.sp          meclgate.spv
cp npn_noise.sp          npn_noise.spv
sed -i 's/.endc/quit\n.endc/g' npn_ic_vc_ib.spv
sed -i 's/.endc/quit\n.endc/g' npn_ic_ib_is_vb.spv
sed -i 's/.endc/quit\n.endc/g' meclgate.spv
sed -i 's/.endc/quit\n.endc/g' npn_noise.spv
$VALGRIND --log-file=../../../memory_test/mextram_npn_ic_vc_ib.vlog            $NGSPICE npn_ic_vc_ib.spv
$VALGRIND --log-file=../../../memory_test/mextram_npn_ic_ib_is_vb.vlog            $NGSPICE npn_ic_ib_is_vb.spv
$VALGRIND --log-file=../../../memory_test/mextram_meclgate.vlog           $NGSPICE meclgate.spv
$VALGRIND --log-file=../../../memory_test/mextram_npn_noise.vlog           $NGSPICE npn_noise.spv
rm *.spv
cd ../../../memory_test

cd ../examples/ngspice/MOSVAR
cp mosvar_c_v.sp            mosvar_c_v.spv
sed -i 's/.endc/quit\n.endc/g' mosvar_c_v.spv
$VALGRIND --log-file=../../../memory_test/MOSVAR_mosvar_c_v.vlog        $NGSPICE mosvar_c_v.spv
rm *.spv
cd ../../../memory_test

cd ../examples/mvsg
cp pfet_id_vd_vg.sp            pfet_id_vd_vg.spv
cp nfet_id_vd_vg.sp            nfet_id_vd_vg.spv
cp nfet_id_vd_vg_gummel.sp        nfet_id_vd_vg_gummel.spv
sed -i 's/.endc/quit\n.endc/g' pfet_id_vd_vg.spv
sed -i 's/.endc/quit\n.endc/g' nfet_id_vd_vg.spv
sed -i 's/.endc/quit\n.endc/g' nfet_id_vd_vg_gummel.spv
$VALGRIND --log-file=../../memory_test/mvsg_pfet_id_vd_vg.vlog            $NGSPICE pfet_id_vd_vg.spv
$VALGRIND --log-file=../../memory_test/mvsg_nfet_id_vd_vg.vlog            $NGSPICE nfet_id_vd_vg.spv
$VALGRIND --log-file=../../memory_test/mvsg_nfet_id_vd_vg_gummel.vlog        $NGSPICE nfet_id_vd_vg_gummel.spv
rm *.spv
cd ../../memory_test

cd ../examples/psp102
cp pmos_id_vd_vg_vb.sp            pmos_id_vd_vg_vb.spv
cp nmos_id_vd_vg_vb.sp            nmos_id_vd_vg_vb.spv
sed -i 's/.endc/quit\n.endc/g' pmos_id_vd_vg_vb.spv
sed -i 's/.endc/quit\n.endc/g' nmos_id_vd_vg_vb.spv
$VALGRIND --log-file=../../memory_test/psp102_pmos_id_vd_vg_vb.vlog            $NGSPICE pmos_id_vd_vg_vb.spv
$VALGRIND --log-file=../../memory_test/psp102_nmos_id_vd_vg_vb.vlog            $NGSPICE nmos_id_vd_vg_vb.spv
rm *.spv
cd ../../memory_test

cd ../examples/ngspice/psp103
cp nmos_id_vg_vb.sp    nmos_id_vg_vb.spv
cp psp_ro.sp          psp_ro.spv
cp pmos_id_vd_vg_vb.sp pmos_id_vd_vg_vb.spv
cp nmos_id_vd_vg_vb.sp nmos_id_vd_vg_vb.spv
cp psp_inverter.sp    psp_inverter.spv
cp nmos_pmos_id_vd_vg_temp_PSP.sp   nmos_pmos_id_vd_vg_temp_PSP.spv
cp c7552_ann_psp.net  c7552_ann_psp.spv
sed -i 's/.endc/quit\n.endc/g' nmos_id_vg_vb.spv
sed -i 's/.endc/quit\n.endc/g' psp_ro.spv
sed -i 's/.endc/quit\n.endc/g' pmos_id_vd_vg_vb.spv
sed -i 's/.endc/quit\n.endc/g' nmos_id_vd_vg_vb.spv
sed -i 's/.endc/quit\n.endc/g' psp_inverter.spv
sed -i 's/.endc/quit\n.endc/g' nmos_pmos_id_vd_vg_temp_PSP.spv
sed -i 's/.endc/quit\n.endc/g' c7552_ann_psp.spv
sed -i 's/15ns/0.1ns/g' c7552_ann_psp.spv
$VALGRIND --log-file=../../../memory_test/psp103_nmos_id_vg_vb.vlog    $NGSPICE nmos_id_vg_vb.spv
$VALGRIND --log-file=../../../memory_test/psp103_psp_ro.vlog          $NGSPICE psp_ro.spv
$VALGRIND --log-file=../../../memory_test/psp103_pmos_id_vd_vg_vb.vlog $NGSPICE pmos_id_vd_vg_vb.spv
$VALGRIND --log-file=../../../memory_test/psp103_nmos_id_vd_vg_vb.vlog $NGSPICE nmos_id_vd_vg_vb.spv
$VALGRIND --log-file=../../../memory_test/psp103_psp_inverter.vlog    $NGSPICE psp_inverter.spv
$VALGRIND --log-file=../../../memory_test/psp103_nmos_pmos_id_vd_vg_temp_PSP.vlog   $NGSPICE nmos_pmos_id_vd_vg_temp_PSP.spv
$VALGRIND --log-file=../../../memory_test/psp103_c7552_ann_psp.vlog   $NGSPICE c7552_ann_psp.spv
rm *.spv
cd ../../../memory_test

cd ../examples/r2_cmc
cp res_r_vr_temp.sp              res_r_vr_temp.spv
sed -i 's/.endc/quit\n.endc/g' res_r_vr_temp.spv
$VALGRIND --log-file=../../memory_test/r2_res_r_vr_temp.vlog          $NGSPICE res_r_vr_temp.spv
rm *.spv
cd ../../memory_test

cd ../examples/ngspice/r3_cmc
cp res_r_vr_temp.sp               res_r_vr_temp.spv
sed -i 's/.endc/quit\n.endc/g' res_r_vr_temp.spv
$VALGRIND --log-file=../../../memory_test/r3_res_r_vr_temp.vlog          $NGSPICE res_r_vr_temp.spv
rm *.spv
cd ../../../memory_test

cd ../examples/ngspice/vbic
cp npn_cj_vc_cb_ac.sp npn_cj_vc_cb_ac.spv
cp npn_ic_vc_ib_sfh.sp   npn_ic_vc_ib_sfh.spv
cp npn_ic_vc_ib.sp     npn_ic_vc_ib.spv
cp npn_ic_vc_ib_qs.sp  npn_ic_vc_ib_qs.spv
cp npn_ic_ib_is_vb.sp     npn_ic_ib_is_vb.spv
cp DFF_Y_ECL.sp   DFF_Y_ECL.spv
sed -i 's/.endc/quit\n.endc/g' npn_cj_vc_cb_ac.spv
sed -i 's/.endc/quit\n.endc/g' npn_ic_vc_ib_sfh.spv
sed -i 's/.endc/quit\n.endc/g' npn_ic_vc_ib.spv
sed -i 's/.endc/quit\n.endc/g' npn_ic_vc_ib_qs.spv
sed -i 's/.endc/quit\n.endc/g' npn_ic_ib_is_vb.spv
sed -i 's/.endc/quit\n.endc/g' DFF_Y_ECL.spv
$VALGRIND --log-file=../../../memory_test/vbic_npn_cj_vc_cb_ac.vlog       $NGSPICE npn_cj_vc_cb_ac.spv
$VALGRIND --log-file=../../../memory_test/vbic_npn_ic_vc_ib_sfh.vlog         $NGSPICE npn_ic_vc_ib_sfh.spv
$VALGRIND --log-file=../../../memory_test/vbic_npn_ic_vc_ib.vlog           $NGSPICE npn_ic_vc_ib.spv
$VALGRIND --log-file=../../../memory_test/vbic_npn_ic_vc_ib_qs.vlog        $NGSPICE npn_ic_vc_ib_qs.spv
$VALGRIND --log-file=../../../memory_test/vbic_npn_ic_ib_is_vb.vlog           $NGSPICE npn_ic_ib_is_vb.spv
$VALGRIND --log-file=../../../memory_test/vbic_DFF_Y_ECL.vlog         $NGSPICE DFF_Y_ECL.spv
rm *.spv
cd ../../../memory_test

# Check the results
# Find correct response: ngspice-<version> done
#NGSPICE_OK="ngspice-`$NGSPICE -v | awk '/^ngspice/ {print $6;}'` done"

#echo "*****************************************"
#echo "vlog files with errors found by valgrind:"
#grep -L "ERROR SUMMARY: 0 errors from 0 context" ./*.vlog
#echo "*****************************************"
#echo "log files with ngspice errors:"
#grep -L "$NGSPICE_OK" ./*.log
#echo "*****************************************"

ELAPSED="Elapsed: $(($SECONDS / 3600))hrs $((($SECONDS / 60) % 60))min $(($SECONDS % 60))sec"
echo
echo $ELAPSED
