#set terminal postscript eps color
#set output "mex_out.eps"

set title "Ic=f(Vce) Ve,Vs=0V Temp: 27degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Vce [V]"
set ylabel "Ic [A]"
plot 'mex_out.cir.prn' using 2:(-$3) t "Ic" w lp
#set ylabel "dT [deg]"
#plot 'mex_out.cir.prn' using 2:($4) t "dt" w lp
