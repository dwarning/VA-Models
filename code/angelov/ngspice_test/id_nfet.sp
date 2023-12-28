Sample netlist angelov hemt: Id plot hemt

.model nfet angelov

vd d 0 dc=3
vg g 0 dc=0.0
vs s 0 dc=0.0

N1 d g s nfet

.control
pre_osdi ../../osdilibs/angelov.osdi
op
show all
dc vg -2 1 0.01
plot -i(vd)
plot deriv(-i(vd))
dc vd 0.0 4 0.01 vg -2 0.5 0.5
plot -i(vd)
.endc

.end

