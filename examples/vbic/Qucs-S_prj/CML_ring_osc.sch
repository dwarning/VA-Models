<Qucs Schematic 24.2.1>
<Properties>
  <View=-99,-35,1204,734,0.914174,0,0>
  <Grid=10,10,1>
  <DataSet=CML_ring_osc.dat>
  <DataDisplay=CML_ring_osc.dpl>
  <OpenDisplay=0>
  <Script=CML_ring_osc.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Erstellt von:>
  <FrameText2=Datum:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <GND * 1 70 300 0 0 0 0>
  <GND * 1 70 30 0 0 0 2>
  <R R1 1 70 150 15 -26 0 1 "10 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <Vdc V1 1 70 270 18 -26 0 1 "-5 V" 1>
  <BJT_SPICE Q1 1 70 60 0 34 1 2 "4" 1 "npn" 1 "N" 1 "M_BFP780" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM1 1 260 460 0 51 0 0 "\npre_osdi vbic_1p3.osdi\n" 1 "" 0 "" 0>
  <.TR TR1 1 30 380 0 51 0 0 "lin" 1 "0" 1 "100n" 1 "200001" 1 "Trapezoidal" 0 "2" 0 "1 ns" 0 "1e-16" 0 "150" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "26.85" 0 "1e-3" 0 "1e-6" 0 "1" 0 "CroutLU" 0 "no" 0 "no" 1 "10 ps" 1>
  <GND * 1 1000 460 0 0 0 0>
  <Vpulse Vref 1 1000 410 18 -26 0 1 "-5 V" 1 "-2 V" 1 "10ps" 1 "1 ms" 1 "100 ps" 1 "1 ns" 0>
  <Sub INV8 1 930 190 54 28 0 3 "CML_stage.sch" 0>
  <Sub INV11 1 610 290 -65 35 0 2 "CML_stage.sch" 0>
  <Sub INV12 1 510 290 -64 35 0 2 "CML_stage.sch" 0>
  <Sub INV13 1 410 290 -64 35 0 2 "CML_stage.sch" 0>
  <Sub INV14 1 310 290 -62 35 0 2 "CML_stage.sch" 0>
  <Sub INV15 1 210 290 -65 35 0 2 "CML_stage.sch" 0>
  <Sub INV10 1 710 290 -64 35 0 2 "CML_stage.sch" 0>
  <Sub INV9 1 810 290 -56 35 0 2 "CML_stage.sch" 0>
  <Sub INV1 1 210 90 20 44 0 0 "CML_stage.sch" 0>
  <Sub INV7 1 810 90 20 44 0 0 "CML_stage.sch" 0>
  <Sub INV6 1 710 90 20 44 0 0 "CML_stage.sch" 0>
  <Sub INV5 1 610 90 20 44 0 0 "CML_stage.sch" 0>
  <Sub INV4 1 510 90 20 44 0 0 "CML_stage.sch" 0>
  <Sub INV3 1 410 90 20 44 0 0 "CML_stage.sch" 0>
  <Sub INV2 1 310 90 20 44 0 0 "CML_stage.sch" 0>
  <SpiceInclude SpiceInclude1 1 290 400 -33 16 0 0 "../Modelcards/vbic_va.mod" 1 "" 0 "" 0 "" 0 "" 0>
</Components>
<Wires>
  <810 20 810 30 "" 0 0 0 "">
  <810 20 1000 20 "" 0 0 0 "">
  <410 20 410 30 "" 0 0 0 "">
  <410 20 510 20 "" 0 0 0 "">
  <510 20 510 30 "" 0 0 0 "">
  <510 20 610 20 "" 0 0 0 "">
  <610 20 610 30 "" 0 0 0 "">
  <610 20 710 20 "" 0 0 0 "">
  <710 20 810 20 "" 0 0 0 "">
  <710 20 710 30 "" 0 0 0 "">
  <810 150 810 160 "" 0 0 0 "">
  <1000 20 1000 190 "" 0 0 0 "">
  <1000 190 1000 360 "" 0 0 0 "">
  <990 190 1000 190 "" 0 0 0 "">
  <810 350 810 360 "" 0 0 0 "">
  <810 220 810 230 "" 0 0 0 "">
  <810 160 860 160 "" 0 0 0 "">
  <860 160 860 190 "" 0 0 0 "">
  <860 190 870 190 "" 0 0 0 "">
  <860 190 860 220 "" 0 0 0 "">
  <810 220 860 220 "" 0 0 0 "">
  <410 150 410 160 "" 0 0 0 "">
  <410 160 510 160 "" 0 0 0 "">
  <510 150 510 160 "" 0 0 0 "">
  <510 160 610 160 "" 0 0 0 "">
  <610 150 610 160 "" 0 0 0 "">
  <610 160 710 160 "" 0 0 0 "">
  <710 160 810 160 "" 0 0 0 "">
  <710 150 710 160 "" 0 0 0 "">
  <840 120 900 120 "" 0 0 0 "">
  <900 120 900 160 "" 0 0 0 "">
  <840 60 960 60 "" 0 0 0 "">
  <960 60 960 160 "" 0 0 0 "">
  <900 220 900 260 "" 0 0 0 "">
  <840 260 900 260 "" 0 0 0 "">
  <960 220 960 320 "" 0 0 0 "">
  <840 320 960 320 "" 0 0 0 "">
  <340 60 380 60 "" 0 0 0 "">
  <340 120 380 120 "" 0 0 0 "">
  <440 60 480 60 "" 0 0 0 "">
  <440 120 480 120 "" 0 0 0 "">
  <540 60 580 60 "" 0 0 0 "">
  <540 120 580 120 "" 0 0 0 "">
  <640 60 680 60 "" 0 0 0 "">
  <640 120 680 120 "" 0 0 0 "">
  <740 60 780 60 "" 0 0 0 "">
  <740 120 780 120 "" 0 0 0 "">
  <310 20 410 20 "" 0 0 0 "">
  <310 20 310 30 "" 0 0 0 "">
  <310 160 410 160 "" 0 0 0 "">
  <310 150 310 160 "" 0 0 0 "">
  <70 90 70 120 "output" 80 90 17 "">
  <70 180 70 220 "" 0 0 0 "">
  <70 220 70 240 "" 0 0 0 "">
  <20 220 70 220 "" 0 0 0 "">
  <20 60 20 220 "" 0 0 0 "">
  <20 60 40 60 "" 0 0 0 "">
  <810 360 1000 360 "enable" 940 330 124 "">
  <100 60 140 60 "" 0 0 0 "">
  <610 350 610 360 "" 0 0 0 "">
  <610 220 610 230 "" 0 0 0 "">
  <510 360 610 360 "" 0 0 0 "">
  <510 350 510 360 "" 0 0 0 "">
  <510 220 610 220 "" 0 0 0 "">
  <510 220 510 230 "" 0 0 0 "">
  <540 320 580 320 "" 0 0 0 "">
  <540 260 580 260 "" 0 0 0 "">
  <310 360 410 360 "" 0 0 0 "">
  <410 360 510 360 "" 0 0 0 "">
  <410 350 410 360 "" 0 0 0 "">
  <410 220 510 220 "" 0 0 0 "">
  <410 220 410 230 "" 0 0 0 "">
  <440 320 480 320 "" 0 0 0 "">
  <440 260 480 260 "" 0 0 0 "">
  <310 350 310 360 "" 0 0 0 "">
  <310 220 410 220 "" 0 0 0 "">
  <310 220 310 230 "" 0 0 0 "">
  <340 320 380 320 "" 0 0 0 "">
  <340 260 380 260 "" 0 0 0 "">
  <610 360 710 360 "" 0 0 0 "">
  <710 360 810 360 "" 0 0 0 "">
  <710 350 710 360 "" 0 0 0 "">
  <610 220 710 220 "" 0 0 0 "">
  <710 220 810 220 "" 0 0 0 "">
  <710 220 710 230 "" 0 0 0 "">
  <640 320 680 320 "" 0 0 0 "">
  <640 260 680 260 "" 0 0 0 "">
  <740 320 780 320 "" 0 0 0 "">
  <740 260 780 260 "" 0 0 0 "">
  <210 360 310 360 "" 0 0 0 "">
  <210 350 210 360 "" 0 0 0 "">
  <70 220 210 220 "" 0 0 0 "">
  <210 220 310 220 "" 0 0 0 "">
  <210 220 210 230 "" 0 0 0 "">
  <140 60 140 320 "out1" 170 150 118 "">
  <140 320 180 320 "" 0 0 0 "">
  <170 260 180 260 "" 0 0 0 "">
  <240 320 280 320 "" 0 0 0 "">
  <240 260 280 260 "" 0 0 0 "">
  <210 160 310 160 "" 0 0 0 "">
  <210 150 210 160 "" 0 0 0 "">
  <210 20 310 20 "" 0 0 0 "">
  <210 20 210 30 "" 0 0 0 "">
  <240 120 280 120 "" 0 0 0 "">
  <240 60 280 60 "" 0 0 0 "">
  <170 120 170 260 "out2" 200 170 84 "">
  <170 120 180 120 "" 0 0 0 "">
  <140 60 180 60 "" 0 0 0 "">
  <1000 360 1000 380 "" 0 0 0 "">
  <1000 440 1000 460 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 450 693 527 319 3 #c0c0c0 1 00 1 0 2e-09 8e-09 0 -3 1 0.5 1 -1 1 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/tran.v(output)" #0000ff 0 3 0 0 0>
	<"ngspice/tran.v(enable)" #ff0000 0 3 0 0 0>
	<"ngspice/tran.v(out1)" #ff00ff 0 3 0 0 0>
	<"ngspice/tran.v(out2)" #00ff00 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>