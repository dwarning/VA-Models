#set terminal postscript eps color
#set output "npn_ic_ib_vb.eps"

set title "Ic,b=f(Vbe) Ve,Vs=0V Temp: 27degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Vbe [V]"
set ylabel "Ic [A]"
set logscale y
plot 'npn_ic_ib_vb.cir.prn' using 2:(-$3) t "Ic" w lp,\
     'npn_ic_ib_vb.cir.prn' using 2:(-$4) t "Ib" w lp,\
     'npn_ic_ib_vb.cir.prn' using 2:($5) t "Is" w lp
