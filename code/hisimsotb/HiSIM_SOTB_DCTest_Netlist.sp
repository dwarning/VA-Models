DC Analysis for HiSIM_SOTB

.model MOSFET hisimsotb_va
.INCLUDE HiSIM_SOTB_1.2.0_Default_Model.txt

NMdev d g 0 0 MOSFET
.INCLUDE HiSIM_SOTB_1.2.0_Default_Instance.txt

Vds   d 0  dc   0.0
Vgs   g 0  dc   0.0

.control
pre_osdi ../osdilibs/hisimsotb.osdi
dc  Vds 0 2.0 0.2  Vgs 0.5 2.0 0.5
plot  -I(Vds)
.endc

.end

