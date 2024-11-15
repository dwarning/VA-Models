#set terminal postscript eps color
#set output "inverter150_transient.eps"

set title "inverter150_transient"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'inverter150.cir.prn' using 2:($3) t "in" w lines,\
     'inverter150.cir.prn' using 2:($4) t "out" w lines
