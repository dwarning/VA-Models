#set terminal postscript eps color
#set output "simple_inverter_dc.eps"

set title "simple_inverter_dc"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "vin"
set ylabel "Voltage"
plot 'simple_inverter_dc.cir.prn' using 2:($3) t "vin" w lines,\
     'simple_inverter_dc.cir.prn' using 2:($4) t "vout" w lines
