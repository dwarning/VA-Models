*****************==== 17-Stage CMOS RO ====*******************
***********Benchmarking Implementation of BSIM4.8.0
.include "../Modelcards/modelcard.nmos"
.include "../Modelcards/modelcard.pmos"

vdd 1 0 2.0
nmp1 3 2 1 1 p1 l=0.18u w=10u ad=5p pd=11u as=5p ps=11u
+ minsd=0 nf=2 SA=2u SB=8u NF=3 SD=0.2u 
nmn1 3 2 0 0 n1 l=0.18u w=5u
+ minsd=0 nf=1 SA=2u SB=8u NF=3 SD=0.2u 
nmp2 4 3 1 1 p1 l=0.18u w=10u ad=5p pd=11u as=5p ps=11u SA=2u SB=8u NF=3 SD=0.2u 
nmn2 4 3 0 0 n1 l=0.18u w=5u ad=5p pd=6u as=5p ps=6u SA=2u SB=8u NF=3 SD=0.2u 
nmp3 5 4 1 1 p1 l=0.18u w=10u ad=5p pd=11u as=5p ps=11u SA=2u SB=8u NF=3 SD=0.2u 
nmn3 5 4 0 0 n1 l=0.18u w=5u ad=5p pd=6u as=5p ps=6u  SA=2u SB=8u NF=3 SD=0.2u 
nmp4 6 5 1 1 p1 l=0.18u w=10u ad=5p pd=11u as=5p ps=11u  SA=2u SB=8u NF=3 SD=0.2u 
nmn4 6 5 0 0 n1 l=0.18u w=5u ad=5p pd=6u as=5p ps=6u  SA=2u SB=8u NF=3 SD=0.2u 
nmp5 7 6 1 1 p1 l=0.18u w=10u ad=5p pd=11u as=5p ps=11u  SA=2u SB=8u NF=3 SD=0.2u 
nmn5 7 6 0 0 n1 l=0.18u w=5u ad=5p pd=6u as=5p ps=6u  SA=2u SB=8u NF=3 SD=0.2u 
nmp6 8 7 1 1 p1 l=0.18u w=10u ad=5p pd=11u as=5p ps=11u  SA=2u SB=8u NF=3 SD=0.2u 
nmn6 8 7 0 0 n1 l=0.18u w=5u ad=5p pd=6u as=5p ps=6u  SA=2u SB=8u NF=3 SD=0.2u 
nmp7 9 8 1 1 p1 l=0.18u w=10u ad=5p pd=11u as=5p ps=11u  SA=2u SB=8u NF=3 SD=0.2u 
nmn7 9 8 0 0 n1 l=0.18u w=5u ad=5p pd=6u as=5p ps=6u  SA=2u SB=8u NF=3 SD=0.2u 
nmp8 10 9 1 1 p1 l=0.18u w=10u ad=5p pd=11u as=5p ps=11u  SA=2u SB=8u NF=3 SD=0.2u 
nmn8 10 9 0 0 n1 l=0.18u w=5u ad=5p pd=6u as=5p ps=6u  SA=2u SB=8u NF=3 SD=0.2u 
nmp9 11 10 1 1 p1 l=0.18u w=10u ad=5p pd=11u as=5p ps=11u  SA=2u SB=8u NF=3 SD=0.2u 
nmn9 11 10 0 0 n1 l=0.18u w=5u ad=5p pd=6u as=5p ps=6u  SA=2u SB=8u NF=3 SD=0.2u 
nmp10 12 11 1 1 p1 l=0.18u w=10u ad=5p pd=11u as=5p ps=11u SA=2u SB=8u NF=3 SD=0.2u  
nmn10 12 11 0 0 n1 l=0.18u w=5u ad=5p pd=6u as=5p ps=6u  SA=2u SB=8u NF=3 SD=0.2u 

nmp11 13 12 1 1 p1 l=0.18u w=10u ad=5p pd=11u as=5p ps=11u SA=2u SB=8u NF=3 SD=0.2u  
nmn11 13 12 0 0 n1 l=0.18u w=5u ad=5p pd=6u as=5p ps=6u  SA=2u SB=8u NF=3 SD=0.2u 
nmp12 14 13 1 1 p1 l=0.18u w=10u ad=5p pd=11u as=5p ps=11u SA=2u SB=8u NF=3 SD=0.2u  
nmn12 14 13 0 0 n1 l=0.18u w=5u ad=5p SA=2u SB=8u NF=3 SD=0.2u 
nmp13 15 14 1 1 p1 l=0.18u w=10u ad=5p pd=11u as=5p ps=11u  SA=2u SB=8u NF=3 SD=0.2u 
nmn13 15 14 0 0 n1 l=0.18u w=5u ad=5p pd=6u as=5p ps=6u  SA=2u SB=8u NF=3 SD=0.2u 
nmp14 16 15 1 1 p1 l=0.18u w=10u ad=5p ps=11u  SA=2u SB=8u NF=3 SD=0.2u 
nmn14 16 15 0 0 n1 l=0.18u w=5u ad=5p pd=6u as=5p ps=6u  SA=2u SB=8u NF=3 SD=0.2u 
nmp15 17 16 1 1 p1 l=0.18u w=10u ad=5p pd=11u as=5p ps=11u  SA=2u SB=8u NF=3 SD=0.2u 
nmn15 17 16 0 0 n1 l=0.18u w=5u ad=5p as=5p ps=6u  SA=2u SB=8u NF=3 SD=0.2u 
nmp16 18 17 1 1 p1 l=0.18u w=10u ad=5p pd=11u as=5p ps=11u  SA=2u SB=8u NF=3 SD=0.2u 
nmn16 18 17 0 0 n1 l=0.18u w=5u pd=6u as=5p ps=6u SA=2u SB=8u NF=3 SD=0.2u 
nmp17 2  18 1 1 p1 l=0.18u w=10u ad=5p pd=11u as=5p ps=11u SA=2u SB=8u NF=3 SD=0.2u 
nmn17 2  18 0 0 n1 l=0.18u w=5u ad=5p pd=6u as=5p ps=6u SA=2u SB=8u NF=3 SD=0.2u 
c1 18 0 .1p

.control
pre_osdi ../../../osdilibs/bsim4.osdi
tran .1ns 10ns
plot v(2) v(5)
.endc

.options acct reltol=1e-3 

.end
