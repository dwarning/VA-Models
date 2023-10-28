HICUM/L2 version 3.0.0 Noise Test

vcc 4 0 26
vin 1 0 ac 1

ccouple 1 b 1

ibias 0 b 100uA

rload 4 c 1k noisy=0

NQ1 C B 0 0 hicumL2va
.include ../Modelcards/examples.lib

.control
pre_osdi ../../osdilibs/hicumL2.osdi
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
