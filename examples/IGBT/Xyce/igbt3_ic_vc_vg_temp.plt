#set terminal postscript eps color
#set output "igbt3_ic_vc_vg_temp.eps"

set title "Ic=f(Vc) Ve=0V Vg=5 ... 20V Temp: 27degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Vce [V]"
set ylabel "Ic [A]"
plot "igbt3_ic_vc_vg_temp.cir.prn" using 3:(-$4)
