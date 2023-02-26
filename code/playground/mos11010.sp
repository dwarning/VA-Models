Test circuit for mos11010

VB b 0 dc=0
VG g 0 dc=0.5
VD d 0 dc=1.5

NM1 d  g  0  b mm11 w=1e-5 l=1e-6


.model mm11 mos11010 type=1 a1r=99380 a2r=40.47 a3r=0.754 alpexp=1.039 alpr=0.01062
+ betsq=0.0001201 col=3.2e-10 dta=0 etabetr=1.3 etamobr=2.825 etaph=1.75 etar=0.4
+ etasat=0.8753 fbet1=-0.3741 fbet2=0 gatenoise=0 kor=0.5763 kpinv=0.22
+ lap=-1.864e-08 lmin=2e-07 lp1=2.806e-06 lp2=1e-10 lvar=0 moexp=3.146
+ mor=0.00105 nfar=1 nfbr=0 nfcr=0 nt=1.6237e-20 nu=1 nuexp=3.228 phibr=0.85
+ sdiblexp=6.756 sdiblo=1.06e-06 sl2ko=-1.737e-14 sl2phib=1.428e-14 sla1=-0.002805
+ sla2=1e-15 sla3=-8.705e-08 slalp=0.9957 slko=2.649e-08 slphib=-1.024e-08
+ slssf=1.002e-06 slthesat=1 ssfr=0.002304 sta1=0.093 stetamob=0 stvfb=0
+ swa1=0 swa2=0 swa3=0 swalp=0 swetamob=0 swko=0 swphib=0 swssf=0 swtheph=0
+ swther=0 swthesat=0 swthesr=0 swtheth=0 thephr=0.001 ther1=0 ther2=1
+ therr=0.1267 thesatexp=2 thesatr=0.06931 thesrr=0.7109 thethexp=1
+ thethr=0.002413 tox=3.2e-09 tr=21 vfb=-1.038 vp=0.05 wot=0 wvar=0

.options 
+        temp=21
+        tnom=27

.control
pre_osdi mos11010.osdi
dc VD 0.0 1.5 0.01 VG 0.5 1.5 0.1
plot -i(VD)
dc VG 0.0 1.0 0.01 VB -1.0 0.0 0.2
plot abs(i(VD)) ylog 
.endc
.end
