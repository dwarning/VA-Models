#set terminal postscript eps color
#set output "pmos_id_vd_vg.eps"

set title "BSIMCMG Id=f(Vds) Vg=-0.5..-1V Temp: 27degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Vds [V]"
set ylabel "Id [A]"
plot 'pmos_id_vd_vg.cir.prn' using (-$2):($3) t "Id" w lp
