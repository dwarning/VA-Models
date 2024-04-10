BSIMBULK noise test

nm1 out in 0 0 nmos W=100u L=10u

Vin in 0 dc 0.9 ac 1
Vdd vdd 0 1.5
Rl out vdd 620 noisy=0

.include ../Modelcards/model.l

.control
pre_osdi ../../../osdilibs/bsimbulk.osdi
noise v(out) vin dec 10 10 1G 1
setplot noise1
plot ally
plot inoise_spectrum onoise_spectrum loglog
setplot noise2
print all
.endc

.END
