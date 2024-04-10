Ask for small signal values of vbic model

.include ../Modelcards/Infineon_VBIC.lib

v1 1 0 dc 5.0
*rc 1 c 2k
vb b 0 dc 0.6
nq1 1 b 0 T M_BFP780

.control
pre_osdi ../../../osdilibs/vbic_1p3.osdi
save @nq1[gm] @nq1[go] @nq1[gpi]
save @nq1[cbe] @nq1[cbc]
save @nq1[qbe] @nq1[qbc]
dc v1 0.0 5 0.01
plot @nq1[gm] @nq1[go] @nq1[gpi]
plot @nq1[cbe] @nq1[cbc]
plot @nq1[qbe] @nq1[qbc]
.endc

.end
