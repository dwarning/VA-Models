<Qucs Schematic 24.2.1>
<Properties>
  <View=-92,-41,975,590,1.11587,0,0>
  <Grid=10,10,1>
  <DataSet=npn_ft_ic.dat>
  <DataDisplay=npn_ft_ic.dpl>
  <OpenDisplay=0>
  <Script=HICUM_L2.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Titel>
  <FrameText1=Gezeichnet von:>
  <FrameText2=Datum:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <GND * 1 190 160 0 0 0 0>
  <GND * 1 50 160 0 0 0 0>
  <BiasT X1 1 50 130 34 -26 0 1 "1 H" 0 "1 F" 0>
  <Vdc Vce 1 320 210 18 -26 0 1 "1.2 V" 1>
  <GND * 1 380 250 0 0 0 0>
  <GND * 1 320 250 0 0 0 0>
  <GND * 1 270 250 0 0 0 0>
  <Idc Ic 1 270 190 18 -26 0 1 "10 mA" 1>
  <GND * 1 110 250 0 0 0 0>
  <Iac Ib 1 110 190 20 -26 0 1 "1" 1 "1 GHz" 0 "0" 0 "0" 0>
  <CCCS gain 1 350 130 -26 -70 1 0 "-2" 1 "0" 0>
  <.DC DC1 0 30 300 0 41 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <BJT_SPICE Q1 1 190 130 -26 34 0 0 "4" 1 "npn" 1 "N" 1 "hicumL2va" 1 "" 0 "" 0 "" 0 "" 0>
  <GND * 1 220 130 0 0 0 0>
  <SpiceInclude SpiceInclude1 1 60 380 -33 16 0 0 "../Modelcards/examples.lib" 1 "" 0 "" 0 "" 0 "" 0>
  <.CUSTOMSIM CUSTOM2 1 30 450 0 51 0 0 "\npre_osdi hicumL2.osdi" 1 "" 0 "custom#ac1#.plot;custom#ac1#.print" 0>
  <.CUSTOMSIM CUSTOM1 1 570 60 0 51 0 0 "\nlet vcea = 1.2\nalter Vce = $&vcea\nlet ac_runs =50\nlet Ice = vector(ac_runs)\nlet ft = vector(ac_runs)\nlet ind = 0\nlet ic_act = 0.001\nwhile ind < ac_runs\n  alter Ic = $&ic_act\n  ac dec 100 1e6 1e12\n  meas ac freq_at when vdb(vgain#branch)=0\n  let Ice[ind] = ic_act\n  let ft[ind] = freq_at\n  let ind = ind + 1\n  let ic_act = ic_act + 0.001\n  destroy ac1\nend" 1 "Ice;ft" 0 "" 0>
</Components>
<Wires>
  <50 50 50 100 "" 0 0 0 "">
  <50 50 400 50 "" 0 0 0 "">
  <400 50 400 100 "" 0 0 0 "">
  <380 100 400 100 "" 0 0 0 "">
  <320 160 320 180 "" 0 0 0 "">
  <380 160 380 250 "" 0 0 0 "">
  <320 240 320 250 "" 0 0 0 "">
  <270 220 270 250 "" 0 0 0 "">
  <190 100 270 100 "" 0 0 0 "">
  <270 100 320 100 "" 0 0 0 "">
  <270 100 270 160 "" 0 0 0 "">
  <110 220 110 250 "" 0 0 0 "">
  <80 130 110 130 "" 0 0 0 "">
  <110 130 160 130 "" 0 0 0 "">
  <110 130 110 160 "b" 120 140 20 "">
  <190 100 190 100 "c" 171 80 0 "">
</Wires>
<Diagrams>
  <Rect 240 549 319 239 3 #c0c0c0 1 10 1 0 0.01 0.05 1 0 2e+11 4.39954e+11 1 -1 1 1 315 0 225 1 0 0 "" "" "">
	<"ngspice/ft@ice" #0000ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
  <Text 10 0 16 #ed333b 0 "ft = f(Ic)">
</Paintings>
