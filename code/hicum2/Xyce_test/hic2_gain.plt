#set terminal postscript eps color
#set output "hic2_gain.eps"

set title "gain stage"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "frequency"
set ylabel "Gain [dB]"
set log x
plot 'hic2_gain.cir.FD.prn' using 2:($3) t "C" w lines
