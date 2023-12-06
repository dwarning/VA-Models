#set terminal postscript eps color
#set output "ECL-RO-9.eps"

set title "ECL-RO-9"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'ECL-RO-9.cir.prn' using 2:($3) t "out9" w lines
