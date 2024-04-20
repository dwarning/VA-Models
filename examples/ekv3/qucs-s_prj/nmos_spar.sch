<Qucs Schematic 24.2.1>
<Properties>
  <View=-48,-30,1106,651,1.03231,0,0>
  <Grid=10,10,1>
  <DataSet=nmos_spar.dat>
  <DataDisplay=nmos_spar.dpl>
  <OpenDisplay=0>
  <Script=spar_nmos.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Erstellt von:>
  <FrameText2=Datum:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <GND * 1 290 200 0 0 0 0>
  <BiasT X1 1 290 110 -26 34 0 0 "1 H" 0 "1 F" 0>
  <Vdc Vgs1 1 290 170 18 -26 0 1 "Vgs" 1>
  <GND * 1 200 200 0 0 0 0>
  <Pac P1 1 200 170 18 -26 0 1 "1" 1 "50 Ohm" 1 "0 dBm" 0 "1 MHz" 0 "26.85" 0 "true" 0>
  <GND * 1 570 200 0 0 0 0>
  <Pac P2 1 570 170 18 -26 0 1 "2" 1 "50 Ohm" 1 "0 dBm" 0 "1 MHz" 0 "26.85" 0 "true" 0>
  <BiasT X2 1 530 80 -26 34 1 2 "1 H" 0 "1 F" 0>
  <GND * 1 530 200 0 0 0 0>
  <Vdc Vds1 1 530 160 -64 -26 1 1 "Vds" 1>
  <GND * 1 390 200 0 0 0 0>
  <GND * 1 430 200 0 0 0 0>
  <Vdc VB1 1 430 160 28 -16 0 1 "0" 1>
  <MOS_SPICE X3 1 390 110 -26 34 0 0 "X" 0 "4" 0 "nmos" 0 "nch90 w=10u l=0.1u nf=4" 1 "+ad=1e-12 as=1e-12" 1 "+pd=4u ps=4u" 1 "" 0 "" 0>
  <.SP SP1 1 650 20 0 69 0 0 "log" 1 "10 MHz" 1 "10 GHz" 1 "301" 1 "yes" 1 "1" 0 "2" 0 "no" 0 "no" 0>
  <SpiceInclude SpiceInclude2 0 40 140 -34 16 0 0 "../Modelcards/90nm_xyce.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <SpiceInclude SpiceInclude1 1 40 60 -34 16 0 0 "../Modelcards/90nm_ngspice.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <SpicePar SpicePar1 1 200 30 -28 16 0 0 "Vgs=1.2" 1 "Vds=0.2" 1>
</Components>
<Wires>
  <320 110 360 110 "" 0 0 0 "">
  <200 110 260 110 "" 0 0 0 "">
  <200 110 200 140 "" 0 0 0 "">
  <390 80 500 80 "" 0 0 0 "">
  <570 80 570 140 "" 0 0 0 "">
  <560 80 570 80 "" 0 0 0 "">
  <530 110 530 130 "" 0 0 0 "">
  <530 190 530 200 "" 0 0 0 "">
  <390 140 390 200 "" 0 0 0 "">
  <430 190 430 200 "" 0 0 0 "">
  <410 110 430 110 "" 0 0 0 "">
  <430 110 430 130 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 285 404 240 160 3 #c0c0c0 1 00 1 0 2e+09 1e+10 1 -0.00346704 0.02 0.04 1 -1 1 1 315 0 225 1 0 0 "" "" "">
	<"xyce/S(1,2)" #0000ff 0 3 0 0 0>
	<"ngspice/ac.v(s_1_2)" #ff0000 0 3 0 0 0>
  </Rect>
  <Rect 545 404 240 160 3 #c0c0c0 1 00 1 0 2e+09 1e+10 1 0.12319 0.002 0.130007 1 -1 1 1 315 0 225 1 0 0 "" "" "">
	<"xyce/S(2,1)" #0000ff 0 3 0 0 0>
	<"ngspice/ac.v(s_2_1)" #ff0000 0 3 0 0 0>
  </Rect>
  <Rect 25 404 240 160 3 #c0c0c0 1 00 1 0 2e+09 1e+10 1 0.997673 0.001 1.00021 1 -1 1 1 315 0 225 1 0 0 "" "" "">
	<"xyce/S(1,1)" #0000ff 0 3 0 0 0>
	<"ngspice/ac.v(s_1_1)" #ff0000 0 3 0 0 0>
  </Rect>
  <Rect 800 610 240 160 3 #c0c0c0 1 00 1 0 2e+09 1e+10 1 0.01602 1e-05 0.0160444 1 -1 1 1 315 0 225 1 0 0 "" "" "">
	<"xyce/Y(2,2)" #0000ff 0 3 0 0 0>
	<"ngspice/ac.v(y_2_2)" #ff0000 0 3 0 0 0>
  </Rect>
  <Rect 540 610 240 160 3 #c0c0c0 1 00 1 0 2e+09 1e+10 1 0.00221787 5e-05 0.00236709 1 -1 1 1 315 0 225 1 0 0 "" "" "">
	<"xyce/Y(2,1)" #0000ff 0 3 0 0 0>
	<"ngspice/ac.v(y_2_1)" #ff0000 0 3 0 0 0>
  </Rect>
  <Rect 20 610 240 160 3 #c0c0c0 1 00 1 0 2e+09 1e+10 1 -0.000141863 0.001 0.00157757 1 -1 1 1 315 0 225 1 0 0 "" "" "">
	<"xyce/Y(1,1)" #0000ff 0 3 0 0 0>
	<"ngspice/ac.v(y_1_1)" #ff0000 0 3 0 0 0>
  </Rect>
  <Rect 280 610 240 160 3 #c0c0c0 1 00 1 0 2e+09 1e+10 1 -6.2704e-05 0.0005 0.000697352 1 -1 1 1 315 0 225 1 0 0 "" "" "">
	<"xyce/Y(1,2)" #0000ff 0 3 0 0 0>
	<"ngspice/ac.v(y_1_2)" #ff0000 0 3 0 0 0>
  </Rect>
  <Rect 800 400 240 160 3 #c0c0c0 1 00 1 0 2e+09 1e+10 1 0.110316 0.0005 0.1115 1 -1 1 1 315 0 225 1 0 0 "" "" "">
	<"xyce/S(2,2)" #0000ff 0 3 0 0 0>
	<"ngspice/ac.v(s_2_2)" #ff0000 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
  <Text 10 10 16 #ed333b 0 "S-Param">
</Paintings>
