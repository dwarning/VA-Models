Id-Vd Characteristics for PSP_HV 

.include Modelcards/nld25

* --- Voltage Sources ---
vd drain 0 dc 0.1
vg gate 0 dc 1.0
vs source 0 dc 0
vb substrate 0 dc 0

* --- Transistor ---
nx1 drain gate source substrate t nld25 W=100e-6 L=1e-6

* --- DC Analysis ---
.control
pre_osdi ../../osdilibs/psphv.osdi
dc vg 0 5 0.01 vb 0 -2 -0.5
plot -i(vd)
dc vd 0 25 0.05 vg 1.5 5.0 1.0
plot -i(vd)
settype temperature v(t)
plot v(t)
.endc
.end
