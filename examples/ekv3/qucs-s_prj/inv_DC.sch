<Qucs Schematic 24.2.1>
<Properties>
  <View=-40,-59,1099,613,1.04565,0,0>
  <Grid=10,10,1>
  <DataSet=inv_DC.dat>
  <DataDisplay=inv_DC.dpl>
  <OpenDisplay=0>
  <Script=EKV3_inv_dc.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=>
  <FrameText1=>
  <FrameText2=>
  <FrameText3=>
</Properties>
<Symbol>
</Symbol>
<Components>
  <.DC DC1 1 10 40 0 40 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <.SW SW1 1 10 110 0 65 0 0 "DC1" 1 "lin" 1 "V1" 1 "0" 1 "1.5" 1 "101" 1 "false" 0>
  <SpiceInclude SpiceInclude1 1 40 320 -34 16 0 0 "../Modelcards/90nm_ngspice.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <GND * 5 340 350 0 0 0 0>
  <GND * 5 380 310 0 0 0 0>
  <GND * 5 190 330 0 0 0 0>
  <GND * 1 560 250 0 0 0 0>
  <Vdc V1 1 190 280 -49 -18 0 1 "1" 1>
  <GND * 5 470 90 0 0 0 0>
  <Vdc V2 1 420 70 -26 -59 0 2 "1.5" 1>
  <R R1 1 520 230 -26 15 0 0 "1 Meg" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <MOS_SPICE X1 1 340 160 -26 34 0 0 "X" 0 "4" 0 "pmos" 0 "pch90 w=3u l=0.1u nf=1" 1 "+ ad=3p as=3p" 1 "+ pd=8u ps=8u" 1 "" 0 "" 0>
  <MOS_SPICE X2 1 340 290 -26 34 0 0 "X" 0 "4" 0 "nmos" 0 "nch90 w=1u l=0.1u nf=1" 1 "+ad=1e-12 as=1e-12" 1 "+pd=4u ps=4u" 1 "" 0 "" 0>
  <SpiceInclude SpiceInclude2 0 40 400 -34 16 0 0 "../Modelcards/90nm_xyce.lib" 1 "" 0 "" 0 "" 0 "" 0>
</Components>
<Wires>
  <340 320 340 350 "" 0 0 0 "">
  <270 290 310 290 "" 0 0 0 "">
  <270 160 310 160 "" 0 0 0 "">
  <360 290 380 290 "" 0 0 0 "">
  <380 290 380 310 "" 0 0 0 "">
  <360 160 370 160 "" 0 0 0 "">
  <370 100 370 160 "" 0 0 0 "">
  <340 100 340 130 "" 0 0 0 "">
  <340 100 370 100 "" 0 0 0 "">
  <190 310 190 330 "" 0 0 0 "">
  <270 160 270 230 "" 0 0 0 "">
  <270 230 270 290 "" 0 0 0 "">
  <190 230 270 230 "in" 199 190 32 "">
  <190 230 190 250 "" 0 0 0 "">
  <340 190 340 230 "" 0 0 0 "">
  <340 230 340 260 "" 0 0 0 "">
  <340 230 490 230 "out" 470 190 110 "">
  <560 230 560 250 "" 0 0 0 "">
  <550 230 560 230 "" 0 0 0 "">
  <340 70 340 100 "" 0 0 0 "">
  <340 70 390 70 "" 0 0 0 "">
  <470 70 470 90 "" 0 0 0 "">
  <450 70 470 70 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 597 371 461 292 3 #c0c0c0 1 00 1 -1 0.2 1 1 -1 0.5 1 1 -1 0.5 1 315 0 225 1 0 0 "" "" "">
	<"ngspice/sw1.v(in)" #0000ff 0 3 0 0 0>
	<"ngspice/sw1.v(out)" #ff0000 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
  <Text 0 0 14 #ff0000 0 "EKV3 inverter DC input test">
</Paintings>
