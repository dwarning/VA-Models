VBIC Output Test Ic=f(Vc,Ib) vs self heating
.option absmos=1e-12 relmos=1e-6 relv=1e-6 absv=1e-9 post
vc c 0 0
vb b 0 1
ve e 0 0
vs s 0 0
vc1 c c1 0
vb1 b b1 0
ve1 e e1 0
vs1 s s1 0
.temp 27
NQ1 c1 b1 e1 s1 vbicmod sw_et=1 m=5
* area=1

.include Modelcards/vbic.mod

.control
pre_osdi ../osdilibs/vbic_1p3.osdi
dc vc 0.0 5.0001 0.05 vb 0.7 1.0001 0.05
altermod @vbicmod[RTH]=0
dc vc 0.0 5.0001 0.05 vb 0.7 1.0001 0.05
plot dc1.vc1#branch dc2.vc1#branch
.endc
.end

