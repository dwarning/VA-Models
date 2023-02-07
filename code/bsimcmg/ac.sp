Sample netlist for BSIM-MG
*AC Response 

*.hdl "bsimcmg.va"
.include Modelcards/modelcard.nmos

.param myvdd=1.2

* --- Voltage Sources ---
vdd supply  0 dc=myvdd
vsig  gate  0 dc=0.5 ac=1
vbs bulk 0 dc=0

* --- Transistor ---
nm1 vout gate 0 bulk 0 BSIMCMG_osdi_N TFIN=15n L=30n NFIN=10 NRS=1 NRD=1
+ FPITCH  = 4.00E-08

* --- Load ---
rl supply vout r=6k
cl supply vout c=10f

* --- AC Analysis ---
.ac dec 10 1k 1T

* For Bias Point Testing 
* .dc vsig -1 1.5 0.01

*.alter
*.param myvdd=2.0

.control
pre_osdi ../osdilibs/bsimcmg.osdi
run
show all
plot vdb(vout)
plot cph(vout)
.endc

.end

