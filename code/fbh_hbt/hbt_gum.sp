FBHHBT Gummel Test Ic,b=f(Vc,Ib) Vce=1V

VB B 0 1.0
VC C 0 1.0

NQ1 C B 0 T fbhhbt
RT T 0 1.0

.control
pre_osdi ../osdilibs/fbhhbt-2.3.osdi
option gmin=1e-13
dc vb 0.5 1.5 0.01
*plot i(vc) i(vb)
*gnuplot fgum i(vc) i(vb) xlimit 0.2 1.2 ylog ylimit 1e-12 0.1
plot abs(i(vc)) abs(i(vb)) xlimit 0.5 1.5 ylog; ylimit 1e-14 0.1
plot abs(i(vc))/abs(i(vb)) vs abs(i(vc)) xlog xlimit 1e-09 1000e-3; ylimit 0 500
.endc

.model fbhhbt HBT_X
*+ Jsf=1e-15
*+ Jse=1e-17

.end
