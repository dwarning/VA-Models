<Qucs Schematic 24.2.1>
<Properties>
  <View=-61,-20,1737,1041,0.662582,0,0>
  <Grid=10,10,1>
  <DataSet=npn_spar_NF_Vbe.dat>
  <DataDisplay=npn_spar_NF_Vbe.dpl>
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
  <GND * 1 660 310 0 0 0 0>
  <BiasT X1 1 660 220 -26 34 0 0 "1 H" 0 "1 F" 0>
  <GND * 1 830 310 0 0 0 0>
  <GND * 1 920 310 0 0 0 0>
  <GND * 1 760 310 0 0 0 0>
  <BiasT X2 1 830 190 -26 34 1 2 "1 H" 0 "1 F" 0>
  <GND * 1 570 310 0 0 0 0>
  <NutmegEq NutmegEq1 1 250 90 -30 18 0 0 "sp" 1 "gain=db((S_2_1))" 1 "Cbe=imag(v(Y_1_1)+v(Y_1_2))/(2*pi*frequency)" 1 "Cbc=-imag(v(Y_1_2))/(2*pi*frequency)" 1>
  <Vdc Vbe 1 660 280 18 -26 0 1 "Vbe" 1>
  <Vdc Vce 1 830 270 18 -26 0 1 "Vce" 1>
  <.SP SP1 1 40 80 0 70 0 0 "log" 1 "1 Hz" 1 "100 GHz" 1 "111" 1 "yes" 1 "1" 0 "2" 0 "no" 0 "no" 0>
  <Pac P1 1 570 280 18 -26 0 1 "1" 1 "50 Ohm" 1 "0 dBm" 0 "1 GHz" 0 "26.85" 0 "true" 0>
  <Pac P2 1 920 280 18 -26 0 1 "2" 1 "50 Ohm" 1 "0 dBm" 0 "1 GHz" 0 "26.85" 0 "true" 0>
  <SpicePar SpicePar2 1 1000 40 -28 16 0 0 "Vbe=0.9" 1 "Vce=1.2" 1>
  <.SW SW1 1 980 140 0 51 0 0 "SP1" 1 "list" 1 "Vbe" 1 "0.8" 0 "1.0" 0 "[0.85; 0.9; 1.0]" 1 "false" 0>
  <BJT_SPICE Q1 1 760 220 -26 34 0 0 "4" 1 "npn" 1 "N" 1 "hicumL2va" 1 "" 0 "" 0 "" 0 "" 0>
  <SpiceInclude SpiceInclude1 1 70 280 -33 16 0 0 "../Modelcards/examples.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM1 1 260 250 0 51 0 0 "\npre_osdi hicumL2.osdi" 1 "" 0 "custom#ac1#.plot;custom#ac1#.print" 0>
</Components>
<Wires>
  <830 300 830 310 "" 0 0 0 "">
  <830 220 830 240 "" 0 0 0 "">
  <920 190 920 250 "" 0 0 0 "">
  <860 190 920 190 "" 0 0 0 "">
  <690 220 730 220 "" 0 0 0 "">
  <760 190 800 190 "" 0 0 0 "">
  <570 220 630 220 "" 0 0 0 "">
  <570 220 570 250 "" 0 0 0 "">
  <790 220 790 270 "" 0 0 0 "">
  <760 250 760 270 "" 0 0 0 "">
  <760 270 760 310 "" 0 0 0 "">
  <760 270 790 270 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 40 540 240 160 3 #c0c0c0 1 00 1 1 1 1e+11 1 0.539219 0.2 1.03443 1 -1 1 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.v(s_1_1)" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 330 540 240 160 3 #c0c0c0 1 00 1 0 2e+10 1e+11 1 -0.00657903 0.05 0.0732531 1 -1 1 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.v(s_1_2)" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 600 540 240 160 3 #c0c0c0 1 00 1 0 2e+09 1e+10 1 -0.209434 2 4.44167 1 -1 1 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.v(s_2_1)" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 870 540 240 160 3 #c0c0c0 1 00 1 -1 0.5 1 1 -1 1 1 1 -1 1 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.v(s_2_2)" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 40 770 240 160 3 #c0c0c0 1 00 1 0 2e+09 1e+10 1 3e-05 1 3 1 -1 1 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.v(y_1_1)" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 320 770 240 160 3 #c0c0c0 1 00 1 0 2e+09 1e+10 1 1e-06 1 0.1 1 -1 1 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.v(y_1_2)" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 590 770 240 160 3 #c0c0c0 1 00 1 0 2e+09 1e+10 1 0.03 1 1 1 -1 1 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.v(y_2_1)" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 40 1000 240 160 3 #c0c0c0 1 00 1 0 2e+09 1e+10 1 0.3 1 10000 1 -1 1 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.v(z_1_1)" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 320 1000 240 160 3 #c0c0c0 1 00 1 -1 0.5 1 1 -1 1 1 1 -1 1 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.v(z_1_2)" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 870 1000 240 160 3 #c0c0c0 1 00 1 -1 0.5 1 1 -1 1 1 1 -1 1 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.v(z_2_2)" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 590 1000 240 160 3 #c0c0c0 1 00 1 -1 0.5 1 1 -1 1 1 1 -1 1 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.v(z_2_1)" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 870 770 240 160 3 #c0c0c0 1 00 1 0 2e+09 1e+10 1 0.0003 1 0.3 1 -1 1 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.v(y_2_2)" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 1200 1000 240 160 3 #c0c0c0 1 10 1 0 2e+10 1e+11 1 8 2 12.3436 1 -1 1 1 315 0 225 1 0 0 "" "" "">
	<"ngspice/ac.v(rn)" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 1202 769 240 160 3 #c0c0c0 1 10 1 0 2e+10 1e+11 1 1.46849 2 6 1 -1 1 1 315 0 225 1 0 0 "" "" "">
	<"ngspice/ac.v(nfmin)" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 1197 307 447 277 3 #c0c0c0 1 10 1 0 1e+09 1e+10 1 -17.5155 5 15 1 -1 0.5 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.gain" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 1202 564 442 215 3 #c0c0c0 1 10 1 1 1 1e+11 0 0 1 10 1 -1 0.5 1 315 0 225 1 0 0 "" "" "">
	<"ngspice/ac.v(nf)" #0000ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
  <Text 40 20 16 #ed333b 0 "S-Param">
</Paintings>
