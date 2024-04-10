Diode Param Temp Test

va a 0 dc 1.0
nd1 a 0 juncap AB=100e-12 dta=0.0

.control
pre_osdi ../../../osdilibs/juncap200.osdi
dc va 0.01 1.5 0.01 temp -25 125 50
plot abs(i(va)) ylog
.endc

.MODEL juncap JUNCAP200 
+ IDSATRBOT=1e-06 
+ VBRBOT=100
+ VBRSTI=100
+ VBRGAT=100
.end
