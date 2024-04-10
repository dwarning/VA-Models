OSDI EKV 2.6 PMOS Test
*.options abstol=1e-15

* one voltage source per MOS terminal:
VD d 0 -0.1
VG g 0 -1
VS s 0 0
VB b 0 0

* model definitions:
.include ../Modelcards/ekv26_0u5.par

*OSDI EKV:
N1 d g s b pch W=10e-6 L=5e-7

.control
pre_osdi ../../../osdilibs/ekv26.osdi
set xbrushwidth=3
dc VG 0 -3.3 -0.01 VB 0 2.0 0.5
plot -i(VD)
dc Vd 0 -3.3 -0.01 VG 0 -3.3 -0.3
plot -i(VD)
.endc

.end
