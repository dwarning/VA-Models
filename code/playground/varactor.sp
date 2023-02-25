Verilog-A varactor test circuit

Vt n 0 ac 1 PWL(0 -5 10u 5)
NCv n 0 varactor 

.model varactor varactor c0=1pF c1=0.5pF v0=0 v1=1

*capacitanceInF ac freq=1/(2*M_PI) start=-2 stop=2 dev=Vt param=dc
*save Cv:1

.control
pre_osdi varactor.osdi
tran 1n 10u 10n
plot -i(Vt)/1e6 vs v(n)
.endc
.end
