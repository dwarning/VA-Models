Diode Param Temp Test

va a 0 dc 1.0
nd1 a 0 diocmc AB=100e-12

.control
pre_osdi ../osdilibs/diode_cmc.osdi
dc va 0.01 1.5 0.01 temp -25 125 50
plot abs(i(va)) ylog
.endc

.MODEL diocmc DIODE_CMC IDSATRBOT=1e-06 RSBOT=10 ;RSCOM=1e-6
+ VBRBOT=100
+ VBRSTI=100
+ VBRGAT=100
+ CORECOVERY=1
+ TAU=200n
+ INJ1=1.0
+ INJ2=10.0
+ WI=5u
+ NQS=50e-09
+ DEPNQS=1e-09
*+ TAUT=100n
.end

