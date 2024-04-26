<Qucs Schematic 24.2.1>
<Properties>
  <View=-34,-44,931,576,1.23548,0,0>
  <Grid=10,10,1>
  <DataSet=npn_cje_cjc_cjs_vb.dat>
  <DataDisplay=npn_cje_cjc_cjs_vb.dpl>
  <OpenDisplay=0>
  <Script=cgs_nmos.m>
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
  <.CUSTOMSIM CUSTOM2 1 400 10 0 51 0 0 "\npre_osdi hicumL2.osdi\nlet points = 250\nset vgsp = ''$&points''\nlet Cje = vector($vgsp)\nlet Cjc = vector($vgsp)\nlet Cjs = vector($vgsp)\nlet Vbe = vector($vgsp)\nlet ind = 0\nwhile ind < $vgsp\n  let dc = -2+ind*0.01\n  alter @v1[dc] = $&dc\n  alter @v4[dc] = $&dc\n  ac lin 1 1e6 1e6\n  let Cje[ind] = (-imag(v1#branch)+imag(v2#branch))/(2*pi*1e6)\n  let Cjc[ind] = imag(v3#branch)/(2*pi*1e6)\n  let Cjs[ind] = (-imag(v3#branch)+imag(v4#branch))/(2*pi*1e6)\n  let Vbe[ind] = $&dc\n  let ind = ind + 1\n  destroy ac1\nend\n\n\n\n" 1 "Cje;Cjc;Cjs;Vbe" 0 "" 0>
  <GND * 1 80 170 0 0 0 0>
  <GND * 1 180 170 0 0 0 0>
  <GND * 1 240 170 0 0 0 0>
  <GND * 1 340 170 0 0 0 0>
  <Vdc V1 1 80 80 -54 -14 0 1 "1" 1>
  <Vac V11 1 80 140 18 -26 0 1 "1 V" 1 "1 kHz" 0 "0" 0 "0" 0 "0" 0 "0" 0>
  <GND * 1 80 380 0 0 0 0>
  <GND * 1 180 380 0 0 0 0>
  <GND * 1 240 380 0 0 0 0>
  <GND * 1 340 380 0 0 0 0>
  <Vdc V2 1 340 90 -73 -16 0 3 "0.0" 1>
  <Vdc V3 1 80 320 -73 -16 1 1 "0.0" 1>
  <Vac V44 1 340 330 18 -26 0 1 "1 V" 1 "1 kHz" 0 "0" 0 "0" 0 "0" 0 "0" 0>
  <Vdc V4 1 340 260 -54 -14 1 3 "1" 1>
  <SpiceInclude SpiceInclude1 1 50 430 -33 16 0 0 "../Modelcards/examples.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <BJT_SPICE Q1 1 180 50 -26 34 0 0 "4" 1 "npn" 1 "N" 1 "hicumL2va" 1 "" 0 "" 0 "" 0 "" 0>
  <BJT_SPICE Q2 1 180 260 -26 34 0 0 "4" 1 "npn" 1 "N" 1 "hicumL2va" 1 "" 0 "" 0 "" 0 "" 0>
</Components>
<Wires>
  <210 50 240 50 "" 0 0 0 "">
  <180 10 180 20 "" 0 0 0 "">
  <80 50 150 50 "" 0 0 0 "">
  <180 80 180 170 "" 0 0 0 "">
  <340 120 340 170 "" 0 0 0 "">
  <180 10 340 10 "" 0 0 0 "">
  <340 10 340 60 "" 0 0 0 "">
  <210 260 240 260 "" 0 0 0 "">
  <80 260 150 260 "" 0 0 0 "">
  <180 290 180 380 "" 0 0 0 "">
  <240 50 240 170 "" 0 0 0 "">
  <240 260 240 380 "" 0 0 0 "">
  <80 260 80 290 "" 0 0 0 "">
  <80 350 80 380 "" 0 0 0 "">
  <180 220 180 230 "" 0 0 0 "">
  <180 220 340 220 "" 0 0 0 "">
  <340 220 340 230 "" 0 0 0 "">
  <340 290 340 300 "" 0 0 0 "">
  <340 360 340 380 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 650 180 240 160 3 #c0c0c0 1 00 1 -2 0.5 0.5 1 2e-14 1e-14 5.34297e-14 1 -1 1 1 315 0 225 1 0 0 "Vbe" "" "">
	<"ngspice/cjc@vbe" #0000ff 0 3 0 0 0>
	<"ngspice/cje@vbe" #ff0000 0 3 0 0 0>
	<"ngspice/cjs@vbe" #ff00ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
