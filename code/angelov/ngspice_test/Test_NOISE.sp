* Qucs 24.1.0 Test_NOISE.sch
VIds _net0 _net1 DC 0
V3 _net2 _net3 DC 0 SIN(0 1 1K 0 0 0) AC 1 ACPHASE 0
V2 _net0 0 DC 25
R2 out _net1  500 tc1=0.0 tc2=0.0 
R1 _net4  _net2 3.3k noisy=0
V1 _net3 0 DC -0.4V
Nangelov1 out _net4 0 mod_angelov_angelov1
.MODEL mod_angelov_angelov1 angelov noise=1 selft=0 trise=0.0 temp=25.0 idsmod=0 igmod=0 capmod=2 noimod=0 ipk0=0.05 vpks=-0.2 dvpks=0.2 p1=0.8 p2=0.0 p3=0.0 alphar=0.1 alphas=1.0 lambda=0.001 lvg=0.0 b1=0.1 b2=4.0 lsb0=0.0 vtr=20.0 vsb2=0.0 cds=10f cgspi=10f cgs0=100f cgdpi=10f cgdpe=10f cgd0=100f p10=0.0 p11=1.0 p20=0.0 p21=0.2 p30=0.0 p31=0.2 p40=0.0 p41=1.0 p111=0.0 ij=0.00005 pg=15.0 ne=1.0 vjg=0.7 rg=1.0 rd=0.1 rd2=0.0 ri=0.05 rs=0.05 rgd=0.05 ld=100p ls=10p lg=100p tau=0.0 rcmin=1.0e3 rc=10.0e3 crf=0.0 rcin=100.0e3 crfin=0.0 rth=0.001 cth=1e-4 tcipk0=-0.002 tcp1=-0.002 tccgs0=0.002 tccgd0=0.002 tclsb0=0.0 tcrc=0.0 tccrf=0.0 tcrs=0.003 tcrtherm=0.001 tcvpk=0.001 tcvjg=-0.001 tcvtr=0.000 noiser=0.5 noisep=1.0 noisec=0.9 fnc=0.0 kf=1e-14 af=1.0 ffe=1.0 td=25.0 td1=0.1 tmn=1.0 klf=1.0e9 fgr=60.0e3 np=1.5 lw=0.1 tnom=25.0 
.control
pre_osdi '../../osdilibs/angelov.osdi'
ac dec 11 1 10g 
plot vdb(out) 
noise v(out) V3 dec 11 1 10G
print inoise_total onoise_total
setplot noise1
plot inoise_spectrum onoise_spectrum
.endc
.END
