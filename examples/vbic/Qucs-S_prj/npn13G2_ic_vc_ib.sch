<Qucs Schematic 24.2.1>
<Properties>
  <View=-30,-62,1005,549,1.15072,0,0>
  <Grid=10,10,1>
  <DataSet=npn13G2_ic_vc_ib.dat>
  <DataDisplay=npn13G2_ic_vc_ib.dpl>
  <OpenDisplay=0>
  <Script=hic2_out.m>
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
  <IProbe Pr1 1 300 40 -26 16 1 2>
  <GND * 1 130 230 0 0 0 0>
  <Idc I1 1 130 180 -48 -26 1 1 "5u" 1>
  <.DC DC1 1 20 290 0 43 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <GND * 1 230 230 0 0 0 0>
  <GND * 1 280 230 0 0 0 0>
  <.SW SW1 1 190 290 0 71 0 0 "DC1" 1 "lin" 1 "V1" 1 "0" 1 "2" 1 "201" 1 "false" 0>
  <GND * 1 380 230 0 0 0 0>
  <.SW SW2 1 330 290 0 71 0 0 "SW1" 1 "lin" 1 "I1" 1 "1u" 1 "10u" 1 "10" 1 "false" 0>
  <Vdc V1 1 380 140 18 -26 0 1 "2.0" 1>
  <SpiceInclude SpiceInclude1 1 480 370 -33 16 0 0 "../Modelcards/SG13G2_hbt_woStatistics.hsp.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM1 1 810 360 0 51 0 0 "\npre_osdi vbic_1p3.osdi\n" 1 "" 0 "" 0>
  <BJT_SPICE Q1 1 230 130 -26 34 0 0 "4" 1 "npn" 1 "X" 1 "npn13G2 nx=8" 1 "" 0 "" 0 "" 0 "" 0>
</Components>
<Wires>
  <230 40 230 100 "" 0 0 0 "">
  <230 40 270 40 "" 0 0 0 "">
  <130 130 200 130 "B" 160 100 22 "">
  <130 130 130 150 "" 0 0 0 "">
  <130 210 130 230 "" 0 0 0 "">
  <230 160 230 230 "" 0 0 0 "">
  <380 170 380 230 "" 0 0 0 "">
  <330 40 380 40 "" 0 0 0 "">
  <380 40 380 110 "" 0 0 0 "">
  <260 130 280 130 "" 0 0 0 "">
  <280 130 280 230 "" 0 0 0 "">
  <230 40 230 40 "C" 240 10 0 "">
</Wires>
<Diagrams>
  <Rect 570 282 386 242 3 #c0c0c0 1 00 1 0 0.2 2 1 -0.000423403 0.001 0.004 1 -1 0.5 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/sw1.i(pr1)" #0000ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
