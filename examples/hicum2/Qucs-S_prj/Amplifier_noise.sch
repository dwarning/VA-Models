<Qucs Schematic 24.2.1>
<Properties>
  <View=-70,-30,1265,758,0.892132,0,0>
  <Grid=10,10,1>
  <DataSet=Amplifier_noise.dat>
  <DataDisplay=Amplifier_noise.dpl>
  <OpenDisplay=0>
  <Script=hic2_noise_amp.m>
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
  <GND * 1 240 360 0 0 0 0>
  <R R1 1 240 290 15 -26 0 1 "2 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <GND * 1 110 360 0 0 0 0>
  <IProbe Pr1 1 450 130 -26 16 1 2>
  <GND * 1 640 220 0 0 0 0>
  <R R4 1 560 310 15 -26 0 1 "47k" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <GND * 1 560 340 0 0 0 0>
  <GND * 1 360 370 0 0 0 0>
  <R R2 1 360 340 15 -26 0 1 "100 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <R R3 1 240 200 15 -26 0 1 "11 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <.AC AC1 1 740 30 0 42 0 0 "log" 1 "1 Hz" 1 "1 GHz" 1 "81" 1 "no" 0>
  <R R5 1 360 180 15 -26 0 1 "19 k" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <Vac V1 1 110 330 18 -26 0 1 "1 V" 1 "4 kHz" 1 "0" 0 "0" 0 "0" 0 "0" 0>
  <Vdc V2 1 640 190 18 -26 0 1 "5 V" 1>
  <.SW SW1 1 230 420 0 71 0 0 "NOISE1" 1 "lin" 1 "R5" 1 "14k" 1 "22k" 1 "5" 1 "false" 0>
  <C C1 1 180 260 -26 17 0 0 "1000 u" 1 "" 0 "neutral" 0>
  <.NOISE NOISE1 1 50 410 0 69 0 0 "log" 1 "1 Hz" 1 "1 GHz" 1 "91" 1 "v(out)" 1 "V1" 1>
  <C C2 1 510 220 -26 17 0 0 "1 uF" 1 "" 0 "neutral" 0>
  <GND * 1 390 260 0 0 0 0>
  <BJT_SPICE Q1 1 360 260 -26 34 0 0 "4" 1 "npn" 1 "N" 1 "hicumL2va" 1 "" 0 "" 0 "" 0 "" 0>
  <SpiceInclude SpiceInclude1 1 80 620 -33 16 0 0 "../Modelcards/examples.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM1 1 270 620 0 51 0 0 "\npre_osdi hicumL2.osdi" 1 "" 0 "custom#ac1#.plot;custom#ac1#.print" 0>
</Components>
<Wires>
  <240 260 330 260 "" 0 0 0 "">
  <360 130 360 150 "" 0 0 0 "">
  <360 290 360 310 "" 0 0 0 "">
  <240 320 240 360 "" 0 0 0 "">
  <360 210 360 220 "" 0 0 0 "">
  <360 220 360 230 "" 0 0 0 "">
  <360 220 480 220 "out" 460 180 97 "">
  <360 130 420 130 "" 0 0 0 "">
  <480 130 640 130 "" 0 0 0 "">
  <640 130 640 160 "" 0 0 0 "">
  <540 220 560 220 "" 0 0 0 "">
  <560 220 560 280 "" 0 0 0 "">
  <210 260 240 260 "" 0 0 0 "">
  <110 260 150 260 "in" 110 210 6 "">
  <110 260 110 300 "" 0 0 0 "">
  <240 130 360 130 "" 0 0 0 "">
  <240 130 240 170 "" 0 0 0 "">
  <240 230 240 260 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 500 717 431 297 3 #c0c0c0 1 11 1 0 1 0 1 0 1 0 1 -1 0.5 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/noise1.ac.inoise_spectrum" #0000ff 0 3 0 0 0>
	<"ngspice/noise1.ac.onoise_spectrum" #ff0000 0 3 0 0 0>
  </Rect>
  <Rect 730 378 454 208 3 #c0c0c0 1 11 1 1 1 1e+09 1 10 1 100 1 -1 0.5 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac1.ac.v(out)" #0000ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
  <Text 10 10 12 #000000 0 "Here is a noise analysis example. This is BJT \none-stage amplifier. Simulate this circuit and plot\nonoise _ total and inoise _ total variables to obtain\ndependencies of total noise vs. collector resistance.\nNOTE: This Example could be run only with Ngspice">
</Paintings>
