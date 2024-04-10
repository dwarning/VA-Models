#set terminal postscript eps color
#set output "psp_out_pmos_nm.eps"

set title "Id=f(Vds) Vg=-1.5...0V Temp: 27degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Vds [V]"
set ylabel "Id [A]"
plot 'psp_out_pmos_nm.cir.prn' using 2:($3) t "Id" w lp
