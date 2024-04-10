Transient Analysis with SHE for HiSIM_HV

.model MOSFET hisimhv_va level=62 version=2.51
.INCLUDE HiSIM_HV_2.5.1_Default_Model.txt
+ COSELFHEAT=1 

NMdev d g 0 0 MOSFET
.INCLUDE HiSIM_HV_2.5.1_Default_Instance.txt

Vgs g 0 dc 0.0 pulse(0 20 100e-9 1e-9 1e-9 1e-6 2e-6)
Vds d 0 dc 20.0

.control
pre_osdi ../../osdilibs/hisimhv.osdi
tran 1e-9 2.5e-6
plot  -I(Vds)
plot V(g)
.endc

.end
