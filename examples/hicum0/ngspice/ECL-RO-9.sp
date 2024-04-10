.title ECL nor gate ring oscillator, 9 stages, 734 MHz
.include "../Modelcards/model-card-hicumL0V1p11_mod.lib"

.subckt nor in1 in2 a1 a2 vee GND
XQ1 R1-Pad2 IN1 Q1-Pad3 VEE DT1 hicumL0V1p1_c_sbt
XQ2 R1-Pad2 IN2 Q1-Pad3 VEE DT1 hicumL0V1p1_c_sbt
XQ3 R2-Pad2 R3-Pad2 Q1-Pad3 VEE DT1 hicumL0V1p1_c_sbt
XQ4 GND R2-Pad2 A1 VEE DT1 hicumL0V1p1_c_sbt
XQ5 GND R1-Pad2 A2 VEE DT1 hicumL0V1p1_c_sbt

Rt1 DT1 0 1G

R1 GND R1-Pad2 220
R2 GND R2-Pad2 220
R3 GND R3-Pad2 575
R4 R3-Pad2 VEE 1.92k
R5 Q1-Pad3 VEE 780

Ra1 A1 VEE 510
Ra2 A2 VEE 510
.ends

X1 out9 out9 a1 out1 vee gnd nor
X2 out1 out1 a2 out2 vee gnd nor
X3 out2 out2 a3 out3 vee gnd nor
X4 out3 out3 a4 out4 vee gnd nor
X5 out4 out4 a5 out5 vee gnd nor
X6 out5 out5 a2 out6 vee gnd nor
X7 out6 out6 a3 out7 vee gnd nor
X8 out7 out7 a4 out8 vee gnd nor
X9 out8 out8 a5 out9 vee gnd nor

V1 VEE GND -5.2

.tran 0.02n 200n

.control
pre_osdi ../../osdilibs/hicumL0_v2p1p0.osdi
run
rusage all
plot out9 xlimit 100n 110n
linearize out9
fft out9
plot mag(out9) xlimit 0 2G ylimit 0 0.5
.endc
.end
