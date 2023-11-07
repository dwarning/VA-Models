Sample netlist BSIMBULK: Id plot pmos

*.hdl "bsimbulk.va"
.include ../Modelcards/model.l

vd d 0 dc=-0.05
vg g 0 dc=0
vs s 0 dc=0
vb b 0 dc=0

nm1 d g s b pmos W=20e-6 L=1e-6

.control
pre_osdi ../../osdilibs/bsimbulk.osdi
dc vg -1.3 0.0 0.01 vb 0 1.2 0.2
plot -i(vd)
dc vd -1.3 0.0 0.01 vg -1.2 -0.4 0.2
plot -i(vd)
.endc

.end
