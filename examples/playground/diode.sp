Test Verilog-A diode model

Vd n 0 ac 1 dc 1; sin(0 10 1GHz)
R1 n d 10
ND1 d 0 diode

.model diode diode_va 
+area=400e-12
+is=1e-06
+rs=7.04e-6
+af=0.333333333333333333333333 bv=5 cjo=1pF

.control
pre_osdi diode.osdi
option gmin=1e-15
op
*dc Vd 0.01 1 0.01; temp -25 125 25
*plot abs(i(Vd)) ylog
*dc Vd -6 1 0.01
*plot -i(Vd)
*ac dec 4 1GHz 1THz
*plot mag(v(d)/i(Vd))
*tran 1p 10n
*plot -i(Vd)
.endc
.end
