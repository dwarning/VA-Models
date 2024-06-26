* 51 stage Ring-Osc.

.include "../Modelcards/modelcard.pmos"
.include "../Modelcards/modelcard.nmos"

vin in out 2 pulse 2 0 0.1n 5n 1 1 1
vdd dd 0 dc 0 pulse 0 1.5 0 1n 1 1 1
vss ss 0 dc 0
ve  sub  0 dc 0

xinv1 dd ss sub in out25 inv25 
xinv2 dd ss sub out25 out50 inv25
xinv5 dd ss sub out50 out inv1
xinv11 dd ss sub out buf inv1
cout  buf ss 1pF

.control
pre_osdi ../../../osdilibs/bsimsoi.osdi
option reltol=1e-4
*option itl1=1000 itl4=20 temp=85 gmin=1e-15 abstol=1e-12 reltol=1e-4
tran 0.2n 10n
plot v(out25) v(out50)
.endc

.subckt inv1 dd ss sub in out
nn1  out in  ss sub  nmos1  w=4u  l=0.15u  AS=6p AD=6p PS=7u PD=7u pdbcp=0u
np1  out in  dd sub  pmos1  w=10u l=0.15u  AS=15p AD=15p PS=13u PD=13u pdbcp=0u 
.ends 

.subckt inv5 dd ss sub in out
xinv1 dd ss sub in 1 inv1
xinv2 dd ss sub 1  2 inv1
xinv3 dd ss sub 2  3 inv1
xinv4 dd ss sub 3  4 inv1
xinv5 dd ss sub 4 out inv1
.ends 

.subckt inv25 dd ss sub in out
xinv1 dd ss sub in 1 inv5
xinv2 dd ss sub 1  2 inv5
xinv3 dd ss sub 2  3 inv5
xinv4 dd ss sub 3  4 inv5
xinv5 dd ss sub 4 out inv5
.ends 

.end
