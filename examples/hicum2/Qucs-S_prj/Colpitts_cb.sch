<Qucs Schematic 24.2.1>
<Properties>
  <View=-140,-20,1090,706,0.96832,0,0>
  <Grid=10,10,1>
  <DataSet=Colpitts_cb.dat>
  <DataDisplay=Colpitts_cb.dpl>
  <OpenDisplay=0>
  <Script=hic2_colpitts_cb.m>
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
  <GND * 1 190 280 0 0 0 0>
  <R R1 1 80 210 -67 -26 0 3 "2.2k" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <Vdc Vn 1 130 260 -20 19 0 0 "1.8 V" 1>
  <Vdc Vp 1 250 260 -13 23 0 0 "1.8 V" 1>
  <.FFT FFT1 1 340 340 0 66 0 0 "5GHz" 1 "1MHz" 1 "hanning" 1 "2" 0 "0" 0>
  <NutmegEq NutmegEq1 1 370 500 -28 16 0 0 "fft" 1 "S=dB(v(out))" 1>
  <C C2 1 360 150 17 -26 0 1 "3 pF" 1 "" 0 "neutral" 0>
  <C C1 1 360 220 17 -26 0 1 "1.5 p" 1 "" 0 "neutral" 0>
  <IProbe Pr1 1 150 170 16 -26 0 1>
  <L L1 1 300 210 -48 -19 1 1 "4n" 1 "" 0>
  <R R2 1 300 150 15 -26 0 1 "0.5 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <BJT_SPICE Q1 1 190 210 -97 -16 1 1 "4" 1 "npn" 1 "N" 1 "hicumL2va" 1 "" 0 "" 0 "" 0 "" 0>
  <GND * 1 190 180 0 0 0 2>
  <.TR TR1 1 50 330 0 67 0 0 "lin" 1 "0 us" 1 "0.1 us" 1 "10001" 1 "Trapezoidal" 0 "2" 0 "1 ns" 0 "1e-16" 0 "150" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "26.85" 0 "1e-3" 0 "1e-6" 0 "1" 0 "CroutLU" 0 "no" 0 "yes" 0 "0" 0>
  <SpiceInclude SpiceInclude1 1 80 510 -33 16 0 0 "../Modelcards/examples.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM1 1 50 580 0 51 0 0 "\npre_osdi hicumL2.osdi" 1 "" 0 "custom#ac1#.plot;custom#ac1#.print" 0>
</Components>
<Wires>
  <160 260 190 260 "" 0 0 0 "">
  <190 260 220 260 "" 0 0 0 "">
  <190 240 190 260 "" 0 0 0 "">
  <280 260 300 260 "" 0 0 0 "">
  <150 210 160 210 "" 0 0 0 "">
  <190 260 190 280 "" 0 0 0 "">
  <80 240 80 260 "" 0 0 0 "">
  <80 260 100 260 "" 0 0 0 "">
  <360 110 360 120 "" 0 0 0 "">
  <300 110 360 110 "" 0 0 0 "">
  <220 210 240 210 "" 0 0 0 "">
  <240 110 240 210 "" 0 0 0 "">
  <240 110 300 110 "out" 290 80 42 "">
  <360 180 360 190 "" 0 0 0 "">
  <360 250 360 260 "" 0 0 0 "">
  <300 260 360 260 "" 0 0 0 "">
  <80 130 80 180 "" 0 0 0 "">
  <150 130 150 140 "" 0 0 0 "">
  <80 130 150 130 "E" 120 100 32 "">
  <150 200 150 210 "" 0 0 0 "">
  <360 180 450 180 "" 0 0 0 "">
  <150 70 150 130 "" 0 0 0 "">
  <150 70 450 70 "" 0 0 0 "">
  <450 70 450 180 "" 0 0 0 "">
  <300 110 300 120 "" 0 0 0 "">
  <300 240 300 260 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 510 314 425 284 3 #c0c0c0 1 00 0 9.8e-08 1e-08 1e-07 1 -2 2 5.11444 1 -1 0.5 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/tran.v(out)" #0000ff 0 3 0 0 0>
	<"ngspice/tran.v(e)" #0000ff 0 3 0 0 0>
	<"ngspice/tran.i(pr1)" #ff00ff 0 3 0 0 1>
  </Rect>
  <Rect 510 602 425 222 3 #c0c0c0 1 00 1 0 5e+08 5e+09 0 -100 10 10 1 -1 0.5 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.s" #0000ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
  <Text 40 20 16 #000000 0 "Colpitts oscillator common base">
</Paintings>
