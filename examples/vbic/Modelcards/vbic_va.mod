* greped from Infineon_VBIC.lib
.MODEL M_BFP780 vbic13_4t TYPE=1
+ Tnom=25 Cbeo=2.47E-012 Cje=561.3E-015 Pe=0.7 Me=0.333 Aje=-1 Wbe=1
+ Cbco=10E-015 Cjc=668.6E-015 Pc=0.54 Mc=0.333 Ajc=-1 Cjep=2.616E-015
+ Cjcp=900E-015 Ps=0.6 Ms=0.3 Ajs=-0.5 Fc=0.94 Vef=545.4 Ver=3.291 Is=2.3E-015
+ Nf=0.9855 Ibei=1.893E-018 Nei=0.9399 Iben=4.77E-015 Nen=1.361 Ikf=1
+ Nr=0.9912 Ibci=157.5E-018 Nci=1.1 Ibcn=4.929E-015 Ncn=1.463 Ikr=0.01178
*+ Wsp=1 Isp=1E-015 Nfp=1 Ibcip=1E-015 Ncip=1.029 Ibcnp=1E-015 Ncnp=1 Ikp=1E-3
+ Wsp=1 Isp=1E-015 Nfp=1 Ibcip=1E-015 Ncip=1.029 Ibcnp=1E-015 Ncnp=1.1 Ikp=1E-3
+ Ibeip=1E-015 Ibenp=1E-015 Re=0.15 Rcx=0.01 Rci=2.665 Qco=1E-015
+ Vo=0.0005022 Gamm=5.659E-012 Hrcf=0.21 Rbx=5 Rbi=1.964 Rbp=265.5 Rs=26.56
+ Avc1=3.97 Avc2=29.52 Tf=1.6E-012 Qtf=50E-3 Xtf=30 Vtf=0.7 Itf=1 Tr=1E-015
+ Td=500E-015 Cth=0 Rth=80 Ea=1.12 Eaie=1.12 Eaic=1.12 Eais=1 Eane=1.12
+ Eanc=1.12 Eans=1 Xre=0 Xrb=0 Xrc=0 Xrs=0 Xvo=0 Xis=-1.631 Xii=0 Xin=0
+ Tnf=0 Tavc=0.002613 Kfn=0 Afn=1 Bfn=1

.MODEL NPN_VBIC_VLG vbic13_4t TYPE=1
+TNOM    = 27             RCI     = 1E3            RCX     = 50
+VO      = 1.5            GAMM    = 3.402097E-11   HRCF    = 1
+RBX     = 243            RBI     = 20             RE      = 30
+RS      = 0              RBP     = 0              IS      = 8.084033E-18
+NF      = 1              NR      = 1.005          FC      = 0.5
+CJE     = 2.083234E-15   PE      = 0.8793669      ME      = 0.3108762
+CJC     = 1.803275E-15   PC      = 0.5512188      MC      = 0.4454263
+CJCP    = 8E-15          PS      = 0.66956        MS      = 0.2243
+IBEI    = 4.542609E-20   WBE     = 1              NEI     = 1
+IBEN    = 3.275162E-16   NEN     = 1.5543186      IBCI    = 3.594252E-19
+NCI     = 0.996          IBCN    = 1.717776E-17   NCN     = 1.202521
+AVC1    = 3E-4           AVC2    = 1E-5           ISP     = 1.332E-19
+WSP     = 1              NFP     = 1              IBEIP   = 0
+IBENP   = 0              IBCIP   = 0              NCIP    = 1
+IBCNP   = 0              NCNP    = 2              VEF     = 109.6523
+VER     = 2.2052435      IKF     = 6.03524E-3     IKR     = 1.807895E-4
+IKP     = 2.908576E-5    TF      = 1.1E-12        XTF     = 21.5423
+VTF     = 12.4758677     ITF     = 0.0175231      TR      = 2.23542E-9

* hspice vbic99_dc example
.model vbic99_dc vbic13_5t TYPE=1
+tref = 27.0 rcx = 10.0 rci = 60.0 vo = 2.0
+gamm = 2e-11 hrcf = 2.0 rbx = 10.0 rbi = 40.0
+re = 2.0 rs = 20.0 rbp = 40.0 is = 1.0e-16
+nf = 1.0 nr = 1.0 fc = 0.9 cbeo = 0.0
+cje = 1.0e-13 pe = 0.75 me = 0.33 aje = -0.5
+cbco = 0.0 cjc = 2e-14 qco = 1e-12 cjep = 1e-13
+pc = 0.75 mc = 0.33 ajc = -0.5 cjcp = 4e-13
+ps = 0.75 ms = 0.33 ajs = -0.5 ibei = 1.0e-18
+wbe = 1.0 nei = 1.0 iben = 5.0e-15 nen = 2.0
+ibci = 2.0e-17 nci = 1.0 ibcn = 5.0e-15 ncn = 2.0
+avc1 = 2.0 avc2 = 15.0 isp = 1.0e-15 wsp = 1.0
+nfp = 1.0 ibeip = 0.0 ibenp = 0.0 ibcip = 0.0
+ncip = 1.0 ibcnp = 0.0 ncnp = 2.0 vef = 10.0
+ver = 4.0 ikf = 2e-3 ikr = 2e-4 ikp = 2e-4
+tf = 10e-12 qtf = 0.0 xtf = 20.0 vtf = 0.0
+itf = 8e-2 tr = 100e-12 td = 1e-20 kfn = 0.0
+afn = 1.0 bfn = 1.0 xre = 0 xrbi = 0
+xrci = 0 xrs = 0 xvo = 0 ea = 1.12
+eaie = 1.12 eaic = 1.12 eais = 1.12 eane = 1.12
+eanc = 1.12 eans = 1.12 xis = 3.0 xii = 3.0
+xin = 3.0 tnf = 0.0 tavc = 0.0 rth = 300.0
+cth = 0.0 vrt = 0.0 art = 0.1 ccso = 0.0
+qbm = 0.0 nkf = 0.5 xikf = 0 xrcx = 0
+xrbx = 0 xrbp = 0 isrr = 1.0 xisr = 0.0
+dear = 0.0 eap = 1.12 vbbe = 0.0 nbbe = 1.0
+ibbe = 1.0e-6 tvbbe1 = 0.0 tvbbe2 = 0.0 tnbbe = 0.0

* hspice vbic95 example
.model vbic95 vbic13_4t TYPE=1
+ afn=1 ajc=-0.5 aje=0.5 ajs=0.5
+ avc1=0 avc2=0 bfn=1 cbco=0 cbeo=0 cjc=2e-14
+ cjcp=4e-13 cje=1e-13 cjep=1e-13 cth=0
+ ea=1.12 eaic=1.12 eaie=1.12 eais=1.12 eanc=1.12
+ eane=1.12 eans=1.12 fc=0.9 gamm=2e-11 hrcf=2
+ ibci=2e-17 ibcip=0 ibcn=5e-15 ibcnp=0
+ ibei=1e-18 ibeip=0 iben=5e-15 ibenp=0
+ ikf=2e-3 ikp=2e-4 ikr=2e-4 is=1e-16 isp=1e-15 itf=8e-2
+ kfn=0 mc=0.33 me=0.33 ms=0.33
+ nci=1 ncip=1 ncn=2 ncnp=2 nei=1 nen=2
+ nf=1 nfp=1 nr=1 pc=0.75 pe=0.75 ps=0.75 qco=1e-12 qtf=0
+ rbi=4 rbp=4 rbx=1 rci=6 rcx=1 re=0.2 rs=2
+ rth=300 tavc=0 td=2e-11 tf=10e-12 tnf=0 tr=100e-12
+ tnom=25 tref=25 vef=10 ver=4 vo=2
+ vtf=0 wbe=1 wsp=1
+ xii=3 xin=3 xis=3 xrb=0 xrc=0 xre=0 xrs=0 xtf=20 xvo=0
