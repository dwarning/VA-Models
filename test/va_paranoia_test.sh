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

cd ../code/ASMHEMT
cp id_nfet.sp     id_nfet.spv
cp gummel_nfet.sp gummel_nfet.spv
sed -i 's/.endc/quit\n.endc/g' id_nfet.spv
sed -i 's/.endc/quit\n.endc/g' gummel_nfet.spv
$VALGRIND --log-file=../../test/asmhemt_id_nfet.vlog     $NGSPICE id_nfet.spv
$VALGRIND --log-file=../../test/asmhemt_gummel_nfet.vlog $NGSPICE gummel_nfet.spv
rm *.spv
cd ../../test

cd ../code/bsim6
cp ringosc_17.sp         ringosc_17.spv
cp inverter_transient.sp inverter_transient.spv
cp inv_dc.sp             inv_dc.spv
cp id_pmos.sp            id_pmos.spv
cp id_nmos.sp            id_nmos.spv
cp gummel_pmos.sp        gummel_pmos.spv
cp gummel_nmos.sp        gummel_nmos.spv
sed -i 's/.endc/quit\n.endc/g' ringosc_17.spv
sed -i 's/.endc/quit\n.endc/g' inverter_transient.spv
sed -i 's/.endc/quit\n.endc/g' inv_dc.spv
sed -i 's/.endc/quit\n.endc/g' id_pmos.spv
sed -i 's/.endc/quit\n.endc/g' id_nmos.spv
sed -i 's/.endc/quit\n.endc/g' gummel_pmos.spv
sed -i 's/.endc/quit\n.endc/g' gummel_nmos.spv
$VALGRIND --log-file=../../test/bsim6_ringosc_17.vlog         $NGSPICE ringosc_17.spv
$VALGRIND --log-file=../../test/bsim6_inverter_transient.vlog $NGSPICE inverter_transient.spv
$VALGRIND --log-file=../../test/bsim6_inv_dc.vlog             $NGSPICE inv_dc.spv
$VALGRIND --log-file=../../test/bsim6_id_pmos.vlog            $NGSPICE id_pmos.spv
$VALGRIND --log-file=../../test/bsim6_id_nmos.vlog            $NGSPICE id_nmos.spv
$VALGRIND --log-file=../../test/bsim6_gummel_pmos.vlog        $NGSPICE gummel_pmos.spv
$VALGRIND --log-file=../../test/bsim6_gummel_nmos.vlog        $NGSPICE gummel_nmos.spv
rm *.spv
cd ../../test

cd ../code/bsimbulk
cp ring_osc.sp             ring_osc.spv
cp inv_tran.sp             inv_tran.spv
cp inv_dc.sp               inv_dc.spv
cp id_nmos.sp              id_nmos.spv
cp nmos_pmos.sp            nmos_pmos.spv
cp gummel_pmos.sp          gummel_pmos.spv
cp gummel_nmos.sp          gummel_nmos.spv
cp bsimbulk_ro.sp          bsimbulk_ro.spv
cp bsimbulk_inverter.sp    simbulk_inverter.spv
cp c7552_ann_bsimbulk.net  c7552_ann_bsimbulk.spv
sed -i 's/.endc/quit\n.endc/g' ring_osc.spv
sed -i 's/.endc/quit\n.endc/g' inv_tran.spv
sed -i 's/.endc/quit\n.endc/g' inv_dc.spv
sed -i 's/.endc/quit\n.endc/g' id_nmos.spv
sed -i 's/.endc/quit\n.endc/g' nmos_pmos.spv
sed -i 's/.endc/quit\n.endc/g' gummel_pmos.spv
sed -i 's/.endc/quit\n.endc/g' gummel_nmos.spv
sed -i 's/.endc/quit\n.endc/g' bsimbulk_ro.spv
sed -i 's/.endc/quit\n.endc/g' simbulk_inverter.spv
sed -i 's/.endc/quit\n.endc/g' c7552_ann_bsimbulk.spv
$VALGRIND --log-file=../../test/bsimbulk_ring_osc.vlog           $NGSPICE ring_osc.spv
$VALGRIND --log-file=../../test/bsimbulk_inv_tran.vlog           $NGSPICE inv_tran.spv
$VALGRIND --log-file=../../test/bsimbulk_inv_dc.vlog             $NGSPICE inv_dc.spv
$VALGRIND --log-file=../../test/bsimbulk_id_nmos.vlog            $NGSPICE id_nmos.spv
$VALGRIND --log-file=../../test/bsimbulk_nmos_pmos.vlog          $NGSPICE nmos_pmos.spv
$VALGRIND --log-file=../../test/bsimbulk_gummel_pmos.vlog        $NGSPICE gummel_pmos.spv
$VALGRIND --log-file=../../test/bsimbulk_gummel_nmos.vlog        $NGSPICE gummel_nmos.spv
$VALGRIND --log-file=../../test/bsimbulk_bsimbulk_ro.vlog        $NGSPICE bsimbulk_ro.spv
$VALGRIND --log-file=../../test/bsimbulk_simbulk_inverter.vlog   $NGSPICE simbulk_inverter.spv
$VALGRIND --log-file=../../test/bsimbulk_c7552_ann_bsimbulk.vlog $NGSPICE c7552_ann_bsimbulk.spv
rm *.spv
cd ../../test

cd ../code/bsimcmg
cp simple_inverter_dc.sp simple_inverter_dc.spv
cp ringosc_17stg.sp      ringosc_17stg.spv
cp NuV-test.sp          NuV-test.spv
cp inverter_transient.sp inverter_transient.spv
cp inverter_ro.sp        inverter_ro.spv
cp id_pmos.sp            id_pmos.spv
cp id_nmos.sp            id_nmos.spv
cp ac.sp                 ac.spv
sed -i 's/.endc/quit\n.endc/g' simple_inverter_dc.spv
sed -i 's/.endc/quit\n.endc/g' ringosc_17stg.spv
sed -i 's/.endc/quit\n.endc/g' NuV-test.spv
sed -i 's/.endc/quit\n.endc/g' inverter_transient.spv
sed -i 's/.endc/quit\n.endc/g' inverter_ro.spv
sed -i 's/.endc/quit\n.endc/g' id_pmos.spv
sed -i 's/.endc/quit\n.endc/g' id_nmos.spv
sed -i 's/.endc/quit\n.endc/g' ac.spv
$VALGRIND --log-file=../../test/bsimcmg_simple_inverter_dc.vlog $NGSPICE simple_inverter_dc.spv
$VALGRIND --log-file=../../test/bsimcmg_ringosc_17stg.vlog      $NGSPICE ringosc_17stg.spv
$VALGRIND --log-file=../../test/bsimcmg_NuV-test.vlog           $NGSPICE NuV-test.spv
$VALGRIND --log-file=../../test/bsimcmg_inverter_transient.vlog $NGSPICE inverter_transient.spv
$VALGRIND --log-file=../../test/bsimcmg_inverter_ro.vlog        $NGSPICE inverter_ro.spv
$VALGRIND --log-file=../../test/bsimcmg_id_pmos.vlog            $NGSPICE id_pmos.spv
$VALGRIND --log-file=../../test/bsimcmg_id_nmos.vlog            $NGSPICE id_nmos.spv
$VALGRIND --log-file=../../test/bsimcmg_ac.vlog                 $NGSPICE ac.spv
rm *.spv
cd ../../test

cd ../code/bsimimg
cp ids_pmos.sp            ids_pmos.spv
cp ids_nmos.sp            ids_nmos.spv
sed -i 's/.endc/quit\n.endc/g' ids_pmos.spv
sed -i 's/.endc/quit\n.endc/g' ids_nmos.spv
$VALGRIND --log-file=../../test/bsimimg_ids_pmos.vlog            $NGSPICE ids_pmos.spv
$VALGRIND --log-file=../../test/bsimimg_ids_nmos.vlog            $NGSPICE ids_nmos.spv
rm *.spv
cd ../../test

cd ../code/bsimsoi
cp ring_osc.sp           ring_osc.spv
cp inverter_tr.sp        inverter_tr.spv
cp inverter_dc.sp        inverter_dc.spv
cp id_pmos.sp            id_pmos.spv
cp id_nmos.sp            id_nmos.spv
sed -i 's/.endc/quit\n.endc/g' ring_osc.spv
sed -i 's/.endc/quit\n.endc/g' inverter_tr.spv
sed -i 's/.endc/quit\n.endc/g' inverter_dc.spv
sed -i 's/.endc/quit\n.endc/g' id_pmos.spv
sed -i 's/.endc/quit\n.endc/g' id_nmos.spv
$VALGRIND --log-file=../../test/bsimsoi_ring_osc.vlog           $NGSPICE ring_osc.spv
$VALGRIND --log-file=../../test/bsimsoi_inverter_tr.vlog        $NGSPICE inverter_tr.spv
$VALGRIND --log-file=../../test/bsimsoi_inverter_dc.vlog        $NGSPICE inverter_dc.spv
$VALGRIND --log-file=../../test/bsimsoi_id_pmos.vlog            $NGSPICE id_pmos.spv
$VALGRIND --log-file=../../test/bsimsoi_id_nmos.vlog            $NGSPICE id_nmos.spv
rm *.spv
cd ../../test

cd ../code/diode_cmc
cp dio_trr_vp.sp           dio_trr_vp.spv
cp diode_temp.sp           diode_temp.spv
sed -i 's/.endc/quit\n.endc/g' dio_trr_vp.spv
sed -i 's/.endc/quit\n.endc/g' diode_temp.spv
$VALGRIND --log-file=../../test/diode_cmc_dio_trr_vp.vlog       $NGSPICE dio_trr_vp.spv
$VALGRIND --log-file=../../test/diode_cmc_diode_temp.vlog       $NGSPICE diode_temp.spv
rm *.spv
cd ../../test

cd ../code/ekv
cp oneshot.sp    oneshot.spv
cp mosamp2.sp    mosamp2.spv
cp inverter.sp   inverter.spv
cp id_pmos.sp    id_pmos.spv
cp id_nmos.sp    id_nmos.spv
cp dio_test.sp   dio_test.spv
cp comparator.sp comparator.spv
sed -i 's/.endc/quit\n.endc/g' oneshot.spv
sed -i 's/.endc/quit\n.endc/g' mosamp2.spv
sed -i 's/.endc/quit\n.endc/g' inverter.spv
sed -i 's/.endc/quit\n.endc/g' id_pmos.spv
sed -i 's/.endc/quit\n.endc/g' id_nmos.spv
sed -i 's/.endc/quit\n.endc/g' dio_test.spv
sed -i 's/.endc/quit\n.endc/g' comparator.spv
$VALGRIND --log-file=../../test/ekv_oneshot.vlog    $NGSPICE oneshot.spv
$VALGRIND --log-file=../../test/ekv_mosamp2.vlog    $NGSPICE mosamp2.spv
$VALGRIND --log-file=../../test/ekv_inverter.vlog   $NGSPICE inverter.spv
$VALGRIND --log-file=../../test/ekv_id_pmos.vlog    $NGSPICE id_pmos.spv
$VALGRIND --log-file=../../test/ekv_id_nmos.vlog    $NGSPICE id_nmos.spv
$VALGRIND --log-file=../../test/ekv_dio_test.vlog   $NGSPICE dio_test.spv
$VALGRIND --log-file=../../test/ekv_comparator.vlog $NGSPICE comparator.spv
rm *.spv
cd ../../test

cd ../code/EPFL-HEMT
cp id_nfet.sp           id_nfet.spv
sed -i 's/.endc/quit\n.endc/g' id_nfet.spv
$VALGRIND --log-file=../../test/EPFL-HEMT_id_nfet.vlog     $NGSPICE id_nfet.spv
rm *.spv
cd ../../test

cd ../code/fbh_hbt
cp hbt_out.sp           hbt_out.spv
cp hbt_gum.sp           hbt_gum.spv
sed -i 's/.endc/quit\n.endc/g' hbt_out.spv
sed -i 's/.endc/quit\n.endc/g' hbt_gum.spv
$VALGRIND --log-file=../../test/fbh_hbt_hbt_out.vlog       $NGSPICE hbt_out.spv
$VALGRIND --log-file=../../test/fbh_hbt_hbt_gum.vlog       $NGSPICE hbt_gum.spv
rm *.spv
cd ../../test

cd ../code/hicum0
cp hic0_out.sp        hic0_out.spv
cp hic0_gum.sp        hic0_gum.spv
cp ECL-RO.sp         ECL-RO.spv
cp ECL-RO-5.sp       ECL-RO-5.spv
cp DFF_Y_ECL_HICUM.sp DFF_Y_ECL_HICUM.spv
cp bip_subsmod.sp     bip_subsmod.spv
sed -i 's/.endc/quit\n.endc/g' hic0_out.spv
sed -i 's/.endc/quit\n.endc/g' hic0_gum.spv
sed -i 's/.endc/quit\n.endc/g' ECL-RO.spv
sed -i 's/.endc/quit\n.endc/g' ECL-RO-5.spv
sed -i 's/.endc/quit\n.endc/g' DFF_Y_ECL_HICUM.spv
sed -i 's/.endc/quit\n.endc/g' bip_subsmod.spv
$VALGRIND --log-file=../../test/hicum0_hic0_out.vlog         $NGSPICE hic0_out.spv
$VALGRIND --log-file=../../test/hicum0_hic0_gum.vlog         $NGSPICE hic0_gum.spv
$VALGRIND --log-file=../../test/hicum0_ECL-RO.vlog           $NGSPICE ECL-RO.spv
$VALGRIND --log-file=../../test/hicum0_ECL-RO-5.vlog         $NGSPICE ECL-RO-5.spv
$VALGRIND --log-file=../../test/hicum0_DFF_Y_ECL_HICUM.vlog  $NGSPICE DFF_Y_ECL_HICUM.spv
$VALGRIND --log-file=../../test/hicum0_bip_subsmod.vlog      $NGSPICE bip_subsmod.spv
rm *.spv
cd ../../test

cd ../code/hicum2
cp hic2_tran.sp    hic2_tran.spv
cp hic2_out.sp     hic2_out.spv
cp hic2_gum.sp     hic2_gum.spv
cp hic2_gum_inv.sp hic2_gum_inv.spv
cp hic2_gain.sp    hic2_gain.spv
cp hic2_ft.sp      hic2_ft.spv
sed -i 's/.endc/quit\n.endc/g' hic2_tran.spv
sed -i 's/.endc/quit\n.endc/g' hic2_out.spv
sed -i 's/.endc/quit\n.endc/g' hic2_gum.spv
sed -i 's/.endc/quit\n.endc/g' hic2_gum_inv.spv
sed -i 's/.endc/quit\n.endc/g' hic2_gain.spv
sed -i 's/.endc/quit\n.endc/g' hic2_ft.spv
$VALGRIND --log-file=../../test/hicum2_hic2_tran.vlog    $NGSPICE hic2_tran.spv
$VALGRIND --log-file=../../test/hicum2_hic2_out.vlog     $NGSPICE hic2_out.spv
$VALGRIND --log-file=../../test/hicum2_hic2_gum.vlog     $NGSPICE hic2_gum.spv
$VALGRIND --log-file=../../test/hicum2_hic2_gum_inv.vlog $NGSPICE hic2_gum_inv.spv
$VALGRIND --log-file=../../test/hicum2_hic2_gain.vlog    $NGSPICE hic2_gain.spv
$VALGRIND --log-file=../../test/hicum2_hic2_ft.vlog      $NGSPICE hic2_ft.spv
rm *.spv
cd ../../test

cd ../code/hisim2
cp HiSIM2_TRTest_Netlist.sp HiSIM2_TRTest_Netlist.spv
cp HiSIM2_DCTest_Netlist.sp HiSIM2_DCTest_Netlist.spv
cp HiSIM2_ACTest_Netlist.sp HiSIM2_ACTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM2_TRTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM2_DCTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM2_ACTest_Netlist.spv
$VALGRIND --log-file=../../test/HiSIM2_TRTest_Netlist.vlog $NGSPICE HiSIM2_TRTest_Netlist.spv
$VALGRIND --log-file=../../test/HiSIM2_DCTest_Netlist.vlog $NGSPICE HiSIM2_DCTest_Netlist.spv
$VALGRIND --log-file=../../test/HiSIM2_ACTest_Netlist.vlog $NGSPICE HiSIM2_ACTest_Netlist.spv
rm *.spv
cd ../../test

cd ../code/hisimhv
cp HiSIM_HV_TRTest_Netlist.sp HiSIM_HV_TRTest_Netlist.spv
cp HiSIM_HV_DCTest_Netlist.sp HiSIM_HV_DCTest_Netlist.spv
cp HiSIM_HV_ACTest_Netlist.sp HiSIM_HV_ACTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM_HV_TRTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM_HV_DCTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM_HV_ACTest_Netlist.spv
$VALGRIND --log-file=../../test/HiSIM_HV_TRTest_Netlist.vlog $NGSPICE HiSIM_HV_TRTest_Netlist.spv
$VALGRIND --log-file=../../test/HiSIM_HV_DCTest_Netlist.vlog $NGSPICE HiSIM_HV_DCTest_Netlist.spv
$VALGRIND --log-file=../../test/HiSIM_HV_ACTest_Netlist.vlog $NGSPICE HiSIM_HV_ACTest_Netlist.spv
rm *.spv
cd ../../test

cd ../code/hisimsoi
cp HiSIM_SOI_TRTest_Netlist.sp HiSIM_SOI_TRTest_Netlist.spv
cp HiSIM_SOI_DCTest_Netlist.sp HiSIM_SOI_DCTest_Netlist.spv
cp HiSIM_SOI_ACTest_Netlist.sp HiSIM_SOI_ACTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM_SOI_TRTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM_SOI_DCTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM_SOI_ACTest_Netlist.spv
$VALGRIND --log-file=../../test/HiSIM_SOI_TRTest_Netlist.vlog $NGSPICE HiSIM_SOI_TRTest_Netlist.spv
$VALGRIND --log-file=../../test/HiSIM_SOI_DCTest_Netlist.vlog $NGSPICE HiSIM_SOI_DCTest_Netlist.spv
$VALGRIND --log-file=../../test/HiSIM_SOI_ACTest_Netlist.vlog $NGSPICE HiSIM_SOI_ACTest_Netlist.spv
rm *.spv
cd ../../test

cd ../code/hisimsotb
cp HiSIM_SOTB_TRTest_Netlist.sp HiSIM_SOTB_TRTest_Netlist.spv
cp HiSIM_SOTB_DCTest_Netlist.sp HiSIM_SOTB_DCTest_Netlist.spv
cp HiSIM_SOTB_ACTest_Netlist.sp HiSIM_SOTB_ACTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM_SOTB_TRTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM_SOTB_DCTest_Netlist.spv
sed -i 's/.endc/quit\n.endc/g' HiSIM_SOTB_ACTest_Netlist.spv
$VALGRIND --log-file=../../test/HiSIM_SOTB_TRTest_Netlist.vlog $NGSPICE HiSIM_SOTB_TRTest_Netlist.spv
$VALGRIND --log-file=../../test/HiSIM_SOTB_DCTest_Netlist.vlog $NGSPICE HiSIM_SOTB_DCTest_Netlist.spv
$VALGRIND --log-file=../../test/HiSIM_SOTB_ACTest_Netlist.vlog $NGSPICE HiSIM_SOTB_ACTest_Netlist.spv
rm *.spv
cd ../../test

cd ../code/L-UTSOI
cp id_pmos.sp            id_pmos.spv
cp id_nmos.sp            id_nmos.spv
sed -i 's/.endc/quit\n.endc/g' id_pmos.spv
sed -i 's/.endc/quit\n.endc/g' id_nmos.spv
$VALGRIND --log-file=../../test/L-UTSOI_id_pmos.vlog            $NGSPICE id_pmos.spv
$VALGRIND --log-file=../../test/L-UTSOI_id_nmos.vlog            $NGSPICE id_nmos.spv
rm *.spv
cd ../../test

cd ../code/mextram
cp mex_out.sp            mex_out.spv
cp mex_gum.sp            mex_gum.spv
cp meclgate.sp          meclgate.spv
sed -i 's/.endc/quit\n.endc/g' mex_out.spv
sed -i 's/.endc/quit\n.endc/g' mex_gum.spv
sed -i 's/.endc/quit\n.endc/g' meclgate.spv
$VALGRIND --log-file=../../test/mextram_mex_out.vlog            $NGSPICE mex_out.spv
$VALGRIND --log-file=../../test/mextram_mex_gum.vlog            $NGSPICE mex_gum.spv
$VALGRIND --log-file=../../test/mextram_meclgate.vlog           $NGSPICE meclgate.spv
rm *.spv
cd ../../test

cd ../code/MOSVAR
cp test_mosvar.sp            test_mosvar.spv
sed -i 's/.endc/quit\n.endc/g' test_mosvar.spv
$VALGRIND --log-file=../../test/MOSVAR_test_mosvar.vlog        $NGSPICE test_mosvar.spv
rm *.spv
cd ../../test

cd ../code/mvsg
cp id_pfet.sp            id_pfet.spv
cp id_nfet.sp            id_nfet.spv
cp gummel_nfet.sp        gummel_nfet.spv
sed -i 's/.endc/quit\n.endc/g' id_pfet.spv
sed -i 's/.endc/quit\n.endc/g' id_nfet.spv
sed -i 's/.endc/quit\n.endc/g' gummel_nfet.spv
$VALGRIND --log-file=../../test/mvsg_id_pfet.vlog            $NGSPICE id_pfet.spv
$VALGRIND --log-file=../../test/mvsg_id_nfet.vlog            $NGSPICE id_nfet.spv
$VALGRIND --log-file=../../test/mvsg_gummel_nfet.vlog        $NGSPICE gummel_nfet.spv
rm *.spv
cd ../../test

cd ../code/psp102
cp id_pmos.sp            id_pmos.spv
cp id_nmos.sp            id_nmos.spv
sed -i 's/.endc/quit\n.endc/g' id_pmos.spv
sed -i 's/.endc/quit\n.endc/g' id_nmos.spv
$VALGRIND --log-file=../../test/psp102_id_pmos.vlog            $NGSPICE id_pmos.spv
$VALGRIND --log-file=../../test/psp102_id_nmos.vlog            $NGSPICE id_nmos.spv
rm *.spv
cd ../../test

cd ../code/psp103
cp psp_transfer.sp    psp_transfer.spv
cp psp_ro.sp          psp_ro.spv
cp psp_out_pmos_nm.sp psp_out_pmos_nm.spv
cp psp_out_nmos_nm.sp psp_out_nmos_nm.spv
cp psp_inverter.sp    psp_inverter.spv
cp nmos_pmos_PSP.sp   nmos_pmos_PSP.spv
cp c7552_ann_psp.net  c7552_ann_psp.spv
sed -i 's/.endc/quit\n.endc/g' psp_transfer.spv
sed -i 's/.endc/quit\n.endc/g' psp_ro.spv
sed -i 's/.endc/quit\n.endc/g' psp_out_pmos_nm.spv
sed -i 's/.endc/quit\n.endc/g' psp_out_nmos_nm.spv
sed -i 's/.endc/quit\n.endc/g' psp_inverter.spv
sed -i 's/.endc/quit\n.endc/g' nmos_pmos_PSP.spv
sed -i 's/.endc/quit\n.endc/g' c7552_ann_psp.spv
sed -i 's/15ns/0.1ns/g' c7552_ann_psp.spv
$VALGRIND --log-file=../../test/psp103_psp_transfer.vlog    $NGSPICE psp_transfer.spv
$VALGRIND --log-file=../../test/psp103_psp_ro.vlog          $NGSPICE psp_ro.spv
$VALGRIND --log-file=../../test/psp103_psp_out_pmos_nm.vlog $NGSPICE psp_out_pmos_nm.spv
$VALGRIND --log-file=../../test/psp103_psp_out_nmos_nm.vlog $NGSPICE psp_out_nmos_nm.spv
$VALGRIND --log-file=../../test/psp103_psp_inverter.vlog    $NGSPICE psp_inverter.spv
$VALGRIND --log-file=../../test/psp103_nmos_pmos_PSP.vlog   $NGSPICE nmos_pmos_PSP.spv
$VALGRIND --log-file=../../test/psp103_c7552_ann_psp.vlog   $NGSPICE c7552_ann_psp.spv
rm *.spv
cd ../../test

cd ../code/r2_cmc
cp res_r2_cmc.sp              res_r2_cmc.spv
sed -i 's/.endc/quit\n.endc/g' res_r2_cmc.spv
$VALGRIND --log-file=../../test/r2_res_r2_cmc.vlog          $NGSPICE res_r2_cmc.spv
rm *.spv
cd ../../test

cd ../code/r3_cmc
cp res_r3_cmc.sp               res_r3_cmc.spv
sed -i 's/.endc/quit\n.endc/g' res_r3_cmc.spv
$VALGRIND --log-file=../../test/r3_res_r3_cmc.vlog          $NGSPICE res_r3_cmc.spv
rm *.spv
cd ../../test

cd ../code/vbic
cp vbic_ac_par.sp vbic_ac_par.spv
cp self-heat.sp   self-heat.spv
cp npn_out.sp     npn_out.spv
cp npn_out_qs.sp  npn_out_qs.spv
cp npn_gum.sp     npn_gum.spv
cp DFF_Y_ECL.sp   DFF_Y_ECL.spv
sed -i 's/.endc/quit\n.endc/g' vbic_ac_par.spv
sed -i 's/.endc/quit\n.endc/g' self-heat.spv
sed -i 's/.endc/quit\n.endc/g' npn_out.spv
sed -i 's/.endc/quit\n.endc/g' npn_out_qs.spv
sed -i 's/.endc/quit\n.endc/g' npn_gum.spv
sed -i 's/.endc/quit\n.endc/g' DFF_Y_ECL.spv
$VALGRIND --log-file=../../test/vbic_vbic_ac_par.vlog       $NGSPICE vbic_ac_par.spv
$VALGRIND --log-file=../../test/vbic_self-heat.vlog         $NGSPICE self-heat.spv
$VALGRIND --log-file=../../test/vbic_npn_out.vlog           $NGSPICE npn_out.spv
$VALGRIND --log-file=../../test/vbic_npn_out_qs.vlog        $NGSPICE npn_out_qs.spv
$VALGRIND --log-file=../../test/vbic_npn_gum.vlog           $NGSPICE npn_gum.spv
$VALGRIND --log-file=../../test/vbic_DFF_Y_ECL.vlog         $NGSPICE DFF_Y_ECL.spv
rm *.spv
cd ../../test

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
