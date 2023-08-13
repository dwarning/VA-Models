#set terminal postscript eps color
#set output "id_pmos.eps"

set title "BSIMCMG Id=f(Vds) Vg=-0.5..-1V Temp: 27degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Vds [V]"
set ylabel "Id [A]"
plot 'id_pmos.cir.prn' using (-$2):($3) t "Id" w lp
