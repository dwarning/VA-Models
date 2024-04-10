#set terminal postscript eps color
#set output "inverter_ro.eps"

set title "inverter_ro"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'inverter_ro.cir.prn' using 2:($4) t "vout" w lines
