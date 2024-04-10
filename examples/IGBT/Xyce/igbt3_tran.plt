#set terminal postscript eps color
#set output "igbt3_tran.eps"

set title "igbt3_tran Temp: 27degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot "igbt3_tran.cir.prn" using 2:($3) t "Gate" w lines,\
     "igbt3_tran.cir.prn" using 2:($4) t "Anode" w lines
