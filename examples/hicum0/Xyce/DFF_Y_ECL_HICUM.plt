#set terminal postscript eps color
#set output "DFF_Y_ECL_HICUM.eps"

set title "DFF Y ECLHICUM"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'DFF_Y_ECL_HICUM.cir.prn' using 2:($3) t "D" w lines,\
     'DFF_Y_ECL_HICUM.cir.prn' using 2:($4) t "CLK" w lines, \
     'DFF_Y_ECL_HICUM.cir.prn' using 2:($5) t "Q" w lines
