<Qucs Schematic 24.2.1>
<Properties>
  <View=-112,-34,1049,651,1.02628,0,0>
  <Grid=10,10,1>
  <DataSet=npn13G2_ic_ib_vbe.dat>
  <DataDisplay=npn13G2_ic_ib_vbe.dpl>
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
  <GND * 1 160 230 0 0 0 0>
  <GND * 1 30 230 0 0 0 0>
  <IProbe Pr_Ic 1 230 40 -26 16 1 2>
  <IProbe Pr_Ib 1 80 130 -26 16 0 0>
  <GND * 1 310 230 0 0 0 0>
  <Vdc Vbe 1 30 180 18 -26 0 1 "0.5" 1>
  <Vdc Vce 1 310 130 18 -26 0 1 "1.0" 1>
  <SpiceOptions SpiceOptions1 1 310 300 -34 16 0 0 "DEVICE" 0 "GMIN=1e-13" 1>
  <GND * 1 270 230 0 0 0 0>
  <IProbe Pr_Is 1 270 180 -50 -26 0 3>
  <.DC DC1 1 20 290 0 43 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <.SW SW1 1 20 370 0 51 0 0 "DC1" 1 "lin" 1 "Vbe" 1 "0.4" 1 "1.0" 1 "61" 1 "false" 0>
  <SpiceInclude SpiceInclude1 1 50 560 -33 16 0 0 "../Modelcards/SG13G2_hbt_woStatistics.hsp.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM1 1 270 370 0 51 0 0 "\npre_osdi vbic_1p3.osdi\n" 1 "" 0 "" 0>
  <NutmegEq NutmegEq1 1 300 500 -28 16 0 0 "SW1" 1 "Beta=i(vpr_ic)/i(vpr_ib)" 1>
  <BJT_SPICE Q1 1 160 130 -26 34 0 0 "4" 1 "npn" 1 "X" 1 "npn13G2 nx=8" 1 "" 0 "" 0 "" 0 "" 0>
</Components>
<Wires>
  <310 40 310 100 "" 0 0 0 "">
  <260 40 310 40 "" 0 0 0 "">
  <30 210 30 230 "" 0 0 0 "">
  <30 130 30 150 "" 0 0 0 "">
  <30 130 50 130 "" 0 0 0 "">
  <310 160 310 230 "" 0 0 0 "">
  <270 210 270 230 "" 0 0 0 "">
  <110 130 130 130 "" 0 0 0 "">
  <160 40 200 40 "" 0 0 0 "">
  <160 40 160 100 "" 0 0 0 "">
  <160 160 160 230 "" 0 0 0 "">
  <190 130 270 130 "" 0 0 0 "">
  <270 130 270 150 "" 0 0 0 "">
  <110 130 110 130 "B" 120 100 0 "">
</Wires>
<Diagrams>
  <Rect 540 252 386 242 3 #c0c0c0 1 01 1 0.4 0.1 1 0 1e-13 0.02 0.12 1 80.8831 200 864.465 315 0 225 0 0 0 "Vbe" "Ic,b,s" "Beta">
	<"ngspice/sw1.i(vpr_ib)" #0000ff 0 3 0 0 0>
	<"ngspice/sw1.i(vpr_ic)" #ff0000 0 3 0 0 0>
	<"ngspice/sw1.i(vpr_is)" #ff00ff 0 3 0 0 0>
	<"ngspice/sw1.beta" #00ff00 0 3 0 0 1>
  </Rect>
  <Rect 532 578 394 256 3 #c0c0c0 1 10 0 1e-09 1 0.01 1 -1 0.5 1 1 -1 0.5 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/sw1.beta@sw1.i(vpr_ic)" #0000ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
