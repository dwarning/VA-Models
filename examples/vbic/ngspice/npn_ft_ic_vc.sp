VBIC Test ft = f(Ic) Vce: 0.4 ... 1.6V

.include ../Modelcards/SG13G2_hbt_woStatistics.hsp.lib

vce 1 0 dc 1.2
vgain 1 c dc 0.0
f 0 2 vgain -1
l 2 b 1g
c 2 0 1g
ib 0 b dc 0.0 ac 1.0
ic 0 c dc 0.001
XQ1 C B 0 0 npn13G2 nx=8 selft=0

.control
pre_osdi ../../../osdilibs/vbic_1p3.osdi
let run = 0
let ft_runs = 50
setplot const
compose myicv start=1m stop=50m log=$&ft_runs
set curplot=new          $ create a new plot
set curplotname=ft_plot
set curplottitle="IHP SG13G2 ft = f(Ic)"
set scratch=$curplot     $ store its name to 'scratch'
setplot $scratch         $ make 'scratch' the active plot
let ic=unitvec(ft_runs)  $ create a vector in plot 'scratch' to store ic data
let nvc = 0
foreach myvc 0.4 0.8 1.2 1.6
  set nvcs = "$&nvc"
  alter @vce[dc] = $myvc
  let ft{$nvcs}=vector(ft_runs)  $ create a vector in plot 'scratch' to store ft data
  let run = 0
  foreach myic $&myicv
    alter @ic[dc] = $myic
    ac dec 100 1G 1000g
    meas ac freq_at when vdb(vgain#branch)=0
    set run ="$&run"            $ create a variable from the vector
    set ac = $curplot           $ store the current plot to ac
    setplot $scratch            $ make 'scratch' the active plot
    let ic[run] = $myic         $ store ic to vector ft in plot 'scratch'
    let ft{$nvcs}[run] = {$ac}.freq_at $ store ft to vector ft in plot 'scratch'
    destroy $ac                 $ remove ac plot
    let run = run + 1
  end
  let nvc = nvc + 1
end
plot ft0 ft1 ft2 ft3 vs ic xlog
.endc

.end
