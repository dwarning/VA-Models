* Sample netlist: Inverter DC *

.option post ingold numdgt=10
.temp 27

*.hdl "bsimbulk.va"
.include Modelcards/model.l

v1 vdd 0 dc=1.0
v2 in 0 dc=0.5

.subckt inv vin vout vdd vss
    nmn vout vin vss vss BSIMBULK_osdi_N W=10u L=1u
    nmp vout vin vdd vdd BSIMBULK_osdi_P W=10u L=1u
.ends

x1 in out vdd 0 inv

.dc v2 0.0 1 0.01

.control
pre_osdi ../osdilibs/bsimbulk107.osdi
run
plot v(in) v(out)
.endc

.end
