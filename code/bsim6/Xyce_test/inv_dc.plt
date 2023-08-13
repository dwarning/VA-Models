#set terminal postscript eps color
#set output "inv_dc.eps"

set title "inv_dc"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "vin"
set ylabel "Voltage"
plot 'inv_dc.cir.prn' using 2:($3) t "vout" w lines
