#set terminal postscript eps color
#set output "hic2_noise_I.eps"

set title "hicum2 I Noise"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Frequency"
set ylabel "Noise []"
set logscale x
set logscale y
plot 'hic2_noise_I.cir.NOISE.prn' using 2:($3) t "onoise" w lines
