** MOSFET Gain Stage (AC): Benchmarking Implementation of BSIM4.8.0 

NM1 d g 0 0 N1 L=0.09u W=4u
Rsource 1 g 100k
Rload d vdd 1k

Vdd vdd 0 1.8 
Vin 1 0 dc 0.8 ac 1

.control
pre_osdi ../../osdilibs/bsim4.osdi
op
print all
ac dec 10 100 1000Meg 
plot vdb(d)
.endc

.include "../Modelcards/modelcard.nmos"

.end
