* DC Analysis wthout SHE for HiSIM_HV

.model MOSFET hisimhv_va LEVEL=62 VERSION=2.51
.INCLUDE HiSIM_HV_2.5.1_Default_Model.txt
+ RDVSUB   = 1.0
+ RDVDSUB  = 1.0
+ DDRIFT   = 1.0E-06
+ VBISUB   = 0.7
+ NSUBSUB  = 1.0E+15

NMLDMOS  d g 0 0 sub dt MOSFET
.INCLUDE HiSIM_HV_2.5.1_Default_Instance.txt
+ COSUBNODE = 1
+ COSELFHEAT = 1

Vds   d 0  dc   0.0
Vgs   g 0  dc   0.0
Vss sub 0  dc -20.0

.control
pre_osdi ../../osdilibs/hisimhv.osdi
dc  Vds 0 20.0 0.2  Vgs 2 20.0 2.0
plot  -I(Vds)
plot v(dt)
.endc

.end

