#!/bin/bash

# Copyright 2023 The ngspice team
# Authors: Holger Vogt, Dietmar Warning
# License: New BSD

mkdir -p admslibs

#buildxyceplugin ../ASMHEMT/vacode/asmhemt.va .
cd ./bsim4/vacode
buildxyceplugin bsim4.va ../../admslibs
rm *.la *.log
rmdir --ignore-fail-on-non-empty .libs
cd ../..
cd ./bsim6/vacode
buildxyceplugin BSIM6.1.1.va ../../admslibs
rm *.la *.log
rmdir --ignore-fail-on-non-empty .libs
cd ../..
cd ./bsimbulk/vacode
#buildxyceplugin bsimbulk106.va ../../admslibs
buildxyceplugin bsimbulk107.va ../../admslibs
rm *.la *.log
rmdir --ignore-fail-on-non-empty .libs
cd ../..
cd ./bsimcmg/vacode110
buildxyceplugin bsimcmg.va ../../admslibs
rm *.la *.log
rmdir --ignore-fail-on-non-empty .libs
cd ../..
#buildxyceplugin bsimimg.va ../../admslibs
cd ./bsimsoi/vacode
buildxyceplugin bsimsoi.va ../../admslibs
rm *.la *.log
rmdir --ignore-fail-on-non-empty .libs
cd ../..
cd ./diode_cmc/vacode
buildxyceplugin diode_cmc.va ../../admslibs
rm *.la *.log
rmdir --ignore-fail-on-non-empty .libs
cd ../..
cd ./ekv/vacode
buildxyceplugin ekv26.va ../../admslibs
rmdir --ignore-fail-on-non-empty .libs
rm *.la *.log
cd ../..
#buildxyceplugin ../EPFL-HEMT/vacode/epfl_hemt.va .
#buildxyceplugin ../fbh_hbt/vacode/fbh_hbt-2_1.va .
#buildxyceplugin ../fbh_hbt/vacode/fbh_hbt-2_3.va .
#buildxyceplugin ../hicum0/vacode/HICUML0-2.va .
cd ./hicum2/vacode
buildxyceplugin hicumL2.va ../../admslibs
rm *.la *.log
rmdir --ignore-fail-on-non-empty .libs
cd ../..
#buildxyceplugin ../hisim2/vacode/hisim2.va .
#buildxyceplugin ../hisimhv/vacode242/hisimhv.va .
#buildxyceplugin ../hisimhv/vacode250/hisimhv.va .
#buildxyceplugin ../hisimsoi/vacode/hisimsoi.va .
#buildxyceplugin ../hisimsotb/vacode/hisimsotb.va .
cd ./IGBT/vacode
buildxyceplugin nigbt.va ../../admslibs
rm *.la *.log
rmdir --ignore-fail-on-non-empty .libs
cd ../..
#buildxyceplugin ../L-UTSOI/vacode/L_UTSOI_102.va .
cd ./mextram/504p12p1_vacode
buildxyceplugin bjt504.va ../../admslibs
buildxyceplugin bjt504t.va ../../admslibs
rm *.la *.log
rmdir --ignore-fail-on-non-empty .libs
cd ../..
cd ./mextram/505p2p0_vacode
buildxyceplugin bjt505.va ../../admslibs
buildxyceplugin bjt505t.va ../../admslibs
rm *.la *.log
rmdir --ignore-fail-on-non-empty .libs
cd ../..
#buildxyceplugin ../MOSVAR/vacode/mosvar.va .
#buildxyceplugin ../mvsg/vacode/mvsg_cmc.va .
#buildxyceplugin ../psp102/vacode/psp102.va .
#buildxyceplugin ../psp103/vacode/psp103.va .
#buildxyceplugin ../r2_cmc/vacode/r2_cmc.va .
#buildxyceplugin ../r2_cmc/vacode/r2_et_cmc.va .
cd ./r3_cmc/vacode
buildxyceplugin r3_cmc.va ../../admslibs
rm *.la *.log
rmdir --ignore-fail-on-non-empty .libs
cd ../..
cd ./vbic/vacode
buildxyceplugin vbic_1p3.va ../../admslibs
rm *.la *.log
rmdir --ignore-fail-on-non-empty .libs
cd ../..

echo done

