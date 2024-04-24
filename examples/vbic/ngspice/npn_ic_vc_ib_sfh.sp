VBIC Output Test Ic=f(Vc,Ib) vs self heating

vc c 0 0
vb b 0 1
ve e 0 0
vs s 0 0
vc1 c c1 0
vb1 b b1 0
ve1 e e1 0
vs1 s s1 0
.temp 27
NQ1 c1 b1 e1 s1 tj vbic99_dc sw_et=1 m=5
* area=1

.include ../Modelcards/vbic_va.mod

.control
pre_osdi ../../../osdilibs/vbic_1p3_5t.osdi
dc vc 0.0 5.0001 0.05 vb 0.7 1.0001 0.05
altermod @vbic99_dc[RTH]=0
dc vc 0.0 5.0001 0.05 vb 0.7 1.0001 0.05
plot dc1.vc1#branch dc2.vc1#branch
plot dc1.v(tj) dc2.v(tj)
.endc
.end

