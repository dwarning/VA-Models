<Qucs Schematic 24.2.1>
<Properties>
  <View=-60,-35,957,566,1.17167,0,0>
  <Grid=10,10,1>
  <DataSet=npn_noise_Vb_Vc.dat>
  <DataDisplay=npn_noise_Vb_Vc.dpl>
  <OpenDisplay=0>
  <Script=hic2_noise_Vb_Vc.m>
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
  <GND * 1 140 210 0 0 0 0>
  <GND * 1 20 210 0 0 0 0>
  <GND * 1 380 210 0 0 0 0>
  <GND * 1 440 100 0 0 0 0>
  <CCVS SRC2 1 410 70 -26 34 0 0 "-1" 1 "0" 0>
  <GND * 1 100 210 0 0 0 0>
  <R R1 1 100 170 15 -26 0 1 "1 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <L L1 1 190 100 -26 10 0 0 "1e9" 1 "" 0>
  <Vdc Vce 1 380 170 18 -26 0 1 "1 V" 1>
  <Vdc Vbe 1 140 170 18 -26 0 1 "0.85 V" 1>
  <Vac V1 1 20 170 18 -26 0 1 "1 V" 1 "1 kHz" 1 "0" 0 "0" 0 "0" 0 "0" 0>
  <.NOISE NOISE1 1 40 250 0 69 0 0 "log" 1 "1 Hz" 1 "10 kHz" 1 "101" 1 "v(out)" 1 "V1" 1>
  <.SW SW1 1 210 260 0 51 0 0 "NOISE1" 1 "lin" 1 "Vbe" 1 "0.7" 1 "0.925" 1 "10" 1 "false" 0>
  <BJT_SPICE Q1 1 260 100 -26 34 0 0 "4" 1 "npn" 1 "N" 1 "hicumL2va" 1 "" 0 "" 0 "" 0 "" 0>
  <GND * 1 260 210 0 0 0 0>
  <GND * 1 290 100 0 0 0 0>
  <SpiceInclude SpiceInclude1 1 70 460 -33 16 0 0 "../Modelcards/examples.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM1 1 260 440 0 51 0 0 "\npre_osdi hicumL2.osdi" 1 "" 0 "custom#ac1#.plot;custom#ac1#.print" 0>
  <NutmegEq NutmegEq2 1 530 20 -28 16 0 0 "NOISE1" 1 "Beta=100" 1 "Sib=v(onoise_spectrum)*v(onoise_spectrum)/(Beta*Beta)" 1>
</Components>
<Wires>
  <20 100 100 100 "in" 30 70 6 "">
  <20 100 20 140 "" 0 0 0 "">
  <20 200 20 210 "" 0 0 0 "">
  <380 20 380 40 "" 0 0 0 "">
  <440 40 470 40 "out" 430 10 12 "">
  <380 200 380 210 "" 0 0 0 "">
  <380 100 380 140 "" 0 0 0 "">
  <100 100 100 140 "" 0 0 0 "">
  <100 200 100 210 "" 0 0 0 "">
  <260 20 380 20 "" 0 0 0 "">
  <260 20 260 70 "C" 236 20 19 "">
  <140 200 140 210 "" 0 0 0 "">
  <140 100 160 100 "" 0 0 0 "">
  <140 100 140 140 "" 0 0 0 "">
  <260 130 260 210 "" 0 0 0 "">
  <220 100 230 100 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 510 443 369 323 3 #c0c0c0 1 11 1 0 1 0 1 0 1 0 1 -1 0.5 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.sib" #0000ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
