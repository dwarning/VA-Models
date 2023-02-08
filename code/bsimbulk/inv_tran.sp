* Sample netlist: Inverter transient *

*.hdl "bsimbulk.va"
.include Modelcards/model.l

v1 vdd 0 dc=1.0
v2 in 0 dc=0.5 sin(0.5 0.5 1meg)

.subckt inv vin vout vdd vss
    nmn vout vin vss vss BSIMBULK_osdi_N W=10u L=10u
    nmp vout vin vdd vdd BSIMBULK_osdi_P W=10u L=10u
.ends

x1 in 1 vdd 0 inv
x2 1 2 vdd 0 inv
x3 2 3 vdd 0 inv
x4 3 4 vdd 0 inv
x5 4 out vdd 0 inv

.tran 10n 5u

.control
pre_osdi ../osdilibs/bsimbulk107.osdi
run
rusage all
plot v(in) v(out)
.endc

.end
