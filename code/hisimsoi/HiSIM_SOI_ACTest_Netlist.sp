AC Analysis with Noise Model for HiSIM_SOI

.model MOSFET hisimsoi_va
.INCLUDE HiSIM_SOI_1.4.0_Default_Model.txt

NMLDMOS d g 0 0 MOSFET 
.INCLUDE HiSIM_SOI_1.4.0_Default_Instance.txt

VDD    dd 0  2.0
RLOAD  dd d  2.3k
CLOAD  dd d  100f
VGS     g 0  dc 2 ac 1.0

.control
pre_osdi ../osdilibs/hisimsoi.osdi
show all
ac DEC 10 1k 1T
plot  vdB(d)
.endc

.end
