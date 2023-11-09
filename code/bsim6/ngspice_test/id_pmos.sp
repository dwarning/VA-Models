Sample netlist BSIM6: Id plot pmos

*.hdl "BSIM6.1.1.va"
.include "../Modelcards/modelcard.pmos"

vd d 0 dc -50m
vg g 0 dc -1.0
vs s 0 dc 0.0
vb b 0 dc 0.0

N1 d g s b pmos W = 10e-6 L = 10e-6

.control
pre_osdi ../../osdilibs/BSIM6.1.1.osdi
op
show all
dc vg -1.3 0.0 0.01 vb 0.0 0.5 0.1
plot -i(vd)
dc vd -1.3 0.0 0.01 vg -1.0 -0.4 0.2
plot -i(vd)
.endc

.end

