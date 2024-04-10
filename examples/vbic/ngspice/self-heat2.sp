VBIC self heating

.include ../Modelcards/SG13G2_hbt_woStatistics.hsp.lib

vc c 0 2
ib 0 b 1u
vs s 0 0
XQ1 C B 0 S npn13G2 nx=1
*XQ1 C B 0 S npn13G2l nx=1
*XQ1 C B 0 S npn13G2v nx=1

.control
pre_osdi ../../../osdilibs/vbic_1p3.osdi
let rth_est=11e3
save all
op
print all
dc vc 0.0 1.6 0.05 ib .1u 1u .1u
altermod @n.xq1.nqnpn13g2[RTH]=0
dc vc 0.0 1.6 0.05 ib .1u 1u .1u
plot abs(dc1.i(vc)) abs(dc2.i(vc))
plot 'rth_est*abs(dc1.i(vc))*abs(dc1.v(c))'
.endc

.end

