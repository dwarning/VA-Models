Sample netlist asmhemt: Gummel Test
*Drain current symmetry for hemt

.model nfet mvsg_cmc type=1 rth=5

vd d 0 dc=3
vg g 0 dc=0.0
vs s 0 dc=0.0
vb b 0 dc=0.0

N1 d g s b nfet

.control
pre_osdi ../osdilibs/mvsg_cmc.osdi
dc vd -5.0 5.0 0.01 vg -1.0 0.0 0.5
plot -i(vd)
let gx=deriv(-i(vd))
plot gx
let gx2=deriv(gx)
plot gx2
let gx3=deriv(gx2)
plot gx3
*let gx4=deriv(gx3)
*plot gx4
.endc

.end
