#set terminal postscript eps color
#set output "ECL-RO.eps"

set title "ECL-RO"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'ECL-RO.cir.prn' using 2:($3) t "a1" w lines,\
     'ECL-RO.cir.prn' using 2:($4) t "a2" w lines,\
     'ECL-RO.cir.prn' using 2:($5) t "in1" w lines,\
     'ECL-RO.cir.prn' using 2:($6) t "in2" w lines
