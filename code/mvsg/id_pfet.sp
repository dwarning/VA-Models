Sample netlist mvsg_cmc: Id plot hemt

.model pfet mvsg_cmc type=-1 rth=5

vd 0 d dc=5
vg 0 g dc=0.0
vs 0 s dc=0.0
vb 0 b dc=0.0

N1 d g s b pfet

.control
pre_osdi ../osdilibs/mvsg_cmc.osdi
dc vg -5 5 0.01
plot -i(vd)
dc vd 0.0 50 0.1 vg -2 0 0.5
plot -i(vd)
.endc

.end

