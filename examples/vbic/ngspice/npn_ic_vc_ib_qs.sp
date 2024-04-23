BJT Quasi-Saturation Output Test Ic=f(Vc,Ib)

.include ../Modelcards/Infineon_VBIC.lib

IB 0 B 100u
VC C 0 0.0
VE E 0 0.0
XQ1 C B E E T BFP780

.control
pre_osdi ../../../osdilibs/vbic_1p3_5t.osdi
dc vc 0.0 2.0 0.01 ib 100u 1000u 100u
plot -i(vc)
settype temperature v(t)
plot v(t)
.endc

.end
