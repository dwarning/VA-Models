Sample netlist asmhemt: Id plot hemt

.model nfet asmhemt

vd d 0 dc=3
vg g 0 dc=0.0
vs s 0 dc=0.0
vb b 0 dc=0.0

N1 d g s b dt nfet
rth0 dt 0 5.0

.control
pre_osdi ../../osdilibs/asmhemt.osdi
op
show all
dc vg -3 3 0.01
plot -i(vd)
dc vd 0.0 40 0.1 vg -1 3 0.5
plot -i(vd)
settype temperature v(dt)
plot v(dt)
.endc

.end

