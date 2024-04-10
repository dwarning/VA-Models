*Samle netlist for BSIM-MG
* (exec-spice "ngspice %s" t)
* Drain Noise Simulation 

.include ../Modelcards/modelcard.nmos

* --- Voltage Sources ---
vds 1 0 dc=1v
vgs gate 0 dc=0.6v ac=1
vbs bulk 0 dc=0v

* --- Circuit ---
lbias 1 drain 1m
cload drain 2 1m
rload 2 0 R=10k noise=0
N1 drain gate 0 bulk 0 nmos TFIN=15n L=30n NFIN=10 NRS=1 NRD=1
+ FPITCH = 4.00E-08

* --- Analysis ---
.control
pre_osdi ../../osdilibs/bsimcmg.osdi

op
print all

ac dec 11 100k 1000g
plot vdb(drain)

noise v(drain) vgs dec 11 10k 100g
setplot noise1
plot ally
plot inoise_spectrum onoise_spectrum loglog
setplot noise2
print all

echo "silence in the studio, no noise today"

.endc

.end

