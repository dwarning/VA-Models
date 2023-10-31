PSP103 noise test

nm1 out in 0 0 nch
+l=0.1u
+w=1u
+sa=0.0e+00
+sb=0.0e+00
+absource=1.0e-12
+lssource=1.0e-06
+lgsource=1.0e-06
+abdrain=1.0e-12
+lsdrain=1.0e-06
+lgdrain=1.0e-06
+mult=1.0e+00

Vin in 0 dc 0.9 ac 1
Vdd vdd 0 1.5
Rl out vdd 1e2 noisy=0

.include ../Modelcards/psp103_nmos-2.mod

.control
pre_osdi ../../osdilibs/psp103.osdi
noise v(out) vin dec 10 10 10G 1
setplot noise1
plot ally
plot inoise_spectrum onoise_spectrum loglog
setplot noise2
print all
.endc

.END
