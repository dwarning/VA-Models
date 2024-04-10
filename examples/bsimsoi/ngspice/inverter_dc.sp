Sample netlist for BSIMSOI 
*Inverter DC

.include "../Modelcards/modelcard.pmos"
.include "../Modelcards/modelcard.nmos"

Vpower VD 0 1.5
Vgnd VS 0 0
Vgate Gate 0 0.0
nn0 VS Gate Out VS nmos1 W=10u L=0.18u
np0 VD Gate Out VS pmos1 W=20u L=0.18u

.control
pre_osdi ../../../osdilibs/bsimsoi.osdi
dc Vgate 0 1.5 0.05
plot v(Gate) v(out)
.endc
.END
