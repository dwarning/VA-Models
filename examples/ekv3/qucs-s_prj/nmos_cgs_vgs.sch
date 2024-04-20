<Qucs Schematic 24.2.1>
<Properties>
  <View=-34,-66,931,504,1.2342,0,0>
  <Grid=10,10,1>
  <DataSet=nmos_cgs_vgs.dat>
  <DataDisplay=nmos_cgs_vgs.dpl>
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
  <GND * 1 160 220 0 0 0 0>
  <GND * 1 320 160 0 0 0 0>
  <IProbe Pr1 1 240 60 -11 -59 1 2>
  <GND * 1 220 220 0 0 0 0>
  <Vdc VB1 1 220 180 28 -16 0 1 "0" 1>
  <Vdc VD1 1 320 110 28 -16 0 1 "0.05" 1>
  <GND * 1 60 270 0 0 0 0>
  <Vac V2 1 60 180 18 -26 0 1 "1 V" 1 "1 kHz" 0 "0" 0 "0" 0 "0" 0 "0" 0>
  <Vdc V1 1 60 240 -54 -14 0 1 "1" 1>
  <.CUSTOMSIM CUSTOM2 1 400 10 0 51 0 0 "\nlet vgspoints = 160\nset vgsp = ''$&vgspoints''\nlet vecCgs = vector($vgsp)\nlet vecVgs = vector($vgsp)\nlet vind = 0\nwhile vind < $vgsp\n  let v1_act = -0.1+vind*0.01\n  alter V1 = $&v1_act\n  ac lin 1 1meg 1meg \n  let Cj = -imag(V1#branch)/(2*pi*1e6)\n  let vecCgs[vind] = Cj\n  let vecVgs[vind] = $&v1_act\n  let vind = vind + 1\n  destroy ac1\nend\n\n" 1 "vecCgs;vecVgs;" 0 "" 0>
  <SpiceInclude SpiceInclude1 1 180 290 -34 16 0 0 "../Modelcards/90nm_ngspice.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM3 1 20 350 0 51 0 0 "pre_osdi ../../../osdilibs/ekv3.osdi\n" 1 "" 0 "" 0>
  <MOS_SPICE X1 1 160 150 -26 34 0 0 "X" 0 "4" 0 "nmos" 0 "nch90 w=10u l=0.1u nf=4" 1 "+ad=10e-12 as=10e-12" 1 "+pd=14u ps=14u" 1 "" 0 "" 0>
</Components>
<Wires>
  <320 140 320 160 "" 0 0 0 "">
  <320 60 320 80 "" 0 0 0 "">
  <270 60 320 60 "" 0 0 0 "">
  <160 180 160 220 "" 0 0 0 "">
  <160 60 210 60 "" 0 0 0 "">
  <160 60 160 120 "" 0 0 0 "">
  <220 210 220 220 "" 0 0 0 "">
  <180 150 220 150 "" 0 0 0 "">
  <60 150 130 150 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 650 180 240 160 3 #c0c0c0 1 00 1 0 0.2 1 1 -0.1 0.5 1.1 1 -0.1 0.5 1.1 315 0 225 1 0 0 "" "" "">
	<"ngspice/veccgs@vecvgs" #0000ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
