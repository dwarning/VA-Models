<Qucs Schematic 24.2.1>
<Properties>
  <View=-40,-96,1152,608,0.999161,0,0>
  <Grid=10,10,1>
  <DataSet=pmos_id_vg_vb.dat>
  <DataDisplay=pmos_id_vg_vb.dpl>
  <OpenDisplay=0>
  <Script=EKV3_idvd_pmos.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Title:>
  <FrameText1=Drawn by:>
  <FrameText2=Datum:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <GND * 1 60 240 0 0 0 0>
  <GND * 1 160 220 0 0 0 0>
  <GND * 1 320 160 0 0 0 0>
  <IProbe Pr1 1 240 60 -11 -59 0 0>
  <GND * 1 230 220 0 0 0 0>
  <Vdc VG 1 60 190 -54 -14 1 3 "1" 1>
  <Vdc VB 1 230 180 28 -16 1 3 "0" 1>
  <Vdc VD 1 320 110 28 -16 1 3 "0.05" 1>
  <.DC DC1 1 10 290 0 41 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <.SW SW1 1 190 290 0 51 0 0 "DC1" 1 "lin" 1 "VG" 1 "0" 1 "1.5" 1 "151" 1 "false" 0>
  <.SW SW2 1 350 290 0 51 0 0 "SW1" 1 "lin" 1 "VB" 1 "0" 1 "-1.5" 1 "4" 1 "false" 0>
  <MOS_SPICE X1 1 160 150 -26 34 0 0 "X" 0 "4" 0 "pmos" 0 "pch90 w=3u l=0.1u nf=1" 1 "+ ad=3p as=3p" 1 "+ pd=8u ps=8u" 1 "" 0 "" 0>
  <SpiceInclude SpiceInclude1 1 40 370 -34 16 0 0 "../Modelcards/90nm_ngspice.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <SpiceInclude SpiceInclude2 0 40 450 -34 16 0 0 "../Modelcards/90nm_xyce.lib" 1 "" 0 "" 0 "" 0 "" 0>
</Components>
<Wires>
  <160 180 160 220 "" 0 0 0 "">
  <60 150 130 150 "" 0 0 0 "">
  <60 150 60 160 "" 0 0 0 "">
  <60 220 60 240 "" 0 0 0 "">
  <320 140 320 160 "" 0 0 0 "">
  <320 60 320 80 "" 0 0 0 "">
  <270 60 320 60 "" 0 0 0 "">
  <160 60 160 120 "" 0 0 0 "">
  <160 60 210 60 "" 0 0 0 "">
  <230 210 230 220 "" 0 0 0 "">
  <180 150 230 150 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 610 511 501 471 3 #c0c0c0 1 00 1 0 0.2 1.5 1 -9.0724e-06 2e-05 0.0001 1 -1 0.2 1 315 0 225 1 0 0 "Vd" "Id" "">
	<"ngspice/sw1.i(pr1)" #0000ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
  <Text 0 0 14 #ff0000 0 "EKV3 pmos DC curves">
</Paintings>
