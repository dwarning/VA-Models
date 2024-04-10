* Sample netlist: Inverter DC *

.temp 27

*.hdl "bsimbulk.va"
.include ../Modelcards/model.l

v1 vdd 0 dc=1.0
v2 in 0 dc=0.5

.subckt inv vin vout vdd vss
    nmn vout vin vss vss nmos W=10u L=10u
    nmp vout vin vdd vdd pmos W=10u L=10u
.ends

x1 in out vdd 0 inv

.dc v2 0.0 1 0.01

.control
pre_osdi ../../osdilibs/bsimbulk.osdi
run
plot v(in) v(out)
.endc

.end
