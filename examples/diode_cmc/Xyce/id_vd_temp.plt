#set terminal postscript eps color
#set output "id_vd_temp.eps"

set title "Id=f(Vd) Temp: -25 ... 125degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Vd [V]"
set ylabel "Id [A]"
set logscale y
plot 'id_vd_temp.cir.prn' using 2:(-$3) t "Id" w lp