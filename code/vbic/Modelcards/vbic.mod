.model vbicmod vbic13_4t
+ Type=1
+ Tnom=27 RCX=10 RCI=60 VO=2 GAMM=2.e-11
+ HRCF=2 RBX=10 RBI=40 RE=2
+ RS=20 RBP=40 IS=1e-16 NF=1.00000e+00
+ NR=1.00000e+00 FC=9.00000e-01 CBEO=0
+ CJE=1.e-13 PE=0.75 ME=0.33
+ AJE=-5.00000e-01 CBCO=0 CJC=2e-14
+ QCO=1e-12 CJEP=1e-13 PC=7.50000e-01
+ MC=3.30000e-01 AJC=-5.00000e-01 CJCP=4e-13
+ PS=7.50000e-01 MS=3.30000e-01 AJS=-5.00000e-01
+ IBEI=1e-18 WBE=1.0000 NEI=1.00000e+00
+ IBEN=5e-15 NEN=2.00000e+00 IBCI=2e-17
+ NCI=1.00000e+00 IBCN=5e-15 NCN=2.00000e+00
+ AVC1=2 AVC2=15 ISP=1e-15
+ WSP=1.000e+00 NFP=1.00000e+00 IBEIP=0
+ IBENP=0 IBCIP=0 NCIP=1.00000e+00
+ IBCNP=0 NCNP=2.00000e+00 VEF=10
+ VER=4 IKF=0.002 IKR=0.0002 IKP=0.0002
+ TF=1.e-11 QTF=0 XTF=20
+ VTF=0 ITF=0.08 TR=1e-10
+ KFN=0 AFN=1.0e+00
+ BFN=1.0000e+00 XRE=0 XRB=0
+ XRC=0 XRS=0 XVO=0
+ EA=1.12000e+00 EAIE=1.12000e+00
+ EANE=1.12000e+00 EANC=1.12000e+00
+ EANS=1.12000e+00 XIS=3.00000e+00
+ XII=3.00000e+00 XIN=3.00000e+00
+ TNF=0 TAVC=0
+ RTH=300 CTH=0
+ TD=0
*+ TD=2.e-11

.MODEL NPN_VBIC_VLG vbic13_4t 
+Type=1
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
