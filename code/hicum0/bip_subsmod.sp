Bip model in subckt Gummel Test Ic=f(Vc,Vb)

VB B 0 0.5
VC C 0 1.0
VS S 0 0.0
X1 C B 0 S T bip_default

.control
pre_osdi ../osdilibs/HICUML0-2.osdi
dc vb 0.35 1.2 0.01
plot abs(i(vc)) abs(i(vb)) abs(i(vs)) ylimit 0.1p 1.0 ylog
plot abs(i(vc))/abs(i(vb)) vs abs(i(vc)) xlog xlimit 1n 1  ylimit 0 150 retraceplot
.endc

********************************************************************************
* Complete test transistor: default
********************************************************************************
.subckt bip_default c b e s dt
nqhcm0 c b e s dt hic0_full
.model hic0_full hic0_full
.ends bip_default
********************************************************************************

.end
