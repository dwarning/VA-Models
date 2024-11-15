#set terminal postscript eps color
#set output "pmos150_id_vd_vg.eps"

set title "PMOS150 Id=f(Vds) Temp: 27degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Vds [V]"
set ylabel "Id [A]"
#set logscale y
plot 'pmos150_id_vd_vg.cir.prn' using (-$2):(-$4) t "Id" w lp
