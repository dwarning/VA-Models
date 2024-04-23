<Qucs Schematic 24.2.1>
<Properties>
  <View=-231,-30,1787,1161,0.59026,0,0>
  <Grid=10,10,1>
  <DataSet=npn13G2_spar_NF_vbe.dat>
  <DataDisplay=npn13G2_spar_NF_vbe.dpl>
  <OpenDisplay=0>
  <Script=Test_SYZ.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Drawn By:>
  <FrameText2=Date:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <SpiceInclude SpiceInclude1 1 60 280 -33 16 0 0 "../Modelcards/SG13G2_hbt_woStatistics.hsp.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.SP SP1 1 30 80 0 70 0 0 "lin" 1 "2 GHz" 1 "26 GHz" 1 "241" 1 "yes" 1 "1" 0 "2" 0 "no" 0 "no" 0>
  <NutmegEq NutmegEq1 1 230 90 -30 18 0 0 "sp" 1 "gain=db((S_2_1))" 1>
  <GND * 1 510 310 0 0 0 0>
  <GND * 1 770 310 0 0 0 0>
  <GND * 1 610 310 0 0 0 0>
  <GND * 1 420 310 0 0 0 0>
  <Vdc Vbe 1 510 280 18 -26 0 1 "Vbe" 1>
  <Pac P1 1 420 280 18 -26 0 1 "1" 1 "50 Ohm" 1 "0 dBm" 0 "1 GHz" 0 "26.85" 0 "true" 0>
  <Pac P2 1 770 280 18 -26 0 1 "2" 1 "50 Ohm" 1 "0 dBm" 0 "1 GHz" 0 "26.85" 0 "true" 0>
  <BiasT X1 1 510 220 -26 34 0 0 "1 H" 0 "1 F" 0>
  <SpicePar SpicePar2 1 850 40 -28 16 0 0 "Vbe=0.78" 1 "Vcb=0.25" 1>
  <.SW SW1 1 820 140 0 51 0 0 "SP1" 1 "lin" 1 "Vbe" 1 "0.78" 1 "0.96" 1 "10" 1 "false" 0>
  <BiasT X2 1 700 190 -26 34 1 2 "1 H" 0 "1 F" 0>
  <GND * 1 700 310 0 0 0 0>
  <Vdc Vce 1 700 270 18 -26 0 1 "Vbe+Vcb" 1>
  <BJT_SPICE Q1 1 610 220 -26 34 0 0 "4" 1 "npn" 1 "X" 1 "npn13G2 nx=8" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM1 1 370 40 0 51 0 0 "\npre_osdi vbic_1p3.osdi\n" 1 "" 0 "" 0>
</Components>
<Wires>
  <420 220 480 220 "" 0 0 0 "">
  <420 220 420 250 "" 0 0 0 "">
  <610 270 610 310 "" 0 0 0 "">
  <770 190 770 250 "" 0 0 0 "">
  <730 190 770 190 "" 0 0 0 "">
  <700 300 700 310 "" 0 0 0 "">
  <700 220 700 240 "" 0 0 0 "">
  <610 270 640 270 "" 0 0 0 "">
  <640 220 640 270 "" 0 0 0 "">
  <610 250 610 270 "" 0 0 0 "">
  <540 220 580 220 "B" 550 190 8 "">
  <610 190 670 190 "C" 630 160 15 "">
</Wires>
<Diagrams>
  <Rect 42 732 611 333 3 #c0c0c0 1 00 1 1e+09 1 3e+10 1 0 1 2 1 -1 1 1 315 0 225 1 0 0 "" "" "">
	<"ngspice/ac.v(nfmin)" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 40 1120 618 330 3 #c0c0c0 1 00 1 2e+09 2e+09 2.6e+10 1 14.3003 5 45 1 -1 0.5 1 315 0 225 1 0 0 "" "" "">
	<"ngspice/ac.v(rn)" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 710 1120 618 330 3 #c0c0c0 1 00 1 2e+09 2e+09 2.6e+10 0 0 0.2 1 1 -1 0.5 1 315 0 225 1 0 0 "" "" "">
	<"ngspice/ac.v(sopt)" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 712 744 614 345 3 #c0c0c0 1 00 1 3e+09 1 3e+10 1 1.55404 2 11.3037 1 -1 0.5 1 315 0 225 1 0 0 "" "" "">
	<"ngspice/ac.v(nf)" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 1087 337 447 277 3 #c0c0c0 1 00 1 1e+09 1 3e+10 1 2.44756 5 26.7797 1 -1 0.5 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.gain" #0000ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
  <Text 30 10 16 #ed333b 0 "S-Param">
</Paintings>
