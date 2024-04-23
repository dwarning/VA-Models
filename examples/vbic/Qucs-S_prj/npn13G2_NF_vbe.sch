<Qucs Schematic 24.2.1>
<Properties>
  <View=-99,-15,1151,723,0.952575,0,0>
  <Grid=10,10,1>
  <DataSet=npn13G2_NF_vbe.dat>
  <DataDisplay=npn13G2_NF_vbe.dpl>
  <OpenDisplay=0>
  <Script=npn13G2_vbic_NF.m>
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
  <BiasT X1 1 200 110 -9 -35 0 0 "1 uH" 0 "1 uF" 0>
  <GND * 1 100 190 0 0 0 0>
  <GND * 1 320 120 0 0 0 0>
  <Vdc Vbe 1 200 180 -76 -21 1 1 "1.0 V" 1>
  <GND * 1 200 220 0 0 0 0>
  <Pac P1 1 100 150 -98 -47 1 1 "1" 0 "50 Ohm" 1 "0 dBm" 1 "1 GHz" 1 "26.85" 0 "true" 0>
  <GND * 1 280 150 0 0 0 0>
  <BiasT X2 1 380 60 -11 -35 1 2 "1 uH" 0 "1 uF" 0>
  <GND * 1 380 170 0 0 0 0>
  <Vdc Vce 1 380 130 21 -19 0 1 "Vbe+Vcb" 1>
  <GND * 1 500 140 0 0 0 0>
  <Pac P2 1 500 100 23 -34 0 1 "2" 0 "50 Ohm" 1 "0 dBm" 1 "1 GHz" 1 "26.85" 0 "true" 0>
  <BJT_SPICE Q1 1 280 110 -26 34 0 0 "4" 1 "npn" 1 "X" 1 "npn13G2 nx=8" 1 "" 0 "" 0 "" 0 "" 0>
  <.SW SW1 1 350 290 0 66 0 0 "SP1" 1 "list" 1 "Vbe" 1 "0.78" 0 "0.84" 0 "[0.78; 0.80; 0.82; 0.84]" 1 "false" 0>
  <SpiceInclude SpiceInclude1 1 50 530 -33 16 0 0 "../Modelcards/SG13G2_hbt_woStatistics.hsp.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.DC DC1 1 20 290 0 40 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <SpicePar SpicePar1 1 40 380 -28 16 0 0 "Nx=8" 1 "Vbe=0.78" 1 "Vcb=0.25" 1>
  <.SP SP1 1 200 290 0 66 0 0 "lin" 1 "2 GHz" 1 "26 GHz" 1 "13" 1 "yes" 1 "1" 1 "2" 1 "no" 0 "no" 0>
  <.CUSTOMSIM CUSTOM1 1 370 510 0 51 0 0 "\npre_osdi vbic_1p3.osdi\n" 1 "" 0 "" 0>
</Components>
<Wires>
  <230 110 250 110 "" 0 0 0 "">
  <100 110 170 110 "" 0 0 0 "">
  <100 110 100 120 "" 0 0 0 "">
  <100 180 100 190 "" 0 0 0 "">
  <320 110 320 120 "" 0 0 0 "">
  <310 110 320 110 "" 0 0 0 "">
  <200 140 200 150 "" 0 0 0 "">
  <200 210 200 220 "" 0 0 0 "">
  <280 140 280 150 "" 0 0 0 "">
  <280 60 280 80 "" 0 0 0 "">
  <280 60 350 60 "" 0 0 0 "">
  <380 90 380 100 "" 0 0 0 "">
  <380 160 380 170 "" 0 0 0 "">
  <410 60 500 60 "" 0 0 0 "">
  <500 60 500 70 "" 0 0 0 "">
  <500 130 500 140 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Tab 649 682 288 337 3 #c0c0c0 1 00 1 0 1 1 1 0 1 1 1 0 1 52 315 0 225 1 0 0 "" "" "">
	<"ngspice/ac.v(nf)" #0000ff 0 3 0 0 0>
  </Tab>
  <Rect 631 298 419 271 3 #c0c0c0 1 00 1 2e+09 5e+09 2.6e+10 1 18.0169 5 35 1 -1 0.5 1 315 0 225 1 0 0 "" "" "">
	<"ngspice/ac.v(nf)" #0000ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
