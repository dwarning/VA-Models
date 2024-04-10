*Sample netlist for BSIM-CMG 
* (exec-spice "ngspice %s" t)
*Inverter DC

.include ../Modelcards/modelcard.nmos
.include ../Modelcards/modelcard.pmos
* --- Voltage Sources ---
vdd   supply  0 dc=1.0
vsig  vin  0 dc=0.5 sin (0.5 0.5 1MEG)

NP1 vout vin supply supply pmos  TFIN=15n L=40n NFIN=20 NRS=1 NRD=1
NN1 vout vin 0 0 nmos            TFIN=15n L=40n NFIN=10 NRS=1 NRD=1 D=40n

* --- DC Analysis ---
.dc vsig 0 1 0.01

* --- Transient Analysis ---
*.tran 10n 2u

.control
pre_osdi ../../osdilibs/bsimcmg.osdi
set xbrushwidth=3
run
plot v(vout) v(vin)
.endc

.end
