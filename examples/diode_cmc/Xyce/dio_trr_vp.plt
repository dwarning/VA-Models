#set terminal postscript eps color
#set output "diode_trr.eps"

set title "Id=f(time) Temp: 27degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Id [A]"
plot 'dio_trr_vp.cir.prn' using 2:(-$3) t "Idio" w lp,\
     'dio_trr_vp.cir.prn' using 2:($4/5) t "Vdio/5" w lp