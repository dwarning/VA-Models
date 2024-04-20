<Qucs Schematic 24.2.1>
<Properties>
  <View=-60,-40,846,495,1.31402,0,0>
  <Grid=10,10,1>
  <DataSet=nmos_vd_vg_NOISE.dat>
  <DataDisplay=nmos_vd_vg_NOISE.dpl>
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
  <GND * 1 220 190 0 0 0 0>
  <Vac V1 1 80 190 18 -26 0 1 "1 V" 1 "1 kHz" 0 "0" 0 "0" 0 "0" 0 "0" 0>
  <GND * 1 80 230 0 0 0 0>
  <GND * 1 320 190 0 0 0 0>
  <GND * 1 380 190 0 0 0 0>
  <CCVS SRC1 1 350 60 -26 34 0 0 "1 Ohm" 1 "0" 0>
  <BiasT X2 1 160 120 -26 34 0 0 "1 H" 0 "1 F" 0>
  <GND * 1 160 230 0 0 0 0>
  <R R1 1 440 80 15 -26 0 1 "1 GOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <GND * 1 440 190 0 0 0 0>
  <Vdc VG 1 160 190 -54 -14 0 1 "1.0" 1>
  <Vdc VD 1 320 140 28 -16 0 1 "0.5" 1>
  <.DC DC1 0 30 270 0 42 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <.NOISE NOISE1 1 210 270 0 65 0 0 "log" 1 "1 MegHz" 1 "10 GHz" 1 "101" 1 "v(sid)" 1 "V1" 1>
  <MOS_SPICE X1 1 220 120 -214 -85 0 0 "X" 0 "4" 0 "nmos" 0 "nch90 w=10u l=0.1u nf=4" 1 "+ad=10e-12 as=10e-12" 1 "+pd=14u ps=14u" 1 "" 0 "" 0>
  <SpiceInclude SpiceInclude2 0 570 110 -34 16 0 0 "../Modelcards/90nm_xyce.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <SpiceInclude SpiceInclude1 1 570 30 -34 16 0 0 "../Modelcards/90nm_ngspice.lib" 1 "" 0 "" 0 "" 0 "" 0>
</Components>
<Wires>
  <220 170 260 170 "" 0 0 0 "">
  <220 170 220 190 "" 0 0 0 "">
  <260 120 260 170 "" 0 0 0 "">
  <240 120 260 120 "" 0 0 0 "">
  <220 150 220 170 "" 0 0 0 "">
  <80 220 80 230 "" 0 0 0 "">
  <220 30 220 90 "D" 250 40 37 "">
  <220 30 320 30 "" 0 0 0 "">
  <320 170 320 190 "" 0 0 0 "">
  <380 90 380 190 "" 0 0 0 "">
  <440 30 440 50 "" 0 0 0 "">
  <380 30 440 30 "Sid" 410 40 14 "">
  <320 90 320 110 "" 0 0 0 "">
  <80 120 80 160 "" 0 0 0 "">
  <80 120 130 120 "" 0 0 0 "">
  <160 150 160 160 "" 0 0 0 "">
  <160 220 160 230 "" 0 0 0 "">
  <440 110 440 190 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 380 420 240 160 3 #c0c0c0 1 11 1 0 1 0 1 0 1 0 1 -1 1 1 315 0 225 1 0 0 "" "" "">
	<"ngspice/ac.inoise_spectrum" #0000ff 0 3 0 0 0>
	<"ngspice/ac.onoise_spectrum" #ff0000 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
  <Text 0 0 14 #ff0000 0 "EKV3 nmos NOISE curves">
</Paintings>
