OSDI BSIMCMG Test

VD d 0 -0.05
VG g 0 -1
VS s 0 0
VB e 0 0

.include Modelcards/modelcard.pmos

*OSDI BSIMCMG:
N1 d g s e BSIMCMG_osdi_P L=0.2u NF=20

.control
pre_osdi ../osdilibs/bsimcmg.osdi
dc Vg 0.0 -1.0 -0.01
plot -i(VD)
dc Vd 0 -1.0 -0.01 VG -0.5 -1.0 -0.1
plot -i(VD)
.endc

.end
