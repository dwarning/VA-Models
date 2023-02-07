* Initial Height Delay Tr Tf Width Period
vin in 0 pulse 0.1 0.9 0.0 1p 1p 32p 64p
vdd 1 0 DC 1.0

.subckt Inv in out vdd
* Invokes the BSIM CMG111.1.0 paramset infile ‘Top.v‘.
Nxp1 out in vdd 0 BSIMCMG_osdi_P L=30n
Nxn1 out in 0 0 BSIMCMG_osdi_N L=30n
.ends

.subckt Ten in out vdd
x1 in n1 vdd Inv
x2 n1 n2 vdd Inv
x3 n2 n3 vdd Inv
x4 n3 n4 vdd Inv
x5 n4 n5 vdd Inv
x6 n5 n6 vdd Inv
x7 n6 n7 vdd Inv
x8 n7 n8 vdd Inv
x9 n8 n9 vdd Inv
x10 n9 out vdd Inv
.ends

.subckt Fifty in out vdd
x1 in n1 vdd Ten
x2 n1 n2 vdd Ten
x3 n2 n3 vdd Ten
x4 n3 n4 vdd Ten
x5 n4 out vdd Ten
.ends

x100A in outA 1 Fifty
x100B in outB 1 Fifty
x100C in outC 1 Fifty
x100D in outD 1 Fifty
x100E in outE 1 Fifty
x100F in outF 1 Fifty

.control
pre_osdi ../osdilibs/bsimcmg.osdi

tran 2p 1.2n

* write ascii rawfile
*set filetype=ascii
*write

rusage equations tranpoints accept rejected totiter loadtime

*plot pointplot in outA outB outC outD outE outF
plot in outA outB outC outD outE outF
.endc

.include Modelcards/modelcard.nmos
.include Modelcards/modelcard.pmos

.end