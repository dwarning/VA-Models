MEXTRAM Noise Test

vcc 4 0 26
vin 1 0 dc 0 ac 1

ccouple 1 b 1

ibias 0 b 100u

rload 4 c 1k noisy=0

NQ1 C B 0 0 BJTRF1

*.model BJTRF1 bjt504va
*.model BJTRF1 bjt504tva
.model BJTRF1 bjt505va
*.model BJTRF1 bjt505tva

.control
*pre_osdi ../../osdilibs/bjt504.osdi
*pre_osdi ../../osdilibs/bjt504t.osdi
pre_osdi ../../osdilibs/bjt505.osdi
*pre_osdi ../../osdilibs/bjt505t.osdi
op
print all
noise v(3) vin dec 10 10 99Meg 1
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
