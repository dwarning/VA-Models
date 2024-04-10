* Qucs 24.1.0 Test_DC_out.sch
Vds _net0 0 DC 3
Vgs _net1 0 DC 0
VId _net0 _net2 DC 0
Nangelov1 _net2 _net1 0 mod_angelov_angelov1
.MODEL mod_angelov_angelov1 angelov noise=1 selft=0 trise=0.0 temp=25.0 idsmod=0 igmod=0 capmod=2 noimod=0 ipk0=0.05 vpks=-0.2 dvpks=0.2 p1=0.8 p2=0.0 p3=0.0 alphar=0.1 alphas=1.0 lambda=0.001 lvg=0.0 b1=0.1 b2=4.0 lsb0=0.0 vtr=20.0 vsb2=0.0 cds=0.0 cgspi=0.0 cgs0=0.0 cgdpi=0.0 cgdpe=0.0 cgd0=0.0 p10=0.0 p11=1.0 p20=0.0 p21=0.2 p30=0.0 p31=0.2 p40=0.0 p41=1.0 p111=0.0 ij=0.00005 pg=15.0 ne=1.0 vjg=0.7 rg=0.05 rd=0.05 rd2=0.0 ri=0.05 rs=0.05 rgd=0.05 ld=0.0 ls=0.0 lg=0.0 tau=0.0 rcmin=1.0e3 rc=10.0e3 crf=0.0 rcin=100.0e3 crfin=0.0 rth=0.001 cth=1e-4 tcipk0=-0.002 tcp1=-0.002 tccgs0=0.002 tccgd0=0.002 tclsb0=0.0 tcrc=0.0 tccrf=0.0 tcrs=0.003 tcrtherm=0.001 tcvpk=0.001 tcvjg=-0.001 tcvtr=0.000 noiser=0.5 noisep=1.0 noisec=0.9 fnc=0.0 kf=0.0 af=1.0 ffe=1.0 td=25.0 td1=0.1 tmn=1.0 klf=1.0e14 fgr=60.0e3 np=0.3 lw=0.1 tnom=25.0 
.control
pre_osdi '../../../osdilibs/angelov.osdi'
dc vds 0 5 0.00998004 vgs -2 0.7 0.3
plot VId#branch deriv(i(vid))
.endc
.END
