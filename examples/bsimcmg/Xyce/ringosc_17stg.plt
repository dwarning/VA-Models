#set terminal postscript eps color
#set output "ringosc_17stg.eps"

set title "ringosc_17stg"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'ringosc_17stg.cir.prn' using 2:($3) t "1" w lines,\
     'ringosc_17stg.cir.prn' using 2:($4) t "17" w lines
