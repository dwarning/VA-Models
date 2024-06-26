Simulation of nonlinear capacitors
*Plot I(Cx)/1e6A  to get pico as multiplier on the Y-axis.
*Change the  X-axis to  time*1e6V/1s or to V(vc)

V1 vc 0 PWL(0 -5 10u 5)
NCx vc bi 0 pmoscap w=10u l=10u ngcon=2

.model nmoscap mosvar type=-1 toxo=13n VFBO=0 NSUBO=1e22 igmax=1e-3
.model pmoscap mosvar type=1 toxo=13n VFBO=-1; NSUBO=1e22 rshg=10 igmax=1e-3

.control
pre_osdi ../../../osdilibs/mosvar.osdi
tran 1n 10u 10n
plot -i(v1)/1e6 vs v(vc)
.endc
.end
