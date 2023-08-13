#set terminal postscript eps color
#set output "inverter_transient.eps"

set title "inverter_transient"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'inverter_transient.cir.prn' using 2:($3) t "vi" w lines,\
     'inverter_transient.cir.prn' using 2:($4) t "vo" w lines
