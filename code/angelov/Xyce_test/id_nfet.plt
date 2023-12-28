#set terminal postscript eps color
#set output "id_nfet.eps"

set title "Id=f(Vgs) Vd=3V Temp: 25degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Vgs [V]"
set ylabel "Id [A]"
plot 'id_nfet.cir.prn' using 2:(-$3) t "Id" w lp
