#set terminal postscript eps color
#set output "angeglov_id_vg.eps"

set title "Id=f(Vgs) Vd=3V Temp: 25degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Vgs [V]"
set ylabel "Id [A]"
plot 'angeglov_id_vg.cir.prn' using 2:(-$3) t "Id" w lp
