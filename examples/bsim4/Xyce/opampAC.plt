#set terminal postscript eps color
#set output "opampAC.eps"

set title "gain stage"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "frequency"
set ylabel "Gain [dB]"
set logscale x
plot 'opampAC.cir.FD.prn' using 2:($3) t "8" w lines
