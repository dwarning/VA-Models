DC Analysis wthout SHE for HiSIM2

.model MOSFET hisim2_va
.INCLUDE HiSIM2_3.2.0_Default_Model.txt

NMOS  d g 0 b MOSFET
.INCLUDE HiSIM2_3.2.0_Default_Instance.txt

Vds   d 0  dc   0.1
Vgs   g 0  dc   0.0
Vbs   b 0  dc   0.0

.control
pre_osdi ../osdilibs/hisim2.osdi
dc  Vgs 0 2.0 0.01  Vbs 0.0 -1.0 -0.2
*dc  Vds 0 2.0 0.01  Vgs 0.5 2.0 0.1
plot  -I(Vds)
.endc

.end

