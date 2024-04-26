<Qucs Schematic 24.2.1>
<Properties>
  <View=-41,-54,900,501,1.26702,0,0>
  <Grid=10,10,1>
  <DataSet=npn_noise_I.dat>
  <DataDisplay=npn_noise_I.dpl>
  <OpenDisplay=0>
  <Script=BJT-noise.m>
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
  <GND * 1 410 250 0 0 0 0>
  <GND * 1 270 250 0 0 0 0>
  <Idc I1 1 410 110 18 -26 0 1 "1 mA" 1>
  <Vac Vin 1 270 210 18 -26 0 1 "1 V" 1 "1 kHz" 1 "0" 0 "0" 0 "0" 0 "0" 0>
  <.NOISE NOISE1 1 10 10 0 65 0 0 "log" 1 "1 Hz" 1 "1 GHz" 1 "91" 1 "v(c)" 1 "Vin" 1>
  <.CUSTOMSIM CUSTOM1 0 10 220 0 51 0 0 "\n*noise v(C) vin dec 10 1 1G 1\nlet Icn=sqrt(onoise_spectrum)/1e6\n" 1 "" 0 "" 0>
  <R_SPICE R1 1 210 60 -28 -49 0 2 "1Meg noisy=0" 1 "" 0 "" 0 "" 0 "" 0 "2" 0 "R" 0>
  <SpiceInclude SpiceInclude1 1 270 290 -33 16 0 0 "../Modelcards/examples.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM2 1 240 360 0 51 0 0 "\npre_osdi hicumL2.osdi" 1 "" 0 "custom#ac1#.plot;custom#ac1#.print" 0>
  <BJT_SPICE Q1 1 270 140 -26 34 0 0 "4" 1 "npn" 1 "N" 1 "hicumL2va" 1 "" 0 "" 0 "" 0 "" 0>
  <GND * 1 300 140 0 0 0 0>
</Components>
<Wires>
  <270 170 270 180 "" 0 0 0 "">
  <270 60 270 110 "C" 296 70 9 "">
  <270 240 270 250 "" 0 0 0 "">
  <240 60 270 60 "" 0 0 0 "">
  <170 140 240 140 "B" 190 100 13 "">
  <170 60 180 60 "" 0 0 0 "">
  <170 60 170 140 "" 0 0 0 "">
  <410 140 410 250 "" 0 0 0 "">
  <270 60 410 60 "" 0 0 0 "">
  <410 60 410 80 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 490 353 369 323 3 #c0c0c0 1 11 1 1 1 1e+09 1 3e-09 1 1e-05 1 -1 0.5 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.onoise_spectrum" #0000ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
