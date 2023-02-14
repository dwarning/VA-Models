VBIC Output Test Ic=f(Vc,Ib)

.include Modelcards/qnva.mod

IB 0 B 200n
VC C 0 2.0
VS S 0 0.0
XQ1 C B 0 S T qnva le=20.02 m=2 par1=1

.control
pre_osdi ../osdilibs/vbic_1p3.osdi
dc vc 0.0 4.0 0.05 ib 1u 10u 1u
plot abs(i(vc))
*plot v(t)
.endc

.end
