VBIC Noise Test

vcc 4 0 50
vin 1 0 ac 1

ccouple 1 2 1

ibias 0 2 100uA

rload 4 3 1k noisy=0

nq1 3 2 0 0 VBIC_EXAMPLE sw_noise=1

.model VBIC_EXAMPLE vbic13_4t
+ajc=-0.5 aje=0.5 ajs=0.5
+avc1=0 avc2=0 cbco=0 cbeo=0 cjc=2e-14
+cjcp=4e-13 cje=1e-13 cjep=1e-13 cth=0
+ea=1.12 eaic=1.12 eaie=1.12 eais=1.12 eanc=1.12
+eane=1.12 eans=1.12 fc=0.9 gamm=2e-11 hrcf=2
+ibci=2e-17 ibcip=0 ibcn=5e-15 ibcnp=0
+ibei=1e-18 ibeip=0 iben=5e-15 ibenp=0
+ikf=2e-3 ikp=2e-4 ikr=2e-4 is=1e-16 isp=1e-15 itf=8e-2
+mc=0.33 me=0.33 ms=0.33
+nci=1 ncip=1 ncn=2 ncnp=2 nei=1 nen=2
+nf=1 nfp=1 nr=1 pc=0.75 pe=0.75 ps=0.75 qco=1e-12 qtf=0
+rbi=4 rbp=4 rbx=1 rci=6 rcx=1 re=0.2 rs=2
+rth=300 tavc=0 td=2e-11 tf=10e-12 tnf=0 tr=100e-12
+tnom=25 tref=25 vef=10 ver=4 vo=2
+vtf=0 wbe=1 wsp=1
+xii=3 xin=3 xis=3 xrb=0 xrc=0 xre=0 xrs=0 xtf=20 xvo=0
+kfn=.3e-16 afn=1 bfn=1

.control
pre_osdi ../../osdilibs/vbic_1p3.osdi
noise v(3) vin dec 10 10 99Meg 1
setplot
setplot noise1
plot ally
plot inoise_spectrum
plot onoise_spectrum
setplot noise2
print all
echo
print inoise_total onoise_total
.endc

.end
