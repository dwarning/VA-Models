#set terminal postscript eps color
#set output "nigbt.eps"

set title "Ic=f(Vc) Ve=0V Vg=5 ... 20V Temp: 27degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Vce [V]"
set ylabel "Ic [A]"
plot "nigbt.cir.prn" using 3:(-$4)
