.title ECL OR/NOR Gate MC10102
.include "../Modelcards/model-card-hicumL0V1p11_mod.lib"
V1 VEE GND -5.2
V2 IN1 GND dc -1.75 pulse(-1.75 -0.9 0 1n 1n 5u 10u)
V3 IN2 GND dc -1.75 pulse(-1.75 -0.9 0 1n 1n 2.5u 5u)
R1 GND Q1-Pad1 220
R2 GND Q3-Pad1 220
XQ1 Q1-Pad1 IN1 Q1-Pad3 VEE DT hicumL0V1p1_c_sbt
XQ2 Q1-Pad1 IN2 Q1-Pad3 VEE DT hicumL0V1p1_c_sbt
R5 Q1-Pad3 VEE 780
R3 GND Q3-Pad2 575
R4 Q3-Pad2 VEE 1.92k
XQ3 Q3-Pad1 Q3-Pad2 Q1-Pad3 VEE DT hicumL0V1p1_c_sbt
XQ4 GND Q3-Pad1 A1_OR VEE DT hicumL0V1p1_c_sbt
Ra1 A1_OR VEE 510
XQ5 GND Q1-Pad1 A2_NOR VEE DT hicumL0V1p1_c_sbt
Ra2 A2_NOR VEE 510
Rt1 DT GND 1G
.tran 0.1n 100u
.control
pre_osdi ../../osdilibs/hicumL0_v2p1p0.osdi
run
plot A1_OR A2_NOR+2 in1+4 in2+6
.endc
.end
