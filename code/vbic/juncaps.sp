Comparing junction capacitances

.include Modelcards/vbic.mod

*********
* Circuit
*********
* Y11 et Y21 parameters computation
NQ1 2 1 0 0 NPN_VBIC_VLG
* v1 = vbe = vbc
v1 1 11 dc 0
v11 11 0 dc 0 ac 1 0
v2 0 2 dc 0
* Y12 et Y22 parameters computation
NQ2 4 3 0 0 NPN_VBIC_VLG
* v4 = vbc = vsc
v4 44 4 dc 0
v44 44 0 dc 0 ac 1 0
v3 3 0 dc 0

**************************************
* Analysis and capacitance computation
**************************************
.control
pre_osdi ../osdilibs/vbic_1p3.osdi
altermod @q.xq1.nqnpn13g2[RTH]=0
altermod @q.xq2.nqnpn13g2[RTH]=0
destroy all
deftype v admittance S
deftype v capacitance F
 set width=180
 let f=1e9;
 let pi=3.141592654;
 let omega=2.0*pi*f
 compose dcsweep start=-2 stop=0.55 lin=51
 settype voltage dcsweep
 foreach dc $&dcsweep
   alter @v1[dc] = $dc
   alter @v4[dc] = $dc
   ac lin 1 $&f $&f
 end
 * create new working place
 setplot new
 * compose on all ac analysis
 compose imy11 values -imag(all.i(v1))
 compose imy21 values imag(all.i(v2))
 compose imy12 values -imag(all.i(v3))
 compose imy22 values imag(all.i(v4))
 settype admittance imy11 imy21 imy12 imy22
 let cje=(imy11+imy21)/omega
 let cjc=-imy12/omega
 let cjs=(imy12+imy22)/omega
 settype capacitance cje cjc cjs
 plot cje cjc cjs vs dcsweep
.endc

.end
