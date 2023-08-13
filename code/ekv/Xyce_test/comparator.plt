#set terminal postscript eps color
#set output "comparator.eps"

set title "comparator"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'comparator.cir.prn' using 2:($3) t "A" w lines,\
     'comparator.cir.prn' using 2:($4) t "B" w lines, \
     'comparator.cir.prn' using 2:($5) t "9" w lines, \
     'comparator.cir.prn' using 2:($6) t "8" w lines
