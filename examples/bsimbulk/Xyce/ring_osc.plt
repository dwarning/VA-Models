#set terminal postscript eps color
#set output "ring_osc.eps"

set title "ring_osc"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'ring_osc.cir.prn' using 2:($3) t "1" w lines,\
     'ring_osc.cir.prn' using 2:($4) t "17" w lines
