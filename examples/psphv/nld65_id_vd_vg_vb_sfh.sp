Id-Vd Characteristics for PSP_HV 

.include Modelcards/nld65
+gtho=0.05

* --- Voltage Sources ---
vd drain 0 dc 0.1
vg gate 0 dc 1.0
vs source 0 dc 0
vb substrate 0 dc 0

* --- Transistor ---
nx1 drain gate source substrate t nld65 W=100e-6 L=1e-6

* --- DC Analysis ---
.control
pre_osdi ../../osdilibs/psphv.osdi
dc vg 0 5 0.01 vb 0 -2 -0.5
plot -i(vd)
dc vd 0 60 0.05 vg 1.5 5.0 0.5
plot -i(vd)
settype temperature v(t)
plot v(t)
.endc
.end
