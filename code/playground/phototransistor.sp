Phototransistor test

.control
pre_osdi phototransistor.osdi
dc Vc 0 3 0.01 Vlp 0 10m 1m
plot -i(Vc)
dc Vwl 500 1000 10
plot -i(Vc)
.endc

Ib 0 b 0.0
Vc c 0 3.0
Vlp lpower 0 10e-3
Vwl wl 0 800
nq1 c b 0 lpower wl phtransistor

.model phtransistor phototransistor

.end