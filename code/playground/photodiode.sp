Photodiode test

.control
pre_osdi photodiode.osdi
dc Vdiode -5 0.85 0.01 Vlp 0 40m 10m
plot i(Vdiode)
.endc

Vdiode a 0 -2.0
Vlp lpower 0 1e-3
nd1 a 0 lpower phdiode

.model phdiode photodiode

.end