OSDI EKV 2.6 dioden test

.include ../Modelcards/ekv26_0u5.par

vd  d 0 dc 0.0
vg  g 0 dc 0.0
vs  s 0 dc 0.0
vb  b 0 dc 0.0
*N1 d g s b nch W=5e-6 L=0.5e-6
N1 d g s b pch W=5e-6 L=0.5e-6

.control
pre_osdi ../../../osdilibs/ekv26.osdi
dc vb 3 -0.1 -0.01 temp -50 150 50
plot i(vd)
.endc
*
.end

