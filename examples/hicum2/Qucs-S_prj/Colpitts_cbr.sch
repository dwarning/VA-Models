<Qucs Schematic 24.2.1>
<Properties>
  <View=-217,-40,1165,776,0.86152,0,0>
  <Grid=10,10,1>
  <DataSet=Colpitts_cbr.dat>
  <DataDisplay=Colpitts_cbr.dpl>
  <OpenDisplay=0>
  <Script=hic2_colpitts_cbr.m>
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
  <Vdc Vp 1 400 220 23 -13 0 1 "2.5 V" 1>
  <GND * 1 400 380 0 0 0 0>
  <R R2 1 120 330 -97 -26 1 1 "40 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <C C1 1 280 110 17 -26 1 3 "1.4 p" 1 "" 0 "neutral" 0>
  <C C2 1 280 190 17 -26 1 3 "2.9 pF" 1 "" 0 "neutral" 0>
  <C C3 1 170 320 17 -26 0 1 "10 uF" 1 "" 0 "neutral" 0>
  <R R3 1 120 220 -106 -26 1 1 "100 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <.TR TR1 1 50 410 0 67 0 0 "lin" 1 "0 us" 1 "0.1 us" 1 "20001" 1 "Trapezoidal" 0 "2" 0 "1 ns" 0 "1e-16" 0 "150" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "26.85" 0 "1e-3" 0 "1e-6" 0 "1" 0 "CroutLU" 0 "no" 0 "yes" 0 "0" 0>
  <L L1 1 230 180 -48 -19 0 3 "4 n" 1 "" 0>
  <IProbe Pr1 1 350 80 -26 16 1 2>
  <R R1 1 230 340 18 -26 1 3 "200" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <.FFT FFT1 1 300 410 0 68 0 0 "5GHz" 1 "1MHz" 1 "hanning" 1 "2" 0 "0" 0>
  <NutmegEq NutmegEq1 1 330 570 -28 16 0 0 "fft" 1 "S=dB(v(out))" 1>
  <R R4 1 230 120 15 -26 0 1 "0.5 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <BJT_SPICE Q1 1 230 270 -26 34 0 0 "4" 1 "npn" 1 "N" 1 "hicumL2va" 1 "" 0 "" 0 "" 0 "" 0>
  <SpiceInclude SpiceInclude1 1 80 580 -33 16 0 0 "../Modelcards/examples.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM1 1 50 650 0 51 0 0 "\npre_osdi hicumL2.osdi" 1 "" 0 "custom#ac1#.plot;custom#ac1#.print" 0>
</Components>
<Wires>
  <280 140 280 150 "" 0 0 0 "">
  <230 80 280 80 "" 0 0 0 "">
  <230 220 280 220 "" 0 0 0 "">
  <280 150 280 160 "" 0 0 0 "">
  <280 150 330 150 "" 0 0 0 "">
  <330 150 330 300 "" 0 0 0 "">
  <230 300 330 300 "" 0 0 0 "">
  <400 80 400 190 "" 0 0 0 "">
  <400 250 400 370 "" 0 0 0 "">
  <230 300 230 310 "" 0 0 0 "">
  <400 370 400 380 "" 0 0 0 "">
  <120 370 170 370 "" 0 0 0 "">
  <120 360 120 370 "" 0 0 0 "">
  <230 220 230 240 "" 0 0 0 "">
  <120 80 230 80 "" 0 0 0 "">
  <120 80 120 190 "" 0 0 0 "">
  <120 250 120 270 "" 0 0 0 "">
  <120 270 120 300 "" 0 0 0 "">
  <120 270 170 270 "" 0 0 0 "">
  <170 270 200 270 "B" 190 240 6 "">
  <170 370 230 370 "" 0 0 0 "">
  <280 80 320 80 "" 0 0 0 "">
  <170 270 170 290 "" 0 0 0 "">
  <170 350 170 370 "" 0 0 0 "">
  <230 210 230 220 "" 0 0 0 "">
  <230 80 230 90 "" 0 0 0 "">
  <380 80 400 80 "" 0 0 0 "">
  <230 370 280 370 "" 0 0 0 "">
  <260 270 280 270 "" 0 0 0 "">
  <280 370 400 370 "" 0 0 0 "">
  <280 270 280 370 "" 0 0 0 "">
  <280 220 280 220 "out" 300 200 0 "">
  <230 310 230 310 "E" 240 300 0 "">
</Wires>
<Diagrams>
  <Rect 510 304 425 284 3 #c0c0c0 1 00 0 9.9e-08 1e-08 1e-07 1 -0.250059 1 4.33102 1 -0.00213833 0.005 0.0119492 315 0 225 0 0 0 "" "" "">
	<"ngspice/tran.v(out)" #ff0000 0 3 0 0 0>
	<"ngspice/tran.v(e)" #0000ff 0 3 0 0 0>
	<"ngspice/tran.v(b)" #ff00ff 0 3 0 0 0>
	<"ngspice/tran.i(pr1)" #00ff00 0 3 0 0 1>
  </Rect>
  <Rect 510 622 425 222 3 #c0c0c0 1 00 1 0 5e+08 5e+09 0 -100 10 0 1 -1 0.5 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.s" #0000ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
  <Text 30 0 16 #000000 0 "Colpitts oscillator common base">
</Paintings>
