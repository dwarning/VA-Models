<Qucs Schematic 24.2.1>
<Properties>
  <View=-194,-31,833,576,1.16007,0,0>
  <Grid=10,10,1>
  <DataSet=Test_ECL-OR-NOR.dat>
  <DataDisplay=Test_ECL-OR-NOR.dpl>
  <OpenDisplay=0>
  <Script=test_ECL-OR-NOR.m>
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
  <GND * 1 30 210 0 0 0 0>
  <Vrect V2 1 30 180 18 -26 0 1 "0 V" 1 "20 ns" 1 "20 ns" 1 "1 ns" 0 "1 ns" 0 "0 ns" 0 "-2.5 V" 1>
  <.TR TR1 1 10 300 0 51 0 0 "lin" 1 "0" 1 "50 ns" 1 "2501" 0 "Trapezoidal" 0 "2" 0 "1 ns" 0 "1e-16" 0 "150" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "26.85" 0 "1e-3" 0 "1e-6" 0 "1" 0 "CroutLU" 0 "no" 0 "yes" 0 "0" 0>
  <IProbe Pr1 1 220 160 16 -26 0 1>
  <SpiceInclude SpiceInclude1 1 40 460 -33 16 0 0 "../Modelcards/examples.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM1 1 230 450 0 51 0 0 "\npre_osdi hicumL2.osdi" 1 "" 0 "custom#ac1#.plot;custom#ac1#.print" 0>
  <Sub SUB1 1 160 100 81 -26 0 1 "ECL-OR-NOR.sch" 0>
  <Vdc V1 1 220 220 18 -26 0 1 "-5.2" 1>
  <GND * 1 220 250 0 0 0 0>
</Components>
<Wires>
  <160 40 160 70 "" 0 0 0 "">
  <160 40 330 40 "" 0 0 0 "">
  <160 130 160 160 "" 0 0 0 "">
  <160 160 330 160 "" 0 0 0 "">
  <100 130 100 150 "" 0 0 0 "">
  <100 40 100 70 "" 0 0 0 "">
  <30 150 100 150 "" 0 0 0 "">
  <30 40 30 150 "" 0 0 0 "">
  <30 40 100 40 "IN" 40 10 16 "">
  <330 40 330 40 "A1" 340 10 0 "">
  <330 160 330 160 "A2" 340 130 0 "">
</Wires>
<Diagrams>
  <Rect 290 422 349 235 3 #c0c0c0 1 00 1 0 1e-08 5e-08 1 -3 1 0.25 1 -0.0231126 0.001 -0.0206357 315 0 225 0 0 0 "" "" "">
	<"ngspice/tran.v(in)" #0000ff 2 3 0 0 0>
	<"ngspice/tran.v(a1)" #ff0000 2 3 0 0 0>
	<"ngspice/tran.v(a2)" #ff00ff 2 3 0 0 0>
	<"ngspice/tran.i(pr1)" #00ff00 3 3 0 0 1>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
