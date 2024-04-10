Id-Vd Characteristics for PSP_HV 

.include Modelcards/psp103_params

* --- Voltage Sources ---
vd drain 0 dc 0.1
vg gate 0 dc 1.0
vs source 0 dc 0
vb substrate 0 dc 0

* --- Transistor ---
nx1 drain gate source substrate psp103hv W=10e-6 L=1e-6

* --- DC Analysis ---
.control
pre_osdi ../osdilibs/psphv.osdi
dc vg 0 1.5 0.01 vb 0 -2 -0.5
plot -i(vd)
dc vd 0 3 0.01 vg 0.4 1.6 0.2
plot -i(vd)
.endc
.end
