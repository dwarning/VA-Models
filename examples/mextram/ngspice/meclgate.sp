Motorola MECL III ECL gate

vee 22 0 -6.0
vin 1 0 pulse -0.8 -1.8 0.2ns 0.2ns 0.2ns 10ns 20ns
rs 1 2 50
nq1 4 2 6 22 BJTRF1
nq2 4 3 6 22 BJTRF1
nq3 5 7 6 22 BJTRF1
nq4 0 8 7 22 BJTRF1

d1 8 9 dmod
d2 9 10 dmod

rp1 3 22 50k
rc1 0 4 100
rc2 0 5 112
re 6 22 380
r1 7 22 2k
r2 0 8 350
r3 10 22 1958

nq5 0 5 11 22 BJTRF1
nq6 0 4 12 22 BJTRF1

rp2 11 22 560
rp3 12 22 560

nq7 13 12 15 22 BJTRF1
nq8 14 16 15 22 BJTRF1

re2 15 22 380
rc3 0 13 100
rc4 0 14 112

nq9 0 17 16 22 BJTRF1

r4 16 22 2k
r5 0 17 350
d3 17 18 dmod
d4 18 19 dmod
r6 19 22 1958

nq10 0 14 20 22 BJTRF1
nq11 0 13 21 22 BJTRF1

rp4 20 22 560
rp5 21 22 560

.model dmod d rs=40 tt=0.1ns cjo=0.9pf n=1 is=1e-14 eg=1.11 vj=0.8 m=0.5

*.model BJTRF1 bjt504_va
*.model BJTRF1 bjt504t_va
.model BJTRF1 bjt505_va
*.model BJTRF1 bjt505t_va


*.options acct bypass=1
*.SAVE v(12) v(21)
.control
*pre_osdi ../../../osdilibs/bjt504.osdi
*pre_osdi ../../../osdilibs/bjt504t.osdi
pre_osdi ../../../osdilibs/bjt505.osdi
*pre_osdi ../../../osdilibs/bjt505t.osdi
*op
*dc vin -2.0 0 0.02
tran 0.2ns 200ns
plot v(12) v(21)
.endc
.end
