#set terminal postscript eps color
#set output "id_nmos.eps"

set title "Id=f(Vgs) Vd=50mV Temp: 27degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Vgs [V]"
set ylabel "Id [A]"
set logscale y
plot 'id_nmos.cir.prn' using 2:(-$3) t "Id" w lp
