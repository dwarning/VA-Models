AC Analysis with Noise Model for HiSIM-HV

.model MOSFET hisimhv_va level=62 version=2.51
.INCLUDE HiSIM_HV_2.5.1_Default_Model.txt
+ COFLICK =1 
+ COTHRML =1 
+ COIGN   =1 
+ CORSRD  =1 

NMLDMOS d g 0 0 MOSFET 
.INCLUDE HiSIM_HV_2.5.1_Default_Instance.txt

VDD    dd 0  20
RLOAD  dd d  4.3k
CLOAD  dd d  10f
VGS     g 0  dc 5 ac 1.0

.control
pre_osdi ../../osdilibs/hisimhv.osdi
show all
ac DEC 10 1k 1T
plot  vdB(d)
.endc

.end
