FBHHBT Gummel Test Ic,b=f(Vc,Ib) Vce=1V

IB 0 B 1m
VC C 0 1.0

NQ1 C B 0 T fbhhbt
RT T 0 1.0

.control
pre_osdi ../osdilibs/fbhhbt-2.3.osdi
option gmin=1e-13
dc vc 0 5 0.1 ib 1m 10m 1m
plot abs(i(vc))
plot v(t)
.endc

.model fbhhbt HBT_X
*+ Jsf=1e-15
*+ Jse=1e-17

.end
