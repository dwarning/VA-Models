<Qucs Schematic 24.2.1>
<Properties>
  <View=-205,-40,1144,756,0.883166,0,0>
  <Grid=10,10,1>
  <DataSet=Colpitts_cbr2.dat>
  <DataDisplay=Colpitts_cbr2.dpl>
  <OpenDisplay=0>
  <Script=hic2_colpitts_cbr2.m>
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
  <GND * 1 400 380 0 0 0 0>
  <R R1 1 230 340 18 -26 1 3 "200" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <R R3 1 120 190 -106 -26 1 1 "100 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <Vdc Vp 1 400 220 23 -13 0 1 "2.5 V" 1>
  <C C2 1 350 340 17 -26 1 3 "1.4 pF" 1 "" 0 "neutral" 0>
  <C C1 1 350 240 17 -26 1 3 "3.9 p" 1 "" 0 "neutral" 0>
  <R R2 1 120 330 -97 -26 1 1 "40 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <L L1 1 230 170 -48 -19 0 3 "3.6 n" 1 "" 0>
  <IProbe Pr1 1 330 80 -26 16 1 2>
  <R R4 1 230 110 15 -26 0 1 "0.5 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <.FFT FFT1 1 320 410 0 68 0 0 "5GHz" 1 "1MHz" 1 "hanning" 1 "2" 0 "0" 0>
  <NutmegEq NutmegEq1 1 350 570 -28 16 0 0 "fft" 1 "S=dB(v(out))" 1>
  <C C3 1 170 320 17 -26 0 1 "10 uF" 1 "" 0 "neutral" 0>
  <BJT_SPICE Q1 1 230 250 -26 34 0 0 "4" 1 "npn" 1 "N" 1 "hicumL2va" 1 "" 0 "" 0 "" 0 "" 0>
  <.TR TR1 1 50 390 0 67 0 0 "lin" 1 "0 us" 1 "0.1 us" 1 "20001" 1 "Trapezoidal" 0 "2" 0 "1 ns" 0 "1e-16" 0 "150" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "26.85" 0 "1e-3" 0 "1e-6" 0 "1" 0 "CroutLU" 0 "no" 0 "yes" 0 "0" 0>
  <SpiceInclude SpiceInclude1 1 80 560 -33 16 0 0 "../Modelcards/examples.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM1 1 50 630 0 51 0 0 "\npre_osdi hicumL2.osdi" 1 "" 0 "custom#ac1#.plot;custom#ac1#.print" 0>
</Components>
<Wires>
  <400 80 400 190 "" 0 0 0 "">
  <400 250 400 370 "" 0 0 0 "">
  <400 370 400 380 "" 0 0 0 "">
  <120 370 170 370 "" 0 0 0 "">
  <120 360 120 370 "" 0 0 0 "">
  <170 370 230 370 "" 0 0 0 "">
  <230 370 280 370 "" 0 0 0 "">
  <170 350 170 370 "" 0 0 0 "">
  <280 370 350 370 "" 0 0 0 "">
  <120 80 230 80 "" 0 0 0 "">
  <120 80 120 160 "" 0 0 0 "">
  <120 220 120 250 "" 0 0 0 "">
  <280 250 280 370 "" 0 0 0 "">
  <230 280 230 290 "" 0 0 0 "">
  <170 250 170 290 "" 0 0 0 "">
  <120 250 120 300 "" 0 0 0 "">
  <120 250 170 250 "" 0 0 0 "">
  <170 250 200 250 "B" 210 220 10 "">
  <230 290 230 310 "" 0 0 0 "">
  <350 290 350 310 "" 0 0 0 "">
  <230 290 350 290 "" 0 0 0 "">
  <350 270 350 290 "" 0 0 0 "">
  <350 370 400 370 "" 0 0 0 "">
  <230 210 230 220 "" 0 0 0 "">
  <230 210 350 210 "out" 350 160 104 "">
  <230 200 230 210 "" 0 0 0 "">
  <360 80 400 80 "" 0 0 0 "">
  <230 80 300 80 "" 0 0 0 "">
  <260 250 280 250 "" 0 0 0 "">
  <230 310 230 310 "E" 240 290 0 "">
</Wires>
<Diagrams>
  <Rect 500 632 425 222 3 #c0c0c0 1 00 1 0 5e+08 5e+09 0 -100 10 0 1 -1 0.5 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.s" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 490 304 425 284 3 #c0c0c0 1 00 0 9.9e-08 1e-08 1e-07 1 -0.376705 1 3.30926 1 -0.00794072 0.005 0.015 315 0 225 0 0 0 "" "" "">
	<"ngspice/tran.v(out)" #ff0000 0 3 0 0 0>
	<"ngspice/tran.v(e)" #0000ff 0 3 0 0 0>
	<"ngspice/tran.v(b)" #ff00ff 0 3 0 0 0>
	<"ngspice/tran.i(pr1)" #00ff00 0 3 0 0 1>
  </Rect>
</Diagrams>
<Paintings>
  <Text 30 0 16 #000000 0 "Colpitts oscillator common base">
</Paintings>