#set terminal postscript eps color
#set output "inverter90_transient.eps"

set title "inverter90_transient"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'inverter90.cir.prn' using 2:($3) t "in" w lines,\
     'inverter90.cir.prn' using 2:($4) t "out" w lines
