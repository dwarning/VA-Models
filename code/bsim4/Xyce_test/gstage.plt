#set terminal postscript eps color
#set output "gstage.eps"

set title "gain stage"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "frequency"
set ylabel "Gain [dB]"
plot 'gstage.cir.FD.prn' using 2:($3) t "D" w lines
