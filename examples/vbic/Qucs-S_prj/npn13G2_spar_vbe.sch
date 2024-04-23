<Qucs Schematic 24.2.1>
<Properties>
  <View=-32,-50,1485,845,0.785102,0,0>
  <Grid=10,10,1>
  <DataSet=npn13G2_spar_vbe.dat>
  <DataDisplay=npn13G2_spar_vbe.dpl>
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
  <NutmegEq NutmegEq1 1 170 190 -30 18 0 0 "sp" 1 "gain=db((S_2_1))" 1 "Cbe=imag(v(Y_1_1)+v(Y_1_2))/(2*pi*frequency)" 1 "Cbc=-imag(v(Y_1_2))/(2*pi*frequency)" 1>
  <.SP SP1 1 20 80 0 71 0 0 "log" 1 "100 MHz" 1 "65 GHz" 1 "29" 1 "no" 1 "1" 0 "2" 0 "no" 0 "no" 0>
  <NutmegEq NutmegEq2 1 40 650 -27 16 0 0 "sp" 1 "S11_dB=dB(s_1_1)" 1 "S12_dB=dB(s_1_2)" 1 "S21_dB=dB(s_2_1)" 1 "S22_dB=dB(s_2_2)" 1>
  <Pac P3 1 300 710 -93 -26 1 1 "3" 1 "50 Ohm" 1 "0 dBm" 0 "1 GHz" 0 "26.85" 0 "true" 0>
  <Pac P4 1 480 710 18 -26 0 1 "4" 1 "50 Ohm" 1 "0 dBm" 0 "1 GHz" 0 "26.85" 0 "true" 0>
  <GND * 5 390 700 0 0 0 0>
  <GND * 5 300 750 0 0 0 0>
  <GND * 5 480 750 0 0 0 0>
  <.SW SW1 1 270 30 0 51 0 0 "SP1" 1 "list" 1 "Vbe" 1 "0.88" 0 "0.96" 0 "[0.78; 0.88; 0.96]" 1 "false" 0>
  <SPfile X3 1 390 660 -26 -59 0 0 "spar-vbe_088_vcb_025.s2p" 1 "rectangular" 0 "linear" 0 "open" 0 "2" 0>
  <GND * 1 590 280 0 0 0 0>
  <BiasT X1 1 590 190 -26 34 0 0 "1 H" 0 "1 F" 0>
  <GND * 1 690 280 0 0 0 0>
  <GND * 1 500 280 0 0 0 0>
  <Pac P1 1 500 250 18 -26 0 1 "1" 1 "50 Ohm" 1 "0 dBm" 0 "1 MHz" 0 "26.85" 0 "true" 0>
  <Vdc Vbe 1 590 250 18 -26 0 1 "Vbe" 1>
  <GND * 1 900 280 0 0 0 0>
  <Pac P2 1 900 250 18 -26 0 1 "2" 1 "50 Ohm" 1 "0 dBm" 0 "1 MHz" 0 "26.85" 0 "true" 0>
  <BiasT X2 1 810 160 -26 34 1 2 "1 H" 0 "1 F" 0>
  <GND * 1 810 280 0 0 0 0>
  <Vdc Vce 1 810 240 18 -26 0 1 "Vbe+Vcb" 1>
  <SpicePar SpicePar2 1 550 40 -28 16 0 0 "Vbe=0.88" 1 "Vcb=0.25" 1>
  <BJT_SPICE Q1 1 690 190 -26 34 0 0 "4" 1 "npn" 1 "X" 1 "npn13G2 nx=8" 1 "" 0 "" 0 "" 0 "" 0>
  <SpiceInclude SpiceInclude1 1 60 300 -33 16 0 0 "../Modelcards/SG13G2_hbt_woStatistics.hsp.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM1 1 630 30 0 51 0 0 "\npre_osdi vbic_1p3.osdi\n" 1 "" 0 "" 0>
</Components>
<Wires>
  <300 740 300 750 "" 0 0 0 "">
  <480 740 480 750 "" 0 0 0 "">
  <390 690 390 700 "" 0 0 0 "">
  <480 660 480 680 "" 0 0 0 "">
  <420 660 480 660 "" 0 0 0 "">
  <300 660 300 680 "" 0 0 0 "">
  <300 660 360 660 "" 0 0 0 "">
  <620 190 660 190 "B" 650 160 15 "">
  <500 190 560 190 "" 0 0 0 "">
  <500 190 500 220 "" 0 0 0 "">
  <690 160 780 160 "C" 790 130 45 "">
  <900 160 900 220 "" 0 0 0 "">
  <840 160 900 160 "" 0 0 0 "">
  <720 190 720 240 "" 0 0 0 "">
  <690 220 690 240 "" 0 0 0 "">
  <690 240 690 280 "" 0 0 0 "">
  <690 240 720 240 "" 0 0 0 "">
  <810 190 810 210 "" 0 0 0 "">
  <810 270 810 280 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 70 560 240 160 3 #c0c0c0 1 00 1 0 0.2 1 1 -0.1 0.5 1.1 1 -0.1 0.5 1.1 315 0 225 1 0 0 "" "" "">
	<"ngspice/ac.v(s_1_1)" #0000ff 0 3 0 0 0>
	<"ngspice/ac.v(s_3_3)" #ff0000 0 3 0 0 0>
  </Rect>
  <Rect 400 560 240 160 3 #c0c0c0 1 00 1 0 0.2 1 1 -0.1 0.5 1.1 1 -0.1 0.5 1.1 315 0 225 1 0 0 "" "" "">
	<"ngspice/ac.v(s_1_2)" #0000ff 0 3 0 0 0>
	<"ngspice/ac.v(s_3_4)" #ff0000 0 3 0 0 0>
  </Rect>
  <Rect 710 560 240 160 3 #c0c0c0 1 00 1 0 0.2 1 1 -0.1 0.5 1.1 1 -0.1 0.5 1.1 315 0 225 1 0 0 "" "" "">
	<"ngspice/ac.v(s_2_1)" #0000ff 0 3 0 0 0>
	<"ngspice/ac.v(s_4_3)" #ff0000 0 3 0 0 0>
  </Rect>
  <Rect 1020 560 240 160 3 #c0c0c0 1 00 1 0 0.2 1 1 -0.1 0.5 1.1 1 -0.1 0.5 1.1 315 0 225 1 0 0 "" "" "">
	<"ngspice/ac.v(s_2_2)" #0000ff 0 3 0 0 0>
	<"ngspice/ac.v(s_4_4)" #ff0000 0 3 0 0 0>
  </Rect>
  <Rect 997 317 447 277 3 #c0c0c0 1 10 1 0 1e+09 1e+10 1 -17.5155 5 15 1 -1 0.5 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.gain" #0000ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
  <Text 20 20 16 #ed333b 0 "S-Param">
</Paintings>
