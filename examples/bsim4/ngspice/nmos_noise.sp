MOSFET Gain Stage (AC): Benchmarking Implementation of BSIM4.8.0 

NM1 d g 0 0 n1 W = 10e-6 L = 1e-6 nf=1
Rsource 1 g 100k noisy=0
Rload d vdd 1k noisy=0

Vdd vdd 0 1.8 
Vin 1 0 dc 0.8 ac 1

.include "../Modelcards/modelcard.nmos"

.control
pre_osdi ../../../osdilibs/bsim4.osdi
noise v(d) Vin dec 10 100 990Meg 
setplot noise1
plot ally
plot inoise_spectrum onoise_spectrum loglog
setplot noise2
print all
echo
print inoise_total onoise_total
.endc

.end
