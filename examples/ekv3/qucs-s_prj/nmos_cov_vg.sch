<Qucs Schematic 24.2.1>
<Properties>
  <View=-9,8,1106,666,1.06912,0,0>
  <Grid=10,10,1>
  <DataSet=nmos_cov_vg.dat>
  <DataDisplay=nmos_cov_vg.dpl>
  <OpenDisplay=0>
  <Script=nmos_cov_vg.m>
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
  <Vac V1 1 100 100 18 -26 0 1 "1 V" 1 "1 kHz" 0 "0" 0 "0" 0 "0" 0 "0" 0>
  <GND * 1 770 200 0 0 0 0>
  <GND * 1 280 200 0 0 0 0>
  <GND * 1 520 200 0 0 0 0>
  <GND * 1 490 200 0 0 0 0>
  <GND * 1 550 200 0 0 0 0>
  <GND * 1 740 200 0 0 0 0>
  <.CUSTOMSIM CUSTOM1 1 60 240 0 51 0 0 "\npre_osdi ekv3.osdi\nlet points = 300\nset vgsp = ''$&points''\nlet Cgdsb = vector($vgsp)\nlet Cgb = vector($vgsp)\nlet Cgds = vector($vgsp)\nlet Vg = vector($vgsp)\nlet ind = 0\nwhile ind < $vgsp\n  let v1_act = -1.5+ind*0.01\n  alter Vg = $&v1_act\n  ac lin 1 1meg 1meg \n  let Cgdsb[ind] = imag(Vg_dsb#branch)/(2*pi*1e6)\n  let Cgb[ind] = imag(Vg_b#branch)/(2*pi*1e6)\n  let Cgds[ind] = imag(Vg_ds#branch)/(2*pi*1e6)\n  let Vg[ind] = $&v1_act\n  let ind = ind + 1\n  destroy ac1\nend\n\n" 1 "Cgdsb;Cgb;Cgds;Vg" 0 "" 0>
  <GND * 1 100 200 0 0 0 0>
  <MOS_SPICE X1 1 280 100 -248 -26 0 3 "X" 0 "4" 0 "nmos" 0 "nch90 w=10u l=0.1u nf=4" 1 "+ad=10e-12 as=10e-12" 1 "+pd=14u ps=14u" 1 "" 0 "" 0>
  <MOS_SPICE X2 1 520 100 -248 -26 0 3 "X" 0 "4" 0 "nmos" 0 "nch90 w=10u l=0.1u nf=4" 1 "+ad=10e-12 as=10e-12" 1 "+pd=14u ps=14u" 1 "" 0 "" 0>
  <MOS_SPICE X3 1 770 100 -248 -26 0 3 "X" 0 "4" 0 "nmos" 0 "nch90 w=10u l=0.1u nf=4" 1 "+ad=10e-12 as=10e-12" 1 "+pd=14u ps=14u" 1 "" 0 "" 0>
  <SpiceInclude SpiceInclude1 1 330 250 -34 16 0 0 "../Modelcards/90nm_ngspice.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <Vdc Vg 1 100 170 -54 -14 0 1 "1" 1>
  <Vdc Vg_dsb 1 280 170 -54 -14 0 1 "0" 1>
  <Vdc Vg_b 1 520 170 -54 -14 0 1 "0" 1>
  <Vdc Vg_ds 1 740 170 -54 -14 0 1 "0" 1>
</Components>
<Wires>
  <100 50 100 70 "" 0 0 0 "">
  <520 50 520 70 "" 0 0 0 "">
  <770 50 770 70 "" 0 0 0 "">
  <100 50 280 50 "" 0 0 0 "">
  <520 50 770 50 "" 0 0 0 "">
  <550 100 550 200 "" 0 0 0 "">
  <490 100 490 200 "" 0 0 0 "">
  <520 120 520 140 "" 0 0 0 "">
  <280 120 280 140 "" 0 0 0 "">
  <770 120 770 200 "" 0 0 0 "">
  <800 100 800 130 "" 0 0 0 "">
  <740 130 800 130 "" 0 0 0 "">
  <740 100 740 130 "" 0 0 0 "">
  <740 130 740 140 "" 0 0 0 "">
  <100 130 100 140 "" 0 0 0 "">
  <250 120 280 120 "" 0 0 0 "">
  <250 100 250 120 "" 0 0 0 "">
  <280 50 520 50 "" 0 0 0 "">
  <280 50 280 70 "" 0 0 0 "">
  <280 120 310 120 "" 0 0 0 "">
  <310 100 310 120 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 640 623 425 313 3 #c0c0c0 1 00 1 -1.5 0.5 1.5 1 0 5e-13 3e-12 1 -1 0.5 1 315 0 225 1 0 0 "Vg" "" "">
	<"ngspice/cgb@vg" #0000ff 0 3 0 0 0>
	<"ngspice/cgds@vg" #ff0000 0 3 0 0 0>
	<"ngspice/cgdsb@vg" #ff00ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
