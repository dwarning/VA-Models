* Qucs 24.1.0 Test_AC_SYZ.sch
.PARAM Vgs = -0.4
.PARAM Vds = 3.0
C_X1 _net0 _net1 1
L_X1 _net1 _net2 1
Vgs _net2 0 DC {VGS}
VP1 _net0 0 dc 0 ac 0.316228 SIN(0 0.316228 1MEG) portnum 1 z0 50
C_X2 _net3 _net4 1
L_X2 _net4 _net5 1
Vds _net5 0 DC {VDS}
VP2 _net3 0 dc 0 ac 0.316228 SIN(0 0.316228 1MEG) portnum 2 z0 50
Nangelov1 _net4 _net1 0 mod_angelov_angelov1
.MODEL mod_angelov_angelov1 angelov noise=1 selft=0 trise=0.0 temp=25.0 idsmod=0 igmod=0 capmod=2 noimod=0 ipk0=0.05 vpks=-0.2 dvpks=0.2 p1=0.8 p2=0.0 p3=0.0 alphar=0.1 alphas=1.0 lambda=0.001 lvg=0.0 b1=0.1 b2=4.0 lsb0=0.0 vtr=20.0 vsb2=0.0 cds=10f cgspi=10f cgs0=100f cgdpi=10f cgdpe=10f cgd0=100f p10=0.0 p11=1.0 p20=0.0 p21=0.2 p30=0.0 p31=0.2 p40=0.0 p41=1.0 p111=0.0 ij=0.00005 pg=15.0 ne=1.0 vjg=0.7 rg=0.5 rd=0.1 rd2=0.0 ri=0.05 rs=0.05 rgd=0.05 ld=100p ls=10p lg=100p tau=0.0 rcmin=1.0e3 rc=10.0e3 crf=0.0 rcin=100.0e3 crfin=0.0 rth=0.001 cth=1e-4 tcipk0=-0.002 tcp1=-0.002 tccgs0=0.002 tccgd0=0.002 tclsb0=0.0 tcrc=0.0 tccrf=0.0 tcrs=0.003 tcrtherm=0.001 tcvpk=0.001 tcvjg=-0.001 tcvtr=0.000 noiser=0.5 noisep=1.0 noisec=0.9 fnc=0.0 kf=0.0 af=1.0 ffe=1.0 td=25.0 td1=0.1 tmn=1.0 klf=1.0e14 fgr=60.0e3 np=0.3 lw=0.1 tnom=25.0 
.control
pre_osdi '../../osdilibs/angelov.osdi'
SP DEC 101 10MEG 9.9G 1
let gain = db((S_2_1))
let Cgs = imag(v(Y_1_1)+v(Y_1_2))/(2*pi*frequency)
let Cgd = -imag(v(Y_1_2))/(2*pi*frequency)
plot S_1_1 S_1_2 S_2_1 S_2_2
plot Y_1_1 Y_1_2 Y_2_1 Y_2_2
plot Z_1_1 Z_1_2 Z_2_1 Z_2_2
plot gain
*plot Cgs
*plot Cgd
.endc
.END
