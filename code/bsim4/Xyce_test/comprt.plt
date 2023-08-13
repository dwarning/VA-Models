#set terminal postscript eps color
#set output "comprt.eps"

set title "comprt"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'comprt.cir.prn' using 2:($3) t "A" w lines,\
     'comprt.cir.prn' using 2:($4) t "B" w lines, \
     'comprt.cir.prn' using 2:($5) t "9" w lines, \
     'comprt.cir.prn' using 2:($6) t "8" w lines
