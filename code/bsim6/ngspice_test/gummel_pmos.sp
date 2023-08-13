Sample netlist for BSIM6
*Drain current symmetry

.include "../Modelcards/modelcard.pmos"

* --- Voltage Sources ---
vdrain drain 0 dc=0
esource source 0 drain 0 -1
vgate gate  0 dc=-0.5
vbulk bulk 0 dc=0


* --- Transistor ---
N1 drain gate source bulk pmos W=10e-6 L=10e-6 

* --- DC Analysis ---
.dc vdrain -0.1 0.1 0.001 vgate -1 -0.4 0.2
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
