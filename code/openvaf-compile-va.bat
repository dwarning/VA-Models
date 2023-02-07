:: Copyright 2023 The ngspice team
:: Authors: Holger Vogt, Dietmar Warning
:: License: New BSD

MD osdilibs

CD osdilibs

START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o asmhemt.osdi ../ASMHEMT/vacode/asmhemt.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o BSIM6.1.1.osdi ../bsim6/vacode/BSIM6.1.1.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o bsimbulk106.osdi ../bsimbulk/vacode/bsimbulk106.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o bsimbulk107.osdi ../bsimbulk/vacode/bsimbulk107.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o bsimcmg.osdi ../bsimcmg/vacode111/bsimcmg.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o bsimimg.osdi ../bsimimg/vacode/bsimimg.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o bsimsoi.osdi ../bsimsoi/vacode/bsimsoi.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o diode_cmc.osdi ../diode_cmc/vacode/diode_cmc.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o ekv26.osdi ../ekv/vacode/ekv26.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o epfl_hemt.osdi ../EPFL-HEMT/vacode/epfl_hemt.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o fbhhbt-2.3.osdi ../fbh_hbt/vacode/fbhhbt-2.3.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o HICUML0-2.osdi ../hicum0/vacode/HICUML0-2.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o hicumL2.osdi ../hicum2/vacode/hicumL2.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o hisim2.osdi ../hisim2/vacode/hisim2.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o hisimhv.osdi ../hisimhv/vacode/hisimhv.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o L_UTSOI_102.osdi ../L-UTSOI/vacode/L_UTSOI_102.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o bjt504.osdi ../mextram/504p12p1_vacode/bjt504.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o bjt504t.osdi ../mextram/504p12p1_vacode/bjt504t.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o bjt505.osdi ../mextram/505p2p0_vacode/bjt505.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o bjt505t.osdi ../mextram/505p2p0_vacode/bjt505t.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o mosvar.osdi ../MOSVAR/vacode/mosvar.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o mvsg.osdi ../mvsg/vacode/mvsg_cmc.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o psp102.osdi ../psp102/vacode/psp102.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o psp103.osdi ../psp103/vacode/psp103.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o r2_cmc.osdi ../r2_cmc/vacode/r2_cmc.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o r2_et_cmc.osdi ../r2_cmc/vacode/r2_et_cmc.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o r3_cmc.osdi ../r3_cmc/vacode/r3_cmc.va
START /B openvaf.exe -D__OPENVAF__ -D__NGSPICE_COMPACT_MODELING__ -o vbic_1p3.osdi ../vbic/vacode/vbic_1p3.va

echo done

