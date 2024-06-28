VBIC self heating

.include ../Modelcards/SG13G2_hbt_woStatistics.hsp.lib
.param sfh=1
.csparam sfh='sfh'

vc c 0 1.5
ib 0 b 10u
vs s 0 0
XQ1 C B 0 S npn13G2 nx=8 selft=sfh

.control
pre_osdi ../../../osdilibs/vbic_1p3.osdi
let rth_est=14e3
save all
op
print all
dc vc 0.0 1.5 0.05 ib 2u 20u 2u
alterparam sfh=0
reset
dc vc 0.0 1.5 0.05 ib 2u 20u 2u
plot abs(dc1.i(vc)) abs(dc2.i(vc))
plot 'rth_est/8*abs(dc1.i(vc))*abs(dc1.v(c))' dc1.n.xq1.nqnpn13g2#dt
.endc

.end

