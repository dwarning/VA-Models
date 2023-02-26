test circuit for jfet model 

.save @j1[id] @j1s[id] @nj2[id_chan] @nj2s[id_chan]
.save @j1[gm] @j1s[gm] @nj2[gm] @nj2s[gm]

.model njf njf level=1 cgd=1p cgs=1p tnom=27 beta=1e-3 ; mj=0.3
j1 d g1 0 njf
j1s 0 g1s d njf

.model jfetva jfetva njfet=1 level=1 mj=0.3 cgd=1p cgs=1p tnom=27 beta=1e-3
nj2 d g2 0 jfetva
nj2s 0 g2s d jfetva

r1 g g1 r=10
r1s g g1s r=10
r2 g g2 r=10
r2s g g2s r=10

vg g 0 dc=-1 ac=1
vd d 0 dc=3

.control
pre_osdi jfet.osdi
*op
dc vd -3 4 0.01
plot @j1[id] @nj2[id_chan]
ac dec 4 1KHz 1GHz
plot @nj2[gm]
.endc
.end
