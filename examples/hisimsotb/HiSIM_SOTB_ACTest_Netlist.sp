AC Analysis with Noise Model for HiSIM_SOTB

.model MOSFET hisimsotb_va
.INCLUDE HiSIM_SOTB_1.3.0_Default_Model.txt

NMdev d g 0 0 MOSFET
.INCLUDE HiSIM_SOTB_1.3.0_Default_Instance.txt

VDD    dd 0  2.0
RLOAD  dd d  2.5k
CLOAD  dd d  10f
VGS     g 0  dc 1.5 ac 1.0

.control
pre_osdi ../../osdilibs/hisimsotb.osdi
show all
ac DEC 10 1k 1T
plot  vdB(d)
.endc

.end
