AC Analysis with Noise Model for HiSIM2

.model MOSFET hisim2_va
.INCLUDE HiSIM2_3.2.0_Default_Model.txt

NMOS d g 0 0 MOSFET 
.INCLUDE HiSIM2_3.2.0_Default_Instance.txt

VDD    dd 0  2
RLOAD  dd d  120k
CLOAD  dd d  20f
VGS     g 0  dc 1.25 ac 1.0

.control
pre_osdi ../osdilibs/hisim2.osdi
op
print all
ac DEC 10 1k 1G
plot  vdB(d)
.endc

.end
