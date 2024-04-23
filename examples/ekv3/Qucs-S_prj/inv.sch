<Qucs Schematic 24.2.0>
<Properties>
  <View=-113,-92,658,387,1.0167,0,0>
  <Grid=10,10,1>
  <DataSet=inv.dat>
  <DataDisplay=inv.dpl>
  <OpenDisplay=0>
  <Script=EKV3_inv.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Drawn By:>
  <FrameText2=Date:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
  <.ID 40 44 SUB>
  <Line 20 -40 0 -20 #000080 2 1>
  <Line 20 60 0 -20 #000080 2 1>
  <.PortSym 20 60 4 0>
  <.PortSym 20 -60 2 0>
  <Line -40 0 20 0 #000080 2 1>
  <.PortSym -40 0 1 0>
  <Line -20 -40 0 80 #000080 2 1>
  <Line 60 -40 0 80 #000080 2 1>
  <Line -20 -40 80 0 #000080 2 1>
  <Line -20 40 80 0 #000080 2 1>
  <Line 60 0 20 0 #000080 2 1>
  <.PortSym 80 0 3 180>
  <Line 45 0 -50 30 #000000 2 1>
  <Line 45 0 -50 -30 #000000 2 1>
  <Line -5 -30 0 60 #000000 2 1>
  <Ellipse 45 -5 10 10 #000000 1 1 #c0c0c0 1 1>
</Symbol>
<Components>
  <Port P1 1 400 150 30 -12 1 2 "3" 1 "analog" 0 "v" 0 "" 0>
  <Port P2 1 190 150 -55 -9 0 0 "1" 1 "analog" 0 "v" 0 "" 0>
  <Port P3 1 320 280 -9 28 1 1 "4" 1 "analog" 0 "v" 0 "" 0>
  <Port P4 1 320 20 -8 -72 0 3 "2" 1 "analog" 0 "v" 0 "" 0>
  <MOS_SPICE X1 1 320 100 -26 34 0 0 "X" 0 "4" 0 "pmos" 0 "pch90 w=3u l=0.1u nf=1" 1 "+ ad=3p as=3p" 1 "+ pd=8u ps=8u" 1 "" 0 "" 0>
  <MOS_SPICE X2 1 320 200 -26 34 0 0 "X" 0 "4" 0 "nmos" 0 "nch90 w=1u l=0.1u nf=1" 1 "+ad=1e-12 as=1e-12" 1 "+pd=4u ps=4u" 1 "" 0 "" 0>
</Components>
<Wires>
  <320 150 400 150 "" 0 0 0 "">
  <190 150 250 150 "" 0 0 0 "">
  <320 260 360 260 "" 0 0 0 "">
  <320 260 320 280 "" 0 0 0 "">
  <320 20 320 40 "" 0 0 0 "">
  <320 40 360 40 "" 0 0 0 "">
  <360 200 360 260 "" 0 0 0 "">
  <340 200 360 200 "" 0 0 0 "">
  <320 230 320 260 "" 0 0 0 "">
  <250 150 250 200 "" 0 0 0 "">
  <250 200 290 200 "" 0 0 0 "">
  <320 150 320 170 "" 0 0 0 "">
  <360 40 360 100 "" 0 0 0 "">
  <340 100 360 100 "" 0 0 0 "">
  <320 40 320 70 "" 0 0 0 "">
  <250 100 250 150 "" 0 0 0 "">
  <250 100 290 100 "" 0 0 0 "">
  <320 130 320 150 "" 0 0 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>
