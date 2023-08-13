#set terminal postscript eps color
#set output "nigbt_tran.eps"

set title "nigbt_tran Temp: 27degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot "nigbt_tran.cir.prn" using 2:($3) t "Gate" w lines,\
     "nigbt_tran.cir.prn" using 2:($4) t "Anode" w lines
