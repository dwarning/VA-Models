#set terminal postscript eps color
#set output "nmos_noise.eps"

set title "NMOS Noise"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Frequency"
set ylabel "Noise []"
set logscale x
set logscale y
plot 'nmos_noise.cir.NOISE.prn' using 2:($3) t "inoise" w lines,\
     'nmos_noise.cir.NOISE.prn' using 2:($4) t "onoise" w lines
