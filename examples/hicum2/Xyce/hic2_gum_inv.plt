#set terminal postscript eps color
#set output "hic2_gum_inv.eps"

set title "Ic,b=f(Veb) Ve,Vs=0V Temp: 27degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Veb [V]"
set ylabel "Ie [A]"
set logscale y
plot 'hic2_gum_inv.cir.prn' using 2:(-$3) t "Ie" w lp,\
     'hic2_gum_inv.cir.prn' using 2:(-$4) t "Ib" w lp,\
     'hic2_gum_inv.cir.prn' using 2:($5) t "Is" w lp
