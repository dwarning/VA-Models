dc test circuit for igbt model 

.model igbt3 igbt3 kp1=0.1 vt1=-2e-3

vg g 0 dc=10
vc c 0 dc=5
ni1 c g 0 igbt3; kp=1.5 tau=1.6

.control
pre_osdi ../../../osdilibs/igbt3.osdi
op
dc vc 0 300 1 vg 5 20 5
plot abs(i(vc)); ylog
dc vg 0 20 .1 Temp -50 150 50
plot abs(i(vc)); ylog
.endc
.end
