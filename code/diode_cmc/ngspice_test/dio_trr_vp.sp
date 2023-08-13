.title Diode Soft Reverse Recovery Test
nd1 anode 0 diocmc AB=100e-12
R1 Anode Anode1 3
V1 Anode1 0 PULSE(1.1 -3 4n 3n 3n 40n 80n)
*.options method=gear maxord=1 trtol=1
*.options reltol=1e-6 vntol=1e-8 abstol=1e-13
.save all
*.save @d1[vd] @d1[id] @d1[charge]
.control
pre_osdi ../../osdilibs/diode_cmc.osdi
tran 100p 40n ;0 5p
plot -i(v1) v(anode)/10; @d1[id] @d1[vd] v(Anode)
*settype charge @d1[charge]
*plot @d1[charge]
*plot deriv(@d1[charge]) ylimit -1e-3 1e-3
.endc

.MODEL diocmc DIODE_CMC IDSATRBOT=1e-06 RSBOT=10 ;RSCOM=1e-6
+ VBRBOT=100
+ VBRSTI=100
+ VBRGAT=100
+ CORECOVERY=1
+ TAU=200n
+ INJ1=1.2
+ INJ2=10.0
+ WI=5u
+ NQS=6e-09
+ DEPNQS=1e-09
*+ TAUT=100n

.end
