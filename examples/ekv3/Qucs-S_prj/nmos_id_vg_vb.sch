<Qucs Schematic 24.2.1>
<Properties>
  <View=-40,-85,1182,636,0.974632,0,0>
  <Grid=10,10,1>
  <DataSet=nmos_id_vg_vb.dat>
  <DataDisplay=nmos_id_vg_vb.dpl>
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
  <.DC DC1 1 30 340 0 40 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <GND * 1 60 280 0 0 0 0>
  <GND * 1 160 260 0 0 0 0>
  <GND * 1 320 200 0 0 0 0>
  <IProbe Pr1 1 240 100 -11 -59 1 2>
  <GND * 1 220 260 0 0 0 0>
  <Vdc VG 1 60 230 -54 -14 0 1 "1" 1>
  <Vdc VB 1 220 220 28 -16 0 1 "0" 1>
  <.SW SW1 1 210 340 0 65 0 0 "DC1" 1 "lin" 1 "VG" 1 "0" 1 "1.5" 1 "101" 1 "false" 0>
  <Vdc VD 1 320 150 28 -16 0 1 "0.05" 1>
  <.SW SW2 1 360 340 0 65 0 0 "SW1" 1 "lin" 1 "VB" 1 "0" 1 "-1.5" 1 "4" 1 "false" 0>
  <MOS_SPICE X1 1 160 190 -26 34 0 0 "X" 0 "4" 0 "nmos" 0 "nch90 w=1u l=0.1u nf=1" 1 "+ad=1e-12 as=1e-12" 1 "+pd=4u ps=4u" 1 "" 0 "" 0>
  <SpiceInclude SpiceInclude1 1 60 420 -34 16 0 0 "../Modelcards/90nm_ngspice.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <SpiceInclude SpiceInclude2 0 60 490 -34 16 0 0 "../Modelcards/90nm_xyce.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM1 1 390 20 0 51 0 0 "pre_osdi ekv3.osdi\n" 1 "" 0 "" 0>
</Components>
<Wires>
  <60 260 60 280 "" 0 0 0 "">
  <320 180 320 200 "" 0 0 0 "">
  <320 100 320 120 "" 0 0 0 "">
  <270 100 320 100 "" 0 0 0 "">
  <160 220 160 260 "" 0 0 0 "">
  <60 190 60 200 "" 0 0 0 "">
  <60 190 130 190 "" 0 0 0 "">
  <160 100 210 100 "" 0 0 0 "">
  <160 100 160 160 "" 0 0 0 "">
  <220 250 220 260 "" 0 0 0 "">
  <180 190 220 190 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 640 551 501 471 3 #c0c0c0 1 00 1 -1 0.2 1 1 -1 0.2 1 1 -1 0.2 1 315 0 225 1 0 0 "" "" "">
	<"ngspice/sw1.i(pr1)" #0000ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
  <Text 0 0 14 #ff0000 0 "EKV3 nmos DC curves">
</Paintings>
