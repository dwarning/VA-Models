#set terminal postscript eps color
#set output "nmos_amp_ac.eps"

set title "gain stage"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "frequency"
set ylabel "Gain [dB]"
set logscale x
plot 'nmos_amp_ac.cir.FD.prn' using 2:($3) t "vout" w lines
