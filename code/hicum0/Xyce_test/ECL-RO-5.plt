#set terminal postscript eps color
#set output "ECL-RO-5.eps"

set title "ECL-RO-5"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'ECL-RO-5.cir.prn' using 2:($3) t "a1" w lines
