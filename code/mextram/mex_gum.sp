MEXTRAM Gummel Test Ic,b,s=f(Vc,Ib)

.model BJTRF1 bjt504va
*.model BJTRF1 bjt504tva
*.model BJTRF1 bjt505_va
*.model BJTRF1 bjt505t_va

VB B 0 0.5
VC C 0 1.0
VS S 0 0.0
NQ1 C B 0 S BJTRF1
*RT dt 0 100

.control
pre_osdi ../osdilibs/bjt504.osdi
*pre_osdi ../osdilibs/bjt504t.osdi
*pre_osdi ../osdilibs/bjt505.osdi
*pre_osdi ../osdilibs/bjt505t.osdi
dc vb 0.2 1.4 0.01
plot abs(i(vc)) abs(i(vb)) abs(i(vs)) ylog xlimit 0.3 1.4 ylimit 1e-12 100e-3
plot abs(i(vc))/abs(i(vb)) vs abs(-i(vc)) xlog xlimit 1e-09 10e-3 ylimit 0 200
.endc


.end
