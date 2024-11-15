#set terminal postscript eps color
#set output "nmos150_id_vd_vg.eps"

set title "NMOS150 Id=f(Vds) Temp: 27degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Vds [V]"
set ylabel "Id [A]"
#set logscale y
plot 'nmos150_id_vd_vg.cir.prn' using 2:($4) t "Id" w lp
