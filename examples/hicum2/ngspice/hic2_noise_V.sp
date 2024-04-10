HICUM/L2 version 3.0.0 Noise Voltage Test

*      _______
*    _|_     _|_
*    ///    / _ \
*           \/ \/ I1
*           /\_/\
*           \___/
*      _______|
*     |      _|
*     |____|'
*     B    |`->
*            _|_ E
*           /VIN\
*           \___/
*            _|_
*            ///
*
*

vin               E  0  DC    0.0 ac 1
I1                0  B 10uA
nq1               B  B E    hicumL2va M=4


.include ../Modelcards/examples.lib

.control
pre_osdi ../../osdilibs/hicumL2.osdi
setplot           new 

let               V10u  = 0*vector(91)
let               V100u = 0*vector(91)
let               V1m   = 0*vector(91)
let               V10m  = 0*vector(91)

op
print all
noise             v(B) vin dec 10 1 1G 1
destroy
let               unknown1.V10u = sqrt(v(onoise_spectrum))

alter             I1      dc  = 100u
op
print all
noise             v(B) vin dec 10 1 1G 1
destroy
let               unknown1.V100u = sqrt(v(onoise_spectrum))

alter             I1      dc  = 1m
op
print all
noise             v(B) vin dec 10 1 1G 1
destroy
let               unknown1.V1m = sqrt(v(onoise_spectrum))

alter             I1      dc  = 10m
op
print all
noise             v(B) vin dec 10 1 1G 1
destroy
let               unknown1.V10m = sqrt(v(onoise_spectrum))


set pensize =     2
plot unknown1.V10u unknown1.V100u unknown1.V1m unknown1.V10m vs frequency xlimit 1 1e9 loglog title HICUM2_NoiseVoltage

echo              "    ... done."
.endcontrol
.end
