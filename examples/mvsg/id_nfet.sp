Sample netlist mvsg_cmc: Id plot hemt

.model nfet mvsg_cmc type=1 rth=5

vd d 0 dc=5
vg g 0 dc=0.0
vs s 0 dc=0.0
vb b 0 dc=0.0

N1 d g s b nfet

.control
pre_osdi ../../osdilibs/mvsg_cmc.osdi
dc vg -5 5 0.01
plot -i(vd)
dc vd 0.0 50 0.1 vg -2 0 0.5
plot -i(vd)
.endc

.end

