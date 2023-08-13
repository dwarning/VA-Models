#set terminal postscript eps color
#set output "inv_tran.eps"

set title "inverter_transient"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'inv_tran.cir.prn' using 2:($3) t "vi" w lines,\
     'inv_tran.cir.prn' using 2:($4) t "vo" w lines
