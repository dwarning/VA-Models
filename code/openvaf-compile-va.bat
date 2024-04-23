::
::
:: Copyright 2023 The ngspice team
:: Authors: Holger Vogt, Dietmar Warning
:: License: New BSD

MD ..\osdilibs

CD ..\osdilibs

openvaf.exe -D__NGSPICE__ -o angelov.osdi ..\code\angelov\vacode\angelov.va
openvaf.exe -D__NGSPICE__ -o angelov_gan.osdi ..\code\angelov\vacode\angelov_gan.va
openvaf.exe -D__NGSPICE__ -o asmhemt.osdi ..\code\ASMHEMT\vacode\asmhemt.va
openvaf.exe -D__NGSPICE__ -o bsim4.osdi ..\code\bsim4\vacode\bsim4.va
openvaf.exe -D__NGSPICE__ -o BSIM6.1.1.osdi ..\code\bsim6\vacode\BSIM6.1.1.va
openvaf.exe -D__NGSPICE__ -o bsimbulk106.osdi ..\code\bsimbulk\vacode\bsimbulk106.va
openvaf.exe -D__NGSPICE__ -o bsimbulk.osdi ..\code\bsimbulk\vacode\bsimbulk.va
openvaf.exe -D__NGSPICE__ -o bsimcmg110.osdi ..\code\bsimcmg\vacode110\bsimcmg.va
openvaf.exe -D__NGSPICE__ -o bsimcmg.osdi ..\code\bsimcmg\vacode\bsimcmg.va
openvaf.exe -D__NGSPICE__ -o bsimimg.osdi ..\code\bsimimg\vacode\bsimimg.va
openvaf.exe -D__NGSPICE__ -o bsimsoi.osdi ..\code\bsimsoi\vacode\bsimsoi.va
openvaf.exe -D__NGSPICE__ -o diode_cmc.osdi ..\code\diode_cmc\vacode\diode_cmc.va
openvaf.exe -D__NGSPICE__ -o ekv26.osdi ..\code\ekv\vacode\ekv26.va
openvaf.exe -D__NGSPICE__ -o ekv3.osdi ..\code\ekv3\vacode\ekv3.va
openvaf.exe -D__NGSPICE__ -o epfl_hemt.osdi ..\code\EPFL-HEMT\vacode\epfl_hemt.va
openvaf.exe -D__NGSPICE__ -o fbh_hbt-2_1.osdi ..\code\fbh_hbt\vacode\fbh_hbt-2_1.va
openvaf.exe -D__NGSPICE__ -o fbh_hbt-2_3.osdi ..\code\fbh_hbt\vacode\fbh_hbt-2_3.va
openvaf.exe -D__NGSPICE__ -o hicumL0_v2p1p0.osdi ..\code\hicum0\vacode\hicumL0_v2p1p0.va
openvaf.exe -D__NGSPICE__ -o hicumL2V2p4p0.osdi ..\code\hicum2\vacode\hicumL2.va
openvaf.exe -D__NGSPICE__ -o hicumL2.osdi ..\code\hicum2\vacode\hicumL2V3p0p0.va
openvaf.exe -D__NGSPICE__ -o hisim2.osdi ..\code\hisim2\vacode\hisim2.va
openvaf.exe -D__NGSPICE__ -o hisimhv.osdi ..\code\hisimhv\vacode\hisimhv.va
openvaf.exe -D__NGSPICE__ -o hisimsoi.osdi ..\code\hisimsoi\vacode\hisimsoi.va
openvaf.exe -D__NGSPICE__ -o hisimsotb.osdi ..\code\hisimsotb\vacode\hisimsotb.va
openvaf.exe -D__NGSPICE__ -o igbt3.osdi ..\code\IGBT\vacode\igbt3.va
openvaf.exe -D__NGSPICE__ -o L_UTSOI_102.osdi ..\code\L-UTSOI\vacode\L_UTSOI_102.va
openvaf.exe -D__NGSPICE__ -o bjt504.osdi ..\code\mextram\vacode504p12p1\bjt504.va
openvaf.exe -D__NGSPICE__ -o bjt504t.osdi ..\code\mextram\vacode504p12p1\bjt504t.va
openvaf.exe -D__NGSPICE__ -o bjt505.osdi ..\code\mextram\vacode\bjt505.va
openvaf.exe -D__NGSPICE__ -o bjt505t.osdi ..\code\mextram\vacode\bjt505t.va
openvaf.exe -D__NGSPICE__ -o mosvar.osdi ..\code\MOSVAR\vacode\mosvar.va
openvaf.exe -D__NGSPICE__ -o mvsg_cmc.osdi ..\code\mvsg\vacode\mvsg_cmc_3.2.0.va
openvaf.exe -D__NGSPICE__ -o psp102.osdi ..\code\psp102\vacode\psp102.va
openvaf.exe -D__NGSPICE__ -o juncap200.osdi ..\code\psp103\vacode\juncap200.va
openvaf.exe -D__NGSPICE__ -o psp103.osdi ..\code\psp103\vacode\psp103.va
openvaf.exe -D__NGSPICE__ -o psp103_nqs.osdi ..\code\psp103\vacode\psp103_nqs.va
openvaf.exe -D__NGSPICE__ -o psp104.osdi ..\code\psp104\vacode\psp104.va
openvaf.exe -D__NGSPICE__ -o psphv.osdi ..\code\psphv\vacode\psphv.va
openvaf.exe -D__NGSPICE__ -o r2_cmc.osdi ..\code\r2_cmc\vacode\r2_cmc.va
openvaf.exe -D__NGSPICE__ -o r2_et_cmc.osdi ..\code\r2_cmc\vacode\r2_et_cmc.va
openvaf.exe -D__NGSPICE__ -o r3_cmc.osdi ..\code\r3_cmc\vacode\r3_cmc.va
openvaf.exe -D__NGSPICE__ -o vbic_4T_et_cf.osdi ..\code\vbic\vacode\vbic_4T_et_cf.va
openvaf.exe -D__NGSPICE__ -o vbic_1p3.osdi ..\code\vbic\vacode\vbic_1p3.va
openvaf.exe -D__NGSPICE__ -DfiveTerminal -o vbic_1p3_5t.osdi ../code/vbic/vacode/vbic_1p3.va

CD ..

echo done

