#set terminal postscript eps color
#set output "ro_17.eps"

set title "ro_17"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'ro_17.cir.prn' using 2:($3) t "2" w lines,\
     'ro_17.cir.prn' using 2:($4) t "5" w lines
