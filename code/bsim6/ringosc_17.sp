Sample netlist for BSIM6
*17-stage ring oscillator

.include "Modelcards/modelcard.nmos"
.include "Modelcards/modelcard.pmos"

* --- Voltage Sources ---
vdd supply  0 dc=1.0

* --- Inverter Subcircuit ---
.subckt inverter vin vout vdd gnd
    Np1 vout vin vdd vdd pmos  W=20e-6 L=10e-6 
    Nn1 vout vin gnd gnd nmos  W=10e-6 L=10e-6 
.ends

* --- 17 Stage Ring oscillator ---
Xinv1   1  2 supply 0 inverter
Xinv2   2  3 supply 0 inverter
Xinv3   3  4 supply 0 inverter
Xinv4   4  5 supply 0 inverter
Xinv5   5  6 supply 0 inverter
Xinv6   6  7 supply 0 inverter
Xinv7   7  8 supply 0 inverter
Xinv8   8  9 supply 0 inverter
Xinv9   9 10 supply 0 inverter
Xinv10 10 11 supply 0 inverter
Xinv11 11 12 supply 0 inverter
Xinv12 12 13 supply 0 inverter
Xinv13 13 14 supply 0 inverter
Xinv14 14 15 supply 0 inverter
Xinv15 15 16 supply 0 inverter
Xinv16 16 17 supply 0 inverter
Xinv17 17  1 supply 0 inverter

* --- Initial Condition ---
*.ic  1=1

.control
pre_osdi ../osdilibs/BSIM6.1.1.osdi
tran 1n 10u
plot v(1)
meas tran t1 when v(1)=0.5 cross=1
meas tran t2 when v(1)=0.5 cross=7
let period=(t2-t1)/3
print period
let delay_per_stage=period/34
print delay_per_stage
.endc

.end


