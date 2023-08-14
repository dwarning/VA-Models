r3_cmc

v1 1 0 10
Nr3_cmc 1 0 0 dt poly_87OhmPerSquare w=1.05u l=42u

* Poly resistor, r2_cmc model
.include ../Modelcards/poly_87OhmPerSquare.par

.control
pre_osdi ../../osdilibs/r3_cmc.osdi
op
let res = v(1)/-v1#branch
print res
dc v1 -9.9 9.9 0.2 temp -40 160 40
plot v(1)/-v1#branch
*plot v(dt)
.endc

.end
