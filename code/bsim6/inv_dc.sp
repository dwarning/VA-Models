Sample netlist for BSIM6
*Inverter DC Analysis

.include "Modelcards/modelcard.nmos"
.include "Modelcards/modelcard.pmos"
* --- Voltage Sources ---
vdd   supply  0 dc=1.0
vin   vi 0 dc=0.5

* --- Inverter Subcircuit ---
.subckt inverter vin vout vdd gnd
    Np1 vout vin vdd vdd pmos W=20u L=10u
    Nn1 vout vin gnd gnd nmos W=10u L=10u
.ends

* --- Inverter ---
Xinv1  vi vo supply 0 inverter

* --- DC Analysis ---
.control
pre_osdi ../osdilibs/BSIM6.1.1.osdi
dc vin 0 1 0.01
plot v(vi) v(vo)
.endc

.end
