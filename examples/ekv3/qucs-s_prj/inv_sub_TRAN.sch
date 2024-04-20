<Qucs Schematic 24.2.1>
<Properties>
  <View=-151,-30,1109,714,0.944892,0,0>
  <Grid=10,10,1>
  <DataSet=inv_sub_TRAN.dat>
  <DataDisplay=inv_sub_TRAN.dpl>
  <OpenDisplay=0>
  <Script=EKV3_inv_sub_TRAN.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=>
  <FrameText1=>
  <FrameText2=>
  <FrameText3=>
</Properties>
<Symbol>
</Symbol>
<Components>
  <GND * 1 320 100 0 0 0 0>
  <GND * 1 220 260 0 0 0 0>
  <GND * 1 320 260 0 0 0 0>
  <GND * 1 120 260 0 0 0 0>
  <R R1 1 320 220 15 -26 0 1 "1MEG" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <Vdc V2 1 270 80 -15 -56 0 2 "1.5" 1>
  <Vrect V1 1 120 220 -114 -64 0 1 "1.5" 1 "100 ns" 1 "100 ns" 1 "1 ns" 1 "1 ns" 1 "10 ns" 1 "0 V" 1>
  <Sub SUB1 1 200 180 40 44 0 0 "inv.sch" 0>
  <.TR TR1 1 410 120 0 66 0 0 "lin" 1 "0" 1 "500 ns" 1 "1000" 1 "Trapezoidal" 0 "2" 0 "1 ns" 0 "1e-16" 0 "150" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "26.85" 0 "1e-3" 0 "1e-6" 0 "1" 0 "CroutLU" 0 "no" 0 "yes" 0 "0" 0>
  <.DC DC1 1 410 40 0 41 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <SpiceInclude SpiceInclude1 1 610 190 -34 16 0 0 "../Modelcards/90nm_ngspice.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <SpiceInclude SpiceInclude2 0 610 270 -34 16 0 0 "../Modelcards/90nm_xyce.lib" 1 "" 0 "" 0 "" 0 "" 0>
</Components>
<Wires>
  <220 240 220 260 "" 0 0 0 "">
  <320 250 320 260 "" 0 0 0 "">
  <320 180 320 190 "" 0 0 0 "">
  <280 180 320 180 "out" 310 150 22 "">
  <120 180 160 180 "in" 110 150 10 "">
  <120 180 120 190 "" 0 0 0 "">
  <120 250 120 260 "" 0 0 0 "">
  <320 80 320 100 "" 0 0 0 "">
  <300 80 320 80 "" 0 0 0 "">
  <220 80 220 120 "" 0 0 0 "">
  <220 80 240 80 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 40 673 774 331 3 #c0c0c0 1 00 1 0 5e-08 5e-07 1 -0.151658 0.5 1.6528 1 -1 0.5 1 315 0 225 1 0 0 "Time (s)" "" "">
	<"xyce/tran.V(IN)" #0000ff 0 3 0 0 0>
	<"xyce/tran.V(OUT)" #ff0000 0 3 0 0 0>
	<"ngspice/tran.v(in)" #ff00ff 0 3 0 0 0>
	<"ngspice/tran.v(out)" #00ff00 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
  <Text 10 10 14 #ff0000 0 "EKV3 inverter transient test">
</Paintings>
