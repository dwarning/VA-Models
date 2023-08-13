Sample netlist for BSIM6
*Drain current symmetry for nmos

.include "../Modelcards/modelcard.nmos"

* --- Voltage Sources ---
vdrain drain 0 dc=0
esource source 0 drain 0 -1
vgate gate  0 dc=1.0
vbulk bulk 0 dc=0.0


* --- Transistor ---
N1 drain gate source bulk nmos W=10u L=10u

* --- DC Analysis ---
.dc vdrain -0.1 0.1 0.001 vgate 0.0 1.0 0.2
.control
pre_osdi ../../osdilibs/BSIM6.1.1.osdi
run
plot -i(vdrain)
let gx=deriv(-i(vdrain))
let gx2=deriv(gx)
let gx3=deriv(gx2)
plot gx
plot gx2
plot gx3
.endc

.end
