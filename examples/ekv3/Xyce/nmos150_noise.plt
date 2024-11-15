#set terminal postscript eps color
#set output "nmos150_noise.eps"

set title "NMOS Noise"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Frequency"
set ylabel "Noise []"
set logscale x
set logscale y
plot 'nmos150_noise.cir.NOISE.prn' using 2:(sqrt($3)) t "inoise" w lines,\
     'nmos150_noise.cir.NOISE.prn' using 2:(sqrt($4)) t "onoise" w lines
