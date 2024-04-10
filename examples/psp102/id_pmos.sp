Sample netlist PSP102: Id plot pmos

.model pmos PSP102VA type=-1

vd d 0 dc=-50m
vg g 0 dc=0.0
vs s 0 dc=0.0
vb b 0 dc=0.0

N1 d g s b pmos; W=10e-6 L=10e-6

.control
pre_osdi ../osdilibs/psp102.osdi
dc vg -1.5 0.0 0.01 vb 0 1.0 0.2
plot -i(vd)
dc vd -1.5 0.0 0.01 vg -1.5 -0.5 0.2
plot -i(vd)
.endc

.end

