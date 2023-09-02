#!/bin/bash

# Copyright 2023 The ngspice team
# Authors: Holger Vogt, Dietmar Warning
# License: New BSD

mkdir -p osdilibs

cd osdilibs

openvaf -D__NGSPICE__ -o asmhemt.osdi ../ASMHEMT/vacode/asmhemt.va
openvaf -D__NGSPICE__ -o bsim4.osdi ../bsim4/vacode/bsim4.va
openvaf -D__NGSPICE__ -o BSIM6.1.1.osdi ../bsim6/vacode/BSIM6.1.1.va
openvaf -D__NGSPICE__ -o bsimbulk106.osdi ../bsimbulk/vacode/bsimbulk106.va
openvaf -D__NGSPICE__ -o bsimbulk107.osdi ../bsimbulk/vacode/bsimbulk107.va
openvaf -D__NGSPICE__ -o bsimcmg.osdi ../bsimcmg/vacode/bsimcmg.va
openvaf -D__NGSPICE__ -o bsimimg.osdi ../bsimimg/vacode/bsimimg.va
openvaf -D__NGSPICE__ -o bsimsoi.osdi ../bsimsoi/vacode/bsimsoi.va
openvaf -D__NGSPICE__ -o diode_cmc.osdi ../diode_cmc/vacode/diode_cmc.va
openvaf -D__NGSPICE__ -o ekv26.osdi ../ekv/vacode/ekv26.va
openvaf -D__NGSPICE__ -o epfl_hemt.osdi ../EPFL-HEMT/vacode/epfl_hemt.va
openvaf -D__NGSPICE__ -o fbh_hbt-2_1.osdi ../fbh_hbt/vacode/fbh_hbt-2_1.va
openvaf -D__NGSPICE__ -o fbh_hbt-2_3.osdi ../fbh_hbt/vacode/fbh_hbt-2_3.va
openvaf -D__NGSPICE__ -o hicumL0_v2p0p0.osdi ../hicum0/vacode/hicumL0_v2p0p0.va
openvaf -D__NGSPICE__ -o hicumL2.osdi ../hicum2/vacode/hicumL2V3p0p0.va
openvaf -D__NGSPICE__ -o hisim2.osdi ../hisim2/vacode/hisim2.va
openvaf -D__NGSPICE__ -o hisimhv242.osdi ../hisimhv/vacode242/hisimhv.va
openvaf -D__NGSPICE__ -o hisimhv250.osdi ../hisimhv/vacode250/hisimhv.va
openvaf -D__NGSPICE__ -o hisimsoi.osdi ../hisimsoi/vacode/hisimsoi.va
openvaf -D__NGSPICE__ -o hisimsotb.osdi ../hisimsotb/vacode/hisimsotb.va
openvaf -D__NGSPICE__ -o nigbt.osdi ../IGBT/vacode/nigbt.va
openvaf -D__NGSPICE__ -o L_UTSOI_102.osdi ../L-UTSOI/vacode/L_UTSOI_102.va
openvaf -D__NGSPICE__ -o bjt504.osdi ../mextram/504p12p1_vacode/bjt504.va
openvaf -D__NGSPICE__ -o bjt504t.osdi ../mextram/504p12p1_vacode/bjt504t.va
openvaf -D__NGSPICE__ -o bjt505.osdi ../mextram/505p2p0_vacode/bjt505.va
openvaf -D__NGSPICE__ -o bjt505t.osdi ../mextram/505p2p0_vacode/bjt505t.va
openvaf -D__NGSPICE__ -o mosvar.osdi ../MOSVAR/vacode/mosvar.va
openvaf -D__NGSPICE__ -o mvsg_cmc.osdi ../mvsg/vacode/mvsg_cmc.va
openvaf -D__NGSPICE__ -o psp102.osdi ../psp102/vacode/psp102.va
openvaf -D__NGSPICE__ -o psp103.osdi ../psp103/vacode/psp103.va
openvaf -D__NGSPICE__ -o r2_cmc.osdi ../r2_cmc/vacode/r2_cmc.va
openvaf -D__NGSPICE__ -o r2_et_cmc.osdi ../r2_cmc/vacode/r2_et_cmc.va
openvaf -D__NGSPICE__ -o r3_cmc.osdi ../r3_cmc/vacode/r3_cmc.va
openvaf -D__NGSPICE__ -o vbic_1p3.osdi ../vbic/vacode/vbic_1p3.va

echo done

