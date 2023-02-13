DC Analysis for HiSIM_SOI

.model MOSFET hisimsoi_va
.INCLUDE HiSIM_SOI_1.4.0_Default_Model.txt

NMLDMOS  d g 0 0 sub MOSFET
.INCLUDE HiSIM_SOI_1.4.0_Default_Instance.txt

Vds   d 0  dc   0.0
Vgs   g 0  dc   0.0
Vss sub 0  dc  -2.0

.control
pre_osdi ../osdilibs/hisimsoi.osdi
dc  Vds 0 2.0 0.2  Vgs 0.5 2.0 0.5
plot  -I(Vds)
.endc

.end

