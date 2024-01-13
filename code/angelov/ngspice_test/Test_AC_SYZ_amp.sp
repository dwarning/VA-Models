* Qucs 24.1.0 Test_AC_SYZ_amp.sch
.SUBCKT meb _net0 _net2 _net1 
NX1 _net0 _net2 _net1 meb 
.ENDS
.INCLUDE "angelov.mod"
.PARAM Vgs = -0.5
.PARAM Vds = 4.0
C_X1 _net0 _net1 1
L_X1 _net1 _net2 1
R1 _net1 n1  50 tc1=0.0 tc2=0.0 
Vgs _net2 0 DC {VGS}
R2 n2 _net3  50 tc1=0.0 tc2=0.0 
Vds _net4 0 DC {VDS}
C1 0 _net5  1P 
L1 n1 _net5  1U 
C_X2 _net6 _net3 1U
L_X2 _net3 _net4 1U
VP1 _net0 0 dc 0 ac 0.316228 SIN(0 0.316228 1MEG) portnum 1 z0 50
VP2 _net6 0 dc 0 ac 0.316228 SIN(0 0.316228 1MEG) portnum 2 z0 50
XSUB1 n2 _net5 0 meb
.control
pre_osdi '../../osdilibs/angelov.osdi'
SP DEC 101 1MEG 0.99G 1
let gain = db((S_2_1))
plot S_1_1 S_1_2 S_2_1 S_2_2
*plot Y_1_1 Y_1_2 Y_2_1 Y_2_2
*plot Z_1_1 Z_1_2 Z_2_1 Z_2_2
plot gain
*plot NF
*plot Rn
.endc
.END
