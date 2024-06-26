r2_cmc

v1 1 0 10
NRr2_cmc 1 0 rmodel w=1u l=20u isnoisy=1

* Poly resistor, r2_cmc model
.model rmodel r2_cmc(level=2 rsh=200 xl=0.2u xw=-0.05u p3=0.12 q3=1.6 p2=0.015 q2=3.8 tc1=1.5e-4 tc2=7e-7)

.control
pre_osdi ../../osdilibs/r2_cmc.osdi
op
let res = v(1) / -v1#branch
print res
dc v1 -9.9 9.9 0.2 temp -40 160 40
plot v(1)/-v1#branch
.endc

.end
