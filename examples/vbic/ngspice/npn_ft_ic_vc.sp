npn13G2 ft = f(Ic) Vce: 0.6 ... 1.4V

.include ../Modelcards/SG13G2_hbt_woStatistics.hsp.lib
.param nx=8
.csparam nx='nx'

vce 1 0 dc 1.2
vgain 1 c dc 0
f 0 2 vgain -1
l 2 b 1
c 2 0 1
ib 0 b dc 0.0 ac 1.0
ic 0 c dc 0.001
XQ1 C B 0 0 npn13G2 nx=nx selft=1

.control
pre_osdi ../../../osdilibs/vbic_1p3.osdi
let run = 0
let ft_runs = 50
setplot const
compose myicv start=0.1m stop=50m log=$&ft_runs
set curplot=new          $ create a new plot
set curplotname=ft_plot
set curplottitle="IHP SG13G2 ft = f(Ic)"
set scratch=$curplot     $ store its name to 'scratch'
setplot $scratch         $ make 'scratch' the active plot
let ic=unitvec(ft_runs)  $ create a vector in plot 'scratch' to store ic data
let nvc = 0
foreach myvc 0.6 0.8 1.0 1.2 1.4
  set nvcs = "$&nvc"
  alter @vce[dc] = $myvc
  let ft{$nvcs}=vector(ft_runs)  $ create a vector in plot 'scratch' to store ft data
  let run = 0
  foreach myic $&myicv
    alter @ic[dc] = $myic
    ac dec 100 1G 1000g
    meas ac gain_at find vm(vgain#branch) at=30GHz
    set run ="$&run"            $ create a variable from the vector
    set ac = $curplot           $ store the current plot to ac
    setplot $scratch            $ make 'scratch' the active plot
    let ic[run] = $myic         $ store ic in plot 'scratch'
*    let ic[run] = $myic*1e3/(nx*0.07*0.90) $ store ic in plot 'scratch' for mA/um²
    let ft{$nvcs}[run] = {$ac}.gain_at*30e9 $ store ft to vector ft in plot 'scratch'
    destroy $ac                 $ remove ac plot
    let run = run + 1
  end
  let nvc = nvc + 1
end
set color0=white
set color1=black
plot ft0 ft1 ft2 ft3 ft4 vs ic xlog xlabel "A" ylabel "Hz" title "ft=f(Ic,Vce) Vce=0.6...1.4V"
*plot ft0 ft1 ft2 ft3 ft4 vs ic xlog xlabel "mA/um²" ylabel Hz
.endc

.end
