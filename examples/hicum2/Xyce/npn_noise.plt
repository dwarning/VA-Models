#set terminal postscript eps color
#set output "npn_noise.eps"

set title "hicum2 Noise"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Frequency"
set ylabel "Noise []"
set logscale x
set logscale y
plot 'npn_noise.cir.NOISE.prn' using 2:($3) t "inoise" w lines,\
     'npn_noise.cir.NOISE.prn' using 2:($4) t "onoise" w lines
