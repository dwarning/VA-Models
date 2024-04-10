Diode Param Temp Test

Va 1 0 dc=1 PULSE(1.5 -5 5n 1n 1n 40n 80n)
R1 1 Anode 1.0
nd1 Anode 0 diolau
.save all

.control
pre_osdi diode_basic.osdi
dc va 0.01 1.5 0.01 temp -25 125 50
plot abs(i(va)) vs v(Anode) ylog
tran 10p 40n
plot -va#branch v(anode) nd1#qm*1e8
.endc

.MODEL diolau diode_basic Is=1n N=1 Rs=10m Cjo=100p M=.5 tt=4n tau=50n

.end

