Sample netlist for BSIM-CMG 
* (exec-spice "ngspice %s" t)
*Inverter Transient

.include Modelcards/modelcard.nmos
.include Modelcards/modelcard.pmos
* --- Voltage Sources ---
vdd   supply  0 dc=1.0
vsig  vi  0 dc=0.5 sin (0.5 0.5 1MEG)
Vss   ss      0 0

* --- Inverter Subcircuit ---
.subckt mg_inv vin vout vdd vss
NP1 vout vin vdd vdd BSIMCMG_osdi_P  TFIN=15n L=40n NFIN=20 NRS=1 NRD=1
NN1 vout vin vss vss BSIMCMG_osdi_N  TFIN=15n L=40n NFIN=10 NRS=1 NRD=1 D=40n
.ends

* --- Inverter ---
Xinv1  vi 1 supply ss mg_inv
Xinv2  1 2 supply ss mg_inv
Xinv3  2 3 supply ss mg_inv
Xinv4  3 4 supply ss mg_inv
Xinv5  4 vo supply ss mg_inv

* --- Transient Analysis ---
.tran 20n 5u

.control
pre_osdi ../osdilibs/bsimcmg.osdi
run
plot v(vi) v(vo)
.endc

.end
