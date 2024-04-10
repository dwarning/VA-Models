** One-Bit Comparator (Tran): by Weidong Liu 5/16/2000.

NM1 Anot A Vdd Vdd  pch W=3.6u L=1.2u
NM2 Anot A 0 0 nch W=1.8u L=1.2u
NM3 Bnot B Vdd Vdd  pch W=3.6u L=1.2u
NM4 Bnot B 0 0 nch W=1.8u L=1.2u
NM5 AorBnot 0 Vdd Vdd pch W=1.8u L=3.6u
NM6 AorBnot B 1 0 nch W=1.8u L=1.2u
NM7 1 Anot 0 0 nch W=1.8u L=1.2u
NM8 Lnot 0 Vdd Vdd pch W=1.8u L=3.6u
NM9 Lnot Bnot 2 0 nch W=1.8u L=1.2u
NM10 2 A 0 0 nch W=1.8u L=1.2u
NM11 Qnot 0 Vdd Vdd pch W=3.6u L=3.6u
NM12 Qnot AorBnot 3 0 nch W=1.8u L=1.2u
NM13 3 Lnot 0 0 nch W=1.8u L=1.2u
NMQLO 8 Qnot Vdd Vdd  pch W=3.6u L=1.2u
NMQL1 8 Qnot 0 0 nch W=1.8u L=1.2u
NMLTO 9 Lnot Vdd Vdd pch W=3.6u L=1.2u
NMLT1 9 Lnot 0 0 nch W=1.8u L=1.2u
CQ Qnot 0 30f
CL Lnot 0 10f

Vdd Vdd 0 1.8
Va A 0  pulse 0 1.8 10ns .1ns .1ns 15ns 30ns
Vb B 0 0

.tran .1ns 60ns
.include ../Modelcards/ekv26_0u5.par

*----------------------------------------
.control
    pre_osdi ../../../osdilibs/ekv26.osdi
    run  
    plot A B v(9) v(8)
.endc

.end
