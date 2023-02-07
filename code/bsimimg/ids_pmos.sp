bsimimg PMOS Test

* one voltage source per MOS terminal:
VD d 0 -0.05
VG fg 0 -1
VS s 0 0
VB bg 0 0

* model definitions:
.model pch bsimimg
+ TYPE = -1
+ RSC =10m
+ RDC =10m

N1 d fg s bg pch W=1e-6 L=1e-7

.control
pre_osdi ../osdilibs/bsimimg.osdi
set xbrushwidth=3
dc VG 0 -1.0 -0.01 VB 0 1.0 0.2
plot i(VS)
dc Vd 0 -1.2 -0.01 VG 0.5 -1.0 -0.1
plot i(VS)
.endc

.end
