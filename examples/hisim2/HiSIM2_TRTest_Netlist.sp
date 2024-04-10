Transient Analysis with SHE for HiSIM2

.model MOSFET hisim2_va
.INCLUDE HiSIM2_3.2.0_Default_Model.txt

NMOS d g 0 0 MOSFET
.INCLUDE HiSIM2_3.2.0_Default_Instance.txt

Vgs g 0 dc 0.0 pulse(0 2 100e-9 1e-9 1e-9 1e-6 2e-6)
Vds d 0 dc 2.0

.control
pre_osdi ../../osdilibs/hisim2.osdi
tran 1e-9 2.5e-6
plot  -I(Vds)
plot V(g)
.endc

.end
