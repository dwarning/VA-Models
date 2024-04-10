HICUM/L2 version 3.0.0 Noise Current Test

*      _______
*    _|_     _|_
*    ///    / _ \
*           \/ \/ I1
*           /\_/\
*     R1    \___/
*      _/\  __|
*     |   \/ _|
*     |____|'
*     B    |`->
*            _|_ E
*           /VIN\
*           \___/
*            _|_
*            ///
*
*

vin               E  0  DC    0.0 ac 1.0
I1                0  C 50uA
R1                C  B 1Meg noisy=0
nq1               C  B E    hicumL2va m=1

.include ../Modelcards/examples.lib

.control
pre_osdi ../../../osdilibs/hicumL2.osdi
setplot           new 

let               V50u  = 0*vector(91)
let               V100u = 0*vector(91)
let               V500u = 0*vector(91)
let               V1m   = 0*vector(91)

op
print all
noise             v(C) vin dec 10 1 1G 1
destroy
let               unknown1.V50u = sqrt(v(onoise_spectrum))/1Meg

alter             I1      dc  = 100u
op
print all
noise             v(C) vin dec 10 1 1G 1
destroy
let               unknown1.V100u = sqrt(v(onoise_spectrum))/1Meg

alter             I1      dc  = 500u
op
print all
noise             v(C) vin dec 10 1 1G 1
destroy
let               unknown1.V500u = sqrt(v(onoise_spectrum))/1Meg

alter             I1      dc  = 1m
op
print all
noise             v(C) vin dec 10 1 1G 1
destroy
let               unknown1.V1m = sqrt(v(onoise_spectrum))/1Meg


set pensize =     2
plot unknown1.V50u unknown1.V100u unknown1.V500u unknown1.V1m vs frequency xlimit 1 1e9 loglog title HICUM2_NoiseCurrent

echo              "    ... done."
.endcontrol
.end
