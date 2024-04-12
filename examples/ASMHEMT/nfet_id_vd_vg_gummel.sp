Sample netlist asmhemt: Gummel Test
*Drain current symmetry for hemt

.model nfet asmhemt

vd d 0 dc=3
vg g 0 dc=0.0
vs s 0 dc=0.0
vb b 0 dc=0.0

N1 d g s b dt nfet
rth0 dt 0 5.0

.control
pre_osdi ../../osdilibs/asmhemt.osdi
dc vd -1.0 1.0 0.001 vg -0.5 0.5 0.5
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
