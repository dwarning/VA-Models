#set terminal postscript eps color
#set output "res_r3_cmc.eps"

set title "Poly resistor, r2_cmc model Temp: -40 160 grdC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Vr [V]"
set ylabel "R [Ohm]"
plot 'res_r3_cmc.cir.prn' using 2:($3) t "R" w lp
