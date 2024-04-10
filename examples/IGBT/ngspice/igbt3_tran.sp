transient test circuit for igbt model 

.model igbt3 igbt3

va Vaa 0 dc=300
LL Vaa 1 80u
RL 1 a 30
ni1 a g 0 igbt3 kp=1.5 tau=7.1u
*vg gg 0 dc=10 SIN(0 10 1kHz)
vg gg 0 dc=10 PULSE(0 20 20us 20ns 20ns 50us 100us)
Rg gg g 100

*.option abstol=1e-10; gear
.control
pre_osdi ../../../osdilibs/igbt3.osdi
op
*tran 20u 5m
tran 10n 100u uic
plot v(g) v(a)
plot -i(va)
.endc
.end
