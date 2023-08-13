** One-Shot Trigger (Tran): by Weidong Liu 5/16/2000.

NMd1 4 in Vdd Vdd  pch W=3.6u L=1.2u ad=4e-12 as=4e-12
NMd2 4 in 0 0 nch W=1.8u L=1.2u ad=2e-12 as=2e-12
c4 4 0 30f
NMd3 A 4 Vdd Vdd  pch W=3.6u L=1.2u ad=4e-12 as=4e-12
NMd4 A 4 0 0 nch W=1.8u L=1.2u ad=2e-12 as=2e-12
ca A 0 30f

NM1 Anot A Vdd Vdd  pch W=3.6u L=1.2u ad=4e-12 as=4e-12
NM2 Anot A 0 0 nch W=1.8u L=1.2u ad=2e-12 as=2e-12

NM3 Bnot in Vdd Vdd  pch W=3.6u L=1.2u ad=4e-12 as=4e-12
NM4 Bnot in 0 0 nch W=1.8u L=1.2u ad=2e-12 as=2e-12

NM5 AorBnot 0 Vdd Vdd pch W=1.8u L=3.6u ad=2e-12 as=2e-12
NM6 AorBnot in 1 0 nch W=1.8u L=1.2u ad=2e-12 as=2e-12
NM7 1 Anot 0 0 nch W=1.8u L=1.2u ad=2e-12 as=2e-12

NM8 Lnot 0 Vdd Vdd pch W=1.8u L=3.6u ad=4e-12 as=4e-12
NM9 Lnot Bnot 2 0 nch W=1.8u L=1.2u ad=2e-12 as=2e-12
NM10 2 A 0 0 nch W=1.8u L=1.2u ad=2e-12 as=2e-12

NM11 out 0 Vdd Vdd pch W=3.6u L=3.6u ad=4e-12 as=4e-12
NM12 out AorBnot 3 0 nch W=1.8u L=1.2u ad=2e-12 as=2e-12
NM13 3 Lnot 0 0 nch W=1.8u L=1.2u ad=2e-12 as=2e-12

Vcc Vdd 0 1.8
vin in 0 pulse(0 1.8 1ns .1ns .1ns .8ns 5ns)

.tran .1ns 10ns
*.op
.include ../Modelcards/ekv26_0u5.par

*----------------------------------------
.control
    pre_osdi ../../osdilibs/ekv26.osdi
    run  
    plot in out
.endc

.end
