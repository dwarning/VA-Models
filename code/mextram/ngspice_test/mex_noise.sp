MEXTRAM Noise Test

vcc 4 0 50
vin 1 0 ac 1

ccouple 1 2 1

ibias 0 2 100uA

rload 4 3 1k noisy=0

NQ1 3 2 0 0 BJTRF1

.model BJTRF1 bjt505_va

.control
pre_osdi ../../osdilibs/bjt505.osdi
noise v(3) vin dec 10 10 99Meg 1
setplot
setplot noise1
plot ally
plot inoise_spectrum
plot onoise_spectrum
setplot noise2
print all
echo
print inoise_total onoise_total
.endc

.end
