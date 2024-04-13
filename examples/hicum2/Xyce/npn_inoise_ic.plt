#set terminal postscript eps color
#set output "npn_inoise_ic.eps"

set title "hicum2 I Noise"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Frequency"
set ylabel "Noise []"
set logscale x
set logscale y
plot 'npn_inoise_ic.cir.NOISE.prn' using 2:($3) t "onoise" w lines
