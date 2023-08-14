#set terminal postscript eps color
#set output "hic2_tran.eps"

set title "hic2_tran"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'hic2_tran.cir.prn' using 2:($3) t "IN" w lines,\
     'hic2_tran.cir.prn' using 2:($4) t "OUT" w lines
