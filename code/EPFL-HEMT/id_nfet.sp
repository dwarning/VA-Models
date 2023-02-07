Sample netlist epfl_hemt: Id plot hemt

.model nfet EPFL_HEMT_10a

vd d 0 dc=3
vg g 0 dc=0.0
vs s 0 dc=0.0
vb b 0 dc=0.0

N1 d g s b dt nfet
rth0 dt 0 4.0

.control
pre_osdi ../osdilibs/epfl_hemt.osdi
dc vg -4 1 0.01
plot -i(vd)
dc vd 0.0 40 0.11 vg -3 1 0.5
plot -i(vd)
plot v(dt)
.endc

.end

