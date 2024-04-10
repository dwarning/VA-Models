#set terminal postscript eps color
#set output "npn_out.eps"

set title "Ic=f(Vce,Ib) Ve,Vs=0V Temp: 27degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Vce [V]"
set ylabel "Ic [A]"
plot 'npn_out.cir.prn' using 2:(-$3) t "Ic" w l
