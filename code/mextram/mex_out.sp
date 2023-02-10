MEXTRAM Output Test Ic=f(Vc,Ib)

*.model BJTRF1 bjt504va
*.model BJTRF1 bjt504tva
*.model BJTRF1 bjt505_va
.model BJTRF1 bjt505t_va

IB 0 B 1u
VC C 0 2.0
VS S 0 0.0
*NQ1 C B 0 S BJTRF1
NQ1 C B 0 S dt BJTRF1

.control
*pre_osdi ../osdilibs/bjt504.osdi
*pre_osdi ../osdilibs/bjt504t.osdi
*pre_osdi ../osdilibs/bjt505.osdi
pre_osdi ../osdilibs/bjt505t.osdi
dc vc 0 5.0 0.05 ib 2u 10u 2u
plot abs(i(vc)) xlabel Vce title Output-Characteristic
settype temperature v(dt)
plot v(dt)
.endc

.end
