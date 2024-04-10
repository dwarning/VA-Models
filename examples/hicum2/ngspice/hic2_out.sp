HICUM2v2.40 Output Test Ic=f(Vc,Ib)

IB 0 B 1u
VC C 0 1.8
VS S 0 0.0

NQ1 C B 0 S tj hicumL2va
rth tj 0 300

.control
pre_osdi ../../osdilibs/hicumL2.osdi
dc vc 0.0 1.8 0.01 ib 10u 100u 10u
plot -i(vc)
reset
altermod @hicumL2va[flsh]=1
dc vc 0.0 1.8 0.01 ib 1u 10u 1u
plot -i(vc)
plot v(tj)
.endc

.include ../Modelcards/examples.lib

.end
