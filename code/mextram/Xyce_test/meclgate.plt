#set terminal postscript eps color
#set output "meclgate.eps"

set title "meclgate"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'meclgate.cir.prn' using 2:($3) t "v(12)" w lines,\
     'meclgate.cir.prn' using 2:($4) t "v(21)" w lines
