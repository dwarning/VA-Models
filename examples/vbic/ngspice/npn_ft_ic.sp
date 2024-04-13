VBIC Test ft = f(Ic)

.include ../Modelcards/SG13G2_hbt_woStatistics.hsp.lib

vce 1 0 dc 1.2
vgain 1 c dc 0.0
f 0 2 vgain -1
l 2 b 1g
c 2 0 1g
ib 0 b dc 0.0 ac 1.0
ic 0 c dc 0.001
XQ1 C B 0 0 npn13G2 nx=1
*XQ1 C B 0 0 npn13G2l nx=1
*XQ1 C B 0 0 npn13G2v nx=1

.control
pre_osdi ../../../osdilibs/vbic_1p3.osdi
*altermod @n.xq1.nqnpn13g2[RTH]=0
let ft_runs = 15
let run = 0
set curplot=new          $ create a new plot
set curplotname=ft_plot
set curplottitle="IHP SG13G2 ft = f(Ic)"
set scratch=$curplot     $ store its name to 'scratch'
setplot $scratch         $ make 'scratch' the active plot
let ft=unitvec(ft_runs)  $ create a vector in plot 'scratch' to store ft data
let ic=unitvec(ft_runs)  $ create a vector in plot 'scratch' to store ic data
compose myicv start=100u stop=5m log=$&ft_runs
*compose myicv start=350u stop=14m log=$&ft_runs
*compose myicv start=200u stop=1.4m log=$&ft_runs
foreach myic $&myicv
  alter @ic[dc] = $myic
  ac dec 100 1G 1000g
  meas ac freq_at when vdb(vgain#branch)=0
  set run ="$&run"            $ create a variable from the vector
  set dt = $curplot           $ store the current plot to dt
  setplot $scratch            $ make 'scratch' the active plot
  let ic[run] = $myic         $ store ic to vector ft in plot 'scratch'
  let ft[run] = {$dt}.freq_at $ store ft to vector ft in plot 'scratch'
  setplot $dt                 $ go back to the previous plot
  let run = run + 1
end
setplot unknown1
plot ft vs ic xlog
.endc

.end
