<Qucs Schematic 24.2.1>
<Properties>
  <View=-230,0,1166,824,0.853155,0,0>
  <Grid=10,10,1>
  <DataSet=ring_Osc.dat>
  <DataDisplay=ring_Osc.dpl>
  <OpenDisplay=0>
  <Script=EKV3_Ring_Osc.m>
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
  <SpiceInclude SpiceInclude2 0 480 360 -34 16 0 0 "../Modelcards/90nm_xyce.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <SpiceInclude SpiceInclude1 1 480 280 -34 16 0 0 "../Modelcards/90nm_ngspice.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <GND * 1 860 240 0 0 0 0>
  <R R1 1 860 190 15 -26 0 1 "1MEG" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <GND * 1 170 240 0 0 0 0>
  <GND * 1 60 160 0 0 0 0>
  <Vdc V1 1 60 110 -58 -18 0 1 "1.5" 1>
  <Sub SUB1 1 150 140 40 44 0 0 "inv.sch" 0>
  <Sub SUB2 1 300 140 40 44 0 0 "inv.sch" 0>
  <Sub SUB3 1 450 140 40 44 0 0 "inv.sch" 0>
  <Sub SUB4 1 600 140 40 44 0 0 "inv.sch" 0>
  <Sub SUB5 1 740 140 40 44 0 0 "inv.sch" 0>
  <SpiceIC SpiceIC1 1 40 350 -8 16 0 0 "v(out1)=1.5" 1>
  <.DC DC1 1 30 280 0 41 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <.TR TR2 1 200 280 0 66 0 0 "lin" 1 "0" 1 "10ns" 1 "1001" 1 "Trapezoidal" 0 "2" 0 "1 ns" 0 "1e-16" 0 "150" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "26.85" 0 "1e-3" 0 "1e-6" 0 "1" 0 "CroutLU" 0 "no" 0 "yes" 1 "0" 0>
  <.CUSTOMSIM CUSTOM1 1 700 320 0 51 0 0 "pre_osdi ekv3.osdi\n" 1 "" 0 "" 0>
</Components>
<Wires>
  <620 200 620 220 "" 0 0 0 "">
  <470 200 470 220 "" 0 0 0 "">
  <530 140 560 140 "" 0 0 0 "">
  <320 200 320 220 "" 0 0 0 "">
  <380 140 410 140 "" 0 0 0 "">
  <860 220 860 240 "" 0 0 0 "">
  <860 140 860 160 "" 0 0 0 "">
  <170 200 170 220 "" 0 0 0 "">
  <230 140 260 140 "" 0 0 0 "">
  <680 140 700 140 "out4" 680 100 10 "">
  <170 220 320 220 "" 0 0 0 "">
  <320 220 470 220 "" 0 0 0 "">
  <470 220 620 220 "" 0 0 0 "">
  <760 200 760 220 "" 0 0 0 "">
  <620 220 760 220 "" 0 0 0 "">
  <170 220 170 240 "" 0 0 0 "">
  <320 60 320 80 "" 0 0 0 "">
  <470 60 470 80 "" 0 0 0 "">
  <320 60 470 60 "" 0 0 0 "">
  <620 60 620 80 "" 0 0 0 "">
  <470 60 620 60 "" 0 0 0 "">
  <760 60 760 80 "" 0 0 0 "">
  <620 60 760 60 "" 0 0 0 "">
  <170 60 170 80 "" 0 0 0 "">
  <170 60 320 60 "" 0 0 0 "">
  <820 140 840 140 "" 0 0 0 "">
  <840 140 860 140 "" 0 0 0 "">
  <840 40 840 140 "" 0 0 0 "">
  <100 140 110 140 "" 0 0 0 "">
  <100 40 100 140 "" 0 0 0 "">
  <100 40 840 40 "" 0 0 0 "">
  <60 140 60 160 "" 0 0 0 "">
  <60 60 170 60 "" 0 0 0 "">
  <60 60 60 80 "" 0 0 0 "">
  <230 140 230 140 "out1" 220 100 0 "">
  <380 140 380 140 "out2" 370 100 0 "">
  <530 140 530 140 "out3" 520 100 0 "">
  <860 140 860 140 "out" 870 110 0 "">
</Wires>
<Diagrams>
  <Rect 90 783 774 331 3 #c0c0c0 1 00 1 0 1e-09 1e-08 1 -0.156484 0.5 1.67682 1 -1 0.5 1 315 0 225 1 0 0 "Time (s)" "" "">
	<"xyce/tran.V(OUT)" #0000ff 0 3 0 0 0>
	<"ngspice/tran.v(out)" #ff0000 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
