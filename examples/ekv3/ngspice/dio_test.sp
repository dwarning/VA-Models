OSDI EKV3 diode test

.include ../Modelcards/90nm_ngspice.lib

vd  d 0 dc 0.0
vg  g 0 dc 0.0
vs  s 0 dc 0.0
vb  b 0 dc 0.0
*X1 d g s b nch90 W=5e-6 L=0.5e-6
X1 d g s b pch90 W=5e-6 L=0.5e-6

.control
pre_osdi ../../../osdilibs/ekv3.osdi
dc vb 1.5 -0.1 -0.01 temp -50 150 50
plot i(vd)
.endc
*
.end

