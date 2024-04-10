** One-Shot Trigger (Tran): Benchmarking Implementation of BSIM4.8.0 

NMd1 4 in Vdd Vdd  P1 W=3.6u L=0.2u
NMd2 4 in 0 0 N1 W=1.8u L=0.2u
c4 4 0 100f
NMd3 A 4 Vdd Vdd  P1 W=3.6u L=0.2u 
NMd4 A 4 0 0 N1 W=1.8u L=0.2u
ca a 0 100f

NM1 Anot A Vdd Vdd  P1 W=3.6u L=0.2u
NM2 Anot A 0 0 N1 W=1.8u L=0.2u

NM3 Bnot in Vdd Vdd  P1 W=3.6u L=0.2u
NM4 Bnot in 0 0 N1 W=1.8u L=0.2u

NM5 AorBnot 0 Vdd Vdd P1 W=1.8u L=3.6u
NM6 AorBnot in 1 0 N1 W=1.8u L=0.2u
NM7 1 Anot 0 0 N1 W=1.8u L=0.2u

NM8 Lnot 0 Vdd Vdd P1 W=1.8u L=3.6u
NM9 Lnot Bnot 2 0 N1 W=1.8u L=0.2u
NM10 2 A 0 0 N1 W=1.8u L=0.2u

NM11 out 0 Vdd Vdd P1 W=3.6u L=3.6u
NM12 out AorBnot 3 0 N1 W=1.8u L=0.2u
NM13 3 Lnot 0 0 N1 W=1.8u L=0.2u

Vcc vdd 0 1.8
vin in 0 pulse 0 1.8 1ns .1ns .1ns .8ns 5ns

.include "../Modelcards/modelcard.nmos"
.include "../Modelcards/modelcard.pmos"

.control
pre_osdi ../../../osdilibs/bsim4.osdi
tran 1ns 10ns
plot in out
.endc

.end
