<Qucs Schematic 24.2.1>
<Properties>
  <View=-40,-56,1162,666,0.670549,0,0>
  <Grid=10,10,1>
  <DataSet=nmos_id_vd_vg.dat>
  <DataDisplay=nmos_id_vd_vg.dpl>
  <OpenDisplay=0>
  <Script=EKV3_idvd_nmos.m>
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
  <.DC DC1 1 30 290 0 42 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <GND * 1 60 230 0 0 0 0>
  <GND * 1 160 210 0 0 0 0>
  <GND * 1 320 150 0 0 0 0>
  <IProbe Pr1 1 240 50 -11 -59 1 2>
  <Vdc VG 1 60 180 -54 -14 0 1 "1" 1>
  <Vdc VD 1 320 100 28 -16 0 1 "1" 1>
  <.SW SW1 1 210 290 0 65 0 0 "DC1" 1 "lin" 1 "VD" 1 "0" 1 "1.5" 1 "101" 1 "false" 0>
  <.SW SW2 1 360 290 0 65 0 0 "SW1" 1 "lin" 1 "VG" 1 "0.5" 1 "1.5" 1 "6" 1 "false" 0>
  <MOS_SPICE X1 1 160 140 -26 34 0 0 "X" 0 "4" 0 "nmos" 0 "nch90 w=1u l=0.1u nf=1" 1 "+ad=1e-12 as=1e-12" 1 "+pd=4u ps=4u" 1 "" 0 "" 0>
  <SpiceInclude SpiceInclude2 0 60 460 -34 16 0 0 "../Modelcards/90nm_xyce.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <SpiceInclude SpiceInclude1 1 60 380 -34 16 0 0 "../Modelcards/90nm_ngspice.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM1 1 30 530 0 51 0 0 "pre_osdi ekv3.osdi\n" 1 "" 0 "" 0>
</Components>
<Wires>
  <160 190 200 190 "" 0 0 0 "">
  <60 210 60 230 "" 0 0 0 "">
  <160 190 160 210 "" 0 0 0 "">
  <320 130 320 150 "" 0 0 0 "">
  <320 50 320 70 "" 0 0 0 "">
  <270 50 320 50 "" 0 0 0 "">
  <200 140 200 190 "" 0 0 0 "">
  <180 140 200 140 "" 0 0 0 "">
  <160 170 160 190 "" 0 0 0 "">
  <60 140 60 150 "" 0 0 0 "">
  <60 140 130 140 "" 0 0 0 "">
  <160 50 210 50 "" 0 0 0 "">
  <160 50 160 110 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 620 501 501 471 3 #c0c0c0 1 00 1 0 0.2 1.5 1 -0.000111647 0.0002 0.00122812 1 -1 0.2 1 315 0 225 1 0 0 "Vd" "Id" "">
	<"ngspice/sw1.i(pr1)" #0000ff 0 3 0 0 0>
	<"xyce/I(PR1)" #ff0000 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
  <Text 0 0 14 #ff0000 0 "EKV3 nmos DC curves">
</Paintings>
