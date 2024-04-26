<Qucs Schematic 24.2.1>
<Properties>
  <View=-20,-32,1125,696,1.04017,0,0>
  <Grid=10,10,1>
  <DataSet=npn_spar_NF.dat>
  <DataDisplay=npn_spar_NF.dpl>
  <OpenDisplay=0>
  <Script=HICUM-fig10.m>
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
  <IProbe Ic 1 440 130 -6 -53 1 2>
  <GND * 1 390 240 0 0 0 0>
  <GND * 1 150 280 0 0 0 0>
  <Vdc V1 1 140 140 -26 -55 1 0 "0.9 V" 1>
  <GND * 1 100 150 0 0 0 0>
  <GND * 1 640 90 0 0 0 0>
  <Pac P2 1 550 190 22 -27 0 1 "2" 1 "50 Ohm" 1 "0 dBm" 0 "1 GHz" 0 "26.85" 0 "true" 0>
  <GND * 1 550 240 0 0 0 0>
  <Pac P1 1 150 230 -97 -26 1 1 "1" 1 "50 Ohm" 1 "0 dBm" 0 "1 GHz" 0 "26.85" 0 "true" 0>
  <IProbe Ib 1 280 190 -7 12 0 0>
  <.DC DC1 1 690 60 0 40 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <BiasT X3 1 200 190 -26 -52 1 0 "1 H" 0 "1 F" 0>
  <BiasT X4 1 510 130 -26 -52 0 2 "1 H" 0 "1 F" 0>
  <.SP SP1 1 690 140 0 65 0 0 "log" 1 "1 Hz" 1 "100 GHz" 1 "111" 1 "yes" 1 "1" 0 "2" 0 "no" 0 "no" 0>
  <Vdc V2 1 600 80 -26 -56 0 2 "1.2 V" 1>
  <BJT_SPICE Q1 1 390 190 -26 34 0 0 "4" 1 "npn" 1 "N" 1 "hicumL2va" 1 "" 0 "" 0 "" 0 "" 0>
  <SpiceInclude SpiceInclude2 1 900 70 -33 16 0 0 "../Modelcards/examples.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM1 1 870 140 0 51 0 0 "\npre_osdi hicumL2.osdi" 1 "" 0 "custom#ac1#.plot;custom#ac1#.print" 0>
</Components>
<Wires>
  <470 130 480 130 "" 0 0 0 "">
  <390 130 410 130 "" 0 0 0 "">
  <390 130 390 160 "" 0 0 0 "">
  <390 220 390 240 "" 0 0 0 "">
  <200 140 200 160 "" 0 0 0 "">
  <170 140 200 140 "" 0 0 0 "">
  <100 140 100 150 "" 0 0 0 "">
  <100 140 110 140 "" 0 0 0 "">
  <510 80 510 100 "" 0 0 0 "">
  <510 80 570 80 "" 0 0 0 "">
  <640 80 640 90 "" 0 0 0 "">
  <630 80 640 80 "" 0 0 0 "">
  <540 130 550 130 "" 0 0 0 "">
  <550 130 550 160 "" 0 0 0 "">
  <550 220 550 240 "" 0 0 0 "">
  <150 260 150 280 "" 0 0 0 "">
  <150 190 170 190 "" 0 0 0 "">
  <150 190 150 200 "" 0 0 0 "">
  <310 190 360 190 "" 0 0 0 "">
  <230 190 250 190 "" 0 0 0 "">
  <420 190 420 220 "" 0 0 0 "">
  <390 220 420 220 "" 0 0 0 "">
</Wires>
<Diagrams>
  <PS 50 550 200 200 3 #c0c0c0 1 00 1 0 1 1 1 0 4 1 1 0 0 nan 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.v(s_1_1)" #0000ff 0 3 0 0 0>
	<"ngspice/ac.v(s_2_1)" #ff0000 0 3 0 0 0>
  </PS>
  <PS 340 550 200 200 3 #c0c0c0 1 00 1 0 1 1 1 0 4 1 0 0 0.1 0.2 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.v(s_1_2)" #0000ff 0 3 0 0 0>
	<"ngspice/ac.v(s_2_2)" #ff0000 0 3 0 0 0>
  </PS>
  <Rect 610 577 436 267 3 #c0c0c0 1 10 1 1 1 1e+11 0 0 2 20 1 -1 0.5 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.v(nf)" #ff0000 0 3 0 0 0>
	<"ngspice/ac.v(nfmin)" #ff0000 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
  <Text 20 10 13 #000000 0 "Verilog Report, Figure 10 - AC simulation HICUM/L2 v2.4">
</Paintings>
