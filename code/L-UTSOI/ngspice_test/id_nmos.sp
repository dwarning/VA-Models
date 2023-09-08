Id-Vd Characteristics for L_UTSOI NMOS 

.model nmos1 l_utsoi type=1

* --- Voltage Sources ---
vd drain 0 dc=0.05
vg gate 0 dc=1
vs source 0 dc=0
vb substrate 0 0

* --- Transistor ---
nx1 drain gate source substrate nmos1 W=1e-6 L=1e-7
*nx1 drain gate source substrate nmos1 W=1e-6 L=1e-7
*nx1 drain gate source substrate nmos1 W=1e-6 L=1e-7
*nx1 drain gate source substrate 0 0 t nmos1 W=1e-6 L=1e-7

* --- DC Analysis ---
.control
pre_osdi ../../osdilibs/L_UTSOI_102.osdi
dc vg 0 1.2 0.01 vb 0 -1 -0.2
plot -i(vd)
dc vd 0 1.2 0.01 vg 0.5 1.2 0.1
plot -i(vd)
*plot v(t)
.endc
.end
