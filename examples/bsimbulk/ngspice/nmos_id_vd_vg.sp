Sample netlist BSIMBULK: Id plot nmos

*.hdl "bsimbulk.va"
.include ../Modelcards/model.l

vd d 0 dc 0.05
vg g 0 dc 1.0
vs s 0 dc 0
vb b 0 dc 0

nm1 d g s b nmos W=10e-6 L=1e-6

.control
pre_osdi ../../../osdilibs/bsimbulk.osdi
op
show all
dc vg 0.0 1.3 0.01 vb 0 -1.2 -0.2
plot -i(vd)
dc vd 0.0 1.3 0.01 vg 0.4 1.2 0.2
plot -i(vd)
.endc

*.probe dc ids=par'-i(vd)'
*.probe dc gm=deriv(ids)
*.probe dc gm2=deriv(gm)
*.print dc par'ids' par'gm' par'gm2' i(vd)
.end
