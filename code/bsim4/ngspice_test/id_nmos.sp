Sample netlist for BSIM4

.include "../Modelcards/modelcard.nmos"

* --- Voltage Sources ---
vd d  0 dc 50m
vg g  0 dc 1.0
vs s  0 dc 0.0
vb b  0 dc 0.0

* --- Transistor ---
NM1 d g s b n1 W = 10e-6 L = 1e-6 nf=1

* --- DC Analysis ---
.control
pre_osdi ../../osdilibs/bsim4.osdi
op
show all
dc vg 0.0 1.2 0.01 vb -0.5 0 0.1
plot -i(vd)
dc vd 0.0 1.2 0.01 vg 0.4 1.0 0.1
plot -i(vd)
.endc

.end

