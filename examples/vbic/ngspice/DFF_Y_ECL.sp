ECL DFF VBIC test case

V6 D     GND PULSE(-.25 0 0 1P 1P .25N .50N)   
V5 D_BAR GND PULSE(0 -.25 0 1P 1P .25N .50N)   
V4 CLK     GND PULSE(-0.9 -1.2 0 1P 1P .125N .25N)   
V3 CLK_BAR GND PULSE(-1.2 -0.9 0 1P 1P .125N .25N)   
VVCS NET2 GND DC -0.8 
R6 GND NET6  800 
R5 GND NET11  800 
R4 NET12 VEE  350 
VVEE VEE GND DC -2.0 
R3 GND NET10  800 
R2 NET13 VEE  350 
R1 GND Q  800 
NQVLGNPN16 NET7 CLK_BAR NET4 VEE NPN_VBIC_VLG sw_et=0
NQVLGNPN15 NET5 CLK NET3 VEE NPN_VBIC_VLG sw_et=0
NQVLGNPN14 NET10 Q NET7 VEE NPN_VBIC_VLG sw_et=0
NQVLGNPN13 Q NET6 NET9 VEE NPN_VBIC_VLG sw_et=0
NQVLGNPN12 NET6 NET11 NET5 VEE NPN_VBIC_VLG sw_et=0
NQVLGNPN11 NET11 D_BAR NET8 VEE NPN_VBIC_VLG sw_et=0
NQVLGNPN10 NET4 NET2 NET13 VEE NPN_VBIC_VLG sw_et=0
NQVLGNPN9 NET3 NET2 NET12 VEE NPN_VBIC_VLG sw_et=0
NQVLGNPN8 NET8 CLK_BAR NET3 VEE NPN_VBIC_VLG sw_et=0
NQVLGNPN7 NET9 CLK NET4 VEE NPN_VBIC_VLG sw_et=0
NQVLGNPN6 Q NET10 NET7 VEE NPN_VBIC_VLG sw_et=0
NQVLGNPN5 NET10 NET11 NET9 VEE NPN_VBIC_VLG sw_et=0
NQVLGNPN4 NET11 NET6 NET5 VEE NPN_VBIC_VLG sw_et=0
NQVLGNPN3 NET6 D NET8 VEE NPN_VBIC_VLG sw_et=0

.include ../Modelcards/vbic.mod

.SAVE V(D) V(CLK) V(Q)
.control
pre_osdi ../../../osdilibs/vbic_1p3.osdi
*op
TRAN 0.25p 5n
*rusage all
set color0=white
set xbrushwidth=2
plot V(D) V(CLK) V(Q)
.endc
.END
