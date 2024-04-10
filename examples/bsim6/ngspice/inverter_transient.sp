Sample netlist for BSIM6
*Inverter Transient

.include "../Modelcards/modelcard.nmos"
.include "../Modelcards/modelcard.pmos"

* --- Voltage Sources ---
vdd   supply  0 dc=1.0
vin  vi  0 dc=0.5 sin (0.5 0.5 1MEG)

* --- Inverter Subcircuit ---
.subckt inverter vin vout vdd gnd
    Np1 vout vin vdd vdd pmos W=20u L=10u 
    Nn1 vout vin gnd gnd nmos W=10u L=10u 
.ends

* --- Inverter ---
Xinv1  vi 1 supply 0 inverter
Xinv2  1 2 supply 0 inverter
Xinv3  2 3 supply 0 inverter
Xinv4  3 4 supply 0 inverter
Xinv5  4 vo supply 0 inverter

* --- Transient Analysis ---
.control
pre_osdi ../../osdilibs/BSIM6.1.1.osdi
tran 10n 5u
plot v(vi) v(vo)
.endc

.end
