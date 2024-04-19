OSDI EKV3 NMOS Test
*.options abstol=1e-15

* one voltage source per MOS terminal:
VD d 0 0.1
VG g 0 1
VS s 0 0
VB b 0 0

* model definitions:
.include ../Modelcards/90nm_ngspice.lib

*OSDI EKV:
X1 d g s b nch90 W=5e-6 L=0.5e-6

.control
pre_osdi ../../../osdilibs/ekv3.osdi
set xbrushwidth=3
dc Vg 0 1.5 0.01 Vb 0 -1.5 -0.5
plot -i(VD)
dc Vd 0 1.5 0.01 Vg 0 1.5 0.3
plot -i(VD)
.endc

.end
