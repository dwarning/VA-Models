#set terminal postscript eps color
#set output "npn_gain_ic.eps"

set title "gain stage"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "frequency"
set ylabel "Gain [dB]"
set log x
plot 'npn_gain_ic.cir.FD.prn' using 2:($3) t "C" w lines
