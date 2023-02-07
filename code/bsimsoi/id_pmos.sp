Id-Vd Characteristics for bsimsoi PMOS 

.include "Modelcards/modelcard.pmos"

* --- Voltage Sources ---
vd drain  0 dc=-0.05
vg gate  0 dc=1
vs source 0 dc=0
ve substrate 0 0

* --- Transistor ---
nx1 drain gate source substrate pmos1 W=1e-6 L=1e-7 soimod=0 nf=1
*nx1 drain gate source substrate nmos1 W=1e-6 L=1e-7 soimod=1 nf=1
*nx1 drain gate source substrate nmos1 W=1e-6 L=1e-7 soimod=2 nf=1
*nx1 drain gate source substrate 0 0 t nmos1 W=1e-6 L=1e-7 soimod=0 nf=1

* --- DC Analysis ---
.control
pre_osdi ../osdilibs/bsimsoi.osdi
dc vg -1.2 0 0.01
plot -i(vd)
dc vd -1.2 0 0.01 vg -1.2 -0.5 0.1
plot -i(vd)
*plot v(t)
.endc
.end
