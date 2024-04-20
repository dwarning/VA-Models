<Qucs Schematic 24.2.1>
<Properties>
  <View=-213,-47,1229,804,0.826087,0,0>
  <Grid=10,10,1>
  <DataSet=inv_TRAN.dat>
  <DataDisplay=inv_TRAN.dpl>
  <OpenDisplay=0>
  <Script=EKV3_inv_TRAN.m>
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
  <GND * 5 510 330 0 0 0 0>
  <GND * 5 550 290 0 0 0 0>
  <GND * 5 280 310 0 0 0 0>
  <.TR TR1 1 10 150 0 66 0 0 "lin" 1 "0" 1 "500 ns" 1 "1000" 1 "Trapezoidal" 0 "2" 0 "1 ns" 0 "1e-16" 0 "150" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "26.85" 0 "1e-3" 0 "1e-6" 0 "1" 0 "CroutLU" 0 "no" 0 "yes" 0 "0" 0>
  <GND * 1 400 390 0 0 0 0>
  <R R1 1 690 210 67 -19 0 2 "1MEG" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <GND * 1 740 230 0 0 0 0>
  <GND * 5 640 70 0 0 0 0>
  <Vrect V1 0 280 260 -107 -58 0 1 "3.3" 1 "100 ns" 1 "100 ns" 1 "1 ns" 1 "1 ns" 1 "10 ns" 1 "0 V" 1>
  <.DC DC1 1 10 60 0 40 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <Vdc V2 1 590 50 -25 -57 0 2 "1.5" 1>
  <Vdc V4 1 400 340 -75 -23 0 1 "0.75 V" 1>
  <Vac V3 1 400 260 -81 -28 0 1 "0.75V" 1 "10 MHz" 1 "0" 0 "0.01" 0 "0" 0 "0" 0>
  <MOS_SPICE X1 1 510 140 -26 34 0 0 "X" 0 "4" 0 "pmos" 0 "pch90 w=3u l=0.1u nf=1" 1 "+ ad=3p as=3p" 1 "+ pd=8u ps=8u" 1 "" 0 "" 0>
  <MOS_SPICE X2 1 510 270 -26 34 0 0 "X" 0 "4" 0 "nmos" 0 "nch90 w=1u l=0.1u nf=1" 1 "+ad=1e-12 as=1e-12" 1 "+pd=4u ps=4u" 1 "" 0 "" 0>
  <SpiceInclude SpiceInclude1 1 50 330 -34 16 0 0 "../Modelcards/90nm_ngspice.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <SpiceInclude SpiceInclude2 0 50 410 -34 16 0 0 "../Modelcards/90nm_xyce.lib" 1 "" 0 "" 0 "" 0 "" 0>
</Components>
<Wires>
  <510 300 510 330 "" 0 0 0 "">
  <440 270 480 270 "" 0 0 0 "">
  <440 140 480 140 "" 0 0 0 "">
  <530 270 550 270 "" 0 0 0 "">
  <550 270 550 290 "" 0 0 0 "">
  <530 140 540 140 "" 0 0 0 "">
  <540 80 540 140 "" 0 0 0 "">
  <510 80 510 110 "" 0 0 0 "">
  <510 80 540 80 "" 0 0 0 "">
  <440 140 440 210 "" 0 0 0 "">
  <280 290 280 310 "" 0 0 0 "">
  <280 210 280 230 "" 0 0 0 "">
  <440 210 440 270 "" 0 0 0 "">
  <280 210 400 210 "in" 269 170 22 "">
  <400 210 440 210 "" 0 0 0 "">
  <400 210 400 230 "" 0 0 0 "">
  <510 170 510 210 "" 0 0 0 "">
  <510 210 510 240 "" 0 0 0 "">
  <510 210 660 210 "out" 600 180 130 "">
  <740 210 740 230 "" 0 0 0 "">
  <720 210 740 210 "" 0 0 0 "">
  <510 50 510 80 "" 0 0 0 "">
  <510 50 560 50 "" 0 0 0 "">
  <640 50 640 70 "" 0 0 0 "">
  <620 50 640 50 "" 0 0 0 "">
  <400 370 400 390 "" 0 0 0 "">
  <400 290 400 310 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 240 763 774 331 3 #c0c0c0 1 00 1 -1 0.2 1 1 -1 0.5 1 1 -1 0.5 1 315 0 225 1 0 0 "Time (s)" "" "">
	<"ngspice/tran.v(in)" #0000ff 0 3 0 0 0>
	<"ngspice/tran.v(out)" #ff0000 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
  <Text 0 0 14 #ff0000 0 "EKV3 inverter transient test">
</Paintings>
