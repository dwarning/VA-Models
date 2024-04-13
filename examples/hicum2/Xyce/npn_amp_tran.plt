#set terminal postscript eps color
#set output "npn_amp_tran.eps"

set title "hic2_tran"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'npn_amp_tran.cir.prn' using 2:($3) t "IN" w lines,\
     'npn_amp_tran.cir.prn' using 2:($4) t "OUT" w lines
