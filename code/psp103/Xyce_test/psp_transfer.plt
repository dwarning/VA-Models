#set terminal postscript eps color
#set output "psp_transfer.eps"

set title "Id=f(Vgs) Vd=50mV Temp: 27degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Vgs [V]"
set ylabel "Id [A]"
set logscale y
plot 'psp_transfer.cir.prn' using 2:(-$3) t "Id" w lp
