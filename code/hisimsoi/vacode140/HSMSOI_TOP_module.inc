/***********************************************************************

 HiSIM (Hiroshima University STARC IGFET Model)
 Copyright (C) 2000-2016 Hiroshima University and STARC
 Copyright (C) 2016-2018 Hiroshima University
 HiSIM_SOI (Silicon-On-Insulator Model)
 Copyright (C) 2012-2016 Hiroshima University and STARC
 Copyright (C) 2016-2018 Hiroshima University

 MODEL NAME : HiSIM_SOI
 ( VERSION : 1  SUBVERSION : 4  REVISION : 0 )
 Model Parameter 'VERSION' : 1.40
 FILE : HSMSOI_TOP_module.inc

 Date : 2018.07.30

 released by Hiroshima University

***********************************************************************/
//
////////////////////////////////////////////////////////////////
//
//Licensed under the Educational Community License, Version 2.0
//(the "License"); you may not use this file except in
//compliance with the License.
//
//You may obtain a copy of the License at:
//
//  http://opensource.org/licenses/ECL-2.0
//
//Unless required by applicable law or agreed to in writing,
//software distributed under the License is distributed on an
//"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
//either express or implied. See the License for the specific
//language governing permissions and limitations under the
//License.
//
//
//The HiSIM_SOI standard has been supported by the members of
//Silicon Integration Initiative's Compact Model Coalition. A
//link to the most recent version of this standard can be found
//at:
//
//http://www.si2.org/cmc
//
////////////////////////////////////////////////////////////////
//

// Branch Definitions

branch(bc,bp) BRbcbp ;

branch(dp,sp) BRdpsp ;
branch(sp,dp) BRspdp ;
branch(dp,bp) BRdpbp ;
branch(sp,bp) BRspbp ;
branch(gp,sp) BRgpsp ;
branch(gp,dp) BRgpdp ;

branch(d ,dp) BRddp  ;
branch(sp,s ) BRsps  ;
branch(bp,sp) BRbpsp ;
branch(bp,dp) BRbpdp ;

branch(g ,gp) BRggp  ;
branch(gp,s ) BRgps  ;
branch(gp,d ) BRgpd  ;
branch(gp,bp) BRgpbp ;
branch(d ,s ) BRds   ;
branch(s ,d ) BRsd   ;
branch(d ,g ) BRdg   ;
branch(g ,d ) BRgd   ;
branch(s ,g ) BRsg   ;
branch(g ,s ) BRgs   ;
branch(bp,d ) BRbpd  ;
branch(d ,bp) BRdbp  ;
branch(bp,s ) BRbps  ;
branch(s ,bp) BRsbp  ;
branch(bp,g ) BRbpg  ;
branch(g ,bp) BRgbp  ;
branch(e ,bp) BRebp  ;

//
// Parameter definitions
//******* Device Parameters *******//
`IPRoo( L         , 5.0E-6    , "m"            , 0, inf , "Gate length (Lgate)" )
`IPRoo( W         , 5.0E-6    , "m"            , 0, inf , "Gate width (Wgate)" )
`IPRco( AD        , 0.0       , "m^2"          , 0, inf , "Area of drain junction" )
`IPRco( AS        , 0.0       , "m^2"          , 0, inf , "Area of source junction" )
`IPRco( PD        , 0.0       , "m"            , 0, inf , "Perimeter of drain junction" )
`IPRco( PS        , 0.0       , "m"            , 0, inf , "Perimeter of source junction" )
`IPRoo( NGCON     , 1.0       , "-"            , 0, inf , "Number of gate contacts" )
`IPRnb( XGW       , 0E0       , "m"                     , "Distance from gate contact to channel edge" )
`IPRco( XGL       , 0E0       , "m",             0, L   , "Offset of gate length" )
`IPM
`IPRoo( NF        , 1.0       , "-",             0, inf , "Number of gate fingers" )
`IPRco( SA        , 0         , "m",             0, inf , "Length of diffusion between gate and STI" )
`IPRco( SB        , 0         , "m",             0, inf , "Length of diffusion between gate and STI" )
`IPRco( SD        , 0         , "m",             0, inf , "Length of diffusion between gate and gate" )
`IPRnb( PDBCP     , 0.0       , "m"                     , "Parasitic perimeter length for body contact at drain" )
`IPRnb( PSBCP     , 0.0       , "m"                     , "Parasitic perimeter length for body contact at source" )
`IPRnb( LOD       , 10.0E-6   , "m"                     , "diffusion length between gate and STI edge" )
`IPRnb( TEMP      , 0.0       , "C"                     , "Device temperature" )
`IPRnb( DTEMP     , 0         , "C"                     , "Device temperature change" )
`IPRnb( NBT       , 1.0       , ""                      , "Number of body contact" )
`IPRnb( LBT       , 0.0       , "m"                     , "Length of gate over body-contact well" )
`IPRnb( WBTP      , 0.0       , "m"                     , "Distance of gate protrusion over body-contact well" )
`IPRnb( WBTN      , 0.0       , "m"                     , "Distance of gate protrusion over body-contact well" )
`IPRnb( ABTN      , 0.0       , "m^2"                   , "Area of N^+ poly area of body contact" )
`IPRnb( ABTP      , 0.0       , "m^2"                   , "Area of P^+ poly area of body contact" )

//******* Model Flags *******//
`MPIsw( COPPRV    , 0         , ""                      , "Previous phi_s flag" )
`MPIsw( COADOV    , 1         , ""                      , "Lateral field induced and overlap capacitances are added to intrinsic" )
`MPIsw( COISUB    , 0         , ""                      , "Substrate current flag" )
`MPIsw( COFBE     , 0         , ""                      , "Floating-Body Effect flag" )
`MPIsw( COIIGS    , 0         , ""                      , "Gate current flag" )
`MPIsw( COGIDL    , 0         , ""                      , "GIDL current flag" )
`MPIsw( COOVLP    , 0         , ""                      , "Overlap capacitance model selector" )
`MPIsw( COIGN     , 0         , ""                      , "Induced gate and cross correlation noise flag" )
`MPIsw( COFLICK   , 0         , ""                      , "1/f noise flag" )
`MPIsw( COTHRML   , 0         , ""                      , "Thermal noise flag" )
`MPIsw( COISTI    , 0         , ""                      , "STI leakage current flag" )
`MPIsw( CONQS     , 0         , ""                      , "Non-quasi-static model flag" )
`MPIsw( CORG      , 0         , ""                      , "Gate-contact resistance flag" )
`MPIsw( COIEVB    , 0         , ""                      , "Valence-band-electron-tunneling-current model flag" )
`MPIsw( COHIST    , 0         , ""                      , "History Effect flag" )
`MPIsw( COSELFHEAT, 0         , ""                      , "Self-Heating flag" )
`MPIsw( COVBSBIZ  , 0         , ""                      , "Symmetry treatment flag" )
`MPIsw( COLGLEFF  , 0         , ""                      , "Lgate to Leff flag" )
`MPIcc( COQOVSM   , 1         , ""                , 0, 2, "Qover capacitance model selector" )
`MPIcc( COQBDSM   , 1         , ""                , 0, 2, "Gate/body contact well MOS-capacitance model selector" )
`MPRnb( COBCNODE  , 0         , ""                      , "Body contact node flag" )
`MPInb( INFO      , 0         , ""                      , "print information selector" )

//******* Technology Model Parameters *******//
`MPIty( TYPE      , 1         , "-"                     , "1 for nMOS and -1 for pMOS" )
`MPRnb( VERSION   , 1.40      , "-"                     , "model version selector" )
`MPRoo( VMAX      , 7.00E+6   , "cm*s^-1"      , 0, inf , "saturation velocity" )
`MPRnb( BGTMP1    , 90.25E-6  , "eV*K^-1"               , "temperature dependence of bandgap" )
`MPRnb( BGTMP2    , 100.0E-9  , "eV*K^-2"               , "temperature dependence of bandgap" )
`MPRoo( EG0       , 1.1785    , "eV"           , 0, inf , "bandgap" )
`MPRnb( XLD       , 0.0       , "m"                     , "gate overlap length" )
`MPRnb( XLDC      , XLD       , "m"                     , "XLD for capacitance" )
`MPRnb( VFBOVER   , 0.0       , "V"                     , "flat-band voltage in overlap region" )
`MPRco( NOVER     , 1E19      , "cm^-3"        , 0, inf , "impurity concentration in overlap region" )
`MPRnb( XWD       , 0.0       , "m"                     , "gate overlap width" )
`MPRnb( XWDC      , XWD       , "m"                     , "XWD for cap" )
`MPRco( SAREF     , 1E-6      , "m"            , 0, inf , "Reference distance from STI edge to Gate edge" )
`MPRco( SBREF     , 1E-6      , "m"            , 0, inf , "Reference distance from STI edge to Gate edge" )
`MPRco( XQY       , 0.0       , "m"            , 0, inf , "distance from junction to max field point" )
`MPRnb( XQY1      , 0.0       , "F*um^XQY2-1"           , "Vbs-dependence of Qy" )
`MPRnb( XQY2      , 2.0       , "-"                     , "Lgate-dependence of Qy" )
`MPRcc( RSHG      , 0.0       , "Ohm/square"   , 0, 100 , "gate sheet resistance" )
`MPRnb( VFBC      , -1.0      , "V"                     , "flat-band voltage" )
`MPRnb( VBI       , 1.1       , "V"                     , "built-in potential" )
// `MPRnb( NSUBPL    , 0.001     , "m^-1"                  , "modification of pocket-impurity concentration" )
// `MPRnb( NSUBPFAC  , 1         , "-"                     , "modification of pocket-impurity concentration" )
`MPRnb( PARL1     , 10.0E-9   , "cm"                    , "SOI SCE parameter" )
`MPRnb( PARL2     , 10.0E-9   , "m"                     , "depletion width of channel/contact junction" )
`MPRnb( LP        , 0.0       , "m"                     , "pocket penetration length" )
`MPRoo( NSUBP     , 1.0E+17   , "cm^-3"        , 0, inf , "max pocket concentration" )
`MPRnb( NSUBP0    , 0.0       , "um^NSUBWP"             , "modification of pocket concentration for narrow W" )
`MPRnb( NSUBWP    , 1.0       , "-"                     , "modification of pocket concentration for narrow W" )
`MPRnb( WL1       , 0.0       , "um^2WL1P+1"            , "small-size effect parameter for STI leakage" )
`MPRnb( WL1P      , 1.0       , "-"                     , "small-size effect parameter for STI leakage" )
`MPRnb( WL2       , 0.0       , "Vum^WL2P"              , "threshold voltage shift due to small-size effect" )
`MPRnb( WL2P      , 1.0       , "-"                     , "threshold voltage shift due to small-size effect" )
`MPRnb( SCP1      , 0.0       , "-"                     , "magnitude of short-channel effect due to pocket" )
`MPRnb( SCP2      , 0.0       , "V^-1"                  , "Vds-dependence of SCE due to pocket" )
`MPRnb( SCP3      , 0.0       , "m*V^-1"                , "Vds-dependence of SCE due to pocket" )
`MPRnb( SC1       , 0.0       , "-"                     , "magnitude of short-channel effect" )
`MPRnb( SC2       , 0.0       , "V^-1"                  , "Vds-dependence of short-channel effect" )
`MPRnb( SC3       , 0.0       , "m*V^-1"                , "Vbs dependence of short-channel effect" )
`MPRnb( SCR1      , 0.0       , "-"                     , "parameter for SCE via BOX" )
`MPRnb( SCR2      , 0.0       , "-"                     , "parameter for SCE via BOX" )
`MPRnb( SCR3      , 0.23      , "-"                     , "parameter for SCE via BOX" )
`MPRnb( PGD1      , 0.0       , "V"                     , "strength of poly-depletion effect" )
`MPRnb( PGD2      , 1.0       , "V"                     , "threshold voltage of poly-depletion effect" )
`MPRnb( PGD4      , 0.0       , "-"                     , "Lgate-dependence of poly-depletion effect" )
`MPRnb( NDEP      , 1.0       , "-"                     , "depletion charge contribution to Eeff" )
`MPRnb( NINV      , 0.5       , "-"                     , "inversion charge contribution to Eeff" )
`MPRnb( NINVD     , 0.0       , "V^-1"                  , "inversion charge parameter" )
`MPRnb( MUECB0    , 300.0     , "cm^2V^-1s^-1"          , "Coulomb scattering" )
`MPRnb( MUECB1    , 30.0      , "cm^2V^-1s^-1"          , "Coulomb scattering" )
`MPRnb( MUEPH0    , 300.0E-3  , "-"                     , "phonon scattering" )
`MPRnb( MUEPHW    , 0.0       , "um^MUEPHP"             , "phonon-related mobility reduction" )
`MPRnb( MUEPWP    , 1.0       , "-"                     , "phonon-related mobility reduction" )
`MPRnb( MUEPHL    , 0.0       , "-"                     , "L-dependence of phonon mobility reduction" )
`MPRnb( MUEPLP    , 1.0       , "-"                     , "L-dependence of phonon mobility reduction" )
`MPRnb( MUEPHS    , 0.0       , "um^MUEPSP"             , "mobility change due to small size" )
`MPRnb( MUEPSP    , 1.0       , "-"                     , "mobility change due to small size" )
`MPRnb( VTMP      , 0.0       , "cm*s^-1"               , "temperature-dependence of saturation velocity" )
`MPRnb( WVTH0     , 0.0       , "Vum"                   , "threshold voltage shift" )
`MPRoo( MUESR1    , 2.0E15    , "cm^2V^-1s^-1" , 0, inf , "surface-roughness scattering" )
`MPRnb( MUESR0    , 2.0       , "-"                     , "surface-roughness scattering" )
`MPRnb( MUESRL    , 0.0       , "um^MUESLP"             , "L-dependence of surface roughness on mobility" )
`MPRnb( MUESRW    , 0.0       , "um^MUESWP"             , "surface roughness-related mobility change" )
`MPRnb( MUESWP    , 1.0       , "-"                     , "surface roughness-related mobility change" )
`MPRnb( MUESLP    , 1.0       , "-"                     , "L-dependence of surface roughness on mobility" )
`MPRnb( MUETMP    , 1.5       , "um^MUEPLP"             , "temperature-dependence of phonon scattering" )
`MPRco( BB        , ((TYPE>0)?2.0:1.0), "-"  , 0.1, inf , "high-field-mobility degradation" )
`MPRnb( DDLTMAX   , 10.0      , "-"                     , "smoothing coefficient for Vds" )
`MPRnb( DDLTSLP   , 10.0      , "um^-1"                 , "Lgate-dependence of smoothing coefficient" )
`MPRnb( DDLTICT   , 0.0       , "-"                     , "Lgate-dependence of smoothing coefficient" )
`MPRnb( SUB1      , 0.01      , "V^-1"                  , "substrate current coefficient of magnitude" )
`MPRnb( SUB2      , 20.0      , "V"                     , "substrate current coefficient of exponential term" )
`MPRnb( SUB1L     , 2.5E-3    , "m"                     , "Lgate-dependence of SUB1" )
`MPRnb( SUB1LP    , 1.0       , "-"                     , "Lgate-dependence SUB1" )
`MPRnb( SUB2L     , 2.0E-6    , "m"                     , "Lgate-dependence of SUB2" )
`MPRnb( SVDS      , 3.0       , "-"                     , "Substrate current dependence on Vds" )
`MPRnb( SLG       , 3.0E-8    , "m"                     , "substrate current dependence on Lgate" )
`MPRnb( SVBS      , 0.5       , "-"                     , "substrate current dependence on Vbs" )
`MPRnb( SVBSL     , 0.0       , "m^SVBSLP"              , "Lgate-dependence of SVBS" )
`MPRnb( SVBSLP    , 1.0       , "-"                     , "Lgate-dependence of SVBS" )
`MPRnb( SVGS      , 0.8       , "-"                     , "substrate current dependence on Vgs" )
`MPRnb( SVGSL     , 0.0       , "m^SLGLP"               , "Lgate-dependence of SVGS" )
`MPRnb( SVGSLP    , 1.0       , "-"                     , "Lgate-dependence of SVGS" )
`MPRnb( SVGSW     , 0.0       , "m^SVGSWP"              , "Wgate-dependence of SVGS" )
`MPRnb( SVGSWP    , 1.0       , "-"                     , "Wgate-dependence of SVGS" )
`MPRnb( VFBSUB    , -1.0      , "V"                     , "flatband voltage for Isub calculation" )
`MPRnb( VFBSUBL   , 0.0       , "um^VFBSUBLP"           , "Lgate-dependence of VFBSUB" )
`MPRnb( VFBSUBLP  , 1.0       , "-"                     , "Lgate-dependence of VFBSUB" )
`MPRnb( SUBDLT    , 2.0E-3    , "-"                     , "smoothing parameter (hisimsoi_fb only)" )
`MPRnb( HIST1     , 10E-9     , "V"                     , "history-effect parameter" )
`MPRnb( HIST2     , 1E-20     , "A"                     , "history-effect parameter" )
`MPRnb( QHE1      , 1.5       , "-"                     , "FBE parameter" )
`MPRnb( QHE2      , 0.35      , "V"                     , "FBE parameter" )
`MPRnb( EVB1      , 0.0       , "V^-2s^-1"              , "electron tunneling from valence band" )
`MPRnb( EVB2      , 0.0       , "V*m^-1"                , "electron tunneling from valence band" )
`MPRnb( EVB3      , 0.0       , "-"                     , "electron tunneling from valence band" )
`MPRnb( FVBS      , 0.0       , "-"                     , "Vbs dependence of Fowler-Nordheim current" )
`MPRnb( IBPC1     , 0.0       , "Ohm"                   , "impact-ionization-induced bulk potential change" )
`MPRnb( IBPC2     , 0.0       , "V^-1"                  , "impact-ionization-induced bulk potential change" )
`MPRnb( NSTI      , 5.0E17    , "cm^-3"                 , "substrate impurity concentration at STI edge" )
`MPRnb( WSTI      , 0.0       , "m"                     , "width of high-field region at STI edge" )
`MPRnb( WSTIL     , 0.0       , "um^WSTILP"             , "channel-length dependence of WSTI" )
`MPRnb( WSTILP    , 1.0       , "-"                     , "channel-length dependence of WSTI" )
`MPRnb( WSTIW     , 0.0       , "um^WSTIWP"             , "channel-width dependence of WSTI" )
`MPRnb( WSTIWP    , 1.0       , "-"                     , "channel-width dependence of WSTI" )
`MPRnb( SCSTI1    , 0.0       , "-"                     , "the same effect as SC1 but at STI edge" )
`MPRnb( SCSTI2    , 0.0       , "V^-1"                  , "the same effect as SC2 but at STI edge" )
`MPRnb( VTHSTI    , 0.0       , "V"                     , "threshold voltage shift due to STI" )
`MPRnb( VDSTI     , 0.0       , "-"                     , "Vds dependence of STI subthreshold" )
`MPRnb( MUESTI1   , 0.0       , "m"                     , "mobility change due to diffusion length" )
`MPRnb( MUESTI2   , 0.0       , "-"                     , "mobility change due to diffusion length" )
`MPRnb( MUESTI3   , 1.0       , "-"                     , "mobility change due to diffusion length" )
`MPRnb( NSUBPSTI1 , 0.0       , "m"                     , "pocket concentration modifier" )
`MPRnb( NSUBPSTI2 , 0.0       , "-"                     , "pocket concentration modifier" )
`MPRnb( NSUBPSTI3 , 1.0       , "-"                     , "pocket concentration modifier" )
`MPRnb( NSUBCSTI1 , 0.0       , "m"                     , "channel concentration modifier" )
`MPRnb( NSUBCSTI2 , 0.0       , "-"                     , "channel concentration modifier" )
`MPRnb( NSUBCSTI3 , 1.0       , "-"                     , "channel concentration modifier" )
`MPRnb( TPOLY     , 0.0       , "m"                     , "height of poly-Si gate for fringing cap" )
`MPRco( CGBO      , 0.0       , "F*m^-1"       , 0, inf , "gate-to-B overlap cap" )
`MPRco( CGDO      , 0.0       , "F*m^-1"       , 0, inf , "gate-to-drain overlap cap" )
`MPRco( CGSO      , 0.0       , "F*m^-1"       , 0, inf , "gate-to-source overlap cap" )
`MPRnb( OVSLP     , 2.1E-7    , "mV^-1"                 , "coefficient for overlap capacitance" )
`MPRnb( OVMAG     , 0.6E0     , "V"                     , "coefficient for overlap capacitance" )
`MPRnb( JS0       , 1.0E-4    , "A*m^-2"                , "saturation current density" )
`MPRoo( NJ        , 1.0       , "-"            , 0, inf , "emission coefficient" )
`MPRnb( XTI       , 2.0       , "-"                     , "temp coefficient for forward current densities" )
`MPRnb( XTI2      , 0.0       , "-"                     , "temp coefficient for reverse current densities" )
`MPRnb( VDIFFJ    , 1.6E-3    , "V"                     , "diode threshold voltage at junction" )
`MPRnb( DIVX      , 0.0       , "V^-1"                  , "reverse current coefficient" )
`MPRnb( CJ        , 5.0E-04   , "F*m^-2"                , "bottom junc cap/unit area at zero bias" )
`MPRnb( CJSW      , 5.0E-10   , "F*m^-1"                , "sidewall junc cap grading coefficient" )
`MPRnb( CJSWG     , 5.0E-10   , "F*m^-1"                , "sidewall junc cap per unit length at zero bias" )
`MPRoo( MJ        , 0.33      , "-"           ,-inf,1.0 , "bottom junc cap grading coefficient" )
`MPRoo( MJSW      , 0.33      , "-"           ,-inf,1.0 , "sidewall junc cap grading coefficient" )
`MPRoo( MJSWG     , 0.33      , "-"           ,-inf,1.0 , "gate sidewall junc cap grading coefficient" )
`MPRoo( PB        , 1.0       , "V"            , 0, inf , "bottom junc built-in potential" )
`MPRoo( PBSW      , 1.0       , "V"            , 0, inf , "sidewall junc built-in potential" )
`MPRoo( PBSWG     , 1.0       , "V"            , 0, inf , "gate sidewall junc built-in potential" )
`MPRnb( LOVER     , 30E-9     , "m"                     , "overlap length" )
`MPRnb( CLM1      , 700.0E-3  , "-"                     , "hardness coefficient of channel/contact junction" )
`MPRnb( CLM2      , 2.0       , "-"                     , "coefficient for QB contribution" )
`MPRnb( CLM3      , 1.0       , "-"                     , "coefficient for QI contribution" )
`MPRnb( CLM5      , 1.0       , "-"                     , "CLM parameter" )
`MPRnb( CLM6      , 0.0       , "um^-CLM5"              , "CLM parameter" )
`MPRnb( VOVER     , 10.0E-3   , "cm^VOVERP"             , "velocity overshoot effect parameter" )
`MPRnb( VOVERP    , 100.0E-3  , "-"                     , "Leff-dependence of velocity overshoot" )
`MPRnb( VOVERS    , 0.0       , "-"                     , "modification of max velocity due to small size" )
`MPRnb( VOVERSP   , 1.0       , "-"                     , "modification of max velocity due to small size" )
`MPRnb( WFC       , 0.0       , "F*cm^-2*m^-1"          , "Threshold voltage change due to cap change" )
`MPRnb( NSUBCW    , 0.0       , "um^NSUBCWP"            , "substrate concentration modifier" )
`MPRnb( NSUBCWP   , 1.0       , "-"                     , "substrate concentration modifier" )
`MPRnb( NSUBCMAX  , 5E18      , "cm^-3"                 , "upper limit of substrate concentration" )
`MPRnb( NSUBCL    , 0.0       , "um^NSUBCLP"            , "Lgate-dependence of substrate concentration " )
`MPRnb( NSUBCLP   , 1.0       , "-"                     , "Lgate-dependence of substrate concentration " )
`MPRnb( QME1      , 0.0       , "mV"                    , "Vgs-dependence of quantum mechanical effect" )
`MPRnb( QME2      , 0.0       , "V"                     , "Vgs-dependence of quantum mechanical effect" )
`MPRnb( QME3      , 0.0       , "m"                     , "minimum Tox modification" )
`MPRnb( GIDL1     , 5.0E-6    , "A*V^-3/2C^-1m"         , "magnitude of GIDL" )
`MPRnb( GIDL2     , 1.0E6     , "V^-2m^-1F^-3/2"        , "field-dependence of GIDL" )
`MPRnb( GIDL3     , 300.0E-3  , "-"                     , "Vds-dependence of GIDL" )
`MPRnb( GIDL4     , 0.0       , "V"                     , "threshold for Vds dependence" )
`MPRnb( GIDL5     , 0.2E0     , "-"                     , "high-field correction" )
`MPRnb( GLEAK1    , 10.0E3    , "V^-3/2*s^-1"           , "gate-to-channel current coefficient" )
`MPRnb( GLEAK2    , 20.0E6    , "V^-1/2*m^-1"           , "gate-to-channel current coefficient" )
`MPRnb( GLEAK3    , 300.0E-3  , "-"                     , "gate-to-channel current coefficient" )
`MPRnb( GLEAK4    , 4E0       , "m^-1"                  , "gate-to-channel current coefficient" )
`MPRoo( GLEAK5    , 7.5E3     , "V*m^-1"       , 0, inf , "G-t-C short channel correction" )
`MPRnb( GLEAK6    , 250E-3    , "V"                     , "G-t-C Vds-dependence correction" )
`MPRnb( GLEAK7    , 1E-6      , "m^2"                   , "G-t-C L and W dependence correction" )
`MPRnb( GLKSD1    , 1.0E-15   , "A*m*V^-2"              , "G-t-S/D current coefficient" )
`MPRnb( GLKSD2    , 5E6       , "V^-1*m^-1"             , "G-t-S/D current coefficient" )
`MPRnb( GLKSD3    , -5E6      , "m^-1"                  , "G-t-S/D current coefficient" )
`MPRnb( GLKB1     , 5E-16     , "A*V^-2"                , "G-t-S/D current coefficient" )
`MPRnb( GLKB2     , 1E0       , "m*V^-1"                , "G-t-S/D current coefficient" )
`MPRnb( GLKB3     , 0E0       , "V"                     , "G-t-S/D current coefficient" )
`MPRoo( VZADD0    , 10.0E-3   , "V"            , 0, inf , "symmetry conservation coefficient" )
`MPRoo( PZADD0    , 5.0E-3    , "V"            , 0, inf , "symmetry conservation coefficient" )
`MPRnb( NFTRP     , 10E9      , "V^-1"                  , "ratio of trap density to attenuation coefficient" )
`MPRnb( NFALP     , 1.0E-19   , "cm*s"                  , "contribution of mobility fluctuation" )
`MPRnb( CIT       , 0.0       , "F*cm^-2"               , "cap caused by the interface trapped carriers" )
`MPRnb( FALPH     , 1.0       , "sm^3"                  , "power of f describing deviation of 1/f" )
`MPRcc( TNOM      , 27.0      , "C"            , 22, 32 , "temperature selected as a nominal value" )
`MPRnb( DLY1      , 100.0E-12 , "s"                     , "coefficient for delay due to diffusion of carriers" )
`MPRnb( DLY2      , 0.7E0     , "-"                     , "coefficient for delay due to conduction of carriers" )
`MPRnb( DLY3      , 0.8E-6    , "Ohm"                   , "coefficient for RC delay of bulk carriers" )
`MPRoo( TFOX      , 3.5E-9    , "m"            , 0, inf , "front oxide thickness" )
`MPRoo( TSOI      , 5.0E-8    , "m"            , 0, inf , "silicon film thickness" )
`MPRoo( XJ        , 5.0E-8    , "m"            , 0, inf , "impurity doping depth" )
`MPRoo( TBOX      , 1.1E-7    , "m"            , 0, inf , "buried oxide thickness" )
`MPRoo( NSUBS     , 3.0E+17   , "cm^-3"        , 0, inf , "SOI layer impurity concentration" )
`MPRoo( NSUBB     , 4.0E+14   , "cm^-3"        , 0, inf , "substrate impurity concentration" )
`MPRnb( RTH0      , 0.1       , "Kcm/W"                 , "Thermal resistance" )
`MPRnb( CTH0      , 1.0E-7    , "Ws/(Kcm)"              , "thermal capacitance" )
`MPRnb( SC4       , 0.0       , "-"                     , "SCE parameter" )
`MPRnb( PTL       , 0.0       , "V^PTP-1m^PTLP"         , "punchthrough parameter" )
`MPRnb( PTP       , 3.5       , "-"                     , "punchthrough parameter" )
`MPRnb( PT2       , 0.0       , "V^-1"                  , "punchthrough parameter" )
`MPRnb( PTLP      , 1.0       , "-"                     , "punchthrough parameter" )
`MPRnb( GDL       , 0.0       , "m^GDLP"                , "strength of high-field effect" )
`MPRnb( GDLP      , 0.0       , "-"                     , "modification of channel conductance" )
`MPRnb( GDLD      , 0.0       , "m"                     , "modification of channel conductance" )
`MPRnb( PT4       , 0.0       , "-"                     , "punchthrough parameter" )
`MPRnb( PT4P      , 1.0       , "-"                     , "punchthrough parameter" )
`MPRnb( VGSMIN    , -5.0*TYPE , "V"                     , "surface potential limiter" )
`MPRnb( RMIN      , 1E-3      , "ohm"                   , "Minimum resistance" )
`MPRnb( MUEPH1    , 25.0E3    , "cm^2V^-1s^-1"          , "phonon scattering" )

// Definition for the source resistance

//******* Instance parameters *******//
`IPRco( NRS       , 1.0        , ""                  ,   0 , inf , "Number of squares in source ")
`IPRco( NRD       , 1.0        , ""                  ,   0 , inf , "Number of squares in drain ")
`BPRco( LDRIFT    , 1.0E-6     , "m"                 ,   0 , inf , "Parameter for drift region length (drain) ")
`BPRco( LDRIFTS   , 1.0E-6     , "m"                 ,   0 , inf , "Parameter for drift region length (source) ")

//******* Model Flags *******//
`MPIcc( CORS      , 0          , ""                  ,   0 ,   1 , "source side resistance OFF(0)/ON(1)")
`MPIcc( CORD      , 0          , ""                  ,   0 ,   1 , "drain side resistance OFF(0)/ON(1)")
`MPIcc( CORBULK   , 0          , ""                  ,   0 ,   1 , "bulk resistance OFF(0)/ON(1)")

//******* Model parameters *******//
`MPRco( RSH       , 0.0        , "ohm"               ,   0 , inf , "Drain diffusion sheet resistance ")
`MPRnb( NOVERS    , 1E19       , "cm^-3"                         , "impurity concentration in overlap region" )
`MPRoo( RDRMUED   , 1.0E3      , ""                  ,   0 , inf , "Mobility in drift region (drain)")
`MPRoo( RDRMUES   , 1.0E3      , ""                  ,   0 , inf , "Mobility in drift region (source)")
`MPRoo( RDRVMAXD  , 3.0E7      , ""                  ,   0 , inf , "Saturation velocity in drift region (drain)")
`MPRoo( RDRVMAXS  , 3.0E7      , ""                  ,   0 , inf , "Saturation velocity in drift region (source)")
`MPRnb( RDRMUETMP , 0.0        , ""                              , "Temperature dependence of resistance ")
`MPRnb( RDRVTMP   , 0.0        , ""                              , "Temperature dependence of resistance ")
`MPRoo( RDRDJUNC  , 1.0E-6     , ""                  ,   0 , inf , "Junction depth at channel/drift region ")
`MPRco( RDRBBD    , 1          , ""                  , 0.1 , inf , "Degradation of the mobility in drift region (drain)")
`MPRco( RDRBBS    , 1          , ""                  , 0.1 , inf , "degradation of the mobility in drift region (source)")
`MPRnb( RDRBBTMP  , 0          , ""                              , "Temperature coefficient of RDRBB ")
`MPRnb( RDRVMAXW  , 0.0        , ""                              , "Wgate dependence of the saturation velocity in drift region")
`MPRnb( RDRVMAXWP , 1.0        , ""                              , "Wgate dependence of the saturation velocity in drift region")
`MPRnb( RDRVMAXL  , 0.0        , ""                              , "Lgate dependence of the saturation velocity in drift region")
`MPRnb( RDRVMAXLP , 1.0        , ""                              , "Lgate dependence of the saturation velocity in drift region")
`MPRnb( RDRMUEL   , 0.0        , ""                              , "Lgate dependence of the mobility in drift region ")
`MPRnb( RDRMUELP  , 1.0        , ""                              , "Lgate dependence of the mobility in drift region ")

// for new punchthrough model
`MPIcc( COPT      , 0          , "-"                 ,  0 , 1    , "flag punchthrough ")
`MPIsw( COPSPT    , 0          , "-"                             , "flag Ps0 method for deep punchthrough ")
`MPRoc( XJPT      , TSOI       , "m"             ,  0 , TSOI*1.2 , "Junction depth for deep punchthrough ")
`MPRoo( NJUNC     , 1e20       , "cm-3"              ,  0 , inf  , "Junction doping conc; deep punchthrough  ")
`MPRco( MUPT      , 0.0        , "m^2/V/s"           ,  0 , inf  , "mobility for deep punchthrough ")
`MPRnb( VFBPT     , 0.0        , "V"                             , "dVfb for deep punchthrough ")
`MPRnb( PSLIMPT   , 0.0        , "V"                             , "Ps0 limit for deep punchthrough ")
//bulk resistance
`MPRco( RBULK0    , 0.0        , "Ohm"               , 0  , inf  , "offset of bulk resistance ")
`MPRco( RBULKW    , 0.0        , "Ohm/m"             , 0  , inf  , "bulk resistance per width ")

//******* Output Values *******//
`OPP( Rdd       , "Ohm" , " Drift Resistance on Drain side")
`OPP( Rsd       , "Ohm" , " Drift Resistance on Source side")
`OPP( Rbulk     , "Ohm" , " Body Contact Resistance ")

integer rdmod /* 1:RS 2:RD */ ;
real Rdde , Rsde , Conductance , drainConductance , sourceConductance ;

`define Res_min       ( 1e-4 )

//`define __DEBUG_RDRIFTS__

// Control Parameters for Qs,bdep
`define QDEP_DLT   7.0
`define QDEP_DLT2  1.0
`define QDEP_DLT3  0.1
`define QDEP_PW    2
`define Qn_alpha   0
`define Qb_alpha   1
`define QnT3_alp   0
`define QbT3_alp   1
`define WDSOILMT       // Enable WDSOI Limitter
`define PF2ADDFAC  0

// Capacitive contribution from MOSFET built in body contact tub.
`MPRnb( VFBBTP    , (VFBC+1.12), "V"                    , "flatband voltage for overlapped MOSFET part" )
`MPRnb( CBTBN     , 0.0       , "F/m^2"                 , "N^+ poly capacitance" )
`MPRnb( CBTBP     , 0.0       , "F/m^2"                 , "P^+ poly capacitance" )
`MPRnb( XWDBT     , 0.0       , "m"                     , "BT overlap width" )


// Output Physical Values in operating point analysis //
`OPP( idse      , "A"   , "Drain-Source current")
`OPP( Isuba     , "A"   , "Substrate current")
`OPP( igidle    , "A"   , "Gate-Induced Drain Leakage current")
`OPP( igisle    , "A"   , "Gate-Induced Source Leakage current")
`OPP( igde      , "A"   , "Gate-Drain current")
`OPP( igse      , "A"   , "Gate-Source current")
`OPP( igbe      , "A"   , "Gate-Substrate current")
`OPP( ggm       , "S"   , "Transconductance")
`OPP( ggds      , "S"   , "Channel conductance")
`OPP( ggmbs     , "S"   , "Body effect(Back gate) transconductance")
`OPP( ggmt      , "S"   , "Temperature transconductance")
`OPP( deltemp   , "S"   , "Temperature ")
`OPP( vone      , "V"   , "Threshold voltage")
`OPP( vdsate    , "V"   , "Saturation voltage")
`OPP( qge       , "C"   , "Gate charge")
`OPP( qde       , "C"   , "Drain charge")
`OPP( qse       , "C"   , "Bulk charge")
`OPP( cggbd     , "F"   , " g-g MOSFET capacitance")
`OPP( cgdbd     , "F"   , " g-d MOSFET capacitance")
`OPP( cgsbd     , "F"   , " g-s MOSFET capacitance")
`OPP( cbgbd     , "F"   , " b-g MOSFET capacitance")
`OPP( cbsbd     , "F"   , " b-s MOSFET capacitance")
`OPP( cbdbd     , "F"   , " b-d MOSFET capacitance")
`OPP( cdgbd     , "F"   , " d-g MOSFET capacitance")
`OPP( cddbd     , "F"   , " d-d MOSFET capacitance")
`OPP( cdsbd     , "F"   , " d-s MOSFET capacitance")
`OPP( ibdb      , "A"   , " b-d Diode current")
`OPP( ibsb      , "A"   , " b-s Diode current")
`OPP( Gbd       , "S"   , " b-d Diode conductance")
`OPP( Gbs       , "S"   , " b-s Diode conductance")
`OPP( capbdb    , "F"   , " b-d Diode capacitance")
`OPP( capbsb    , "F"   , " b-s Diode capacitance")
// End of Output Physical Values //

//*-----------------*/
real       TMF0 , TMF1 , TMF2 , TMF3 , TMF4   ;
real       arg, x2 , xmax2 , xp , xmp , dnm , m0, mm ;

analog function real expm1 ;
    input   x ; real x ;
    expm1=exp(x)-1.0 ;
endfunction

analog function real log1p ;
    input   x ; real x ;
    log1p=ln (1.0+x) ;
endfunction

analog function real FPOW ;
    input   x , y ; real x , y ;
    FPOW = (x==0.0 && y==0.0) ? 1.0 : pow(x,y) ;
endfunction


// localparam
integer   SUBVERSION;
integer   lp_s0_max;
integer   lp_sl_max;

//-----------------------------------------------------------*
//Change units into MKS.
//----------------//
real      MKS_NSUBP;
real      MKS_VTMP;
real      MKS_NSUBCMAX;
real      MKS_NFALP;
real      MKS_NFTRP;
real      MKS_CIT;
real      MKS_NSUBS;
real      MKS_NSUBB;
real      MKS_RTH0;
real      MKS_CTH0;
real      MKS_NOVER;
real      MKS_NJUNC;
real      MKS_NSTI;
real      MKS_WFC;
real      MKS_VMAX;
real      MKS_PARL1;

//-----------------------------------------------------------*
//----------------//
real      UC_SC2;
real      UC_SC3;
real      UC_SCP2;
real      UC_SCP3;
real      UC_GDLD;
real      UC_CLM2;
real      UC_TNOM;
real      UC_VFBOVER;
real      UC_LOD;
integer   flg_info;
integer   flg_nqs;
integer   flg_skipAcc  ;

real      egtnom;
real      Tfox0;
real      C_soi;
real      C_soi_inv;
real      C_fox0;
real      C_fox0_inv;
real      C_box;
real      C_box_inv;
real      C_box_FD_inv;
real      Lgate;
real      Leff , Leff_cv;
real      Lgleff;
real      LGLE;
real      Wgate;
real      dW;
real      dWBT;
real      dWCV;
real      Weff;
real      weff_cv;
real      weff_nf;
real      weffcv_nf;
real      WG;
real      WL;
real      muesr;
//   Surface   impurity   profile   //
real      Nsubpp;
real      Lod_half_ref;

real      betatnom;
real      qnbulk_esi;
//   Parasitic   component   of   the   channel   current   //
real      ptl0;
real      pt40;
real      gdl0;
//   costi0   and   costi1   for   STI   transistor   model(temperature-independent   part)   //
real      costi00;
real      nsti_p2;
real      cnstpgd;
real      c0bulk;
real      Vfb;
//   Wg   dependence   for   short   channel   devices   //
real      lgatesm;
real      dVthsm;
//   Lg   dependence   of   wsti   //
real      UC_WSTI;
//   CLM5   &   CLM6   //
real      clmmod;
//   Gate   resistance   //
real      grg_cnst;
//   Isub   //
real      zvgs;
real      xvbs;
real      xgate;
real      xsub1;
real      xsub2;
//   Additional   term   of   lateral-field-induced   capacitance   //
real      cqyb0;
//   Lg   dependence   for   Vfbsub   //
real      vfbsub0;
//   Lg   dependence   for   SVGS   //
real      UC_SVGS;
//   Vdseff   //
real      DDLTe;

real      Vgs_min;

//--------------------------------------------------
//  Local Variables
// Constants ----------------------- //
//
real      Vbs_max ;
real      Vbs_bnd ;
real      Gjmin ;
//
real      sti2_dlt ;
// Internal flags --------------------//
integer   flg_pprv ;
integer   flg_noqi ;
integer   flg_ign ;
integer   flg_dPpg ;
integer   flg_qme ;
// Important Variables in HiSIM -------//
// external bias //
real      Vbse, Vdse, Vgse ;
// confine bias //
real      Vdsc, Vgsc, Vbsc, Vbsc_dVbse ;
// internal bias //
real      Vbs, Vds, Vgs, Vgp, Vgs_fb ;
// Ps0 : surface potential at the source side //
real      Ps0 ;
// Psl : surface potential at the drain side //
real      Psl, Psl_lim ;
// Pds :=Psl - Ps0 //
real      Pds, Pds_ini, Pds_max ;
// iteration numbers of Ps0 and Psl equations. //
integer   lp_s0, lp_sl ;
// Xi0 :=beta * ( Ps0 - Vbs ) - 1. //
real      Xi0, Xi0p12 ;
// Xil :=beta * ( Psl - Vbs ) - 1. //
real           Xilp12 ;
// modified bias and potential for sym.//
real      Vbsz, Vdsz, Vgsz, Vzadd, Ps0z, Pzadd, Vgpz ;
real      Vgpd, Ps0_iniC ;
// Chi :=beta * ( Ps{0/l} - Vbs ) //
real      Chi ;
// threshold voltage //
real      Vth, Vth0 , Wd0 ;
// variation of threshold voltage //
real      dVth, dVth0, dVthSC ;
//
real      dVthSCR ;
//
real      dVthW ;
// Alpha and related parameters //
real      Alpha, Achi, VgVt, Pslsat, VdsatS, Vdsat ;
//
// Q_B and capacitances //
real      Qb ;
// Q_BC and capacitances //
// Q_I and capacitances //
real      Qi ;
// Q_D and capacitances //
real      Qd ;
// channel current //
real      Ids, Ids0 , IdsPT , Idsorg , IdsPT0 , IdsPT1 ;
// STI //
real      costi0_p2 ;
real      dVthSCSTI, Vgssti, costi0, costi1, costi3, costi4, costi5, costi6 ;
real      costi7, Psasti, Psbsti, Psab, Psti, sq1sti, sq2sti, Qn0sti, Idssti ;
real      Asti , expsti ;
// constants ------- //
real      beta, beta2, beta_inv ;
// device instances //
real      Ldby, q_Nsub, Nin, Pb2, Pb20, Pb20b, Pbsum, sqrt_Pbsum ;
real      Pb2c, Eg;
// PART-1 ---------- //
real      cnst0SOI, cnst1bulk, fac1, fac1p2 ;
//
real      fb, exp_Chi; // fb_dChi used in COQOVSM==1 block (Qover)
//
real      Qn0, Qb0 ;
//
real      Idd, Idd1 ;
//
real      Eeff, Rns, Mu, Muun, Ey,  Vmaxe ;
//
real      Ps0_min, Acn, Acd, Ac1, Ac2, Ac3, Ac4, Ac31, Ac41 ;
// PART-2 (Isub)---------- //
real      Isub ;
//
//
// (Isub)+//
// IBPC //
real      betaWL;
real      IdsIBPC ;
// PART-3 (overlap) //
integer   flg_overgiven ;
real      Qgos, Qgod, Cgdoe, Cgsoe, Cgbe, Qgob ;
// fringing capacitance //
real      Cf ;
real      Cfd, Cfs, Cfu, Qfd, Qfs, Qfbc ;
// Cqy //
real      Qy ;
// PART-4 (junction diode) //
real      Ibs, Ibd;
// junction capacitance //
real      Qbs, Qbd;
real      W_dios , W_diod , W_dioscv , W_diodcv ;
// PART-5 (NQS) //
real      tau, taub ;
// PART-6 (noise) //
real      Nflic ;
// thermal //
real      Nthrml, Mud_hoso ;

// induced gate noise ( Part 0/3 ) //
real      kusai00, kusaidd, kusaiL, kusai00L, sqrtkusaiL, kusai_ig, gds0_ign ;
real      crl_f ;
// Igate , Gidl , Gisl //
real      Egp12, Egp32, Egidl, Egisl, Igs, Igd ;
real      Igb, Igate, GLPART1, Igidl, Igisl ;
// Accumulation zone //
real      Psa ;
// CLM //
real      Psdl, Ec, Lred, Aclm ;
// Pocket Implant //
real      Vthp, dVthLP ;
// Poly-Depletion Effect //
real      dPpg ;
// Quantum Effect //
real      Tfoxe, dTfox, C_fox, C_fox_inv;
real      Vthq ;
// FMD* parameters for dPpg model //
real      FMDVDS ;
// temporary vars.-- //
real      T0, T1, T2, T3, T4, T5, T6, T7, T8, TX, TY ;
integer   flg_zone, flg_depmode, flg_depmode_d ;
real      Q_FD_SOI ;
real      Vbi_SOI, phi_s0_SOI_ini, phi_b0_SOI_ini, phi_s0_bulk_ini, phi_sL_SOI_ini ;
real      phi_bL_SOI_ini, phi_sL_bulk_ini, phi_s0_SOI, phi_b0_SOI, phi_s0_bulk ;
real      phi_sL_SOI, phi_bL_SOI, phi_sL_bulk, Q_n0, Q_dep0, Q_s0_bulk ;
real      Q_nL, Q_depL, Q_sL_bulk ;
real      Q_s0_dep , Q_sL_dep ;
real      Q_b0_dep , Q_b0_dep_dPbs , Q_b0_dep_dPss ;
real      Q_bL_dep , Q_bL_dep_dPbs , Q_bL_dep_dPss ;
real      Q_s0_dep_ini ;
real      Q_dep_SOI ;
real      Q_depS0 ;
real      Q_depSL ;
// Idd parameters. //
real      Ps0b, Ps0s, PsLs, Ps0_iniA, Ps0_iniB, Ps0_ini ;
real      cnst1SOI, psb_iniA, psb_iniB, Pb2_bulk, shift ;
real      FD_start, FD_end, Q_s0_bulk_0, phi_s0_bulk_0 ;
real      phi_b_dep, phi_b_dep_dPsb, phi_b_dep0, phi_b_dep0_dPsb, Qsub ;

// Qh0* and QhL* are History Effect parameters. //
real      Qhs, Ids_isub, Ps0_isub ;
// Qhs history effect //
real      Qhs_prev, tauh, Rsb ;
//
real      Vgp_ini ;
real      C_S_inv, WdSOI, WdSOI_0, WdSOI_ini0, WdSOI_ini1, WdSOI_ini2 ;
real      Q_WdSOI_max ;
real      scale_fac , PSCONV_3D ;
real      RRR_B, RRR_CSOI_Cbox, RRR_P0, RRR_alpha_SOI, RRR_eta, RRR_CC, RRR_DD ;
real      WdSOI_ini, phi_SOI0, phi_SOIL ;
real      dphi_sb, c_sb, Chib, phi_SOIb, phi_SOIb_dPss ;
real      Ab, Ai,  Db, Di, C2;

// the parameter SHE //
real      TTEMP;
integer   flg_conv ;
integer   flg_conv_0, flg_conv_L; // source side and drain side; =1: successful convergence
real      ptovr, cnstC_foxi ;
// constants //
real      Vbsz2, Qiu, Qbu, Qdrat , Qdrat_noi ;
real      Vbslim;
real      Lch , Lch_cv ;
real      fb_dPss, C_W_SOI ;

real      Vgpsub, vfbsub1 ;
// For limiting the bottom-junction depletion charges in the SOI layer //
real      Ievb, phib ;
real      Pds_qwe, Ievb0;
real      Mfactor ;
// Vdseff //
real      Vdseff, Vdsorg ;
// G/S and G/D Overlap Charges: Qovs/Qovd //
real      Qovd, Qovs ;
real      QbdLD, QbsLD, QbuLD, QsuLD, QiuLD ;

// Mode flag (=0 | 1 ) //
real      ModeNML, ModeRVS ;

// Body contact well MOSFET (capacitance only) variable names are tentative.
real      Qbody_bt_p_sus, Qbody_bt_p_sud, Qbody_bt_p_ius, Qbody_bt_p_iud;
real      Qbody_bt_n_sus, Qbody_bt_n_sud, Qbody_bt_n_ius, Qbody_bt_n_iud;
real      q_bt_ge, q_bt_de, q_bt_se;

// for consts //
real      cnst0bulk ;
real      Vbsbiz ;
// Qb for FB devices //
real      Qs_FB, Qd_FB ;
real      Qinm , Qidn ,  Qdnm , Qddn , Quot ;
// for BT device //
real      exp_bVbsVds, exp_bPs0, exp_bVbs, cfs1, fs01 ;
real      fs01_dPs0, fs02, fs02_dPs0, Fs0, Fs0_dPs0, dPs0, dPsl, dPlim ;
real      fsl1, fsl1_dPsl, fsl2, fsl2_dPsl, Rho, exp_Rho, Fsl, Fsl_dPsl ;
real      Eta, Eta1, Eta1p12, Zeta12, F00 ;
real      F10, Fdd, DtPds ;
real      Vbsp , Vbspz , Vbcs_cl ;
real      Vbs0 , VbsL  ;
// for bt device //
// uc_*** vars. for device and model parameters -> many of them are now localparam.
real      UC_PDBCP    , UC_PSBCP    ;
real      UC_TEMP     ;

// mosfet overlapped with body contact tub.
real      UC_NSUBBTTUB ;
real      UC_AREABT , UC_VFBBT ;
integer   CBTBN_GIVEN , CBTBP_GIVEN , ABTN_GIVEN , ABTP_GIVEN , CBTB_GIVEN ;
integer   PDBCP_GIVEN , PSBCP_GIVEN ;
real      Cbtp , Cbtn , area_bt_p , area_bt_n ;
real      peri_hhi ;

// vars. for hsm2temp.c
real      Nsub;
real      Lod_half ;
real      Nsubps ;
// here->hsmsoi_ vars. for hsmsoieval.c
real      temp_Given , dtemp_Given;
real      rth   ;
real      cth   ;
real      CGS_mphn0 ;
real      UC_NSUBS;
real      qnsub_esi , qnsub_esi2 , cnst_2esi_q_Nsubs ;
real      ptovr0 , wdpl;
real      vmax0 ;
// real ddlte;
real      grg;
real      qbe;
// Vars for capacitance fitting
real      cgsb   , Xd     ,  isube   , noiigate;
real      noicross , qbd_s0 , qbs_s0 ;

// Local Vars. for hsmsoieval.c
integer   i    ;
real      Cthe    ;
real      CGBO_GIVEN , CGDO_GIVEN , CGSO_GIVEN  ;
real      nume   ;
real      Q_depS0_SOI_o_cnst0SOI , Q_depSL_SOI_o_cnst0SOI;
real      Vbsi    , Vdsi    , Vgsi    , Isubs  ;
real      Iqd_nqs , Iqs_nqs, Qd_qs  , Qs_qs ;
real      Rpower  , Qs     , Qi_nqs;
real      Qb_nqs , Iqi_nqs , Iqb_nqs , Qd_nqs , Qs_nqs , Qg_nqs , Qi_qs  , Qb_qs  , Gth   ;
real      vbcd   , vbcs   ;
// Local Definition Vars. by User
real      Iqh_nqs ;
real      Nsubb0  , Qg     , Itemp  , Qhs_hist;
real      noiflick , noithrml , Vdsei   , Vgsei   , Vbsei   , ggdss ;
real      cgbbd  , cdbbd  , csgbd  , csdbd  , cssbd  , csbbd  , cbbbd  , whi_noise ;
// Others
integer   flg_brk8 ;
integer   end_of_part_1  ;
integer   mode ;
real      ci, sid, sigrat, sigrat_s, sigrat_d ;

//
// Definitions for Memory State Variables for COPPRV model
//
real Pss0_ini, Pbs0_ini, Psb0_ini ;
real Pssl_ini, Pbsl_ini, Psbl_ini ;

`ifdef DISABLE_COPPRV
`else
    integer called , mode_prv , mode_prv2 , flg_zone_prv ;
    real    vtol_pprv ;
    real    vtol_pprv_l, vtol_pprv_u ;
    integer flg_pprv_prv;
    real    vbsc_prv  , vdsc_prv  , vgsc_prv ;
    real    vbsc_prv2 , vdsc_prv2 , vgsc_prv2 ;
    real    Vbsc_dif  , Vdsc_dif  , Vgsc_dif  , sum_vdif ;
    real    Vbsc_dif2 , Vdsc_dif2 , Vgsc_dif2 , sum_vdif2 ;
    real    dVbs  , dVds  , dVgs  ;
    real    ddVbs , ddVds , ddVgs ;
    real    TXdvbs , TXdvds , TXdvgs ;
    real    pss0_prv  , pbs0_prv  , psb0_prv ;
    real    pssl_prv  , pbsl_prv  , psbl_prv ;
    // End of Definitions
`endif // COPPRV


analog begin
`ifdef _4_PORTS_CONNECTED_
        V(n6) <+ 0.0;
        V(bc) <+ 0.0;
        if ( COBCNODE == 1 ) begin
            $write(" *** Fatal(HiSIM_SOI): COBCNODE = 1 but terminal 'bc' is not connected.\n" );
            $finish(0);
        end
`else
`ifdef _5_PORTS_CONNECTED_
            V(n6) <+ 0.0;
            if ($port_connected(bc) == 0) begin // 4 nodes
                if ( COBCNODE == 1 )  begin
                    $write(" *** Fatal(HiSIM_SOI): 'bc' is not connected but COBCNODE = 1.\n" );
                    $finish(0);
                end
            end
`else
            //    _6_PORTS_CONNECTED_
            if ($port_connected(n6) == 1) begin
                V(n6,temp) <+ 0.0;
                if ( COBCNODE == 0 ) begin
                    $write(" *** Fatal(HiSIM_SOI): 6 nodes are connected but COBCNODE = 0.\n" );
                    $finish(0);
                end
            end
            else begin
                V(n6) <+ 0.0;
                if ($port_connected(bc) == 0) begin // 4 nodes
                    if ( COBCNODE == 1 )  begin
                        $write(" *** Fatal(HiSIM_SOI): 'bc' is not connected but COBCNODE = 1.\n" );
                        $finish(0);
                    end
                end
            end
`endif
        if (COBCNODE == 0) begin
            V(bc,temp) <+ 0.0;
        end
`endif

    //begin : HSMSOI_model

    // Initial Settings

    Idd        = 0.0 ;
    gds0_ign   = 1e-12 ;
    qse        = 0.0 ;
    flg_ign    = 0 ;
    end_of_part_1 =0 ;
    Xd         = 0.0 ;
    flg_noqi   = 0 ;
    flg_zone   = 0 ;
    Psl        = 0.0 ;
    Psl_lim    = 0.0 ;
    Pds        = 0.0 ;
    Pds_ini    = 0.0 ;
    Ps0z       = 1.0 ;
    Alpha      = 0.0 ;
    VgVt       = 0.0 ;
    Vdsat      = 0.0 ;
    Qb         = 0.0 ;
    Qi         = 0.0 ;
    Qd         = 0.0 ;
    Ids        = 0.0 ;
    fb         = 0.0 ;
    Qn0        = 0.0 ;
    Mu         = 0.0 ;
    Muun       = 0.0 ;
    Ey         = 0.0 ;
    Isub       = 0.0 ;
    betaWL     = 1.0 ;
    IdsIBPC    = 0.0 ;
    Qgos       = 0.0 ;
    Qgod       = 0.0 ;
    Qgob       = 0.0 ;
    Qovd       = 0.0 ;
    Qovs       = 0.0 ;
    QbdLD      = 0.0 ;
    QbsLD      = 0.0 ;
    Ibd        = 0.0 ;
    Ibs        = 0.0 ;
    Gbd        = 0.0 ;
    Gbs        = 0.0 ;
    Qbd        = 0.0 ;
    Qbs        = 0.0 ;
    Qinm       = 0.0 ;
    Qidn       = 0.0 ;
    WdSOI_0    = `t_SOI ;

    // Body contact well parasitic nMOSFET 4 lines
    Qbody_bt_p_sus = 0.0;
    Qbody_bt_p_sud = 0.0;
    Qbody_bt_p_iud = 0.0;
    Qbody_bt_p_ius = 0.0;
    //
    Qbody_bt_n_sus = 0.0;
    Qbody_bt_n_sud = 0.0;
    Qbody_bt_n_iud = 0.0;
    Qbody_bt_n_ius = 0.0;
    UC_AREABT  = 0.0 ;
    UC_VFBBT   = 0.0 ;
    q_bt_ge = 0.0;
    q_bt_se = 0.0;

    tau        = 0.0 ;
    taub       = 0.0 ;
    Mud_hoso   = 0.0 ;
    kusai00    = 0.0 ;
    kusaiL     = 0.0 ;
    kusai00L   = 0.0 ;
    sqrtkusaiL = 0.0 ;
    kusai_ig   = 0.0 ;
    crl_f      = 0.0 ;
    Psdl       = 0.0 ;
    Ec         = 0.0 ;
    Lred       = 0.0 ;
    flg_depmode = 0 ;
    flg_depmode_d = 0 ;
    phi_sL_SOI_ini = 0.0 ;
    phi_bL_SOI_ini = 0.0 ;
    phi_sL_bulk_ini = 0.0 ;
    phi_s0_SOI = 0.0 ;
    phi_b0_SOI = 0.0 ;
    phi_s0_bulk = 0.0 ;
    phi_sL_SOI = 0.0 ;
    phi_bL_SOI = 0.0 ;
    phi_sL_bulk = 0.0 ;
    Q_dep_SOI  = 0.0 ;
    Q_n0       = 0.0 ;
    Q_b0_dep   = 0.0 ;
    Q_bL_dep   = 0.0 ;
    Q_dep0     = 0.0 ;
    Q_s0_bulk  = 0.0 ;
    Q_nL       = 0.0 ;
    Q_depL     = 0.0 ;
    Q_sL_bulk  = 0.0 ;
    shift      = 0.0 ;
    Q_s0_bulk_0 = 0.0 ;
    Iqd_nqs    = 0.0 ;
    Iqs_nqs    = 0.0 ;
    Iqi_nqs    = 0.0 ;
    Qi_nqs     = 0.0 ;
    Qd_nqs     = 0.0 ;
    Qs_nqs     = 0.0 ;

    phi_b_dep0 = 0.0 ;
    Qsub       = 0.0 ;
    Qhs        = 0.0 ;
    WdSOI      = 0.0 ;
    Ps0_iniA   = 0.0 ;
    Qiu        = 0.0 ;
    Qbu        = 0.0 ;
    Qdrat      = 0.5 ;
    Qdrat_noi  = 0.5 ; // for Noise
    Ievb       = 0.0 ;
    Qs_FB      = 0.0 ;
    Qd_FB      = 0.0 ;
    Iqh_nqs    = 0.0 ;
    Qd_qs      = 0.0 ;
    Qs_qs      = 0.0 ;
    Qi_qs      = 0.0 ;
    Qb_qs      = 0.0 ;
    fs01       = 0.0 ;
    fs02       = 0.0 ;
    fsl1       = 0.0 ;
    fsl2       = 0.0 ;
    SUBVERSION = `SUBVERSION;
    lp_s0_max = 200;
    lp_sl_max = 200;
    flg_skipAcc = 0;

    // for Hidden states
    Vbsbiz       = 0.0 ;
    Ps0_ini      = 0.0 ;
    Q_s0_dep_ini = 0.0 ;
    IdsPT0 = 0.0 ;
    Lch_cv = 0.0;

    //-----------------------------------------------------------*
    //Change units into MKS.
    //----------------//
    MKS_VMAX     = VMAX     * `C_cm2m;    //"cm*s^-1"
    MKS_NSUBP    = NSUBP    / `C_cm2m_p3; //"cm^-3"
    MKS_VTMP     = VTMP     * `C_cm2m;    //"cm*s^-1"
    MKS_NSUBCMAX = NSUBCMAX / `C_cm2m_p3; //"cm^-3"
    MKS_NFALP    = NFALP    * `C_cm2m;    //"cm*s"
    MKS_NFTRP    = NFTRP    / `C_cm2m_p2; //V^-1
    MKS_CIT      = CIT      / `C_cm2m_p2; //"F*cm^-2"
    MKS_NSUBS    = NSUBS    / `C_cm2m_p3; //"cm^-3"
    MKS_NSUBB    = NSUBB    / `C_cm2m_p3; //"cm^-3"
    MKS_RTH0     = RTH0     * `C_cm2m;    //"Kcm/W"
    MKS_CTH0     = CTH0     / `C_cm2m;    //"Ws/(Kcm)"
    MKS_NOVER    = NOVER    / `C_cm2m_p3; //"cm^-3"
    MKS_NJUNC    = NJUNC    / `C_cm2m_p3; //"cm^-3"
    MKS_NSTI     = NSTI     / `C_cm2m_p3; //"cm^-3"
    MKS_WFC      = WFC / `C_cm2m_p2; // "F*cm^-2*m^-1"
    MKS_PARL1    = PARL1    * `C_cm2m; //cm

    //-----------------------------------------------------------*
    //----------------//
    UC_SC2    = (( SC1 == 0.0 )? 0.0 : SC2 );
    UC_SC3    = (( SC1 == 0.0 )? 0.0 : SC3 );
    UC_SCP2   = (( SCP1 == 0.0 )? 0.0 : SCP2 );
    UC_SCP3   = (( SC1 == 0.0 )? 0.0 : SCP3 );
    UC_GDLD  = GDLD  * `C_m2um ;
    UC_TNOM   = TNOM  + 273.15;      // [C] -> [K] //
    UC_VFBOVER = VFBOVER;
    UC_LOD    = LOD   * `C_m2cm;
    flg_info = INFO;
    flg_nqs  = CONQS;

    UC_CLM2 = (($param_given(CLM2)) ? CLM2 : 5.0e9/(`t_SOI * NSUBS));
    `Fn_SL_CP(UC_CLM2, UC_CLM2, 2.0, 0.1, 2 )

    // Calculation for Loacl Parameter
    egtnom = EG0 - UC_TNOM * ( 90.25e-6 + UC_TNOM * 1.0e-7 );
    Tfox0 = `t_fox;
    C_soi = `C_ESI / `t_SOI ;
    C_soi_inv = 1.0 / C_soi ;
    C_fox0 = `C_EOX / Tfox0;
    C_fox0_inv = Tfox0 / `C_EOX;
    C_box = `C_EOX / `t_box ;
    C_box_inv = `t_box / `C_EOX ;
    C_box_FD_inv = C_box_inv + C_soi_inv ;
    Lgate = L;
    Leff = Lgate - 2.0e0 * XLD ;
    Leff_cv = Lgate - 2.0e0 * XLDC ;
    Lgleff = (COLGLEFF == 0) ? Lgate : Leff;
    LGLE = Lgleff * `C_m2um;
    Wgate = W / NF;
    dW = XWD;
    dWBT = ((SUBVERSION < 1)? 0.0 : XWDBT);
    dWCV = ((SUBVERSION < 1)? XWD : XWDC );
    if ( COBCNODE == 0 ) begin
        Weff = Wgate - 2.0e0 * dW;
        weff_cv = Wgate - 2.0e0 * dWCV;
    end else begin
        Weff = Wgate - NBT * dWBT - (2.0e0 - NBT) * dW;
        weff_cv = Wgate - NBT * dWBT - (2.0e0 - NBT) * dWCV;
    end
    weff_nf = Weff * NF;
    weffcv_nf = weff_cv * NF;
    WG = Wgate * `C_m2um;     // in um
    WL = WG * LGLE;
    muesr = MUESR0 * (1.0e0 + (MUESRL / pow(LGLE, MUESLP))) * (1.0e0 + (MUESRW / pow(WG, MUESWP)));

    // Surface impurity profile //
    // Check NSUBP > NSUBC
    if (SUBVERSION > 3 && MKS_NSUBP < MKS_NSUBS && LP > 0) begin
        //         if( COERRREP ) begin
        $write("*** error(HiSIM_SOI): NSUBP is smaller than NSUBS when LP > 0.\n" ) ;
        $write("    ( NSUBP = %g < NSUBS = %g, LP %g > 0), reset to NSUBS.\n",NSUBP,NSUBS,LP);
        //         end
        MKS_NSUBP = MKS_NSUBS ;
    end

    Nsubpp = MKS_NSUBP * (1.0e0 + (NSUBP0 / pow(WG, NSUBWP)));
    Lod_half_ref = 2.0 / ( 1.0 / (SAREF + 0.5 * Lgate) + 1.0 / (SBREF + 0.5 * Lgate) ) ;
    betatnom = `C_QE / (`C_KB * UC_TNOM);
    qnbulk_esi = `C_QE * MKS_NSUBB * `C_ESI ;

    // Parasitic component of the channel current //
    ptl0 = PTL * pow(LGLE, -PTLP);
    pt40 = PT4 * pow(LGLE, -PT4P);
    gdl0 = GDL * pow(LGLE + UC_GDLD, -GDLP) ;

    // costi0 and costi1 for STI transistor model(temperature-independent part) //
    costi00 = sqrt (2.0 * `C_QE * MKS_NSTI * `C_ESI );
    nsti_p2 = 1.0 / ( MKS_NSTI * MKS_NSTI );
    cnstpgd = pow(1e0 + 1e0 / LGLE, PGD4) * PGD1;
    c0bulk = qnbulk_esi ;

    Vfb = VFBC;

    // Wg dependence for short channel devices //
    lgatesm = Lgleff + WL1 / pow( WL , WL1P );
    dVthsm = WL2 / pow(WL, WL2P);

    // Lg dependence of wsti //
    UC_WSTI =  WSTI * ( 1.0e0 + WSTIL / pow( lgatesm * `C_m2um , WSTILP )) *
                    1.0e0 + WSTIW / pow( WG , WSTIWP );

    // CLM5 & CLM6 //
    clmmod = 1e0 + pow(LGLE, CLM5) * CLM6;

    // Gate resistance //
    grg_cnst = RSHG * ( XGW + Weff / (3.0e0 * NGCON)) / (NGCON * ( Lgate - XGL ) * NF);

    // Isub //
    zvgs = 1.0 + SVGSW / pow(WG, SVGSWP);
    xvbs = SVBS  * (1.0 + SVBSL / pow(LGLE, SVBSLP));
    xgate = LGLE / (LGLE + SLG);
    xsub1 = SUB1  * (1.0  + SUB1L / pow(LGLE, SUB1LP));
    xsub2 = SUB2 * (1.0 + SUB2L / LGLE);

    // Additional term of lateral-field-induced capacitance //
    cqyb0 = `C_m2um * weffcv_nf * XQY1 / pow(LGLE, XQY2);

    // Lg dependence for Vfbsub //
    vfbsub0 = VFBSUB * (1.0e0 + (VFBSUBL / pow(LGLE, VFBSUBLP)));

    // Lg dependence for SVGS //
    UC_SVGS = SVGS * (1.0e0 + (SVGSL / pow(LGLE, SVGSLP)));

    // Vdseff //
    DDLTe = DDLTSLP * LGLE * DDLTMAX / (DDLTSLP * LGLE + DDLTMAX) + DDLTICT + `Small;
    if (DDLTe < 3.0) begin
        DDLTe = 3.0;
    end

    Vgs_min = TYPE * VGSMIN;

    // @( initial_step or initial_step("static") ) begin

    begin : initializeModel

        CGBO_GIVEN  = $param_given(CGBO) ;
        CGDO_GIVEN  = $param_given(CGDO) ;
        CGSO_GIVEN  = $param_given(CGSO) ;
        CBTBP_GIVEN = $param_given(CBTBP) ;
        CBTBN_GIVEN = $param_given(CBTBN) ;
        PDBCP_GIVEN = $param_given(PDBCP) ;
        PSBCP_GIVEN = $param_given(PSBCP) ;
        ABTP_GIVEN  = $param_given(ABTP) ;
        ABTN_GIVEN  = $param_given(ABTN) ;
        temp_Given  = $param_given(TEMP) ;
        dtemp_Given = (DTEMP==0) ? 0 : 1 ;

        Mfactor = `MFACTOR_USE ;
        Gjmin = $simparam("gmin",1.0e-12);

    end // initializeModel

    begin : initializeInstance

        UC_PDBCP = PDBCP; // deferred
        UC_PSBCP = PSBCP; // deferred

        UC_TEMP  = TEMP  + 273.15 ;      // [C] -> [K] //

        //  Beginning of hsmsoitemp.c

        rth = MKS_RTH0 / (Mfactor * weff_nf) ;
        cth = MKS_CTH0 * (Mfactor * weffcv_nf) ;

        // Half length of diffusion //
        if (SA > 0.0 && SB > 0.0
               &&(NF == 1.0 ||(NF > 1.0 && SD > 0.0))) begin
            T1 = 0.0 ;
            for (i = 0 ; i < NF ; i= i + 1) begin
                T1 = T1 + 1.0 / (SA + 0.5 * Lgate + i * (SD + Lgate))
                    + 1.0 / (SB + 0.5 * Lgate + i * (SD + Lgate)) ;
            end
            Lod_half = 2.0 * NF / T1 ;
        end else begin
            Lod_half = 0.0 ;
        end

        // Surface impurity profile //
        if (Lod_half > 0.0) begin
            T1 = 1.0e0 / (1.0e0 + NSUBPSTI2) ;
            T2 = pow(NSUBPSTI1 / Lod_half, NSUBPSTI3) ;
            T3 = pow(NSUBPSTI1 / Lod_half_ref, NSUBPSTI3) ;
            Nsubps = Nsubpp * (1.0e0 + T1 * T2) / (1.0e0 + T1 * T3) ;
        end else begin
            Nsubps = Nsubpp ;
        end

        T2 = (1.0e0 + (NSUBCW / pow(WG, NSUBCWP)))
               * (1.0e0 + (NSUBCL / pow(LGLE, NSUBCLP))) ;
        T3 = MKS_NSUBCMAX / MKS_NSUBS ;
        `Fn_SUtemp( T1, T2, T3, 0.01)
        UC_NSUBS = MKS_NSUBS * T1 ;

        if (Lod_half > 0.0) begin
            T1 = 1.0e0 / (1.0e0 + NSUBCSTI2) ;
            T2 = pow (NSUBCSTI1 / Lod_half, NSUBCSTI3) ;
            T3 = pow (NSUBCSTI1 / Lod_half_ref, NSUBCSTI3) ;
            UC_NSUBS = UC_NSUBS * (1.0e0 + T1 * T2) / (1.0e0 + T1 * T3) ;
        end

        if (Lgleff > LP) begin
            Nsub = (UC_NSUBS * (Lgleff - LP) + Nsubps * LP) / Lgleff ;
        end else begin
            Nsub = Nsubps + (Nsubps - UC_NSUBS) * (LP - Lgleff) / LP ;
        end

        q_Nsub   = `C_QE * Nsub ;
        qnsub_esi = q_Nsub * `C_ESI ;
        qnsub_esi2 = 2.0 * qnsub_esi ;

        // Pocket Overlap(temperature-independent part) //
        if (Lgleff <= 2.0e0 * LP) begin
            Nsubb0 = 2.0e0 * Nsubps - (Nsubps - UC_NSUBS) * Lgleff / LP - UC_NSUBS ;
            ptovr0 = ln (Nsubb0 / UC_NSUBS) ;
            // ptovr0 will be divided by beta later. //
        end else begin
            ptovr0 = 0.0e0 ;
        end

        // 2 phi_B //
        // @300K, with pocket //
        Pb20   = 2.0e0 / `C_b300 * ln (Nsub / `C_Nin0) ;
        // @300K, w/o pocket //
        Pb2c   = 2.0e0 / `C_b300 * ln (UC_NSUBS / `C_Nin0) ;

        // Depletion Width //
        wdpl = sqrt(2.0e0 * `C_ESI / `C_QE / Nsub) ;

        // Velocity Temperature Dependence(Temperature-dependent part will be multiplied later.) //
        T1 = (1.0e0 + (VOVER / pow(LGLE, VOVERP)))
              * (1.0e0 + (VOVERS / pow(WL, VOVERSP))) ;
        `Fn_SZtemp(vmax0, T1, 0.001)

        // Gate resistance //
        if (CORG == 1) begin
            if (grg_cnst > 1.0e-3) begin
                grg = Mfactor / grg_cnst ; // grg_cnst: localparam
            end else begin
                grg = Mfactor * 1.0e3 ;
                $write("warning(HiSIM_SOI): The gate conductance reset to 1.0e3 mho.\n") ;
            end
        end else begin
            grg = Mfactor * 1.0e3 ;
        end

        // Bulk resistance //
        if (CORBULK == 1) begin
            T0 = RBULKW * weff_nf + RBULK0 ;
            Rbulk = T0 / Mfactor ;
            if (Rbulk < `Res_min) Rbulk = `Res_min ;
        end else begin
            Rbulk = `Res_min ;
        end

        //  End of hsmsoitemp.c
        if ( COBCNODE == 1 ) begin // bt model
            /* Calc. the parasitic parameters and caps for body contact */
            if ( COADOV ) begin

                area_bt_p = (ABTP_GIVEN) ? ABTP : WBTP * NF * LBT ;
                area_bt_n = (ABTN_GIVEN) ? ABTN : WBTN * NF * LBT ;
                Cbtp = 0.0 ; Cbtn = 0.0 ;

                if ( area_bt_p > 0.0 && CBTBP_GIVEN) begin
                    Cbtp =  -area_bt_p * CBTBP ;
                end else Cbtp = 0.0 ;
                if ( area_bt_n > 0.0 && CBTBN_GIVEN) begin
                    Cbtn =  -area_bt_n * CBTBN ;
                    area_bt_n = 0.0 ;
                end

            end else begin /* COADOV=0 */
                area_bt_n = 0.0 ; Cbtn = 0.0 ;
                area_bt_p = 0.0 ; Cbtp = 0.0 ;
            end

            /* Calc. the parasitic parameters for j-diode */
            peri_hhi = ( LBT > Lgate ) ?  0.5 * (LBT - Lgate) : 0.0 ;
            if ( PDBCP_GIVEN==0 ) UC_PDBCP = peri_hhi ;
            if ( PSBCP_GIVEN==0 ) UC_PSBCP = peri_hhi ;

            W_diod   = `W_diod ;
            W_dios   = `W_dios ;
            W_diodcv = weffcv_nf + (NF * UC_PDBCP) ;
            W_dioscv = weffcv_nf + (NF * UC_PSBCP) ;

        end else begin
            area_bt_n = 0.0 ; Cbtn = 0.0 ;
            area_bt_p = 0.0 ; Cbtp = 0.0 ;
            W_diod    = 0.0 ; W_dios   = 0.0 ;
            W_diodcv  = 0.0 ; W_dioscv = 0.0 ;
        end
    end // initializeInstance

    //   Initial Settings for each steps.

    //   get biases from CKT //
    Vdsi  = TYPE * V(BRdpsp) ;
    Vgsi  = TYPE * V(BRgpsp) ;
    Vbsi  = TYPE * V(BRbpsp) ;
    Vdsei = TYPE * V(BRds ) ;
    Vgsei = TYPE * V(BRgps) ;
    Vbsei = TYPE * V(BRbps) ;
    if ( COBCNODE == 1 ) begin // bt model
        vbcd = TYPE * V(BRbpdp) ;
        vbcs = TYPE * V(BRbpsp) ;

        //   NQS nodes
        if (flg_nqs) begin
            Qi_nqs = `NQS_CAP * V(nqs_qi) ;
            Qb_nqs = `NQS_CAP * V(nqs_qb) ;
        end else begin
            Qi_nqs = 0.0 ; // bt
            Qb_nqs = 0.0 ;
        end
    end else begin
        vbcd = 0.0 ;
        vbcs = 0.0 ;

        //   NQS nodes
        if (flg_nqs) begin
            Qd_nqs = `NQS_CAP * V(nqs_qd) ;
            Qs_nqs = `NQS_CAP * V(nqs_qs) ;
            Qb_nqs = `NQS_CAP * V(nqs_qb) ;
        end else begin
            Qd_nqs = 0.0 ; // fb
            Qs_nqs = 0.0 ; // fb
            Qb_nqs = 0.0 ;
        end
    end


    //
    //-------------SHE------------------//
    deltemp = (COSELFHEAT > 0 && MKS_RTH0 > 0) ? ( V(temp) > 0.0 ? V(temp) : 0.0 ) : 0.0 ;

    if (Vdsi >= 0) begin  // normal mode //
        mode = 1 ;
        ModeNML = 1.0 ;
        ModeRVS = 0.0 ;
        Vds  = Vdsi ;
        Vgs  = Vgsi ;
        Vbs  = Vbsi ;
        Vdse = Vdsei ;
        Vgse = Vgsei ;
        Vbse = Vbsei ;
    end  else  begin     // reverse mode //
        mode = -1 ;
        ModeNML = 0.0 ;
        ModeRVS = 1.0 ;
        Vds  = -Vdsi ;
        Vgs  =  Vgsi - Vdsi ;
        Vbs  =  Vbsi - Vdsi ;
        Vdse = -Vdsei ;
        Vgse = Vgsei - Vdsei ;
        Vbse = Vbsei - Vdsei ;
    end

    if ( INFO >= 5 ) begin  // mode, bias conditions ... //
        $write( "--- variables given to HSMevaluate() ----\n" ) ;
        $write( "TYPE   = %d\n" , TYPE ) ;
        $write( "mode   = %d\n" , mode ) ;
        $write( "Vbsei Vbsi    = %20.10e %20.10e\n" , Vbsei, Vbsi ) ;
        $write( "Vdsei Vdsi    = %20.10e %20.10e\n" , Vdsei, Vdsi ) ;
        $write( "Vgsei Vgsi    = %20.10e %20.10e\n" , Vgsei, Vgsi ) ;
        $write( "vbcs vbcd     = %20.10e %20.10e\n" , vbcs, vbcd ) ;
    end

    if ( INFO >= 6 ) begin  // input flags //
        $write( "corg    = %d\n" , CORG ) ;
        $write( "coadov  = %d\n" , COADOV ) ;
        $write( "cofbe   = %d\n" , COFBE ) ;
        $write( "coisub  = %d\n" , COISUB ) ;
        $write( "coievb  = %d\n" , COIEVB ) ;
        $write( "coiigs  = %d\n" , COIIGS ) ;
        $write( "cogidl  = %d\n" , COGIDL ) ;
        $write( "coovlp  = %d\n" , COOVLP ) ;
        $write( "coflick = %d\n" , COFLICK ) ;
        $write( "coisti  = %d\n" , COISTI ) ;
        $write( "conqs   = %d\n" , CONQS  ) ;
        $write( "cohist  = %d\n" , COHIST ) ;
        $write( "cothrml = %d\n" , COTHRML ) ;
        $write( "coign   = %d\n" , COIGN ) ;
        $write( "coselfheat = %d\n" , COSELFHEAT ) ;
    end

    //start_of_evaluation ;

    //-----------------------------------------------------------*
    //* Temperature dependent constants.
    //*-----------------//
    TTEMP = $temperature ;
    if ( temp_Given) TTEMP = UC_TEMP ;
    if (dtemp_Given) begin
        TTEMP = TTEMP + DTEMP ;
    end
    TTEMP = TTEMP + deltemp ;

    // Band gap //
    T1 = TTEMP - UC_TNOM ;
    T2 = T1 * (TTEMP + UC_TNOM) ;
    Eg   = egtnom - BGTMP1 * T1 - BGTMP2 * T2 ;
    beta   = `C_QE / (`C_KB * TTEMP) ;
    beta2   = beta * beta ;
    beta_inv = 1.0 / beta ;

    begin : MUEPH
        //CGS unit
        real CGS_mueph, CGS_wmueph, T1, T2, T3;
        CGS_mueph = MUEPH1 * (1.0e0 + (MUEPHW / pow(WG, MUEPWP)))
              * (1.0e0 + (MUEPHL / pow(LGLE, MUEPLP)))
                * (1.0e0 + (MUEPHS / pow(WL, MUEPSP))) ;
        T2 = 1.0e0 / (1.0e0 + MUESTI2) ;
        T3 = FPOW(MUESTI1 / UC_LOD, MUESTI3) ;
        CGS_wmueph = CGS_mueph * (1.0e0 + T2 * T3) ;
        T1 = pow(TTEMP / UC_TNOM, MUETMP) ;
        CGS_mphn0 = T1 / CGS_wmueph ;
    end

    // Pocket Overlap(temperature-dependent part) //
    ptovr = ptovr0 * beta_inv ;

    // Velocity Temperature Dependence //
    T1 = TTEMP / UC_TNOM ;
    Vmaxe = (vmax0 * MKS_VMAX / (1.8 + 0.4 * T1 + 0.1 * T1 * T1 - MKS_VTMP * (1.0 - T1))) ;

    Egp12 = sqrt(Eg) ;
    Egp32 = Eg * Egp12 ;

    // Intrinsic carrier concentration //
    Nin   = `C_Nin0 * `Fn_Pow(TTEMP / UC_TNOM, 1.5e0)
         * exp(- Eg / 2.0e0 * beta + egtnom / 2.0e0 * betatnom) ;

    // costi0 and costi1 for STI transistor model(temperature-dependent part) //
    costi0 = costi00 * sqrt(beta_inv) ;
    costi0_p2 = costi0 * costi0 ;
    costi1 = Nin * Nin * nsti_p2 ;

    //-----------------------------------------------------------*
    //Fixed part.
    //----------------//

    // Metallurgical channel geometry //
    Lch = Lgate - 2.0e0 * XLD ;

    // 2 phi_B //
    // @temp, with pocket //
    if (SUBVERSION > 3) begin
        Pb2   = 2.0 * beta_inv * ln (Nsub / Nin) ;
    end else begin
        Pb2   = 2.0 * beta_inv * ln (`N_sub_SOI / Nin) ;
    end
    // Debye length //
    Ldby = sqrt((`C_ESI / q_Nsub) * beta_inv) ;
    // Coefficient of the F function for bulk charge //
    // cnst0bulk //
    cnst0SOI = (q_Nsub * `C_SQRT_2) * Ldby ;

    // cnst1: n_{p0} / p_{p0} //
    if ( COBCNODE == 1 ) begin
        cnst0bulk = 0.0 ;
        cnst1bulk = 0.0 ;
        T1 = Nin / Nsub ;
    end else begin
        cnst0bulk    = sqrt(2.0 * c0bulk * beta_inv) ;
        T1 = Nin / `N_sub_bulk ;
        cnst1bulk = T1 * T1 ;
        T1 = Nin / `N_sub_SOI ;
    end
    cnst1SOI = T1 * T1 ;

    C_W_SOI = sqrt(2.0 * (`C_ESI / q_Nsub / beta)) ;

    cnst_2esi_q_Nsubs = `cnst_2esi_q / `N_sub_SOI ;
    // Initial guess of the depletion width in the SOI layer //
    WdSOI_ini = sqrt(`cnst_2esi_q * Pb2 / `N_sub_SOI) ;

    begin : paramCheck

        integer FATAL_flag ;
        FATAL_flag = 0 ;
        `PMINCHECK(Weff,1e-9,"An effective channel width  < 1nm ")
        `PMINCHECK(weff_cv,1e-9,"An effective channel width for C-V < 1nm")
        `PMINCHECK(Leff,1e-9,"An effective channel length < 1nm")
        if (FATAL_flag) $finish(0);

    end // paramCheck

    //-----------------------------------------------------------*
    //set a clamping voltage for Ves.
    //Select Ves or Vbcs according to the existence of the "bc" node.
    //----------------//
    if ( COBCNODE == 1 ) begin
        Vbs_bnd = 0.4 ;
        Vbs_max = 0.8 ;
    end else begin
        Vbs_bnd = `Vbs_bnd ;
        Vbs_max = `Vbs_max ;
    end

    //---------------------------------------------------*
    //Clamp too large biases.
    //-note: Quantities are extrapolated in PART-5.
    //----------------//
    if (Vbs_bnd > Vbs_max * 0.5) begin
        Vbs_bnd = 0.5 * Vbs_max ;
    end
    if (Vbs > Vbs_bnd) begin
        T2 = Vbs - Vbs_bnd ;
        T3 = Vbs_max - Vbs_bnd ;
        `Fn_CP_DX(T4, T2, T3, 4, T8)
        Vbsc = Vbs_bnd + T4 ;
        Vbsc_dVbse = T8 ;
    end else begin
        Vbsc = Vbs ;
        Vbsc_dVbse = 1.0 ;
    end
    Vdsc = (Vds  >  `Vds_max) ?  `Vds_max : Vds  ;
    Vgsc = (Vgs  >  `Vgs_max) ?  `Vgs_max : Vgs  ;
    Vgsc = (Vgs  < -`Vgs_max) ? -`Vgs_max : Vgsc ;
    Vbsc = (Vbsc < -`Vgs_max) ? -`Vgs_max : Vbsc ;

    //  Vbs, Vds and Vgs are determined.  //
    Vds  = Vdsc ;
    Vgs  = Vgsc ;
    Vbs  = Vbsc ;

    // begin : COPPRV_model // (copprv = 1)


    /* Initialize for Hidden states */
    flg_pprv = 0;

    /* Initialization for hidden states */
    Pss0_ini=0.0; Pbs0_ini=0.0; Psb0_ini=0.0;
    Pssl_ini=0.0; Pbsl_ini=0.0; Psbl_ini=0.0;
    Ai       = 0.0 ; Db       = 0.0 ;
    Di       = 0.0 ; C2       = 0.0 ;

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //PART-1: Basic device characteristics.
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

    //-----------------------------------------------------------*
    //Initialization.
    //----------------//
    // Initialization of counters is needed for restart. //
    lp_s0 = 0 ;
    lp_sl = 0 ;

    //-----------------------------------------------------------*
    //    Vxsz: Modified bias introduced to realize symmetry at Vds=0.
    //    ----------------  from HiSIM 2 //
    begin : Vxsz
        real T1;
        T1 = Vbsc_dVbse * Vds / 2 ;
        `Fn_SymAdd(Vzadd, T1, VZADD0)
        if (Vzadd < `ps_conv) begin
            Vzadd = `ps_conv ;
        end

        Vbsz = Vbs + Vzadd ;
        Vdsz = Vds + 2.0 * Vzadd ;
        Vgsz = Vgs + Vzadd ;
    end

    //-----------------------------------------------------------*
    //  Define Vbcs and Vbcsz for FB and BC device.
    //  ----------------
    if ( COBCNODE == 1 ) begin
        Vbsp  = Vbs ;
        Vbspz = Vbsz ;
    end else begin
        Vbsp  = (SUBVERSION < 3) ? Vbs  : 0.0 ;
        Vbspz = (SUBVERSION < 3) ? Vbsz : 0.0 ;
    end

    //---------------------------------------------------*
    //* Factor of modification for symmetry.
    //*-----------------//
    begin : Factor_of_Modification_for_Symmetry
        real T1, T2, T3, TX;
        T1 = (2.0 * q_Nsub * `C_ESI) * C_fox0_inv * C_fox0_inv ;
        T2 = Vgs - Vfb ;
        T3 = 1 + 2.0 / T1 * (T2 - beta_inv - Vbsp) ;
        `Fn_SZtemp(T4, T3, 1e-3)
        TX = sqrt(T4 + `Small) ;
        Pslsat = T2 + T1 * (1.0 - TX) ;
        VdsatS = Pslsat - Pb2 ;
        `Fn_SLtemp(VdsatS, VdsatS, 0.1, 5e-2)
        T1 = Vds / VdsatS ;
        `Fn_SUPoly4(TX, T1, 1.0, T0)
        FMDVDS = TX * TX ;
    end

    //-----------------------------------------------------------*
    //* Quantum Mechanical Effect
    //*-----------------//
    begin : QuantumMechanicalEffect
        real T2, T3, T4, T4w, T5, T6 ;
        if ((QME1 == 0.0 && QME3 == 0.0) || QME2 == 0.0) begin
            flg_qme = 0 ;
        end else begin
            flg_qme = 1 ;
        end
        T2 = sqrt((2.0 * q_Nsub * `C_ESI) * Pb20) ;
        Vthq = Pb20 + Vfb + T2 / C_fox0 ;
        if (flg_qme == 0) begin
            Tfoxe = Tfox0 ;
            C_fox = C_fox0 ;
            C_fox_inv = C_fox0_inv ;
            cnstC_foxi = (cnst0SOI * C_fox0_inv * C_fox0_inv) * cnst0SOI ;

        end else begin             //!if( flg_qme == 0 )
            T5 = Vgs  - Vbsp - Vthq + QME2 ;
            `Fn_SZtemp( T2 , T5 , `qme_dlt)
            T3 = 1.0 /  T2 ;
            T4w = 2.0 * abs(Vthq) ;
            T6 = Vfb - Vthq + QME2 ;
            T4 = (T6 > T4w) ? T6 : T4w;

            `Fn_SUtemp( T2 , T3 , 1.0 / T4  , `qme_dlt )
            dTfox = QME1 * T2 + QME3 ;
            if ( dTfox * 1.0e12 < Tfox0 ) begin
                dTfox = 0.0 ;
                flg_qme = 0 ;
            end
            Tfoxe = Tfox0 + dTfox ;
            C_fox = `C_EOX / Tfoxe ;
            C_fox_inv  = Tfoxe / `C_EOX ;
            cnstC_foxi = (cnst0SOI * cnst0SOI * C_fox_inv) * C_fox_inv ;

        end                        // end of flg_qme if-blocks //
    end

    //---------------------------------------------------*
    //* Vbsz2 : Vbs for dVth
    //*-----------------//
    if ( COBCNODE == 1 || SUBVERSION < 3 ) begin
        `Fn_SUtemp(Vbsz2, Vbspz, 0.5, 1.0e-3)
        Vbslim = - `t_SOI*`t_SOI * q_Nsub/(2.0*`C_ESI) + Pb2 - beta_inv;
        `Fn_SLtemp(Vbsz2, Vbsz2, Vbslim, 1.0e-3) //lower limit for FD condition
        if ( SUBVERSION > 2 ) begin
            `Fn_SUtemp(Vbsz2, Vbsz2, Pb20, 1.0e-3) //lower limit for FD condition
        end
    end else begin
        Vbsz2 = 0.0 ;
    end

    //---------------------------------------------------*
    //* Wd0 : depletion-layer thickness
    //*-----------------//
    // Fixed Wd to Tsoi //
    if ( SUBVERSION < 3 ) begin
        Wd0 = `t_SOI ;
    end else begin
        T1 = 2.0 * `C_ESI / q_Nsub ;
        Wd0 = sqrt(T1 *  (Pb20 - Vbsz2)) ;
    end

    //---------------------------------------------------*
    //* Vthp : Vth with pocket.
    //*-----------------//
    begin : SetVthp
        real T1, T0, T2, T3;
        // Disable Vbs dependence for Vthp(Pocket)  //
        Qb0 = (SUBVERSION < 3) ? sqrt(qnsub_esi2 * Pb20)
                                      : sqrt(qnsub_esi2 * (Pb20 - Vbsz2)) ;
        Vthp = Pb20 + Vfb + Qb0 * C_fox_inv + ptovr ;
        Pb20b = Pb20 ;
        T0 = 0.95 ;
        T1 = T0 * Pb20b - Vbsz2 - 1.0e-3 ;
        T2 = sqrt(T1 * T1 + 4.0 * T0 * Pb20b * 1.0e-3) ;
        T3 = T0 * Pb20b - 0.5 * (T1 + T2) ;
        Pbsum = Pb20b - T3 ;
        sqrt_Pbsum = sqrt(Pbsum) ;
    end

    //-------------------------------------------*
    //     dVthLP : Short-channel effect induced by pocket.
    //     - Vth0 : Vth without pocket.
    //    -----------------//
    begin : SetdVthLP
        real T0, T1, T2, T3, T4, T5, dVth0;

        if (LP != 0.0) begin
            T1 = 2.0 * `C_QE * UC_NSUBS * `C_ESI ;
            T2 = (SUBVERSION < 3) ? sqrt(T1 * Pb2c)
                                        : sqrt(T1 * (Pb2c - Vbsz2)) ;
            Vth0 = Pb2c + Vfb + T2 * C_fox_inv ;
            T1 = `C_ESI * C_fox_inv ;

            T4 = 1.0e0 / (LP * LP) ;
            T3 = 2.0e0 * Wd0 * T4 ;
            T5 = T1 * T3 * (VBI - Pb20b) ;
            dVth0 = T5 ;

            T1 = Vthp - Vth0 ;
            T0 = UC_SCP3 / LP ;
            T2 = SCP1 + T0 * Pbsum ;
            T5 = UC_SCP2 ;
            T3 = T2 + T5 * Vdsz ;
            dVthLP = T1 * dVth0 * T3 ;
        end else begin
            dVthLP = 0.0 ;
        end
    end

    //---------------------------------------------------*
    //* dVthSC : Short-channel effect.
    //*-----------------//
    begin : SetdVthSC
        real T0, T1, T2, T3, T4, T5, dVth0;
        T0 = `C_ESI * Wd0 * 2.0e0 ;
        T1 = C_fox_inv * T0 ;
        T2 = VBI - Pb20b ;
        T3 = Lgleff - PARL2 ;
        T4 = 1.0e0 / (T3 * T3) ;
        dVth0 = T1 * T2 * T4 ;
        T1 = UC_SC3 / Lgleff ;
        T4 = SC1 + T1 * Pbsum ;
        T5 = T4 + UC_SC2 * Vdsz ;
        dVthSC = dVth0 * T5 ;
    end

    //---------------------------------------------------*
    //* dVthSCR : back-field effect.
    //*------------------------//
    begin : SetdVthSCR
        real T1, T2, T3;
        if (SCR1 > 0.0) begin
            T1 = Eg + Pb2 - 2.0 * SCR3 + SCR2 * Vdsz ;
            T2 = Lgleff * 0.5 + MKS_PARL1 ;
            T3 = SCR1 * `t_SOI / T2 ;
            dVthSCR = T1 * T3 ;
        end else begin
            dVthSCR = 0.0 ;
        end
    end

    //---------------------------------------------------*
    //* dVthW : narrow-channel effect.
    //*-----------------//
    begin : SetdVthW
        real T1, T3, T5;

        T1 = C_fox_inv ;
        T3 = 1.0 / (C_fox + MKS_WFC / Weff) ;
        T5 = T1 - T3 ;
        dVthW = Qb0 * T5 + WVTH0 / WG ;
    end

    //---------------------------------------------------*
    //    dVth : Total variation.
    //    - Positive dVth means the decrease in Vth.
    //    ----------------//
    dVth = dVthSC + dVthLP + dVthW + dVthSCR + dVthsm ;

    //---------------------------------------------------*
    //    Vth : Threshold voltage.
    //    ----------------//
    Vth = Vthp - dVth ;

    //---------------------------------------------------*
    //Poly-Depletion Effect
    //----------------//
    begin : SetPolyDepletionEffect
        real T7, T0, T3;

        if (PGD1 == 0.0) begin
            flg_dPpg = 0 ;
        end else begin
            flg_dPpg = 1 ;
        end
        if (flg_dPpg == 0) begin
            dPpg = 0.0 ;
        end else begin
            T7 = Vgsz ;
            T0 = cnstpgd ;
            T3 = T7 - PGD2 ;
            `Fn_ExpLim( dPpg , T3 )
            `Fn_SZtemp( dPpg , dPpg - 1.0 , 0.1 )
            dPpg = dPpg * T0 ;
            `Fn_SUtemp( dPpg , dPpg , `pol_b , `pol_dlt )

        end                        // end of flg_dPpg if-blocks //
    end  // SetPolyDepletionEffect

    //---------------------------------------------------*
    //    Vgp : Effective gate bias with SCE & RSCE & flatband.
    //    ----------------//
    Vgp = Vgs - Vfb + dVth - dPpg ;
    Vgpz = Vgp ;

    //---------------------------------------------------*
    //    Vbi_SOI : Difference of built-in potential between SOI and bulk.
    //    Vgs_fb : Flatband voltage taking account Vbs.
    //    -----------------//
    T1 = ln (`N_sub_SOI / `N_sub_bulk) ;
    Vbi_SOI = beta_inv * T1 ;
    Vgs_fb = Vfb - dVth + dPpg ;

    //-----------------------------------------------------------*
    //Constants in the equation of Ps0 .
    //----------------//
    fac1 = cnst0SOI * C_fox_inv ;
    fac1p2 = fac1 * fac1 ;


    if ( COBCNODE == 0 ) begin
`include "HSMSOI_FB_module.inc"
        V(nqs_qi)  <+ 0.0 ;
    end else begin
`include "HSMSOI_BT_module.inc"
        V(nqs_qd ) <+ 0.0 ;
        V(nqs_qs ) <+ 0.0 ;
        V(nqs_qhs) <+ 0.0 ;
    end

    if (end_of_part_1 == 0) begin

        //-----------------------------------------------------------*
        //* Qdrat : Qd/Qi
        //*-----------------//
        Qdnm = 0.5 + Alpha ;
        Qddn = Qidn * Qinm ;
        Quot = 0.4 * Qdnm / Qddn ;
        Qdrat = 0.6 - Quot ;

        if (Qdrat > 0.5 + `dQdrat) begin
            if (flg_info >= 1) begin
                $write("Qdrat=%.16e 0.5 @ Vgs=%eV\n", Qdrat, Vgs) ;
            end
            Qdrat = 0.5 ;
        end
        Qdrat_noi = Qdrat ; // for Noise
        Qdrat = 0.5 ;       // for Capacitance

        //-----------------------------------------------------------*
        //* Skip CLM and integrated charges if zone==D1
        //*-----------------//
        if (flg_noqi == 0) begin

            //-----------------------------------------------------------*
            //* Channel Length Modulation. Lred: \Delta L
            //*-----------------//
            begin :CLMmodel
                real T0, T1, T2, T3, T4, T5, T6,T6w, T7, T8, T9, T10, T11, T11w, Wd;

                if (CLM2 < `epsm10 && CLM3 < `epsm10) begin
                    Lred = 0.0 ;
                    Psdl = Psl ;
                    if (Psdl > Ps0 + Vdsz - `epsm10) begin
                        Psdl = Ps0 + Vdsz - `epsm10 ;
                    end

                end else begin              //if( clm2 < epsm10 && clm3 < epsm10 )
                    Wd = ( COBCNODE == 1 ) ? `t_SOI : WdSOI_0 ;
                    T0 = 1.0 / Wd ;
                    T1 = Qn0 * T0 ;
                    T2 = CLM3 * T1 ;
                    T5 = UC_CLM2 * q_Nsub + T2 ;
                    T1 = 1.0 / T5 ;
                    T4 = `C_ESI * T1 ;
                    T1 = (1.0e0 - CLM1) ;
                    Psdl = CLM1 * (Vds + Ps0) + T1 * Psl ;
                    if (Psdl > Ps0 + Vdsz - `epsm10) begin
                        Psdl = Ps0 + Vdsz - `epsm10 ;
                    end
                    T6w = Psdl - Psl ;        // can be negative //
                    `Fn_SZtemp(T6, T6w, 1e-3)         // limited //
                    T3 = beta * Qn0 ;
                    T1 = 1.0 / T3 ;
                    T5 = Idd * T1 ;
                    if (T5 < beta_inv ) begin
                        T5 = beta_inv;
                    end
                    T10 = q_Nsub / `C_ESI ;
                    T1 = 1.0e5 * 1.0e4;
                    T2 = 1.0 / Leff ;
                    T11w = (2.0 * T5 + 2.0 * T10 * T6 * T4 + T1 * T4) * T2 ;
                    T7 = T11w * T4 ;
                    T11 = 4.0 * (2.0 * T10 * T6 + T1) ;
                    T8 = T11 * T4 * T4 ;
                    T9 = sqrt(T7 * T7 + T8) ;        // can be nan if Psdl < Psl //

                    //---------------------------------------------------*
                    //* Modify Lred for symmetry.
                    //*-----------------//
                    Lred = FMDVDS * ( 0.5 * (-T7 + T9) ) ;
                end                //if( clm2 < epsm10 && clm3 < epsm10 )

                // CLM5 & CLM6 //
                Lred = Lred * clmmod ;
            end  // CLMmodel
            //-------------------------------------------*
            //End point of CLM. (label)
            //----------------//
        end // end_of_CLM:

        //---------------------------------------------------*
        //    Lch: actual chnnel length
        //    ----------------//
        Lch = Leff - Lred ;
        Lch_cv = Leff_cv - Lred ;
        if (Lch < 1.0e-9) begin
            Lch = 1.0e-9 ;
            $write("*** warning(HiSIM_SOI): actual channel length is too Small. (Lch=%e[m])\n", Lch) ;
            $write("                       CLM5 and/or CLM6 might be too large.\n") ;
        end

        //----------------------------------------------------------*
        //* Evaluate integrated charges in unit [C].
        //*----------------------//
        T1 = -weffcv_nf * Leff_cv ;
        Qb = T1 * Qbu ;
        Qi = T1 * Qiu ;
        Qd = Qi * Qdrat ;
        if ( COBCNODE == 0 ) begin
            Qd_FB = Qb * `C_QBRAT ;
            Qs_FB = Qb * (1.0 - `C_QBRAT) ;
            //----------------------------------------------------------*
            //* Evaluate substrate charge.
            //*----------------------//
            Qsub = 0.5 * (Q_s0_bulk + Q_sL_bulk) * Leff_cv * weffcv_nf ;
        end

        //-----------------------------------------------------------*
        //* Modified potential for symmetry.
        //*----------------- from HiSIM 2.5.1 //
        begin : ModifiedPotentialForSymmetry
            real T1;

            T1 = (Vds - Pds) / 2 ;
            `Fn_SymAdd(Pzadd, T1, PZADD0)
            if (Pzadd < `epsm10) begin
                Pzadd = `epsm10 ;
            end
            Ps0z = Ps0 + Pzadd ;
        end

        //-----------------------------------------------------------*
        //Evaluate universal mobility.
        //----------------//
        begin : EvaluateUniversalMobility
            real T1, T2, T0, T4, T5, T3, T8, T7, T6, CGS_ESI, CGS_Qbu, CGS_Qiu;
            CGS_ESI = `C_ESI / `C_m2cm;
            CGS_Qbu = Qbu / `C_m2cm_p2;
            CGS_Qiu = Qiu / `C_m2cm_p2;

            T1 = NDEP / CGS_ESI ;
            T2 = NINV / CGS_ESI ;
            T0 = NINVD ;
            T4 = 1.0 + (Psl - Ps0) * T0 ;
            T5 = T1 * CGS_Qbu + T2 * CGS_Qiu ;
            T3 = T5 / T4 ;
            Eeff = T3 ;

            `Fn_SZtemp(T0, Eeff, 3.0e3)
            T5 = pow(T0, MUEPH0 - 1.0e0) ;
            T8 = T5 * T0 ;
            T7 = pow(T0, muesr - 1.0e0) ;
            T6 = T7 * T0 ;
            Rns = CGS_Qiu / `C_QE ;

            T1 = 1.0e0 / (MUECB0 + MUECB1 * Rns / 1.0e11)
                    + CGS_mphn0 * T8 + T6 / MUESR1 ;
            Muun = 1.0e0 / T1 ;
            Muun = Muun * `C_cm2m_p2;
        end  // EvaluateUniversalMobility
        //-----------------------------------------------------------*
        //    Mu : mobility
        //    (transplanted from HiSIM_HV_1_0)
        //    -------------- --//
        begin : EvaluateMobility
            real T2,T1,TY,Em,T3,T4,T5,T6;

            T2 = beta *  Qn0 * Lch ;
            `Fn_SZtemp(T2, T2, `Small )
            T1 = 1.0e0 / T2 ;
            TY = Idd * T1 ;
            T2 = 0.2 * Vmaxe / Muun ;
            Ey = sqrt(TY * TY + T2 * T2) ;
            Em = Muun * Ey ;
            T1 = Em / Vmaxe ;
            // note: bb = 2 (electron) ;1 (hole) //
            if (1.0e0 - `epsm10 <= BB && BB <= 1.0e0 + `epsm10) begin
                T3 = 1.0e0 ;
            end else if (2.0e0 - `epsm10 <= BB && BB <= 2.0e0 + `epsm10) begin
                T3 = T1 ;
            end else begin
                T3 = pow(T1, BB - 1.0e0) ;
            end
            T2 = T1 * T3 ;
            T4 = 1.0e0 + T2 ;
            if (1.0e0 - `epsm10 <= BB && BB <= 1.0e0 + `epsm10) begin
                T5 = 1.0 / T4 ;
                // T6 = T5 / T4 ;
            end else if (2.0e0 - `epsm10 <= BB && BB <= 2.0e0 + `epsm10) begin
                T5 = 1.0 / sqrt(T4) ;
                // T6 = T5 / T4 ;
            end else begin
                T6 = pow(T4, (-1.0e0 / BB - 1.0e0)) ;
                T5 = T4 * T6 ;
            end
            // T7 = Muun / Vmaxe * T6 * T3 ;
            Mu = Muun * T5 ;
        end  // EvaluateMobility
        // end_of_mobility : ; //

        //-----------------------------------------------------------*
        //    Ids: channel current.
        //    ----------------//

        betaWL = weff_nf * beta_inv / (Leff - Lred) ;
        Ids0 = betaWL * Idd * Mu ;

        //-----------------------------------------------------------*
        //* Adding parasitic components to the channel current.
        //*-----------------//
        begin : AddingParasiticChannelCurrent
            real T1, T0, T3, T9, T4, T5, T6, T8, T2;

            IdsPT = 0.0 ;
            if (COPT>0 && PTL != 0) begin
                T1 = 0.5 * (Vds - Pds) ;
                `Fn_SymAdd(T6, T1, 0.01)
                T1 = 1.1 - (Ps0 + T6) ;
                `Fn_SZtemp(T2, T1, 0.05)
                T0 = beta * ptl0 ;
                T3 = C_fox * T0 ;
                T0 = pow(T2, PTP) ;
                T9 = T3 * T0 ;
                T4 = 1.0 + Vdsz * PT2 ;
                T0 = pt40 ;
                if (SUBVERSION < 3 || COBCNODE == 1) begin
                    T5 = Ps0 + T6 - Vbsz ;
                end else begin
                    T5 = Ps0 + T6 - phi_b0_SOI ;
                end
                T4 = T4 + Vdsz * T0 * T5 ;
                T6 = T9 * T4 ;
                T9 = T6 ;
            end else begin
                T9 = 0.0 ;
            end
            if (GDL != 0) begin
                T1 = beta * gdl0 ;
                T2 = C_fox * T1 ;
                T8 = T2 * Vdsz ;
            end else begin
                T8 = 0.0 ;
            end
            if ((T9 + T8) > 0.0) begin
                Idd1 = Pds * (T9 + T8) ;
                IdsPT = betaWL * Idd1 * Mu ;
            end
        end
        Ids = Ids0 + IdsPT ;
        IdsPT0 = IdsPT ;

        //-----------------------------------------------------------*
        //* STI
        //* ----------------//
        begin :SetdVthSCSTI
            real T1,T1w, T2, T3, T4, T5, T10, TX,TY;

            if ( COISTI != 0 ) begin
                //---------------------------------------------------*
                //* dVthSCSTI : Short-channel effect induced by Vds(STI).
                //*-----------------//
                //       T1 = `C_ESI * C_fox_inv ;
                T2 = wdpl ;
                T3 =  lgatesm - PARL2 ;
                T4 = 1.0 / (T3 * T3) ;
                T5 = 2.0 * (VBI - Pb20b) *(`C_ESI * C_fox_inv ) * T2 * T4 ;
                dVth0 = T5 * sqrt_Pbsum ;
                T1w = SCSTI1 + (SCSTI2 * Vdsz) ;
                dVthSCSTI = dVth0 * T1w ;
                T1 = VTHSTI - VDSTI * Vds ;
                Vgssti = Vgsz - Vfb + T1 + dVthSCSTI ;

                costi3 = costi0_p2 * C_fox_inv * C_fox_inv ;
                costi4 = costi3 * beta * 0.5 ;
                costi5 = costi4 * beta * 2.0 ;
                T10 = beta_inv - costi3 * (beta * 0.25) + Vfb - VTHSTI - dVthSCSTI + `Small ;
                T1 = Vgsz - T10 - `psisti_dlt ;
                T0 = `Fn_Sgn(T10) ;
                T2 = sqrt (T1 * T1 + T0 * 4.0 * T10 * `psisti_dlt) ;
                T3 = T10 + 0.5 * (T1 + T2) - Vfb + VTHSTI + dVthSCSTI - Vbspz ;
                T4 = beta * T3 - 1.0 ;
                T5 = 4.0 / costi5 ;
                T1w = 1.0 + T4 * T5 ;
                `Fn_SZtemp( T1 , T1w, 1.0e-2)
                costi6 = sqrt (T1 + `Small) ;
                Psasti = Vgssti + (costi4 * (1.0 - costi6)) ;

                T0 = 1.0 / (beta + 2.0 / (Vgssti + `Small)) ;
                Psbsti = ln (1.0 / costi1 / costi3 * (Vgssti * Vgssti)) * T0 ;
                T3 = Psbsti / (Vgssti + `Small) ;
                Psab = Psbsti - Psasti - `sti2_dlt ;
                T0 = sqrt (Psab * Psab + 4.0 * `sti2_dlt * Psbsti) ;
                Psti = Psbsti - 0.5 * (Psab + T0) ;
                T1 = 1.0 / T0 ;
                T0 = costi1 * exp (beta * Psti) ;
                T1w = beta * (Psti - Vbspz) - 1.0 + T0 ;
                `Fn_SZtemp( T1 , T1w, 1.0e-2)
                sq1sti = sqrt (T1 + `epsm10);
                T1w = beta * (Psti - Vbspz) - 1.0;
                `Fn_SZtemp( T1 , T1w, 1.0e-2)
                sq2sti = sqrt (T1 + `epsm10);
                Qn0sti = costi0 * (sq1sti - sq2sti) ;

                // T1: Vdsatsti //
                T1w = Psasti - Psti ;
                `Fn_SZtemp( T1 , T1w , 1.0e-1 )
                TX = Vds / (T1 + `epsm10) ;
                `Fn_CP( TY , TX , 1.0 , 4 )
                costi7 = 2.0 * UC_WSTI * NF * beta_inv ;
                Idssti = costi7 * Mu * Qn0sti * TY / Lch;
                Ids = Ids + Idssti ;
            end
        end
        // end_of_STI: //

        //----------------------------------------------------------*
        //* induced gate noise. ( Part 1/3 )
        //*---------------------- from HiSIM 2.5.1 2010.05.21 //
        if (COIGN != 0 && COTHRML != 0) begin
            kusai00 = VgVt * VgVt ;
            kusaidd = 2.0e0 * beta_inv * C_fox_inv * Idd ;
            kusaiL = kusai00 - kusaidd ;
            `Fn_SZtemp(kusai00, kusai00, 1.0e-3)
            `Fn_SZtemp(kusaiL, kusaiL, 1.0e-3)
            kusai00L = kusai00 - kusaiL ;
            if (Qn0 < `epsm10 || kusai00L < `epsm10)
                flg_ign = 0 ;
            else flg_ign = 1 ;
        end

        //-----------------------------------------------------------*
        //End of PART-1. (label)
        //----------------//
    end // end if(end_of_part_1==0)

`ifdef DISABLE_COPPRV
`else
        flg_zone_prv = flg_zone ;
        called = called + 1 ;
`endif // COPPRV

    // end // End of COPPRV_model

    //-----------------------------------------------------------*
    //* Adding punchthrough current.
    //*-----------------//
    Idsorg = Ids ;
    IdsPT1 = 0.0 ;
    if (COPT > 0 && MUPT > 0.0) begin
  `include "HSMSOI_eval_newPT.inc"
    end //

    IdsPT = IdsPT0 + IdsPT1 ;

    //*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
    //* PART-2: Substrate / gate / leak currents
    //*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

    if ( COBCNODE == 1 ) begin
        //-----------------------------------------------------------*
        //* Isub : substrate current induced by impact ionization.
        //*-----------------//
        begin : IsubModel1
            real T1, T2, T3, T4, T5, T6,T6w, T7, T8, T9;
            real Psislsat, Psisubsat;

            if ( flg_noqi == 1 || COISUB == 0 ) begin
                // Accumulation zone or nonconductive case, in which Ids==0. //
                Isub = 0.0e0 ;
            end else begin
                //-------------------------------------------*
                //* Conductive case.
                //*-----------------//
                if (SUB1 <= 0.0 || MKS_VMAX <= 0.0) begin
                    Isub = 0.0 ;
                end else begin
                    Vgpsub = Vgsz - vfbsub0 + dVth - dPpg ;
                    T1 = Vgpsub ;
                    T7 = C_fox * C_fox ;
                    T8 = qnsub_esi ;
                    T3 = T8 / T7 ;
                    T9 = 2.0 / T8 ;
                    T4 = T9 * T7 ;
                    T5 = T1 - beta_inv - `X_vbs * Vbspz ;
                    T6w = 1.0 + T4 * T5 ;
                    `Fn_SZtemp(T6, T6w, 1.0e-3)
                    T6 = T6 + `Small ;
                    T6 = sqrt(T6) ;
                    Psislsat = T1 * `X_vgs + T3 * (1.0 - T6) ;
                    Psisubsat = `X_vds * Vdsz + Ps0z - `X_slg * `Z_vgs * Psislsat ;
                    `Fn_SZtemp(Psisubsat, Psisubsat, 1.0e-2)  // delta can be 1e-3 //
                    Psisubsat = Psisubsat + `Small ;
                    T2 = exp(-`X_sub2 / Psisubsat) ;
                    Isub = `X_sub1 * Psisubsat * Ids * T2 ;

                end              // end of !if( sub1 < 0 || vmax < 0 )  //
            end
        end  // IsubModel
    end
    //---------------------------------------------------*
    //* Impact-Ionization Induced Bulk Potential Change(IBPC)
    //*-----------------//
    begin : ImpactIonizationInducedBulkPotentialChange
        real T0, dVbsIBPC, Xi0, Xi0p12, Xi0p32, Xil, Xilp12, Xilp32, T10, T2, dG3, dG4, dIdd;

        if (flg_noqi == 0 && Isub > 0e0 && IBPC1 != 0e0) begin

            if ( SUBVERSION < 3 ) begin
                Vbs0 = 0.0 ; VbsL = 0.0 ;
            end else begin
                Vbs0= (COBCNODE == 1) ? Vbs : phi_b0_SOI ;
                VbsL= (COBCNODE == 1) ? Vbs : phi_bL_SOI ;
            end
            // delta Vbs //
            T0 = 1e0 + IBPC2 * dVth ;
            dVbsIBPC = IBPC1 * T0 * Isub ;
            // 081127 //
            Xi0 = beta * (Ps0 - Vbs0) - 1.0 ;
            `Fn_SZtemp(Xi0, Xi0, 1e-1)
            Xi0p12 = sqrt(Xi0) ;
            Xi0p32 = Xi0 * Xi0p12 ;
            Xil = beta * (Psl - VbsL) - 1.0 ;
            `Fn_SZtemp(Xil, Xil, 1e-1)
            Xilp12 = sqrt(Xil) ;
            Xilp32 = Xil * Xilp12 ;

            // dG3 & dG4 //
            T10 = 1e0 / Xi0 ;
            T1 = beta * dVbsIBPC * T10 ;
            T10 = 1e0 / Xil ;
            T2 = beta * dVbsIBPC * T10 ;
            dG3 = cnst0SOI * ( Xilp32 * T2 - Xi0p32 * T1 ) ;
            dG4 = cnst0SOI * 0.5 * ( - Xilp12 * T2 + Xi0p12 * T1 ) ;

            // Add IBPC current into Ids //
            dIdd = dG3 + dG4 ;

            IdsIBPC = betaWL * dIdd * Mu ;

        end // End if(IBPC) //
    end // ImpactIonizationInducedBulkPotentialChange

    begin : COIIGS_model
        real TX, T0, T1, T2, T3, T4, T5, T6, T7, T9, T10;
        real Etun, Psdlz;
        real CGS_Tfox0, CGS_C_fox, CGS_Leff, CGS_weff_nf, CGS_Ey, CGS_Qiu, CGS_cnst0SOI;

        CGS_Tfox0 = Tfox0 * `C_m2cm;
        CGS_C_fox = C_fox / `C_m2cm_p2;
        CGS_Leff  = Leff * `C_m2cm;
        CGS_weff_nf =  weff_nf * `C_m2cm;
        CGS_Ey = Ey / `C_m2cm;
        CGS_Qiu = Qiu / `C_m2cm_p2;
        CGS_cnst0SOI = cnst0SOI / `C_m2cm_p2;

        //-----------------------------------------------------------*
        //* Igate : Gate current induced by tunneling.
        //*----------------- from HiSIM 2.5.1 2010.05.21 //
        if (COIIGS == 0) begin
            Igate = 0.0 ;
            Igs = 0.0 ;
            Igd = 0.0 ;
            Igb = 0.0 ;
            GLPART1 = 0.0 ;
        end else begin

            // Igate //
            if (flg_noqi == 0) begin
                Psdlz = Ps0z + Vdsz - `epsm10 ;
                T1 = Vgsz - Vfb + GLEAK4 * (dVth - dPpg) * CGS_Leff - Psdlz * GLEAK3 ;

                T3 = 1.0 / CGS_Tfox0 ;
                T2 = T1 * T3 ;
                T3 = 1.0 / GLEAK5 ;
                T7 = 1.0 + CGS_Ey * T3 ;
                Etun = T2 * T7 ;
                `Fn_SZtemp(Etun, Etun, `igate_dlt)
                `Fn_SZtemp(T3, Vgsz, 1.0e-3)
                T3 = T3 - VZADD0 ;
                TX = T3 / `cclmmdf ;
                T2 = 1.0 + TX * TX ;
                T1 = 1.0 - 1.0 / T2 ;
                Etun = Etun * T1 ;
                T0 = CGS_Leff * CGS_weff_nf ;
                T7 = GLEAK7 / (GLEAK7 + T0) ;
                T6 = GLEAK6 ;
                T9 = T6 / (T6 + Vdsz) ;
                T4 = 1.0 / (Etun + `Small ) ;
                T1 = - GLEAK2 * Egp32 * T4 ;
                if (T1 < -`EXP_THR) begin
                    Igate = 0.0 ;
                end else begin
                    T2 = exp(T1) ;
                    T3 = GLEAK1 / Egp12 * `C_QE * T0 ;
                    T5 = 1.0 / CGS_cnst0SOI ;
                    T6 =  sqrt ((CGS_Qiu + CGS_C_fox * `VgVt_Small )* T5 ) ;
                    T4 =  T2 * T3 * T6 ;
                    T10 = T4 * Etun * Etun ;
                    Igate = T7 * T9 * T10 ;
                end
            end else begin
                Igate = 0.0 ;
            end

            // Igs //
            T0 = -GLKSD2 * Vgs + GLKSD3 ;
            T2 = exp(CGS_Tfox0 * T0) ;
            T0 = Vgs / CGS_Tfox0 / CGS_Tfox0 ;
            T3 = Vgs * T0 ;
            T4 = GLKSD1 / 1.0e6 * CGS_weff_nf ;
            Igs = T4 * T2 * T3 ;
            if (Vgs >= 0.0e0) begin
                Igs = Igs * -1.0 ;
            end

            // Igd //
            T1 = Vgs - Vds ;
            T0 = -GLKSD2 * T1 + GLKSD3 ;
            T2 = exp(CGS_Tfox0 * T0) ;
            T0 = T1 / CGS_Tfox0 / CGS_Tfox0 ;
            T3 = T1 * T0 ;
            T4 = GLKSD1 / 1.0e6 * CGS_weff_nf ;
            Igd = T4 * T2 * T3 ;
            if (T1 >= 0.0e0) begin
                Igd = Igd * -1.0 ;
            end

            // Igb //
            Etun = (-Vgs + Vbsp + Vfb + GLKB3) / CGS_Tfox0 ;
            `Fn_SZtemp(Etun, Etun, `igate_dlt)
            Etun = Etun + `Small ;
            T1 = -GLKB2 / Etun ;
            if (T1 < -`EXP_THR) begin
                Igb = 0.0 ;
            end else begin
                T2 = exp(T1) ;
                T3 = GLKB1 * CGS_weff_nf * CGS_Leff ;
                Igb = T3 * Etun * Etun * T2 ;
            end
            GLPART1 = 0.5 ;
        end                // if( coiigs == 0 ) //
    end  // COIIGS_model

    begin : COGIDL_model
        real T1, T2, E1, T3, T0, T5;
        real Vdb;

        //-----------------------------------------------------------*
        //* Igidl : GIDL
        //*----------------- from HiSIM 2.5.1 2010.05.21 //
        if (COGIDL == 0) begin
            Igidl = 0.0e0 ;
        end else begin
            T1 = GIDL3 * (Vds + GIDL4) - Vgs + (dVthSC + dVthLP) * GIDL5 ;
            T2 = 1.0 / Tfox0 ;
            E1 = T1 * T2 ;
            `Fn_SZtemp(Egidl, E1, `eef_dlt)
            T3 = 1.0 / (Egidl + `Small) ;
            T0 = - GIDL2 * Egp32 * T3 ;
            if (T0 < -`EXP_THR) begin
                Igidl = 0.0 ;
            end else begin
                T1 = exp(T0) ;
                T2 = GIDL1 / Egp12 * `C_QE * weff_nf ;
                Igidl = T2 * Egidl * Egidl * T1 ;
            end
            Vdb = Vds - Vbsp ;
            if (Vdb > 0.0) begin
                T2 = Vdb * Vdb ;
                T4 = T2 * Vdb ;
                T0 = T4 + `C_gidl_delta ;
                T5 = T4 / T0 ;
                Igidl = Igidl * T5 ;
            end else begin
                Igidl = 0.0 ;
            end

        end
    end // COGIDL_model

    //-----------------------------------------------------------*
    //* Igisl : GISL
    //*----------------- from HiSIM 2.5.1 2010.05.21 //
    begin : COGISL_model
        real T1, T2, E1, T3, T0, T5;
        real Vsb ;

        if (COGIDL == 0) begin
            Igisl = 0.0e0 ;
        end else begin
            T1 = GIDL3 * (-Vds + GIDL4)
                 - (Vgs - Vds) + (dVthSC + dVthLP) * GIDL5 ;
            T2 = 1.0 / Tfox0 ;
            E1 = T1 * T2 ;
            `Fn_SZtemp(Egisl, E1, `eef_dlt)
            T3 =  1  / (Egisl + `Small) ;
            T0 = - GIDL2 * Egp32 * T3 ;
            if (T0 < -`EXP_THR) begin
                Igisl = 0.0 ;
            end else begin
                T1 = exp(T0) ;
                T3 = 1.0 / Egp12 ;
                T2 = GIDL1 * T3 * `C_QE * weff_nf ;
                Igisl = T2 * Egisl * Egisl * T1 ;
            end
            Vsb = -Vbsp ;
            if (Vsb > 0.0) begin
                T2 = Vsb * Vsb ;
                T4 = T2 * Vsb ;
                T0 = T4 + `C_gidl_delta ;
                T5 = T4 / T0 ;
                Igisl = Igisl * T5 ;
            end else begin
                Igisl = 0.0 ;
            end

        end
    end // COGISL_model

    //-----------------------------------------------------------*
    //End of PART-2. (label)
    //----------------//
    // end_of_part_2: ; //

    if ( COBCNODE == 1 ) begin

        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        //PART-3:Parasitic charge                           2013.02.12
        // Intrinsic charge for parasitic MOSFET built over body-contact well
        // and Overlap charge for intrinsic MOSFET)
        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

        //Begin of include ---Intrinsic charge for parasitic MOSFET built over body-contact well---
        begin : IntrinsicChargeForMOSFEToverBodyContact
            real    T0, T1, T2, T3, T5,  T10, T11;
            real    TX, TY;
            real    Cox0, Cox0_inv;
            integer flg_ovloops, flg_ovloopd, flg_overs, flg_overd, lcover, flg_ovzone, flg_conv;
            integer lp_ld, lbt;
            real    Vxbgmt, Vxbgmtcl;
            real    Vbsgmt, Vdsgmt, Vgsgmt, Vgdgmt, Vdbgmt, Vsbgmt, Vgbgmt;
            real    cnst0over;
            real    fac1, fac1p2, VgpLD, Pb2over, Vgb_fb_LD;
            real    Ac41, Ac4, Ps0_min, Ac31, Ac3, Ac2, Ac1, Acd, Acn, Chi, Psa, Ps0LD, Ps0_iniA;
            real    Ta, Tb, Tc, Td, Tq, Tp, Tu, Tv;
            real    VgpLD_shift, cnst1over, gammaChi, psi, Chi_1, Chi_B, Chi_A;
            real    exp_bVbs, fi, fi_dChi, fs01, fs01_dPs0, fb, fb_dChi, fs02, fs02_dPs0;
            real    cfs1, exp_bPs0, Fs0, Fs0_dPs0, dPlim;
            real    Xi0, Xi0p12;
            // Some constants to be used here.
            Cox0 = C_fox0;
            Cox0_inv = 1.0 / Cox0 ;

            fs01 = 0.0;
            fb   = 0.0;
            fs02 = 0.0;

            T2 = -area_bt_n  ; // adding BT area
            T3 = T2 * Qiu ;
            T4 = T3 + T2 * Qbu ;
            Qbody_bt_n_iud = T3 * Qdrat ;
            Qbody_bt_n_ius = T3 - Qbody_bt_n_iud ;
            Qbody_bt_n_sud = T4 * Qdrat ;
            Qbody_bt_n_sus = T4 - Qbody_bt_n_sud ;

            /* Calc Voltage depends cap for body contact */
            if ( COADOV ) begin
                UC_NSUBBTTUB = Nsub;

                for ( lbt = 1 ; lbt <= 1 ; lbt = lbt +1 ) begin
                    //     lbt : 1 ( P+Poly ) , 2 ( N+Poly )
                    CBTB_GIVEN = 0 ;
                    case (lbt)
                        1 : begin // ( P+Poly )
                            UC_AREABT = area_bt_p * 0.5 ;
                            UC_VFBBT  = VFBBTP ;
                            CBTB_GIVEN = CBTBP_GIVEN ;
                        end
                        2 : begin // ( N+Poly )
                            UC_AREABT = area_bt_n * 0.5 ;
                            UC_VFBBT  = VFBC ;
                            CBTB_GIVEN = CBTBN_GIVEN ;
                            CBTB_GIVEN = 1 ;
                        end
                    endcase // case (lbt)
                    //

                    if ( CBTB_GIVEN == 0 ) begin
                        //
                        cnst0over = cnst0SOI * sqrt(UC_NSUBBTTUB / Nsub ) ;
                        // Following for-loop construct was intended for surface-potential based overlap charge used somewhere else;
                        // now recycled for MOSFET built in body contact tub.
                        // If charge partition to S and D does matter, activate for-loop counting twice.
                        for ( lcover = -1 ; lcover <= +1 ; lcover = lcover + 2 ) begin  // source side only

                            flg_ovloops = ( 1 - lcover ) / 2 ; // 1 in Source overlap calc. //
                            flg_ovloopd = ( 1 + lcover ) / 2 ; // 1 in Drain overlap calc. //
                            //-------------------------------------------*
                            //* Qover(G/D overlap charge)  |  note: _dVxs means _dVxse
                            //*------------------------//
                            Vbsgmt = ModeNML * Vbs + ModeRVS * ( Vbs - Vds ) ;
                            Vdsgmt = ModeNML * Vds + ModeRVS * ( - Vds ) ;
                            Vgsgmt = ModeNML * Vgs + ModeRVS * ( Vgs - Vds ) ;
                            Vgdgmt = ModeRVS * Vgs + ModeNML * ( Vgs - Vds ) ;
                            Vdbgmt = Vdsgmt - Vbsgmt ;
                            Vsbgmt = - Vbsgmt ;
                            flg_overs = flg_ovloops * ModeNML + flg_ovloopd * ModeRVS ; // geometrical source //
                            flg_overd = flg_ovloops * ModeRVS + flg_ovloopd * ModeNML ; // geometrical drain //
                            Vgbgmt = flg_overs * Vgsgmt + flg_overd * Vgdgmt ;
                            Vxbgmt = flg_overs * Vsbgmt + flg_overd * Vdbgmt + `epsm10 ;

                            //---------------------------------------------------*
                            //* Clamp -Vxbgmt.
                            //*-----------------//
                            T0 = - Vxbgmt;
                            if ( T0 > Vbs_bnd ) begin
                                T1 =    T0   - Vbs_bnd;
                                T2 =    Vbs_max    - Vbs_bnd;
                                `Fn_SUPoly4( TY, T1, T2, T11 )
                                T10 = Vbs_bnd + TY ;
                            end  else begin
                                T10 = T0 ;
                                T11 = 1.0 ;
                            end
                            Vxbgmtcl = - T10 - `Small2 ;
                            fac1 = cnst0over * Cox0_inv ;
                            fac1p2 = fac1 * fac1 ;
                            VgpLD =  Vgbgmt - UC_VFBBT;

                            T0 =  UC_NSUBBTTUB / Nin;

                            Pb2over = 2.0 / beta * ln ( T0 ) ;
                            Vgb_fb_LD =  - Vxbgmtcl ;


                            //-----------------------------------*
                            //* QsuLD: total charge = Accumulation | Depletion+inversion
                            //*-----------------//
                            if (   VgpLD  < Vgb_fb_LD ) begin
                                //---------------------------*
                                //* Accumulation
                                //*-----------------//
                                flg_ovzone = -1 ;
                                T1 = 1.0 / ( beta * cnst0over ) ;
                                TY = T1 * Cox0 ;
                                Ac41 = 2.0 + 3.0 * `C_SQRT_2 * TY ;
                                Ac4 = 8.0 * Ac41 * Ac41 * Ac41 ;
                                Ps0_min = Eg - Pb2over ;
                                TX = beta * ( VgpLD + Vxbgmtcl ) ;
                                Ac31 = 7.0 * `C_SQRT_2 - 9.0 * TY * ( TX - 2.0 ) ;
                                Ac3 = Ac31 * Ac31 ;
                                if ( Ac4 < Ac3 * 1.0e-8 ) begin
                                    Ac1 = -7.0 * `C_SQRT_2 + Ac31 + 0.5 * Ac4 / Ac31 + 9.0 * TY * ( TX - 2.0 ) ;
                                end else begin
                                    Ac2 = sqrt( Ac4 + Ac3 ) ;
                                    Ac1 = -7.0 * `C_SQRT_2 + Ac2 + 9.0 * TY * ( TX - 2.0 ) ;
                                end
                                Acd = pow( Ac1 , `C_1o3 ) ;
                                Acn = -4.0 * `C_SQRT_2 - 12.0 * TY + 2.0 * Acd + `C_SQRT_2 * Acd * Acd ;
                                Chi = Acn / Acd ;
                                Psa = Chi * beta_inv - Vxbgmtcl ;
                                T1 = Psa + Vxbgmtcl ;
                                T2 = T1 / Ps0_min ;
                                T3 = sqrt( 1.0 + ( T2 * T2 ) ) ;
                                Ps0LD = T1 / T3 - Vxbgmtcl ;
                                T2 = ( VgpLD - Ps0LD ) ;
                                QsuLD = Cox0 * T2 ;
                                QbuLD = QsuLD ;
                            end else begin

                                //---------------------------*
                                //* Depletion and inversion
                                //*-----------------//

                                // initial value for a few fixpoint iterations
                                //to get Ps0_iniA from simplified Poisson equation: //
                                flg_ovzone = 2 ;
                                Chi = `znbd3 ;
                                Ps0_iniA= Chi/beta - Vxbgmtcl ;

                                // 1 .. 2 relaxation steps should be sufficient //
                                for ( lp_ld = 1; lp_ld <= 2; lp_ld = lp_ld + 1 ) begin
                                    TY = exp(-Chi);
                                    TX = 1.0e0 + 4.0e0 * ( beta * ( VgpLD + Vxbgmtcl ) - 1.0e0 + TY ) / ( fac1p2 * beta2 ) ;
                                    if ( TX < `epsm10) begin
                                        TX = `epsm10;
                                    end
                                    Ps0_iniA = VgpLD + fac1p2 * beta / 2.0e0 * ( 1.0e0 - sqrt( TX ) ) ;
                                    Chi = beta * ( Ps0_iniA + Vxbgmtcl ) ;
                                end // End of iteration //
                                if ( Chi < `znbd3 ) begin
                                    flg_ovzone = 1 ;

                                    //-----------------------------------*
                                    //* zone-D1
                                    //* - Ps0_iniA is the analytical solution of QovLD=Qb0 with
                                    //*   Qb0 being approximated by 3-degree polynomial.
                                    //*
                                    //*   new: Inclusion of exp(-Chi) term at right border
                                    //*-----------------//
                                    Ta =  1.0/(9.0*`C_SQRT_2) - (5.0+7.0*`c_expm3) / (54.0*sqrt(2.0+`c_expm3));
                                    Tb = (1.0+`c_expm3) / (2.0*sqrt(2.0+`c_expm3)) - `C_SQRT_2 / 3.0;
                                    Tc =  1.0/`C_SQRT_2 + 1.0/(beta*fac1);
                                    Td = - (VgpLD + Vxbgmtcl) / fac1;
                                    Tq = Tb*Tb*Tb / (27.0*Ta*Ta*Ta) - Tb*Tc/(6.0*Ta*Ta) + Td/(2.0*Ta);
                                    Tp = (3.0*Ta*Tc-Tb*Tb)/(9.0*Ta*Ta);
                                    T5      = sqrt(Tq*Tq + Tp*Tp*Tp);
                                    Tu = pow(-Tq + T5,`C_1o3);
                                    Tv = -pow(Tq + T5,`C_1o3);
                                    TX      = Tu + Tv - Tb/(3.0*Ta);
                                    Ps0_iniA = TX * beta_inv - Vxbgmtcl ;
                                    Chi = beta * ( Ps0_iniA + Vxbgmtcl ) ;
                                end

                                //-----------------------------------*
                                //          * - Ps0_iniB : upper bound.
                                //          *-----------------//
                                flg_ovzone = flg_ovzone + 2;
                                VgpLD_shift = VgpLD + Vxbgmtcl + 0.1;
                                exp_bVbs = exp( beta * - Vxbgmtcl ) + `Small ;
                                T0 = Nin / UC_NSUBBTTUB;
                                cnst1over = T0 * T0;
                                gammaChi = cnst1over * exp_bVbs ;
                                T0    = beta2 * fac1p2;
                                psi = beta*VgpLD_shift;
                                Chi_1      = ln (gammaChi*T0 + psi*psi) - ln (cnst1over*T0) + beta*Vxbgmtcl;
                                `Fn_SU2( Chi_1, Chi_1, psi, 1.0, T1, T2 )

                                // 1 fixpoint step for getting more accurate Chi_B //
                                psi = psi - Chi_1 ;
                                psi = psi + beta*0.1 ;
                                Chi_B = ln (gammaChi*T0 + psi*psi) - ln (cnst1over*T0) + beta*Vxbgmtcl;
                                //*
                                //* Limiting is done for Chi rather than for Ps0LD, to avoid shifting
                                //* for Fn_SU2 //
                                Chi_A = Chi;
                                `Fn_SU2( Chi, Chi_A, Chi_B, `c_ps0ini_2*75.00, T1, T2 ) // org: 50 //

                                // updating Ps0LD //
                                Ps0LD = Chi/beta - Vxbgmtcl ;
                                T1    = Chi - 1.0 + exp(-Chi);
                                if (T1 < `epsm10) begin
                                    T1 = `epsm10 ;
                                end
                                T2 = sqrt(T1);
                                QbuLD = cnst0over * T2 ;

                                //-----------------------------------------------------------*
                                //* QsuLD : Qovs or Qovd in unit area.
                                //* note: QsuLD = Qdep+Qinv.
                                //*-----------------//
                                QsuLD = Cox0 * ( VgpLD - Ps0LD ) ;

                                if ( COQBDSM == 1 ) begin // take initial values from analytical model

                                    //---------------------------------------------------*
                                    //* Calculation of Ps0LD. (beginning of Newton loop)
                                    //* - Fs0 : Fs0 = 0 is the equation to be solved.
                                    //* - dPs0 : correction value.
                                    //*-----------------//

                                    // initial value too close to flat band should not be used //
                                    exp_bVbs = exp( beta * - Vxbgmtcl ) ;
                                    T0 = Nin / UC_NSUBBTTUB;
                                    cnst1over = T0 * T0;
                                    cfs1 = cnst1over * exp_bVbs ;
                                    flg_conv = 0 ;
                                    for ( lp_s0 = 1 ; lp_s0 <= 2*`lp_s0_max + 1 ; lp_s0 = lp_s0 + 1 ) begin
                                        fb = 0.0 ;
                                        Chi = beta * ( Ps0LD + Vxbgmtcl ) ;
                                        if ( Chi < `znbd5 ) begin
                                            //-------------------------------------------*
                                            //* zone-D1/D2. (Ps0LD)
                                            //*-----------------//
                                            fi = Chi * Chi * Chi
                                            * ( `cn_im53 + Chi * ( `cn_im54 + Chi * `cn_im55 ) ) ;
                                            fi_dChi = Chi * Chi
                                                 * ( 3 * `cn_im53 + Chi * ( 4 * `cn_im54 + Chi * 5 * `cn_im55 ) ) ;
                                            fs01 = cfs1 * fi * fi ;
                                            fs01_dPs0 = cfs1 * beta * 2 * fi * fi_dChi ;

                                            fb = Chi * ( `cn_nc51
                                                    + Chi * ( `cn_nc52
                                                              + Chi * ( `cn_nc53
                                                                        + Chi * ( `cn_nc54 + Chi * `cn_nc55 ) ) ) ) ;
                                            fb_dChi = `cn_nc51
                                                 + Chi * ( 2 * `cn_nc52
                                                           + Chi * ( 3 * `cn_nc53
                                                                     + Chi * ( 4 * `cn_nc54 + Chi * 5 * `cn_nc55 ) ) ) ;
                                            fs02 = sqrt( fb * fb + fs01 + `Small ) ;
                                            fs02_dPs0 = ( beta * fb_dChi * 2 * fb + fs01_dPs0 ) / ( fs02 + fs02 ) ;
                                        end else begin
                                            //-------------------------------------------*
                                            //* zone-D3. (Ps0LD)
                                            //*-----------------//
                                            if ( Chi < `large_arg ) begin // avoid exp_Chi to become extremely large //
                                                exp_Chi = exp( Chi ) ;
                                                fs01 = cfs1 * ( exp_Chi - 1.0e0 ) ;
                                                fs01_dPs0 = cfs1 * beta * ( exp_Chi ) ;
                                            end else begin
                                                exp_bPs0 = exp( beta*Ps0LD ) ;
                                                fs01     = cnst1over * ( exp_bPs0 - exp_bVbs ) ;
                                                fs01_dPs0 = cnst1over * beta * exp_bPs0 ;
                                            end
                                            fs02 = sqrt( Chi - 1.0 + fs01 ) ;
                                            fs02_dPs0 = ( beta + fs01_dPs0 ) / fs02 * 0.5 ;

                                        end // end of if( Chi  ... ) block //
                                        //-----------------------------------------------------------*
                                        //* Fs0
                                        //*-----------------//
                                        Fs0 = VgpLD - Ps0LD - fac1 * fs02 ;
                                        Fs0_dPs0 = - 1.0e0 - fac1 * fs02_dPs0 ;
                                        if ( flg_conv == 1 ) begin
                                            lp_s0 = 2*`lp_s0_max+1 ; // break
                                        end else begin
                                            dPs0 = - Fs0 / Fs0_dPs0 ;

                                            //-------------------------------------------*
                                            //* Update Ps0LD .
                                            //*-----------------//
                                            dPlim = 0.5*`dP_max*(1.0 + `Fn_Max(1.0e0,abs(Ps0LD))) ;
                                            if ( abs( dPs0 ) > dPlim ) dPs0 = dPlim * `Fn_Sgn( dPs0 ) ;
                                            Ps0LD = Ps0LD + dPs0 ;

                                            //-------------------------------------------*
                                            //* Check convergence.
                                            //*-----------------//
                                            if ( abs( dPs0 ) <= `ps_conv && abs( Fs0 ) <= `gs_conv ) begin
                                                flg_conv = 1 ;
                                            end

                                        end
                                    end // end of Ps0LD Newton loop //

                                    //-------------------------------------------*
                                    //* Procedure for diverged case.
                                    //*-----------------//
                                    if ( flg_conv == 0 ) begin
                                        $write( "*** warning(HiSIM_SOI): Went Over Iteration Maximum(%M:Ps0LD)\n" ) ;
                                        $write(" -Vxbgmtcl = %e   Vgbgmt = %e\n" , -Vxbgmtcl , Vgbgmt ) ;
                                    end

                                    if ( Chi < `znbd5 ) begin
                                        //-------------------------------------------*
                                        //* zone-D1/D2. (Ps0LD)
                                        //*-----------------//
                                        if ( Chi < `znbd3 ) begin flg_ovzone = 1; end
                                        else begin flg_ovzone = 2; end
                                        Xi0 = fb * fb + `epsm10 ;
                                        Xi0p12 = fb + `epsm10 ;
                                    end else begin
                                        //-------------------------------------------*
                                        //* zone-D3. (Ps0LD)
                                        //*-----------------//
                                        flg_ovzone = 3 ;
                                        Xi0 = Chi - 1.0e0 ;
                                        Xi0p12 = sqrt( Xi0 ) ;
                                    end // end of if( Chi  ... ) block //

                                    //-----------------------------------------------------------*
                                    //* QbuLD and QiuLD
                                    //*-----------------//
                                    QbuLD = cnst0over * Xi0p12 ;
                                    T1 = 1.0 / ( fs02 + Xi0p12 ) ;
                                    QiuLD = cnst0over * fs01 * T1 ;

                                    //-----------------------------------------------------------*
                                    //* Total overlap charge
                                    //*-----------------//
                                    QsuLD = QbuLD + QiuLD;

                                end // end of COQBDSM branches //

                            end // end of Vgbgmt region blocks //

                            // inversion charge = total - depletion //
                            QiuLD = QsuLD - QbuLD  ;

                            //As this block turns back positive inversion charge (as in pMOSFET),
                            // take `-' sign for nMOSFET.
                            case (lbt)
                                1: begin // ( P+Poly)
                                    // Qbody_bt_n_plus
                                    if (flg_ovloops) begin
                                        Qbody_bt_p_sus = - UC_AREABT * QsuLD ;
                                        Qbody_bt_p_ius = - UC_AREABT * QiuLD ;
                                    end
                                    if (flg_ovloopd) begin
                                        Qbody_bt_p_sud = - UC_AREABT * QsuLD ;
                                        Qbody_bt_p_iud = - UC_AREABT * QiuLD ;
                                    end
                                end
                                2: begin // ( N+Poly)
                                    // Qbody_bt_n_plus
                                    if (flg_ovloops) begin
                                        Qbody_bt_n_sus = - UC_AREABT * QsuLD ;
                                        Qbody_bt_n_ius = - UC_AREABT * QiuLD ;
                                    end
                                    if (flg_ovloopd) begin
                                        Qbody_bt_n_sud = - UC_AREABT * QsuLD ;
                                        Qbody_bt_n_iud = - UC_AREABT * QiuLD ;
                                    end
                                end
                            endcase
                        end // end of lcover loop //
                    end // end of if( UC_WBT > 0.0 && UC_NSUBBTTUB == 0.0 ) //
                end // end of lbt loop //
            end /* COADOV=1 */
        end  // IntrinsicChargeForMOSFEToverBodyContact
        //---End of Intrinsic charge for parasitic MOSFET built over body-contact well---

    end

    //-------------------------------------------*
    //Calculation of Psdl for cases of flg_noqi==1.
    //----------------//
    begin : OverlapCharge_CalculationOfPsdl
        real T1,T2;

        Aclm = CLM1 ;
        if (flg_noqi != 0) begin
            T2 = Vds + Ps0 ;
            Psdl = Aclm * T2 + (1.0e0 - Aclm) * Psl ;
            if (XQY !=0) begin
                Ec = 0.0 ;
            end
            if (Psdl > Ps0 + Vds - `epsm10) begin
                Psdl = Ps0 + Vds - `epsm10 ;
            end
        end else begin
            // Ec is removed from Lred calc. part //
            if (XQY !=0) begin
                if ( Idd < `C_IDD_MIN ) begin
                    Ec = 0.0e0 ;
                end else begin
                    T1 =  beta_inv / Leff ;
                    T2 = 1.0 / Qn0 ;
                    Ec = Idd * T1 * T2 ;
                end
            end
        end
    end // Overlapcharge_CalculationOfPsdl

    // Surface-potential based Qover
    begin : OverlapCharge
        real    T0, T1, T2, T3, T4, T5,  T9, T10, T11;
        real    TX, TY;
        real    Cox0, Cox0_inv, Lov, cov_slp, cov_mag, covvg;
        integer flg_ovloops, flg_ovloopd, flg_overs, flg_overd, lcover, flg_ovzone, flg_conv;
        integer lp_ld;
        real    Vxbgmt, Vxbgmtcl;
        real    Vbsgmt, Vdsgmt, Vgsgmt,  Vdbgmt, Vsbgmt, Vgbgmt;
        real    cnst0over;
        real    fac1, fac1p2, VgpLD, Pb2over, Vgb_fb_LD;
        real    Ac41, Ac4, Ps0_min, Ac31, Ac3, Ac2, Ac1, Acd, Acn, Chi, Psa, Ps0LD, Ps0_iniA;
        real    Ta, Tb, Tc, Td, Tq, Tp, Tu, Tv;
        real    VgpLD_shift, cnst1over, gammaChi, psi, Chi_1, Chi_B, Chi_A;
        real    exp_bVbs, fi, fi_dChi, fs01, fs01_dPs0, fb, fb_dChi, fs02, fs02_dPs0;
        real    cfs1, exp_bPs0, Fs0, Fs0_dPs0, dPlim;
        real    Xi0, Xi0p12;

        //-------------------------------------------*
        //* Overlap charges: Qgod, Qgos, and Qover
        //*-----------------//
        // Some constants to be used here.
        Cox0 = C_fox0;
        Cox0_inv = 1.0 / Cox0 ;
        Vgbgmt= 0.0;

        fb   = 0.0;
        fs01 = 0.0;
        fs02 = 0.0;

        if ( COADOV ) begin

            if ( COOVLP >= 1 && LOVER > 0.0 ) begin
                cov_slp = OVSLP;
                cov_mag = OVMAG ;
                covvg = Vgs ;
                Lov = LOVER ;
                if ( MKS_NOVER == 0.0 && LOVER > 0.0 ) begin
                    T1= ( COBCNODE == 1 ) ? W_dioscv * Cox0 : weffcv_nf * Cox0 ;
                    T4 = cov_slp * T1 * ( cov_mag + covvg ) ;
                    T5 = Lov * T1 ;
                    TX = Ps0 ;
                    T9 = 1.2e0 - TX ;
                    Qgos = Vgs * T5 - T9 * T4 ;
                    T4 = cov_slp * T1 * ( cov_mag + covvg - Vds ) ;
                    TX = Psl - Vds ;
                    T9 = 1.2e0 - TX ;
                    Qgod = (Vgs - Vds) * T5 - T4 * T9 ;
                end else begin
                    cnst0over = cnst0SOI * sqrt(MKS_NOVER / Nsub ) ;
                    for ( lcover = -1 ; lcover <= +1 ; lcover = lcover + 2 ) begin
                        flg_ovloops = ( 1 - lcover ) / 2 ; // 1 in Source overlap calc. //
                        flg_ovloopd = ( 1 + lcover ) / 2 ; // 1 in Drain overlap calc. //
                        //-------------------------------------------*
                        //* Qover(G/D overlap charge)  |  note: _dVxs means _dVxse
                        //*------------------------//
                        if ( COBCNODE == 1 ) begin
                            Vbsgmt = ModeNML * Vbs + ModeRVS * ( Vbs - Vds ) ;
                            Vdsgmt = ModeNML * Vds + ModeRVS * ( - Vds ) ;
                            Vgsgmt = ModeNML * Vgs + ModeRVS * ( Vgs - Vds ) ;
                            Vdbgmt = Vdsgmt - Vbsgmt ;
                            Vgbgmt = Vgsgmt - Vbsgmt ;
                            Vsbgmt = - Vbsgmt ;
                            flg_overs = flg_ovloops * ModeNML + flg_ovloopd * ModeRVS ; // geometrical source //
                            flg_overd = flg_ovloops * ModeRVS + flg_ovloopd * ModeNML ; // geometrical drain //
                            Vxbgmt = flg_overs * Vsbgmt + flg_overd * Vdbgmt + `epsm10 ;
                        end else begin
                            flg_overs = flg_ovloops * ModeNML + flg_ovloopd * ModeRVS ; // geometrical source //
                            flg_overd = flg_ovloops * ModeRVS + flg_ovloopd * ModeNML ; // geometrical drain //
                            if (flg_ovloops) Vgbgmt = ModeNML * Vgs + ModeRVS * ( Vgs - Vds ) ;
                            if (flg_ovloopd) Vgbgmt = ModeRVS * Vgs + ModeNML * ( Vgs - Vds ) ;
                            Vxbgmt = 0.0 ;
                        end

                        //---------------------------------------------------*
                        //* Clamp -Vxbgmt.
                        //*-----------------//
                        T0 = - Vxbgmt;
                        if ( T0 > Vbs_bnd ) begin
                            T1 =    T0   - Vbs_bnd;
                            T2 =    Vbs_max    - Vbs_bnd;
                            `Fn_SUPoly4( TY, T1, T2, T11 )
                            T10 = Vbs_bnd + TY ;
                        end  else begin
                            T10 = T0 ;
                            T11 = 1.0 ;
                        end
                        Vxbgmtcl = - T10 - `Small2 ;
                        fac1 = cnst0over * Cox0_inv ;
                        fac1p2 = fac1 * fac1 ;
                        VgpLD = - Vgbgmt + UC_VFBOVER;
                        T0 = MKS_NOVER / Nin ;
                        Pb2over = 2.0 / beta * ln ( T0 ) ;
                        Vgb_fb_LD =  - Vxbgmtcl ;

                        //-----------------------------------*
                        //* QsuLD: total charge = Accumulation | Depletion+inversion
                        //*-----------------//
                        if (   VgpLD  < Vgb_fb_LD ) begin
                            //---------------------------*
                            //* Accumulation
                            //*-----------------//
                            flg_ovzone = -1 ;
                            T1 = 1.0 / ( beta * cnst0over ) ;
                            TY = T1 * Cox0 ;
                            Ac41 = 2.0 + 3.0 * `C_SQRT_2 * TY ;
                            Ac4 = 8.0 * Ac41 * Ac41 * Ac41 ;
                            Ps0_min = Eg - Pb2over ;
                            TX = beta * ( VgpLD + Vxbgmtcl ) ;
                            Ac31 = 7.0 * `C_SQRT_2 - 9.0 * TY * ( TX - 2.0 ) ;
                            Ac3 = Ac31 * Ac31 ;
                            if ( Ac4 < Ac3 * 1.0e-8 ) begin
                                Ac1 = -7.0 * `C_SQRT_2 + Ac31 + 0.5 * Ac4 / Ac31 + 9.0 * TY * ( TX - 2.0 ) ;
                            end else begin
                                Ac2 = sqrt( Ac4 + Ac3 ) ;
                                Ac1 = -7.0 * `C_SQRT_2 + Ac2 + 9.0 * TY * ( TX - 2.0 ) ;
                            end
                            Acd = pow( Ac1 , `C_1o3 ) ;
                            Acn = -4.0 * `C_SQRT_2 - 12.0 * TY + 2.0 * Acd + `C_SQRT_2 * Acd * Acd ;
                            Chi = Acn / Acd ;
                            Psa = Chi * beta_inv - Vxbgmtcl ;
                            T1 = Psa + Vxbgmtcl ;
                            T2 = T1 / Ps0_min ;
                            T3 = sqrt( 1.0 + ( T2 * T2 ) ) ;
                            Ps0LD = T1 / T3 - Vxbgmtcl ;
                            T2 = ( VgpLD - Ps0LD ) ;
                            QsuLD = Cox0 * T2 ;
                            QbuLD = QsuLD ;
                        end else begin

                            //---------------------------*
                            //* Depletion and inversion
                            //*-----------------//

                            // initial value for a few fixpoint iterations
                            //to get Ps0_iniA from simplified Poisson equation: //
                            flg_ovzone = 2 ;
                            Chi = `znbd3 ;
                            Ps0_iniA= Chi/beta - Vxbgmtcl ;

                            // 1 .. 2 relaxation steps should be sufficient //
                            for ( lp_ld = 1; lp_ld <= 2; lp_ld = lp_ld + 1 ) begin
                                TY = exp(-Chi);
                                TX = 1.0e0 + 4.0e0 * ( beta * ( VgpLD + Vxbgmtcl ) - 1.0e0 + TY ) / ( fac1p2 * beta2 ) ;
                                if ( TX < `epsm10) begin
                                    TX = `epsm10;
                                end
                                Ps0_iniA = VgpLD + fac1p2 * beta / 2.0e0 * ( 1.0e0 - sqrt( TX ) ) ;
                                Chi = beta * ( Ps0_iniA + Vxbgmtcl ) ;
                            end // End of iteration //
                            if ( Chi < `znbd3 ) begin
                                flg_ovzone = 1 ;

                                //-----------------------------------*
                                //* zone-D1
                                //* - Ps0_iniA is the analytical solution of QovLD=Qb0 with
                                //*   Qb0 being approximated by 3-degree polynomial.
                                //*
                                //*   new: Inclusion of exp(-Chi) term at right border
                                //*-----------------//
                                Ta =  1.0/(9.0*`C_SQRT_2) - (5.0+7.0*`c_expm3) / (54.0*sqrt(2.0+`c_expm3));
                                Tb = (1.0+`c_expm3) / (2.0*sqrt(2.0+`c_expm3)) - `C_SQRT_2 / 3.0;
                                Tc =  1.0/`C_SQRT_2 + 1.0/(beta*fac1);
                                Td = - (VgpLD + Vxbgmtcl) / fac1;
                                Tq = Tb*Tb*Tb / (27.0*Ta*Ta*Ta) - Tb*Tc/(6.0*Ta*Ta) + Td/(2.0*Ta);
                                Tp = (3.0*Ta*Tc-Tb*Tb)/(9.0*Ta*Ta);
                                T5      = sqrt(Tq*Tq + Tp*Tp*Tp);
                                Tu = pow(-Tq + T5,`C_1o3);
                                Tv = -pow(Tq + T5,`C_1o3);
                                TX      = Tu + Tv - Tb/(3.0*Ta);
                                Ps0_iniA = TX * beta_inv - Vxbgmtcl ;
                                Chi = beta * ( Ps0_iniA + Vxbgmtcl ) ;
                            end
                            if ( COQOVSM > 0 ) begin
                                //-----------------------------------*
                                //          * - Ps0_iniB : upper bound.
                                //          *-----------------//
                                flg_ovzone = flg_ovzone + 2;
                                VgpLD_shift = VgpLD + Vxbgmtcl + 0.1;
                                exp_bVbs = exp( beta * - Vxbgmtcl ) + `Small ;
                                T0 = Nin / MKS_NOVER;
                                cnst1over = T0 * T0;
                                gammaChi = cnst1over * exp_bVbs ;
                                T0    = beta2 * fac1p2;
                                psi = beta*VgpLD_shift;
                                Chi_1      = ln (gammaChi*T0 + psi*psi) - ln (cnst1over*T0) + beta*Vxbgmtcl;
                                `Fn_SU2( Chi_1, Chi_1, psi, 1.0, T1, T2 )

                                // 1 fixpoint step for getting more accurate Chi_B //
                                psi = psi - Chi_1 ;
                                psi = psi + beta*0.1 ;
                                Chi_B = ln (gammaChi*T0 + psi*psi) - ln (cnst1over*T0) + beta*Vxbgmtcl;
                                //*
                                //* Limiting is done for Chi rather than for Ps0LD, to avoid shifting
                                //* for Fn_SU2 //
                                Chi_A = Chi;
                                `Fn_SU2( Chi, Chi_A, Chi_B, `c_ps0ini_2*75.00, T1, T2 ) // org: 50 //

                            end

                            // updating Ps0LD //
                            Ps0LD = Chi/beta - Vxbgmtcl ;
                            T1    = Chi - 1.0 + exp(-Chi);
                            if (T1 < `epsm10) begin
                                T1 = `epsm10 ;
                            end
                            T2 = sqrt(T1);
                            QbuLD = cnst0over * T2 ;

                            //-----------------------------------------------------------*
                            //* QsuLD : Qovs or Qovd in unit area.
                            //* note: QsuLD = Qdep+Qinv.
                            //*-----------------//
                            QsuLD = Cox0 * ( VgpLD - Ps0LD ) ;

                            if ( COQOVSM == 1 ) begin // take initial values from analytical model //

                                //---------------------------------------------------*
                                //* Calculation of Ps0LD. (beginning of Newton loop)
                                //* - Fs0 : Fs0 = 0 is the equation to be solved.
                                //* - dPs0 : correction value.
                                //*-----------------//

                                // initial value too close to flat band should not be used //
                                exp_bVbs = exp( beta * - Vxbgmtcl ) ;
                                T0 = Nin / MKS_NOVER;
                                cnst1over = T0 * T0;
                                cfs1 = cnst1over * exp_bVbs ;
                                flg_conv = 0 ; fs01 = 0.0 ; fs02 = 0.0 ;
                                for ( lp_s0 = 1 ; lp_s0 <= 2*`lp_s0_max + 1 ; lp_s0 = lp_s0 + 1 ) begin
                                    fb = 0.0 ;
                                    Chi = beta * ( Ps0LD + Vxbgmtcl ) ;
                                    if ( Chi < `znbd5 ) begin
                                        //-------------------------------------------*
                                        //* zone-D1/D2. (Ps0LD)
                                        //*-----------------//
                                        fi = Chi * Chi * Chi
                                         * ( `cn_im53 + Chi * ( `cn_im54 + Chi * `cn_im55 ) ) ;
                                        fi_dChi = Chi * Chi
                                              * ( 3 * `cn_im53 + Chi * ( 4 * `cn_im54 + Chi * 5 * `cn_im55 ) ) ;
                                        fs01 = cfs1 * fi * fi ;
                                        fs01_dPs0 = cfs1 * beta * 2 * fi * fi_dChi ;

                                        fb = Chi * ( `cn_nc51
                                                 + Chi * ( `cn_nc52
                                                           + Chi * ( `cn_nc53
                                                                     + Chi * ( `cn_nc54 + Chi * `cn_nc55 ) ) ) ) ;
                                        fb_dChi = `cn_nc51
                                              + Chi * ( 2 * `cn_nc52
                                                        + Chi * ( 3 * `cn_nc53
                                                                  + Chi * ( 4 * `cn_nc54 + Chi * 5 * `cn_nc55 ) ) ) ;
                                        fs02 = sqrt( fb * fb + fs01 + `Small ) ;
                                        fs02_dPs0 = ( beta * fb_dChi * 2 * fb + fs01_dPs0 ) / ( fs02 + fs02 ) ;
                                    end else begin
                                        //-------------------------------------------*
                                        //* zone-D3. (Ps0LD)
                                        //*-----------------//
                                        if ( Chi < `large_arg ) begin // avoid exp_Chi to become extremely large //
                                            exp_Chi = exp( Chi ) ;
                                            fs01 = cfs1 * ( exp_Chi - 1.0e0 ) ;
                                            fs01_dPs0 = cfs1 * beta * ( exp_Chi ) ;
                                        end else begin
                                            exp_bPs0 = exp( beta*Ps0LD ) ;
                                            fs01     = cnst1over * ( exp_bPs0 - exp_bVbs ) ;
                                            fs01_dPs0 = cnst1over * beta * exp_bPs0 ;
                                        end
                                        fs02 = sqrt( Chi - 1.0 + fs01 ) ;
                                        fs02_dPs0 = ( beta + fs01_dPs0 ) / fs02 * 0.5 ;

                                    end // end of if( Chi  ... ) block //
                                    //-----------------------------------------------------------*
                                    //* Fs0
                                    //*-----------------//
                                    Fs0 = VgpLD - Ps0LD - fac1 * fs02 ;
                                    Fs0_dPs0 = - 1.0e0 - fac1 * fs02_dPs0 ;
                                    if ( flg_conv == 1 ) begin
                                        lp_s0 = 2*`lp_s0_max+1 ;  // break
                                    end else begin
                                        dPs0 = - Fs0 / Fs0_dPs0 ;

                                        //-------------------------------------------*
                                        //* Update Ps0LD .
                                        //*-----------------//
                                        dPlim = 0.5*`dP_max*(1.0 + `Fn_Max(1.0e0,abs(Ps0LD))) ;
                                        if ( abs( dPs0 ) > dPlim ) dPs0 = dPlim * `Fn_Sgn( dPs0 ) ;
                                        Ps0LD = Ps0LD + dPs0 ;

                                        //-------------------------------------------*
                                        //* Check convergence.
                                        //*-----------------//
                                        if ( abs( dPs0 ) <= `ps_conv && abs( Fs0 ) <= `gs_conv ) begin
                                            flg_conv = 1 ;
                                        end

                                    end
                                end // end of Ps0LD Newton loop //

                                //-------------------------------------------*
                                //* Procedure for diverged case.
                                //*-----------------//
                                if ( flg_conv == 0 ) begin
                                    $write( "*** warning(HiSIM_SOI): Went Over Iteration Maximum(%M:Ps0LD)\n" ) ;
                                    $write(" -Vxbgmtcl = %e   Vgbgmt = %e\n" , -Vxbgmtcl , Vgbgmt ) ;
                                end

                                if ( Chi < `znbd5 ) begin
                                    //-------------------------------------------*
                                    //* zone-D1/D2. (Ps0LD)
                                    //*-----------------//
                                    if ( Chi < `znbd3 ) begin flg_ovzone = 1; end
                                    else begin flg_ovzone = 2; end
                                    Xi0 = fb * fb + `epsm10 ;
                                    Xi0p12 = fb + `epsm10 ;
                                end else begin
                                    //-------------------------------------------*
                                    //* zone-D3. (Ps0LD)
                                    //*-----------------//
                                    flg_ovzone = 3 ;
                                    Xi0 = Chi - 1.0e0 ;
                                    Xi0p12 = sqrt( Xi0 ) ;
                                end // end of if( Chi  ... ) block //

                                //-----------------------------------------------------------*
                                //* QbuLD and QiuLD
                                //*-----------------//
                                QbuLD = cnst0over * Xi0p12 ;
                                T1 = 1.0 / ( fs02 + Xi0p12 ) ;
                                QiuLD = cnst0over * fs01 * T1 ;

                                //-----------------------------------------------------------*
                                //* Total overlap charge
                                //*-----------------//
                                QsuLD = QbuLD + QiuLD;

                            end // end of COQOVSM branches //

                        end // end of Vgbgmt region blocks //

                        // inversion charge = total - depletion //
                        QiuLD = QsuLD - QbuLD  ;

                        // assign final outputs of Qover model //
                        // note: Qovs and Qovd are exchanged in reverse mode //
                        T4 = ( COBCNODE == 1 ) ? W_dioscv * Lov : weffcv_nf * Lov ;
                        if ( (flg_overs && COBCNODE == 0) || (flg_ovloops && COBCNODE == 1)) begin
                            Qovs =  T4 * QsuLD ;
                            QbsLD = T4 * QbuLD ;
                        end
                        if ( (flg_overd && COBCNODE == 0) || (flg_ovloopd && COBCNODE == 1)) begin
                            Qovd =  T4 * QsuLD ;
                            QbdLD = T4 * QbuLD ;
                        end

                    end // end of lcover loop }//

                end // end of if( MKS_NOVER == 0.0 )} //

                //-----------------------------------*
                //* Additional constant capacitance model
                //*-----------------//
                flg_overgiven = ( ModeRVS * CGSO_GIVEN
                                    + ModeNML * CGDO_GIVEN  ) ;
                if ( flg_overgiven ) begin
                    Cgdoe  = ModeRVS * CGSO + ModeNML * CGDO ;
                    if ( COBCNODE == 1 ) begin
                        T1    = ModeRVS * W_dioscv + ModeNML * W_diodcv ;
                        Cgdoe = Cgdoe *  - T1 ;
                    end else begin
                        Cgdoe = Cgdoe * ( - weffcv_nf ) ;
                    end

                    Qgod = Qgod + - Cgdoe * (Vgs - Vds) ;
                end

                flg_overgiven = ( ModeNML * CGSO_GIVEN
                                    + ModeRVS * CGDO_GIVEN ) ;
                if (flg_overgiven) begin
                    Cgsoe  = ModeNML * CGSO + ModeRVS * CGDO ;
                    if ( COBCNODE == 1 ) begin
                        T1    = ModeNML * W_dioscv + ModeRVS * W_diodcv ;
                        Cgsoe = Cgsoe *  - T1 ;
                    end else begin
                        Cgsoe = Cgsoe * ( - weffcv_nf ) ;
                    end
                    Qgos = Qgos + - Cgsoe * Vgs ;
                end

            end else begin // else case of if( coovlp >= 1 ) //
                if ((mode == `HiSIM_NORMAL_MODE && !CGDO_GIVEN) ||
                     (mode != `HiSIM_NORMAL_MODE && !CGSO_GIVEN) ) begin
                    if ( COBCNODE == 1 ) begin
                        Cgdoe = - Cox0 * LOVER * W_diodcv ;
                    end else begin
                        Cgdoe = - Cox0 * LOVER * weffcv_nf ;
                    end

                end else begin
                    Cgdoe  = ModeRVS * CGSO + ModeNML * CGDO ;
                    if ( COBCNODE == 1 ) begin
                        T1    = ModeRVS * W_dioscv + ModeNML * W_diodcv ;
                        Cgdoe = Cgdoe * - T1 ;
                    end else begin
                        Cgdoe = Cgdoe * ( - weffcv_nf ) ;
                    end
                end
                Qgod = - Cgdoe * (Vgs - Vds) ;

                if ((mode == `HiSIM_NORMAL_MODE && !CGSO_GIVEN) ||
                     (mode != `HiSIM_NORMAL_MODE && !CGDO_GIVEN) ) begin
                    if ( COBCNODE == 1 ) begin
                        Cgsoe = - Cox0 * LOVER * W_dioscv ;
                    end else begin
                        Cgsoe = - Cox0 * LOVER * weffcv_nf ;
                    end
                end else begin
                    Cgsoe  = ModeNML * CGSO + ModeRVS * CGDO ;
                    if ( COBCNODE == 1 ) begin
                        T1     = ModeNML * W_dioscv + ModeRVS * W_diodcv ;
                        Cgsoe = Cgsoe * - T1 ;
                    end else begin
                        Cgsoe = Cgsoe * ( - weffcv_nf ) ;
                    end
                end
                Qgos = - Cgsoe * Vgs ;
            end // end of if( coovlp >= 1 ) //

        end // (COADOV == 1)
    end // OverlapCharge
    //End of include

    //-----------------------------------------------------------*
    //End of PART-3. (label)
    //----------------//
    // end_of_part_3: ; //

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //PART-4: Substrate-source/drain junction diode.
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
    if ( COBCNODE == 1 ) begin
        begin : JunctionDiodeModel
            real T0, T1, T2, T3;
            real Qbs_max, Qbd_max, dlt_Qbs, dlt_Qbd;
            real Xp_max;
            real czbd, czbs, czbdsw, czbssw, czbdswg, czbsswg;
            real Vbdj, Vbsj;
            real js, js2;
            real Nvtm;
            real vbdt, vbst;
            real isbd, isbs, isbd2, isbs2;
            real arg, sarg;

            //-----------------------------------------------------------*
            //Cbsj, Cbdj: node-base S/D biases. (CMI seems require them.)
            //----------------//

            begin             // pn junction diode current {
                Vbdj = vbcd ;
                Vbsj = vbcs ;

                // Diode Current : Ibd,Ibs //
                js =  JS0 * exp((egtnom * betatnom - Eg * beta + XTI * ln(TTEMP / UC_TNOM)) / NJ) ;
                js2 = JS0 * exp((egtnom * betatnom - Eg * beta + XTI2 * ln(TTEMP / UC_TNOM)) / NJ) ;
                isbd  = W_diod * `t_SOI * js ;
                isbd2 = W_diod * `t_SOI * js2 ;
                isbs  = W_dios * `t_SOI * js ;
                isbs2 = W_dios * `t_SOI * js2 ;

                T1 = TTEMP / UC_TNOM ;
                T0 = T1 * T1 ;
                T2 = isbd + `Small ;
                T3 = isbs + `Small ;
                vbdt = NJ / beta * log1p( VDIFFJ * T0 / T2 ) ;
                vbst = NJ / beta * log1p( VDIFFJ * T0 / T3 ) ;

                Nvtm = NJ * beta_inv ;

                // ibd //
                if (Vbdj < vbdt) begin
                    T1 = exp(Vbdj / Nvtm) ;
                    Ibd = isbd * (T1 - 1.0) ;
                end else begin
                    T1 = exp(vbdt / Nvtm) ;
                    Ibd = isbd * (T1 - 1.0) + isbd / Nvtm * T1 * (Vbdj - vbdt) ;
                end
                Ibd = Ibd + DIVX * Vbdj * isbd2 ;

                // ibs //
                if (Vbsj < vbst) begin
                    T1 = exp(Vbsj / Nvtm) ;
                    Ibs = isbs * (T1 - 1.0) ;
                end else begin
                    T1 = exp(vbst / Nvtm) ;
                    Ibs = isbs * (T1 - 1.0)
                       + isbs / Nvtm * T1 * (Vbsj - vbst) ;
                end
                Ibs = Ibs + DIVX * Vbsj * isbs2 ;
                Ibd = Ibd + Gjmin * Vbdj ;
                Ibs = Ibs + Gjmin * Vbsj ;
            end                      // end pn junction diode current}

            //-----------------------------------------------------------*
            //Charges and Capacitances.
            //----------------//
            //  charge storage elements
            //*  bulk-drain and bulk-source depletion capacitances
            //*  czbd : zero bias drain junction capacitance
            //*  czbs : zero bias source junction capacitance
            //*  czbdsw:zero bias drain junction sidewall capacitance
            //*  czbssw:zero bias source junction sidewall capacitance
            ////
            czbd = CJ * AD ;
            czbs = CJ * AS ;
            Xp_max = `t_SOI - XJ ;

            if (Xp_max <= 0) begin    // "=" is added to avoid FPE issues in the
                //                         junction capacitance model. //
                czbd = 0.0 ;
                czbs = 0.0 ;
            end

            // Source Bulk Junction //
            if (PS > W_dioscv) begin
                czbssw  = CJSW * (PS - W_dioscv) ;
                czbsswg = CJSWG * W_dioscv ;
                if (Vbsj < 0.0) begin
                    if (czbs > 0.0) begin
                        arg = 1.0 - Vbsj / PB ;
                        if (MJ == 0.5) begin
                            sarg = 1.0 / sqrt(arg) ;
                        end else begin
                            sarg = `Fn_Pow(arg, -MJ) ;
                        end
                        Qbs = PB * czbs * (1.0 - arg * sarg) / (1.0 - MJ) ;
                    end else begin
                        Qbs = 0.0 ;
                    end
                    if (czbssw > 0.0) begin
                        arg = 1.0 - Vbsj / PBSW ;
                        if (MJSW == 0.5) sarg = 1.0 / sqrt(arg) ;
                        else sarg = `Fn_Pow(arg, -MJSW) ;
                        Qbs = Qbs + PBSW * czbssw * (1.0 - arg * sarg) / (1.0 - MJSW) ;
                    end
                    if (czbsswg > 0.0) begin
                        arg = 1.0 - Vbsj / PBSWG ;
                        if (MJSWG == 0.5) sarg = 1.0 / sqrt(arg) ;
                        else sarg = `Fn_Pow(arg, -MJSWG) ;
                        Qbs = Qbs + PBSWG * czbsswg * (1.0 - arg * sarg) / (1.0 - MJSWG) ;
                    end
                end else begin
                    T1 = czbs + czbssw + czbsswg ;
                    T2 = czbs * MJ / PB
                          + czbssw * MJSW / PBSW +
                          czbsswg * MJSWG / PBSWG ;
                    Qbs = Vbsj * (T1 + Vbsj * 0.5 * T2) ;
                end
            end else begin
                czbsswg = CJSWG * PS ;
                if (Vbsj < 0.0) begin
                    if (czbs > 0.0) begin
                        arg = 1.0 - Vbsj / PB ;
                        if (MJ == 0.5) sarg = 1.0 / sqrt(arg) ;
                        else sarg = `Fn_Pow(arg, -MJ) ;
                        Qbs = PB * czbs * (1.0 - arg * sarg) / (1.0 - MJ) ;
                    end else begin
                        Qbs = 0.0 ;
                    end
                    if (czbsswg > 0.0) begin
                        arg = 1.0 - Vbsj / PBSWG ;
                        if (MJSWG == 0.5) sarg = 1.0 / sqrt(arg) ;
                        else sarg = `Fn_Pow(arg, -MJSWG) ;
                        Qbs = Qbs + PBSWG * czbsswg * (1.0 - arg * sarg) / (1.0 - MJSWG) ;
                    end
                end else begin
                    T1 = czbs + czbsswg ;
                    T2 = czbs * MJ / PB + czbsswg * MJSWG / PBSWG ;
                    Qbs = Vbsj * (T1 + Vbsj * 0.5 * T2) ;
                end
            end

            // Drain Bulk Junction //
            if (PD > W_diodcv) begin
                czbdsw  = CJSW * (PD - W_diodcv) ;
                czbdswg = CJSWG * W_diodcv ;
                if (Vbdj < 0.0) begin
                    if (czbd > 0.0) begin
                        arg = 1.0 - Vbdj / PB ;
                        if (MJ == 0.5) begin
                            sarg = 1.0 / sqrt(arg) ;
                        end else begin
                            sarg = `Fn_Pow(arg, -MJ) ;
                        end
                        Qbd = PB * czbd * (1.0 - arg * sarg) / (1.0 - MJ) ;
                    end else begin
                        Qbd = 0.0 ;
                    end
                    if (czbdsw > 0.0) begin
                        arg = 1.0 - Vbdj / PBSW ;
                        if (MJSW == 0.5) sarg = 1.0 / sqrt(arg) ;
                        else sarg = `Fn_Pow(arg, -MJSW) ;
                        Qbd = Qbd + PBSW * czbdsw * (1.0 - arg * sarg) / (1.0 - MJSW) ;
                    end
                    if (czbdswg > 0.0) begin
                        arg = 1.0 - Vbdj / PBSWG ;
                        if (MJSWG == 0.5) sarg = 1.0 / sqrt(arg) ;
                        else sarg = `Fn_Pow(arg, -MJSWG) ;
                        Qbd = Qbd + PBSWG * czbdswg * (1.0 - arg * sarg) / (1.0 - MJSWG) ;
                    end
                end else begin
                    T1 = czbd + czbdsw + czbdswg ;
                    T2 = czbd * MJ / PB
                          + czbdsw * MJSW / PBSW +
                          czbdswg * MJSWG / PBSWG ;
                    Qbd = Vbdj * (T1 + Vbdj * 0.5 * T2) ;
                end
            end else begin
                czbdswg = CJSWG * PD ;
                if (Vbdj < 0.0) begin
                    if (czbd > 0.0) begin
                        arg = 1.0 - Vbdj / PB ;
                        if (MJ == 0.5) sarg = 1.0 / sqrt(arg) ;
                        else sarg = `Fn_Pow(arg, -MJ) ;
                        Qbd = PB * czbd * (1.0 - arg * sarg) / (1.0 - MJ) ;
                    end else begin
                        Qbd = 0.0 ;
                    end
                    if (czbdswg > 0.0) begin
                        arg = 1.0 - Vbdj / PBSWG ;
                        if (MJSWG == 0.5) sarg = 1.0 / sqrt(arg) ;
                        else sarg = `Fn_Pow(arg, -MJSWG) ;
                        Qbd = Qbd + PBSWG * czbdswg * (1.0 - arg * sarg) / (1.0 - MJSWG) ;
                    end
                end else begin
                    T1 = czbd + czbdswg ;
                    T2 = czbd * MJ / PB + czbdswg * MJSWG / PBSWG ;
                    Qbd = Vbdj * (T1 + Vbdj * 0.5 * T2) ;
                end
            end

            // Limiting the bottom-junction depletion charges in the SOI layer //
            if (czbs > 0.0) begin
                Qbs_max = -`C_QE * `N_sub_SOI * Xp_max * AS ;
                dlt_Qbs = 1e-3 * (-Qbs_max) ;
                `Fn_SUtemp(Qbs, -Qbs, -Qbs_max, dlt_Qbs)
                Qbs = Qbs * -1 ;
            end
            if (czbd > 0.0) begin
                Qbd_max = -`C_QE * `N_sub_SOI * Xp_max * AD ;
                dlt_Qbd = 1e-3 * (-Qbd_max) ;
                `Fn_SUtemp(Qbd, -Qbd, -Qbd_max, dlt_Qbd)
                Qbd = Qbd * -1 ;
            end

        end // JunctionDiodeModel }
    end // end COBCNODE == 1

    //-----------------------------------------------------------*
    //End of PART-4. (label)
    //----------------//
    // end_of_part_4: ; //

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //PART-5: NQS Model.
    //---------------- from HiSIM 2.5.1 //
    begin : NQSmodel
        real T10, T11, T12, T1, T2;

        if (flg_nqs) begin
            if (flg_noqi == 0) begin
                T10 = DLY1 ;
                T11 = DLY2 ;
                T12 = Lch ;
                T1 = T10 * T11 * T12 * T12 ;
                T2 = Mu * VgVt * T10 + T11 * T12 * T12 + `Small ;
                tau = T1 / T2 ;
            end else begin
                tau = DLY1 + `Small ;
            end
            T1 = DLY3 ;
            taub = T1 * C_fox ;
        end
    end // NQSmodel

    //-----------------------------------------------------------*
    //End of PART-5. (label)
    //-----------------//
    //   end_of_part_5: //

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //PART-6: Noise Calculation. from HiSIM 2.5.1 2010.05.21
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

    //-----------------------------------------------------------*
    //* 1/f noise.
    //*-----------------//
    begin : OneOverFnoiseModel
        real T1, T2, T3, T4, NFalpe, NFtrpe, Cite;

        if (COFLICK != 0 && !flg_noqi) begin
            NFalpe = MKS_NFALP ;
            NFtrpe = MKS_NFTRP ;
            Cite = MKS_CIT ;
            T1 = Qn0 / `C_QE ;
            T2 = (C_fox + Qn0 / (Ps0 - Vbsz2) + Cite) * beta_inv / `C_QE ;
            T3 = -2.0E0 * Qi / `C_QE / Lch_cv / weffcv_nf - T1 ;
            if (T3 != T1) begin
                T4 = 1.0E0 / (T1 + T2) / (T3 + T2) + 2.0E0 * NFalpe * Ey * Mu / (T3 - T1)
                    * ln((T3 + T2) /(T1 + T2)) + NFalpe * Ey * Mu * NFalpe * Ey * Mu ;
            end else begin
                T4 = 1.0 / (T1 + T2) / (T3 + T2) + 2.0 * NFalpe * Ey * Mu / (T1 + T2)
                    + NFalpe * Ey * Mu * NFalpe * Ey * Mu ;
            end
            Nflic = Ids * Ids * NFtrpe / (Lch * beta * weff_nf) * T4 ;
        end else begin
            Nflic = 0.0 ;
        end
    end // OneOverFnoiseModel

    //-----------------------------------------------------------*
    //* thermal noise.
    //*-----------------//
    begin : ThermalNoiseModel
        real Eyd, T12, T7, T8, T9, T10, T11, T0,  Mu_Ave;
        real T2, T3, T4, T5, T10w, T7w;
        real gds0_h2, GAMMA;

        if (COTHRML != 0 && !flg_noqi) begin
            Eyd = (Psdl - Ps0) / Lch ;
            T12 = Muun * Eyd / 1.0e5 ;
            // note: bb = 2 (electron) ;1 (hole) //
            if (1.0e0 - `epsm10 <= BB && BB <= 1.0e0 + `epsm10) begin
                T7 = 1.0e0 ;
            end else if (2.0e0 - `epsm10 <= BB && BB <= 2.0e0 + `epsm10) begin
                T7 = T12 ;
            end else begin
                T7 = `Fn_Pow(T12, BB - 1.0e0) ;
            end
            T8 = T12 * T7 ;
            T9 = 1.0e0 + T8 ;
            T10 = `Fn_Pow(T9, (-1.0e0 / BB - 1.0e0)) ;
            T11 = T9 * T10 ;
            Mud_hoso = Muun * T11 ;
            Mu_Ave = (Mu + Mud_hoso) / 2.0 ;
            T0 = Alpha * Alpha ;
            Nthrml = weff_nf * C_fox * VgVt * Mu
                        * ((1e0 + 3e0 * Alpha + 6e0 * T0) * Mud_hoso * Mud_hoso
                           + (3e0 + 4e0 * Alpha + 3e0 * T0) * Mud_hoso * Mu + (6e0 + 3e0 * Alpha + T0) * Mu * Mu)
                          / (15e0 * Lch * (1e0 + Alpha) * Mu_Ave * Mu_Ave) ;
        end else begin
            Nthrml = 0e0 ;
        end

        //----------------------------------------------------------*
        //* induced gate noise. ( Part 2/3 )
        //*----------------------//
        if (COIGN != 0 && COTHRML != 0 && flg_ign == 1 && !flg_noqi) begin
            sqrtkusaiL = sqrt(kusaiL) ;
            T2 = VgVt + sqrtkusaiL ;
            T3 = kusai00 * kusai00 ;
            T4 = kusaiL * kusaiL ;
            T5 = 42.0e0 * kusai00 * kusaiL ;
            T5 = T5 + 4.0e0 * (T3 + T4) ;
            T5 = T5 + 20.0e0 * sqrtkusaiL * VgVt * (kusai00 + kusaiL) ;
            T10w = T2 * T2 ;
            T10 = T10w * T10w ;
            kusai_ig = T5 / (T10 * T2) ;     // Induced Gate Noise parameter //
            gds0_ign = weff_nf / Lch * Mu * C_fox ;
            gds0_h2 = gds0_ign * VgVt ;
            GAMMA = Nthrml / gds0_h2 ;
            T7w = kusai00 + 4.0e0 * VgVt * sqrtkusaiL + kusaiL ;
            // cross-correlation coefficient(= Sigid/sqrt(Sig*Sid) ) //
            crl_f = `c_sqrt_15 * kusai00L * T7w / (6.0e0 * T2 * sqrt(GAMMA * T2 * VgVt * T5)) ;
        end

    end // ThermalNoiseModel

    //-----------------------------------------------------------*
    //End of PART-6. (label)
    //-----------------//
    //   end_of_part_6: //

    //-------------------------------------------*
    //* Add IdsIBPC to Ids.  090110
    //*-----------------//
    Ids = Ids + IdsIBPC ;

    //---------------------------------------------------*
    //Constant capacitance.
    //----------------//
    if ( COBCNODE == 1 ) begin
        Cgbe = Cbtp + Cbtn ;
        if (CGBO_GIVEN) begin
            Cgbe = Cgbe - CGBO * Lgleff ;
        end
        Qgob = - Cgbe * (Vgs - Vbsp) ;
        //---------------------------------------------------*
        //Fringing capacitance.
        //----------------//
        Cfu = `C_EOX / (`C_Pi/ 2.0e0)* log1p(TPOLY / Tfox0) ;
        Cfd = Cfu * NF * ( Wgate + UC_PDBCP );
        Cfs = Cfu * NF * ( Wgate + UC_PSBCP );
        Qfd = Cfd * (Vgs - Vds) ;
        Qfs = Cfs * Vgs ;
        Qfbc = Cfu * LBT*NF * (Vgs- Vbsp);  // for body contact
        //---------------------------------------------------*
        //Add fringing charge/capacitance to overlap.
        //----------------//
        Qgod = Qgod + Qfd ;
        Qgos = Qgos + Qfs ;
        Qgob = Qgob + Qfbc ;
    end else begin
        if (CGBO_GIVEN) begin
            Cgbe = - CGBO * Lgleff ;
            Qgob = - Cgbe * (Vgs -Vbsp) ;
        end else begin
            Cgbe = 0.0 ;
            Qgob = 0.0 ;
        end
        //---------------------------------------------------*
        //Fringing capacitance.
        //----------------//
        Cf = `C_EOX / (`C_Pi / 2.0e0) * Wgate * NF * log1p(TPOLY / Tfox0) ;
        Cfd = Cf ;
        Cfs = Cf ;
        Qfd = Cfd * (Vgs - Vds) ;
        Qfs = Cfs * Vgs ;
        //---------------------------------------------------*
        //Add fringing charge/capacitance to overlap.
        //----------------//
        Qgod = Qgod + Qfd ;
        Qgos = Qgos + Qfs ;
    end

    //-----------------------------------------------------------*
    //Assign outputs.
    //----------------//

    //---------------------------------------------------*
    //Channel current and conductances.
    //----------------//
    idse = Mfactor * Ids ;


    //---------------------------------------------------*
    //Intrinsic charges/capacitances.
    //----------------//
    if (flg_nqs) begin // for flat handling of NQS: the NQS charges are added
        qde = 0.0 ;
        qge = 0.0 ;
        if ( COBCNODE == 1 ) begin
            qse = 0.0 ;
            Xd = Qdrat ;
            Qb_qs = Mfactor * Qb ;
            Qi_qs = Mfactor * Qi ;
        end else begin
            qbe = 0.0 ;
            Qb_qs = Mfactor * Qsub ;
            Qd_qs = Mfactor * (     Qd + Qd_FB) ;
            Qs_qs = Mfactor * (Qi - Qd + Qs_FB) ;
        end
    end else begin             // QS //
        if ( COBCNODE == 1 ) begin
            qge = Mfactor * (-Qb - Qi ) ;
            qde = Mfactor * (     Qd )   ;
            qse = Mfactor * (Qi - Qd )   ;
        end else begin
            qge = Mfactor * (-Qsub - Qi - Qs_FB - Qd_FB) ;
            qde = Mfactor * (     Qd + Qd_FB) ;
            qse = Mfactor * (Qi - Qd + Qs_FB) ;
        end
    end


    //---------------------------------------------------*
    //Overlap capacitances.
    //----------------//

    //---------------------------------------------------*
    //Lateral-field-induced capacitance.
    //----------------//
    begin : LateralFieldInducedCapacitance
        real Pslk, T1, T10, T3, T2;

        if (XQY == 0) begin
            Qy = 0e0 ;
        end else begin
            Pslk = Ec * Leff + Ps0 ;
            if (Pslk > Psdl) begin
                Pslk = Psdl ;
            end
            T1 = Aclm * (Vds + Ps0) + (1.0e0 - Aclm) * Pslk ;
            T10 = sqrt(2.0e0 * `C_ESI / q_Nsub) ;
            T3 = T10 * 1.3 ;
            T2 = `C_ESI * weffcv_nf * T3 ;
            Qy = ((Ps0 + Vds - T1) / XQY - Ec) * T2 ;
        end
        if ( XQY1 != 0.0 ) begin
            Qy = Qy + cqyb0 * Vbsp ;
        end
    end // LateralFieldInducedCapacitance

    //---------------------------------------------------*
    //Add S/D overlap charges/capacitances to intrinsic ones.
    //- NOTE: This function depends on coadov, a control option.
    //----------------//
    if (COADOV == 1) begin
        if ( COBCNODE == 1 ) begin
            q_bt_ge = - Qbody_bt_p_sus - Qbody_bt_p_sud - Qbody_bt_n_sus - Qbody_bt_n_sud ;
            q_bt_de =   Qbody_bt_p_iud + Qbody_bt_n_iud ;
            q_bt_se =   Qbody_bt_p_ius + Qbody_bt_n_ius ;
            qge = qge + Mfactor * ( Qgod + Qgos + Qgob - Qy - Qovs - Qovd + q_bt_ge ) ;
            qde = qde + Mfactor * (-Qgod + Qy + QbdLD + q_bt_de ) ;
            qse = qse + Mfactor * (-Qgos      + QbsLD + q_bt_se ) ;
        end else begin
            qge = qge + Mfactor * ( Qgod + Qgos + Qgob - Qy - Qovs - Qovd) ;
            qde = qde + Mfactor * (-Qgod + Qy + QbdLD) ;
            qse = qse + Mfactor * (-Qgos      + QbsLD) ;
        end
    end

    //---------------------------------------------------*
    //Von, Vdsat,
    //----------------//
    vone = Vth ;
    vdsate = Vdsat ;

    if ( COBCNODE == 1 ) begin
        //Junction diode.
        //----------------//
        ibsb = Mfactor * Ibs ;
        ibdb = Mfactor * Ibd ;

        qbd_s0 = Mfactor * Qbd ;
        qbs_s0 = Mfactor * Qbs ;
    end else begin
        ibsb   = 0.0 ; ibdb   = 0.0 ;
        qbd_s0 = 0.0 ; qbs_s0 = 0.0 ;
    end

    //---------------------------------------------------*
    //Substrate/gate/leak currents.
    //----------------//
    if (COISUB != 1) begin
        isube = 0.0 ;
    end else begin
        isube = Mfactor * Isub ;
    end

    igbe = Mfactor * -Igb ;
    if (mode == `HiSIM_NORMAL_MODE) begin
        igde = Mfactor * (GLPART1 * Igate - Igd) ;
    end else begin
        igde = Mfactor * ((1.0 - GLPART1) * Igate - Igs) ;
    end
    if (mode == `HiSIM_NORMAL_MODE) begin
        igse = Mfactor * ((1.0 - GLPART1) * Igate - Igs) ;
    end else begin
        igse = Mfactor * (GLPART1 * Igate - Igd) ;

    end
    igidle = (mode == `HiSIM_NORMAL_MODE) ? Mfactor * Igidl : Mfactor * Igisl ;
    igisle = (mode == `HiSIM_NORMAL_MODE) ? Mfactor * Igisl : Mfactor * Igidl ;

    //-----------------------------------------------------------*
    //* Noise.
    //*-----------------//
    noiflick = Mfactor * Nflic ;
    noithrml = Mfactor * Nthrml ;

    cgdbd = ddx(qge,V(dp)) ; cgdbd = TYPE * cgdbd ;
    cgsbd = ddx(qge,V(sp)) ; cgsbd = TYPE * cgsbd ;
    cgsb  = (mode > 0) ? cgsbd : cgdbd ;

    //----------------------------------------------------------*
    //* induced gate noise. ( Part 3/3 )
    //*---------------------- from HiSIM 2 //
    begin : InducedGateNoise_3of3
        real T0, T1, Nign0, MuModA, MuModB,correct_w1;

        if (COIGN != 0 && COTHRML != 0 && flg_ign == 1 && !flg_noqi) begin
            T0 = `C_fox_Small * C_fox * weffcv_nf * Leff_cv ;
            T1 = cgsb / Mfactor ;
            Nign0 = `c_16o135 * `C_QE * beta_inv * T1 * T1 / gds0_ign ;
            if (kusai00L > `epsm10 && Vds > `epsm10) begin
                MuModA = Muun / Mu ;
                MuModB = (Muun / Mud_hoso - MuModA) / Vds ;
                correct_w1 = MuModA + `C_2o3 * MuModB * (kusai00 + VgVt * sqrtkusaiL + kusaiL)
                    / (VgVt + sqrtkusaiL) ;
            end else begin
                correct_w1 = Muun / Mud_hoso ;
            end
            noiigate = Mfactor * Nign0 * kusai_ig * correct_w1 ;
            noicross = crl_f ;
            noiigate = ( - T1 > T0 && noiigate > 0 ) ? noiigate : 0.0 ;
            noicross = ( - T1 > T0 ) ? noicross : 0.0 ;
        end else begin
            noiigate = 0.0e0 ;
            noicross = 0.0e0 ;
        end
    end // InducedGateNoise_3of3

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //* PART of New Drift Resistance Model.
    //*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
    Rdde = 0.0 ;
    Rsde = 0.0 ;
    drainConductance = 0.0 ;
    sourceConductance = 0.0 ;
    if ( CORS == 1 ) begin
        rdmod = 1;
        begin : HSMHV_eval_rdrifrs
`include "HSMSOI_eval_rdrift.inc"
        end //  HSMHV_eval_rdrifrs
        Rsde = Rsd / Mfactor ;
        sourceConductance = Conductance ;
    end // if( CORS == 1 )
    if ( CORD == 1 ) begin
        rdmod = 2;
        begin : HSMHV_eval_rdrifrd
`include "HSMSOI_eval_rdrift.inc"
        end //  HSMHV_eval_rdrifrd
        Rdde = Rsd / Mfactor ;
        drainConductance = Conductance ;
    end // if( CORD == 1 )
    //-----------------------------------------------------------*
    //* End of New Drift Resistance Model.
    //*-----------------//


    // *-------------------------------------------------------------
    // * Actually load the device currents                 hsmsoild.c
    // *

    // in case of nqs: construct static contributions to the nqs equations(Iqi_nqs ; Iqb_nqs)       //
    //   and nqs charge contributions to inner drain ; gate and source node(Qd_nqs ; Qg_nqs ; Qs_nqs) //

    if ( COBCNODE == 1 ) begin
        if (flg_nqs) begin
            // .. tau ; taub must be > 0 //
            if (tau  < `tau_min) tau  = `tau_min ;
            if (taub < `tau_min) taub = `tau_min ;
            //
            Qdrat = (mode == 1) ? Xd : (1.0 - Xd) ;
            Iqi_nqs = (Qi_nqs - Qi_qs) / tau ;
            Iqb_nqs = (Qb_nqs - Qb_qs) / taub ;
            //
            Qd_nqs =  Qi_nqs * Qdrat + q_bt_se ;
            Qs_nqs =  Qi_nqs * (1.0 - Qdrat) + q_bt_se ;
            Qg_nqs = -Qi_nqs - Qb_nqs + q_bt_ge ;
        end else begin
            Iqi_nqs = 0.0 ; Iqb_nqs = 0.0 ;
            Qd_nqs  = 0.0 ; Qs_nqs  = 0.0 ; Qg_nqs = 0.0 ;
            Qb_nqs  = 0.0 ;
        end
    end else begin
        if (flg_nqs) begin
            // .. tau ; taub must be > 0 //
            if (tau  < `tau_min) tau  = `tau_min ;
            if (taub < `tau_min) taub = `tau_min ;
            Iqd_nqs = (Qd_nqs - Qd_qs) / tau ;
            Iqs_nqs = (Qs_nqs - Qs_qs) / tau ;
            Iqb_nqs = (Qb_nqs - Qb_qs) / taub ;
            Iqb_nqs = 0.0 ;
            Qg_nqs  = -Qd_nqs -Qs_nqs -Qb_nqs ;
        end else begin
            Iqd_nqs = 0.0 ; Iqs_nqs = 0.0 ; Iqb_nqs = 0.0 ;
            Qd_nqs  = 0.0 ;  Qs_nqs = 0.0 ;  Qg_nqs = 0.0 ;
            Qb_nqs  = 0.0 ;
        end
    end


    //----------------------------------------------new////
    Rdd = Rdde ;
    Rsd = Rsde ;
    if (mode == 1) begin
        Ids = idse ;
        Isub = isube ;
        Isubs = 0.0 ;
        Qg = qge + Qg_nqs;
        Qd = qde + Qd_nqs;
        Qs = qse + Qs_nqs;
        qbe = -(qge + qde + qse ) ;
        Qb = qbe + Qb_nqs;
    end else begin
        Ids = -idse ;
        Isubs = isube ;
        Isub = 0.0 ;
        Qg = qge + Qg_nqs;
        Qd = qse + Qs_nqs;
        Qs = qde + Qd_nqs;
        qbe = -(qge + qde + qse ) ;
        Qb = qbe + Qb_nqs ;
    end

    //---------------------------------------------------*
    // Igd, Igs, Igb, Igidl
    //*-----------------//
    Igd = igde ;
    Igs = igse ;
    Igb = igbe ;
    Igidl = igidle ;
    Igisl = igisle ;

    if ( COBCNODE == 1 ) begin
        //---------------------------------------------------*
        //* Junction diode.
        //*-----------------//
        Ibd = ibdb ;
        Qbd = qbd_s0 ;
        Ibs = ibsb ;
        Qbs = qbs_s0 ;
    end
    //---------------------------------------------------*
    //* Power current.
    //*-----------------//
    if (COSELFHEAT == 1 && MKS_RTH0 > 0.0) begin
        Rpower = Ids * Vds ;
        Cthe = cth ;
        Gth = 1.0 / rth ;
    end else begin
        Rpower = 0.0 ;
        Cthe = 0.0 ;
        Gth = 0.0 ;
    end


    //--print Op points--------*/
    idse    =  Ids  ;
    Isuba   =  TYPE * (Isub + Isubs) ;

    ggds    =  ddx(idse,V(dp)) ;  ggds  = TYPE * ggds  ;
    ggdss   =  ddx(idse,V(sp)) ;  ggdss = TYPE * ggdss ;

    if (mode != `HiSIM_NORMAL_MODE) begin
        ggds    = ggdss ;
    end

    ggm     =  ddx(idse,V(gp)) ;  ggm   = TYPE * ggm   ;
    ggmbs   =  ddx(idse,V(bp)) ;  ggmbs = TYPE * ggmbs ;
    ggmt    =  ddx(idse,V(temp)) ;

    cggbd   =  ddx(Qg,V(gp)) ;  cggbd = TYPE * cggbd ;
    cgdbd   =  ddx(Qg,V(dp)) ;  cgdbd = TYPE * cgdbd ;
    cgsbd   =  ddx(Qg,V(sp)) ;  cgsbd = TYPE * cgsbd ;
    cgbbd   =  ddx(Qg,V(bp)) ;  cgbbd = TYPE * cgbbd ;

    cdgbd   =  ddx(Qd,V(gp)) ;  cdgbd = TYPE * cdgbd ;
    cddbd   =  ddx(Qd,V(dp)) ;  cddbd = TYPE * cddbd ;
    cdsbd   =  ddx(Qd,V(sp)) ;  cdsbd = TYPE * cdsbd ;
    cdbbd   =  ddx(Qd,V(bp)) ;  cdbbd = TYPE * cdbbd ;

    cbgbd   =  ddx(Qb,V(gp)) ;  cbgbd = TYPE * cbgbd ;
    cbdbd   =  ddx(Qb,V(dp)) ;  cbdbd = TYPE * cbdbd ;
    cbsbd   =  ddx(Qb,V(sp)) ;  cbsbd = TYPE * cbsbd ;
    cbbbd   =  ddx(Qb,V(bp)) ;  cbbbd = TYPE * cbbbd ;

    csgbd   =  ddx(Qs,V(gp)) ;  csgbd = TYPE * csgbd ;
    csdbd   =  ddx(Qs,V(dp)) ;  csdbd = TYPE * csdbd ;
    cssbd   =  ddx(Qs,V(sp)) ;  cssbd = TYPE * cssbd ;
    csbbd   =  ddx(Qs,V(bp)) ;  csbbd = TYPE * csbbd ;

    if ( COBCNODE == 1 ) begin
        ibdb    =  TYPE * Ibd  ;
        ibsb    =  TYPE * Ibs  ;

        Gbd     =  ddx(ibdb,V(bp)) ;
        Gbs     =  ddx(ibsb,V(bp)) ;

        capbdb  =  ddx(Qbd,V(bp)) ;
        capbsb  =  ddx(Qbs,V(bp)) ;
    end else begin
        capbdb = 0.0 ; capbsb = 0.0 ;
    end

    // print all outputs ------------VV //
    begin : Print_INFO
        real ggbgs , ggbds , ggbbs ;

        ggbgs   =  ddx(Isuba,V(gp)) ;
        ggbds   =  ddx(Isuba,V(dp)) ;
        ggbbs   =  ddx(Isuba,V(bp)) ;

        // print all outputs ------------VV //
        if ( INFO >= 8 ) begin
            $write( "vone,vdsate = %18.10e %18.10e \n" , vone, vdsate ) ;
            $write( "Ids       = %18.10e \n" , idse ) ;
            $write( "gds       = %18.10e \n" , ggds ) ;
            $write( "gm        = %18.10e \n" , ggm  ) ;
            $write( "gmbs      = %18.10e \n" , ggmbs) ;
            $write( "gmt       = %18.10e \n" , ggmt) ;
            $write( "Qg        = %18.10e \n" , qge ) ;
            $write( "Qd        = %18.10e \n" , qde ) ;
            $write( "Qs        = %18.10e \n" , qse  ) ;
            $write( "Qfd,Cfd   = %18.10e %18.10e \n" , Qfd, Cfd ) ;
            $write( "Qfs,Cfs   = %18.10e %18.10e \n" , Qfs, Cfs ) ;
            $write( "cggb      = %18.10e \n" , cggbd ) ;
            $write( "cgsb      = %18.10e \n" , cgsbd ) ;
            $write( "cgdb      = %18.10e \n" , cgdbd ) ;
            $write( "cgbb      = %18.10e \n" , cgbbd ) ;
            $write( "cbgb      = %18.10e \n" , cbgbd ) ;
            $write( "cbsb      = %18.10e \n" , cbsbd ) ;
            $write( "cbdb      = %18.10e \n" , cbdbd ) ;
            $write( "cbbb      = %18.10e \n" , cbbbd ) ;
            $write( "cdgb      = %18.10e \n" , cdgbd ) ;
            $write( "cdsb      = %18.10e \n" , cdsbd ) ;
            $write( "cddb      = %18.10e \n" , cddbd ) ;
            $write( "cdbb      = %18.10e \n" , cdbbd ) ;
            if ( COBCNODE == 1 ) begin
                $write( "Ibd,Ibs   = %18.10e %18.10e\n" , ibdb , ibsb ) ;
                $write( "Gbd,Gbs   = %18.10e %18.10e\n" , Gbd  , Gbs  ) ;
                $write( "Cbd,Cbs   = %18.10e %18.10e\n" , capbdb , capbsb ) ;
                $write( "Qbd,Qbs   = %18.10e %18.10e\n" , qbd_s0 , qbs_s0 ) ;
            end
            $write( "Isub      = %18.10e \n" , Isuba ) ;
            $write( "gbgs      = %18.10e \n" , ggbgs ) ;
            $write( "gbds      = %18.10e \n" , ggbds ) ;
            $write( "gbbs      = %18.10e \n" , ggbbs ) ;
        end
        // print all outputs ------------AA //
    end // Print_INFO


    // Noise coeff. calculation
    whi_noise = 4.0 * `C_KB* TTEMP * `Kwhite ;
    // Drain Currents
    I(BRdpsp) <+  TYPE * Ids ;

    // Gate Leakage Currents
    if (COIIGS == 1) begin
        I(BRgpsp) <+  TYPE * Igs ;
        I(BRgpdp) <+  TYPE * Igd ;
        I(BRgpbp) <+  TYPE * Igb ;
    end

    // Source & Drain Resistance Currents
    if (CORS) I(BRsps ) <+ V(BRsps ) / Rsd; else V(BRsps ) <+ 0.0 ;
    if (CORD) I(BRddp ) <+ V(BRddp ) / Rdd; else V(BRddp ) <+ 0.0 ;

    // Inner Capacitance Currents
    I(BRgpsp) <+  TYPE * ddt(Qg) ;
    I(BRdpsp) <+  TYPE * ddt(Qd) ;
    I(BRbpsp) <+  TYPE * ddt(Qb) ;

    // Noise Currents
    Qdrat = Qdrat_noi ;
    I(BRdpsp) <+ flicker_noise(noiflick * `Kflic , FALPH  , "iflick") ;
    // Thermal & IG Noise
    sid    = whi_noise * noithrml;
    ci     = noicross;
    sigrat = (sid > 0.0 && noiigate > 0.0) ? sqrt(noiigate/sid) : 0.0 ;
    I(n)     <+ 1*V(n) ;
    I(n)     <+ white_noise(sid) ;
    I(BRdpsp) <+ white_noise((1.0-ci*ci)*sid) ;
    I(BRdpsp) <+ ci*V(n) ;
    sigrat_s  = (mode > 0) ? sigrat*(1-Qdrat) : sigrat*   Qdrat ;
    sigrat_d  = (mode > 0) ? sigrat*   Qdrat  : sigrat*(1-Qdrat) ;
    I(BRgpsp) <+ ddt(V(n)*sigrat_s) ;
    I(BRgpdp) <+ ddt(V(n)*sigrat_d) ;
    //
    if (CORS) I(BRsps ) <+ white_noise(whi_noise * sourceConductance , "isource");
    if (CORD) I(BRddp ) <+ white_noise(whi_noise * drainConductance  , "idrain");

    //   Shot Noise
`define C_QE2     2.0 * `C_QE      //
    if (COIIGS == 1) begin
        I(BRgpdp) <+ white_noise(`C_QE2 * Igd , "iigd") ;
        I(BRgpsp) <+ white_noise(`C_QE2 * Igs , "iigs") ;
        I(BRgpbp) <+ white_noise(`C_QE2 * Igb , "iigb") ;
    end

    // Gate Resistance Currents
    if ( CORG ) begin
        I(BRggp) <+ grg * V(BRggp) ;
    end else begin
        V(BRggp) <+ 0.0 ;
    end

    // Thermal Node Currents with thermal dissipation
    if (COSELFHEAT > 0 && RTH0 > 0.0) begin //MKS_RTH0
        Itemp = Rpower ;
        I(temp) <+ V(temp) * Gth ;
        I(temp) <+ - Itemp ;
        I(temp) <+ V(temp) * `Gnqsmin ;
        I(temp) <+ ddt(Cthe*V(temp)) ;
    end else begin
        I(temp) <+ V(temp)*1e4 ;
    end

    if ( COBCNODE == 1 ) begin
        // Substrate ,  GIDL and GISL Currents
        I(BRdpbp) <+  TYPE * (Igidl + Isub ) ;
        I(BRspbp) <+  TYPE * (Igisl + Isubs) ;
        // Junction Diode Currents
        I(BRbpsp) <+  TYPE * (Ibs + ddt(Qbs)) ;
        I(BRbpdp) <+  TYPE * (Ibd + ddt(Qbd)) ;
        // Substrate Currents
        if (CORBULK) I(BRbcbp) <+ V(BRbcbp) / Rbulk; else V(BRbcbp) <+ 0.0 ;
        // NQS Node Currents
        if (CONQS) begin
            I(nqs_qi) <+ Iqi_nqs ;
            I(nqs_qb) <+ Iqb_nqs ;
            I(nqs_qi) <+ V(nqs_qi)* `Gnqsmin;
            I(nqs_qb) <+ V(nqs_qb)* `Gnqsmin;
            I(nqs_qi) <+ ddt( `NQS_CAP * V(nqs_qi) ) ;
            I(nqs_qb) <+ ddt( `NQS_CAP * V(nqs_qb) ) ;
        end else begin
            V(nqs_qi) <+ 0.0 ;
            V(nqs_qb) <+ 0.0 ;
        end
    end else begin
        //  Substrate ,  GIDL and GISL Currents
        I(BRdpsp)  <+  TYPE * (Igidl + Isub ) ;
        I(BRspdp)  <+  TYPE * (Igisl + Isubs) ;
        // Collapsing Internal Substrate Node
        V(BRebp ) <+  0 ;
        // QHS Node Currents
        if (COHIST) begin
            I(nqs_qhs) <+ Iqh_nqs ;
            I(nqs_qhs) <+ V(nqs_qhs)* `Gnqsmin;
            I(nqs_qhs) <+ ddt( `NQS_CAP * V(nqs_qhs) ) ;
        end else begin
            V(nqs_qhs) <+ 0.0 ;
        end
        if (CONQS) begin
            I(nqs_qd) <+ Iqd_nqs ;
            I(nqs_qs) <+ Iqs_nqs ;
            I(nqs_qb) <+ Iqb_nqs ;
            I(nqs_qd) <+ V(nqs_qd)* `Gnqsmin;
            I(nqs_qs) <+ V(nqs_qs)* `Gnqsmin;
            I(nqs_qb) <+ V(nqs_qb)* `Gnqsmin;
            I(nqs_qd) <+ ddt( `NQS_CAP * V(nqs_qd) ) ;
            I(nqs_qs) <+ ddt( `NQS_CAP * V(nqs_qs) ) ;
            I(nqs_qb) <+ ddt( `NQS_CAP * V(nqs_qb) ) ;
        end else begin
            V(nqs_qd) <+ 0.0 ;
            V(nqs_qs) <+ 0.0 ;
            V(nqs_qb) <+ 0.0 ;
        end
    end

    // end // HSMSOI_model
    //================ End of executable code.=================//

end
