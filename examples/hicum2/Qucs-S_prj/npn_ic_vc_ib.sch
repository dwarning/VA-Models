<Qucs Schematic 24.2.1>
<Properties>
  <View=-57,-11,936,576,1.19966,0,0>
  <Grid=10,10,1>
  <DataSet=npn_ic_vc_ib.dat>
  <DataDisplay=npn_ic_vc_ib.dpl>
  <OpenDisplay=0>
  <Script=HICUM_DC.m>
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
  <GND * 1 210 140 0 0 0 0>
  <GND * 1 70 220 0 0 0 0>
  <IProbe Ic 1 260 70 -7 15 1 2>
  <GND * 1 330 160 0 0 0 0>
  <GND * 1 170 170 0 0 0 0>
  <.DC DC1 1 40 290 0 43 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <Idc Ib 1 70 180 -62 -24 1 1 "1uA" 1>
  <Vdc Vce 1 330 120 18 -26 0 1 "1V" 1>
  <BJT_SPICE Q1 1 170 130 -26 34 0 0 "4" 1 "npn" 1 "N" 1 "hicumL2va" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM1 1 40 450 0 51 0 0 "\npre_osdi hicumL2.osdi" 1 "" 0 "custom#ac1#.plot;custom#ac1#.print" 0>
  <SpiceInclude SpiceInclude1 1 70 380 -33 16 0 0 "../Modelcards/examples.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.SW SW1 1 230 290 0 72 0 0 "DC1" 1 "lin" 1 "Vce" 1 "0" 1 "2.0" 1 "101" 1 "false" 0>
  <.SW SW2 1 320 290 0 72 0 0 "SW1" 1 "lin" 1 "Ib" 1 "5e-6" 1 "50e-5" 1 "9" 1 "false" 0>
</Components>
<Wires>
  <210 130 210 140 "" 0 0 0 "">
  <200 130 210 130 "" 0 0 0 "">
  <70 210 70 220 "" 0 0 0 "">
  <290 70 330 70 "" 0 0 0 "">
  <330 70 330 90 "" 0 0 0 "">
  <330 150 330 160 "" 0 0 0 "">
  <70 130 70 150 "" 0 0 0 "">
  <70 130 140 130 "B" 140 100 43 "">
  <170 70 230 70 "" 0 0 0 "">
  <170 70 170 100 "" 0 0 0 "">
  <170 160 170 170 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 570 270 300 240 3 #c0c0c0 1 00 1 -1 0.5 1 1 -1 0.5 1 1 -1 0.5 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/sw1.i(vic)" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 580 500 240 160 3 #c0c0c0 1 00 1 -1 0.5 1 1 -1 1 1 1 -1 1 1 315 0 225 1 0 0 "" "" "">
	<"ngspice/sw1.v(b)" #ff0000 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
