#!/bin/bash

# Copyright 2023 The ngspice team
# Authors: Holger Vogt, Dietmar Warning
# License: New BSD

mkdir -p ../admslibs

cd ./angelov/vacode
buildxyceplugin angelov.va ../../../admslibs
buildxyceplugin angelov_gan.va ../../../admslibs
rm *.la *.log
rm -rfd .libs/
cd ../..
#buildxyceplugin ../ASMHEMT/vacode/asmhemt.va .
cd ./bsim4/vacode
buildxyceplugin bsim4.va ../../../admslibs
rm *.la *.log
rm -rfd .libs/
cd ../..
cd ./bsim6/vacode
buildxyceplugin BSIM6.1.1.va ../../../admslibs
rm *.la *.log
rm -rfd .libs/
cd ../..
cd ./bsimbulk/vacode
buildxyceplugin bsimbulk.va ../../../admslibs
#buildxyceplugin bsimbulk107.va ../../../admslibs
#buildxyceplugin bsimbulk106.va ../../../admslibs
rm *.la *.log
rm -rfd .libs/
cd ../..
cd ./bsimcmg/vacode
buildxyceplugin bsimcmg.va ../../../admslibs
rm *.la *.log
rm -rfd .libs/
cd ../..
#buildxyceplugin bsimimg.va ../../../admslibs
cd ./bsimsoi/vacode
buildxyceplugin bsimsoi.va ../../../admslibs
rm *.la *.log
rm -rfd .libs/
cd ../..
cd ./diode_cmc/vacode
buildxyceplugin diode_cmc.va ../../../admslibs
rm *.la *.log
rm -rfd .libs/
cd ../..
cd ./ekv/vacode
buildxyceplugin ekv26.va ../../../admslibs
rm -rfd .libs/
rm *.la *.log
cd ../..
cd ./ekv3/vacode
buildxyceplugin ekv3.va ../../../admslibs
rm -rfd .libs/
rm *.la *.log
cd ../..
#buildxyceplugin ../EPFL-HEMT/vacode/epfl_hemt.va .
#buildxyceplugin ../fbh_hbt/vacode/fbh_hbt-2_1.va .
#buildxyceplugin ../fbh_hbt/vacode/fbh_hbt-2_3.va .
cd ./hicum0/vacode
buildxyceplugin hicumL0_v2p0p0.va ../../../admslibs
rm *.la *.log
rm -rfd .libs/
cd ../..
cd ./hicum2/vacode
buildxyceplugin hicumL2_v310.va ../../../admslibs
rm *.la *.log
rm -rfd .libs/
cd ../..
#buildxyceplugin ../hisim2/vacode/hisim2.va .
#buildxyceplugin ../hisimhv/vacode242/hisimhv.va .
#buildxyceplugin ../hisimhv/vacode250/hisimhv.va .
#buildxyceplugin ../hisimsoi/vacode/hisimsoi.va .
#buildxyceplugin ../hisimsotb/vacode/hisimsotb.va .
cd ./IGBT/vacode
buildxyceplugin igbt3.va ../../../admslibs
rm *.la *.log
rm -rfd .libs/
cd ../..
cd ./L-UTSOI/vacode
buildxyceplugin L_UTSOI_102.va ../../../admslibs
rm *.la *.log
rm -rfd .libs/
cd ../..
cd ./mextram/vacode504p12p1
buildxyceplugin bjt504.va ../../../admslibs
buildxyceplugin bjt504t.va ../../../admslibs
rm *.la *.log
rm -rfd .libs/
cd ../..
cd ./mextram/vacode
buildxyceplugin bjt505.va ../../../admslibs
buildxyceplugin bjt505t.va ../../../admslibs
rm *.la *.log
rm -rfd .libs/
cd ../..
cd ./MOSVAR/vacode
buildxyceplugin mosvar.va ../../../admslibs
rm *.la *.log
rm -rfd .libs/
cd ../..
#buildxyceplugin ../mvsg/vacode/mvsg_cmc.va .
#buildxyceplugin ../psp102/vacode/psp102.va .
cd ./psp103/vacode
buildxyceplugin juncap200.va ../../../admslibs
buildxyceplugin psp103.va ../../../admslibs
rm *.la *.log
rm -rfd .libs/
cd ../..
#buildxyceplugin ../r2_cmc/vacode/r2_cmc.va .
#buildxyceplugin ../r2_cmc/vacode/r2_et_cmc.va .
cd ./r3_cmc/vacode
buildxyceplugin r3_cmc.va ../../../admslibs
rm *.la *.log
rm -rfd .libs/
cd ../..
cd ./vbic/vacode
buildxyceplugin vbic_1p3.va ../../../admslibs
rm *.la *.log
rm -rfd .libs/
cd ../..

echo done

