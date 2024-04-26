<Qucs Schematic 24.2.1>
<Properties>
  <View=-151,-35,866,566,1.17167,0,0>
  <Grid=10,10,1>
  <DataSet=Amplifier_ac.dat>
  <DataDisplay=Amplifier_ac.dpl>
  <OpenDisplay=0>
  <Script=HICUM_L2.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Titel>
  <FrameText1=Gezeichnet von:>
  <FrameText2=Datum:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <R R1 1 240 70 15 -26 0 1 "300" 1 "26.85" 0 "0" 0 "0" 0 "26.85" 0 "european" 0>
  <R R2 1 180 130 -26 -53 0 2 "10k" 1 "26.85" 0 "0" 0 "0" 0 "26.85" 0 "european" 0>
  <GND * 1 240 190 0 0 0 0>
  <GND * 1 270 160 0 0 0 1>
  <IProbe Pr1 1 340 40 1 16 1 2>
  <GND * 1 390 100 0 0 0 0>
  <C C1 1 120 160 -26 17 0 0 "1 nF" 1 "" 0 "neutral" 0>
  <Vdc V1 1 390 70 26 -14 0 1 "5 V" 1>
  <BJT_SPICE Q1 1 240 160 -26 34 0 0 "4" 1 "npn" 1 "N" 1 "hicumL2va" 1 "" 0 "" 0 "" 0 "" 0>
  <R R3 1 60 200 15 -26 0 1 "50 Ohm" 1 "26.85" 0 "0" 0 "0" 0 "26.85" 0 "european" 0>
  <Vac V2 1 60 260 -56 -9 0 1 "1 V" 1 "1 GHz" 0 "0" 0 "0" 0 "0" 0 "0" 0>
  <GND * 1 60 300 0 0 0 0>
  <.DC DC1 1 50 340 0 39 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <.AC AC1 1 280 310 0 40 0 0 "log" 1 "100 kHz" 1 "10 GHz" 1 "81" 1 "no" 0>
  <.CUSTOMSIM CUSTOM1 1 280 440 0 51 0 0 "\npre_osdi hicumL2.osdi" 1 "" 0 "custom#ac1#.plot;custom#ac1#.print" 0>
  <SpiceInclude SpiceInclude1 1 80 420 -33 16 0 0 "../Modelcards/examples.lib" 1 "" 0 "" 0 "" 0 "" 0>
</Components>
<Wires>
  <150 130 150 160 "" 0 0 0 "">
  <240 100 240 130 "out" 280 110 11 "">
  <210 130 240 130 "" 0 0 0 "">
  <150 160 210 160 "" 0 0 0 "">
  <240 40 310 40 "" 0 0 0 "">
  <370 40 390 40 "" 0 0 0 "">
  <60 160 90 160 "" 0 0 0 "">
  <60 160 60 170 "" 0 0 0 "">
  <60 290 60 300 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 470 320 240 160 3 #c0c0c0 1 11 1 1e+06 1 1e+10 1 3 1 100 1 -1 1 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.v(out)" #0000ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
