#set terminal postscript eps color
#set output "mosamp2.eps"

set title "mosamp2"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'mosamp2.cir.prn' using 2:($3) t "in" w lines,\
     'mosamp2.cir.prn' using 2:($4) t "out" w lines
