* EKV 2.6
* simple inverter

.param Vcc = 3.3

* model definitions:
*.model .MODEL PCH EKV_VA type=-1
*.model .MODEL NCH EKV_VA type=1
.include ../Modelcards/ekv26_0u5.par

* the voltage sources: 
Vdd vdd gnd DC 'Vcc'
V1 in gnd pulse(0 'Vcc' 0p 200p 100p 1n 2n)
Vmeas vss 0 0

Xnot1 in vdd vss out not1
*Rout out 0 1k

.subckt not1 a vdd vss z
Np1 z a vdd vdd pch W=2u L=0.5u  as=0.26235p  ad=0.26235p  ps=2.51u   pd=2.51u
Nn1 z a vss vss nch W=1u L=0.5u as=0.131175p ad=0.131175p ps=1.52u   pd=1.52u
c3  a     vss   0.384f
c2  z     vss   0.576f
.ends

* simulation command: 
.tran 10ps 10ns
.dc V1 0 'vcc' 'vcc/100'

.control
pre_osdi ../../../osdilibs/ekv26.osdi
run
*set nolegend
set xbrushwidth=3
plot in out
plot dc1.out
plot dc1.i(Vmeas)
rusage
.endc

.end
