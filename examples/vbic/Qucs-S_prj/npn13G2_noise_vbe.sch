<Qucs Schematic 24.2.1>
<Properties>
  <View=-85,-35,982,596,1.11587,0,0>
  <Grid=10,10,1>
  <DataSet=npn13G2_noise_vbe.dat>
  <DataDisplay=npn13G2_noise_vbe.dpl>
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
  <GND * 1 140 220 0 0 0 0>
  <GND * 1 270 220 0 0 0 0>
  <GND * 1 20 220 0 0 0 0>
  <Vac V1 1 20 180 18 -26 0 1 "1 V" 1 "1 kHz" 1 "0" 0 "0" 0 "0" 0 "0" 0>
  <GND * 1 380 220 0 0 0 0>
  <GND * 1 440 110 0 0 0 0>
  <CCVS SRC1 1 410 80 -26 34 0 0 "-1" 1 "0" 0>
  <Vdc Vce 1 380 180 18 -26 0 1 "1 V" 1>
  <Vdc Vbe 1 140 180 18 -26 0 1 "0.85 V" 1>
  <NutmegEq NutmegEq1 1 530 20 -28 16 0 0 "NOISE1" 1 "Beta=100" 1 "Sib=v(onoise_spectrum)*v(onoise_spectrum)/(Beta*Beta)" 1>
  <.SW SW1 1 210 270 0 51 0 0 "NOISE1" 1 "lin" 1 "Vbe" 1 "0.7" 1 "0.925" 1 "10" 1 "false" 0>
  <GND * 1 100 220 0 0 0 0>
  <R R1 1 100 180 15 -26 0 1 "1 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <L L1 1 190 110 -26 10 0 0 "1e9" 1 "" 0>
  <.NOISE NOISE1 1 40 260 0 65 0 0 "log" 1 "1 Hz" 1 "10 MHz" 1 "71" 1 "v(out)" 1 "V1" 1>
  <GND * 1 300 110 0 0 0 0>
  <SpiceInclude SpiceInclude1 1 50 480 -33 16 0 0 "../Modelcards/SG13G2_hbt_woStatistics.hsp.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM1 1 380 470 0 51 0 0 "\npre_osdi vbic_1p3.osdi\n" 1 "" 0 "" 0>
  <BJT_SPICE Q1 1 270 110 -26 34 0 0 "4" 1 "npn" 1 "X" 1 "npn13G2 nx=8" 1 "" 0 "" 0 "" 0 "" 0>
</Components>
<Wires>
  <140 210 140 220 "" 0 0 0 "">
  <20 110 100 110 "in" 40 80 6 "">
  <20 110 20 150 "" 0 0 0 "">
  <20 210 20 220 "" 0 0 0 "">
  <380 30 380 50 "" 0 0 0 "">
  <440 50 470 50 "out" 420 10 12 "">
  <380 210 380 220 "" 0 0 0 "">
  <380 110 380 150 "" 0 0 0 "">
  <270 140 270 220 "" 0 0 0 "">
  <270 30 380 30 "" 0 0 0 "">
  <270 30 270 80 "C" 246 20 19 "">
  <100 110 100 150 "" 0 0 0 "">
  <100 210 100 220 "" 0 0 0 "">
  <220 110 240 110 "B" 230 80 7 "">
  <140 110 160 110 "" 0 0 0 "">
  <140 110 140 150 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 510 453 369 323 3 #c0c0c0 1 11 1 1 1 10000 1 1e-10 1 3e-09 1 -1 0.5 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.sib" #0000ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
