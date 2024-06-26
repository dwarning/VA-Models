HICUM0 Gummel Test Ic=f(Vc,Vb)

VB B 0 0.5
VC C 0 1.0
VS S 0 0.0
*AQ1 C B 0 S DT hicumL0V1p1_c_sbt
XQ1 C B 0 S DT hicumL0V1p1_c_sbt
Rdt dt 0 1G

.control
pre_osdi ../../../osdilibs/hicumL0_v2p1p0.osdi
dc vb 0.2 1.4 0.01
set xbrushwidth=2
plot abs(i(vc)) abs(i(vb)) abs(i(vs)) ylimit 0.1p 100m ylog
plot abs(i(vc))/abs(i(vb)) vs abs(i(vc)) xlog xlimit 100p 100m  ylimit 0 200 retraceplot
.endc

.include ../Modelcards/model-card-hicumL0V1p11_mod.lib

.end
