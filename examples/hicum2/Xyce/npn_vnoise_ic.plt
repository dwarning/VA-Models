#set terminal postscript eps color
#set output "npn_vnoise_ic.eps"

set title "hicum2 V Noise"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Frequency"
set ylabel "Noise []"
set logscale x
set logscale y
plot 'npn_vnoise_ic.cir.NOISE.prn' using 2:($3) t "onoise" w lines
