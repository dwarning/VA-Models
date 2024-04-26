<Qucs Schematic 24.2.1>
<Properties>
  <View=29,126,1118,769,1.09331,0,0>
  <Grid=10,10,1>
  <DataSet=npn_ic_ib_is_vb.dat>
  <DataDisplay=npn_ic_ib_is_vb.dpl>
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
  <GND * 1 270 390 0 0 0 0>
  <GND * 1 320 390 0 0 0 0>
  <GND * 1 140 390 0 0 0 0>
  <IProbe Pr_Ic 1 340 200 -26 16 1 2>
  <IProbe Pr_Ib 1 190 290 -26 16 0 0>
  <GND * 1 420 390 0 0 0 0>
  <.DC DC1 1 120 450 0 43 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <Vdc Vbe 1 140 340 18 -26 0 1 "0.5" 1>
  <IProbe Pr_Is 1 320 340 -50 -26 0 3>
  <.SW SW1 1 120 530 0 51 0 0 "DC1" 1 "lin" 1 "Vbe" 1 "0.2" 1 "1.0" 1 "81" 1 "false" 0>
  <Vdc Vce 1 420 290 18 -26 0 1 "1.0" 1>
  <NutmegEq NutmegEq1 1 250 600 -28 16 0 0 "SW1" 1 "Beta=i(vpr_ic)/i(vpr_ib)" 1>
  <.CUSTOMSIM CUSTOM1 1 360 450 0 51 0 0 "\npre_osdi hicumL2.osdi" 1 "" 0 "custom#ac1#.plot;custom#ac1#.print" 0>
  <SpiceInclude SpiceInclude1 1 390 600 -33 16 0 0 "../Modelcards/examples.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <BJT_SPICE Q1 1 270 290 -26 34 0 0 "4" 1 "npn" 1 "N" 1 "hicumL2va" 1 "" 0 "" 0 "" 0 "" 0>
</Components>
<Wires>
  <420 200 420 260 "" 0 0 0 "">
  <370 200 420 200 "" 0 0 0 "">
  <140 370 140 390 "" 0 0 0 "">
  <140 290 140 310 "" 0 0 0 "">
  <140 290 160 290 "" 0 0 0 "">
  <420 320 420 390 "" 0 0 0 "">
  <320 370 320 390 "" 0 0 0 "">
  <320 290 320 310 "" 0 0 0 "">
  <300 290 320 290 "" 0 0 0 "">
  <270 320 270 390 "" 0 0 0 "">
  <220 290 240 290 "" 0 0 0 "">
  <270 200 310 200 "" 0 0 0 "">
  <270 200 270 260 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 642 728 394 256 3 #c0c0c0 1 10 0 1e-09 0.02 0.102319 1 -1 0.5 1 1 -1 0.5 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/sw1.beta@sw1.i(vpr_ic)" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 650 412 386 242 3 #c0c0c0 1 01 1 -1 0.2 1 0 1e-13 0.02 0.12 1 -1 0.5 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/sw1.i(vpr_ib)" #0000ff 0 3 0 0 0>
	<"ngspice/sw1.i(vpr_ic)" #ff0000 0 3 0 0 0>
	<"ngspice/sw1.i(vpr_is)" #ff00ff 0 3 0 0 0>
	<"ngspice/sw1.beta" #00ff00 0 3 0 0 1>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
