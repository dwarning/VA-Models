<Qucs Schematic 24.2.1>
<Properties>
  <View=15,-41,920,493,1.31748,0,0>
  <Grid=10,10,1>
  <DataSet=npn_noise.dat>
  <DataDisplay=npn_noise.dpl>
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
  <GND * 1 70 220 0 0 0 0>
  <GND * 1 140 220 0 0 0 0>
  <Vac V1 1 70 180 18 -26 0 1 "1 V" 1 "1 kHz" 1 "0" 0 "0" 0 "0" 0 "0" 0>
  <Idc I1 1 140 180 18 -26 0 1 "10 uA" 1>
  <.NOISE NOISE1 1 80 260 0 65 0 0 "log" 1 "1 Hz" 1 "10 GHz" 1 "101" 1 "v(c)" 1 "V1" 1>
  <BiasT X1 1 140 110 -26 34 0 0 "1 H" 1 "1 F" 1>
  <SpiceInclude SpiceInclude1 1 270 260 -33 16 0 0 "../Modelcards/examples.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM1 1 240 330 0 51 0 0 "\npre_osdi hicumL2.osdi" 1 "" 0 "custom#ac1#.plot;custom#ac1#.print" 0>
  <GND * 1 410 220 0 0 0 0>
  <GND * 1 270 220 0 0 0 0>
  <Vdc V2 1 410 190 18 -26 0 1 "6 V" 1>
  <BJT_SPICE Q1 1 270 110 -26 34 0 0 "4" 1 "npn" 1 "N" 1 "hicumL2va" 1 "" 0 "" 0 "" 0 "" 0>
  <GND * 1 300 110 0 0 0 0>
  <R_SPICE R1 1 320 50 -28 -44 0 2 "1k noisy=0" 1 "" 0 "" 0 "" 0 "" 0 "2" 0 "R" 0>
</Components>
<Wires>
  <70 110 110 110 "in" 60 70 6 "">
  <70 110 70 150 "" 0 0 0 "">
  <70 210 70 220 "" 0 0 0 "">
  <140 140 140 150 "" 0 0 0 "">
  <140 210 140 220 "" 0 0 0 "">
  <170 110 240 110 "B" 220 70 63 "">
  <270 140 270 220 "" 0 0 0 "">
  <410 50 410 160 "" 0 0 0 "">
  <270 50 270 80 "C" 246 30 0 "">
  <270 50 290 50 "" 0 0 0 "">
  <350 50 410 50 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 510 403 369 323 3 #c0c0c0 1 11 1 1 1 1e+10 1 0 1 0 1 -1 0.5 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.inoise_spectrum" #0000ff 0 3 0 0 0>
	<"ngspice/ac.onoise_spectrum" #ff0000 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
