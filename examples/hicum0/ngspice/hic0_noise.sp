HICUM/L0 version 2.1.0 Noise Test

vcc 4 0 26
vin 1 0 ac 1

ccouple 1 b 1

ibias 0 b 100uA

rload 4 c 1k noisy=0

XQ1 C B 0 0 DT hicumL0V1p1_c_sbt
.include ../Modelcards/model-card-hicumL0V1p11_mod.lib

.control
pre_osdi ../../osdilibs/hicumL0_v2p1p0.osdi
op
print all
echo
noise v(c) vin dec 10 10 10G 1
setplot
setplot noise1
plot ally
plot inoise_spectrum onoise_spectrum loglog
setplot noise2
print all
echo
print inoise_total onoise_total
.endc

.end
