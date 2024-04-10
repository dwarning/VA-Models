#set terminal postscript eps color
#set output "oneshot.eps"

set title "oneshot"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'oneshot.cir.prn' using 2:($3) t "in" w lines,\
     'oneshot.cir.prn' using 2:($4) t "out" w lines
