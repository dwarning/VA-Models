** Operational Amplifier (AC): Benchmarking Implementation of BSIM4.0.0 by Weidong Liu 5/16/2000.

NVLG1 bias1 1     cm    cm  N1 L=1u W=10u
NVLG2 bias2 in2   cm    cm  N1 L=1u W=10u
NVLG3 vdd   bias1 bias1 vdd P1 L=1u W=2u
NVLG4 bias2 bias1 vdd   vdd P1 L=1u W=2u

NVLG5    cm   bias vss vss N1 L=1u W=2u
NVLGbias bias bias vss vss N1 L=1u W=2u

rbias 0 bias 195k

NVLG6 8 bias  vss vss N1 L=1u W=2u
NVLG7 8 bias2 vdd 8   N1 L=1u W=2u

Cfb bias2 8 2p

Vid 1 c 0 ac 0.1
eid in2 c 1 c -1
vic c   0  dc  0
vss vss 0  -1.8
Vdd vdd 0  1.8 

.control
pre_osdi ../osdilibs/bsim4.osdi
ac dec 10 100 100Meg
plot vdb(8)
.endc

.include "Modelcards/modelcard.nmos"
.include "Modelcards/modelcard.pmos"

.end
