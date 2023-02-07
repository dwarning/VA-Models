Sample netlist for BSIMSOI 
*Inverter Transient

.include "Modelcards/modelcard.pmos"
.include "Modelcards/modelcard.nmos"

* --- Voltage Sources ---
Vpower VD 0 1.5
Vgnd VS 0 0

Vgate   Gate   VS PULSE(0v 1.5v 100ps 50ps 50ps 200ps 500ps)

nn0 VS Gate Out VS nmos1 W=10u L=0.18u
np0 VD Gate Out VS pmos1 W=20u L=0.18u

.control
pre_osdi ../osdilibs/bsimsoi.osdi
tran 0.01n 600ps
plot v(gate) v(out)
.endc
.END

