<Qucs Schematic 24.2.1>
<Properties>
  <View=-30,-62,1017,556,1.13754,0,0>
  <Grid=10,10,1>
  <DataSet=npn_ic_vc_ib_sfh.dat>
  <DataDisplay=npn_ic_vc_ib_sfh.dpl>
  <OpenDisplay=0>
  <Script=hic2_out.m>
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
  <.DC DC1 1 20 290 0 43 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <IProbe Pr1 1 360 60 -26 16 1 2>
  <GND * 1 290 250 0 0 0 0>
  <GND * 1 340 250 0 0 0 0>
  <GND * 1 440 250 0 0 0 0>
  <Vdc VC 1 440 160 18 -26 0 1 "2.0" 1>
  <BJT_SPICE Q1 1 290 150 -26 34 0 0 "5" 1 "npn" 1 "N" 1 "hicumL2va" 1 "" 0 "" 0 "" 0 "" 0>
  <GND * 1 150 250 0 0 0 0>
  <Idc IB 1 150 200 18 -26 0 1 "1 mA" 1>
  <.SW SW1 1 200 290 0 51 0 0 "DC1" 1 "lin" 1 "VC" 1 "0" 1 "2" 1 "201" 1 "false" 0>
  <.CUSTOMSIM CUSTOM1 1 20 20 0 51 0 0 "\npre_osdi hicumL2.osdi" 1 "" 0 "custom#ac1#.plot;custom#ac1#.print" 0>
  <.SW SW2 1 330 290 0 51 0 0 "SW1" 1 "lin" 1 "IB" 1 "10u" 1 "100u" 1 "10" 1 "false" 0>
  <.SW SW3 1 570 330 0 51 0 0 "SW2" 1 "list" 1 "@hicumL2va[flsh]" 1 "5 Ohm" 0 "50 Ohm" 0 "[1 0]" 1 "true" 1>
  <SpiceInclude SpiceInclude1 1 50 430 -33 16 0 0 "../Modelcards/examples.lib" 1 "" 0 "" 0 "" 0 "" 0>
</Components>
<Wires>
  <290 60 290 120 "" 0 0 0 "">
  <290 60 330 60 "" 0 0 0 "">
  <290 180 290 250 "" 0 0 0 "">
  <440 190 440 250 "" 0 0 0 "">
  <390 60 440 60 "" 0 0 0 "">
  <440 60 440 130 "" 0 0 0 "">
  <320 150 340 150 "" 0 0 0 "">
  <340 150 340 250 "" 0 0 0 "">
  <250 170 260 170 "" 0 0 0 "">
  <150 150 260 150 "B" 220 120 62 "">
  <150 150 150 170 "" 0 0 0 "">
  <150 230 150 250 "" 0 0 0 "">
  <250 170 250 190 "" 0 0 0 "">
  <290 60 290 60 "C" 300 30 0 "">
  <250 170 250 170 "Tj" 230 160 0 "">
</Wires>
<Diagrams>
  <Rect 560 282 386 242 3 #c0c0c0 1 00 1 0 0.2 2 1 -0.00338018 0.01 0.036912 1 -3.28117 10 36.0929 315 0 225 0 0 0 "Vce" "Ic" "Tj">
	<"ngspice/sw1.i(pr1)" #0000ff 0 3 0 0 0>
	<"ngspice/sw1.v(tj)" #ff0000 0 3 0 0 1>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
