#set terminal postscript eps color
#set output "idvd_nmos.eps"

set title "Id=f(Vds) Vg=0.4..1V Temp: 27degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Vds [V]"
set ylabel "Id [A]"
plot 'idvd_nmos.cir.prn' using 2:(-$3) t "Id" w lp
