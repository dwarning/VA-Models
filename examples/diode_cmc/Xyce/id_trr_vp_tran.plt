#set terminal postscript eps color
#set output "id_trr_vp_tran.eps"

set title "Id=f(time) Temp: 27degC"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Id [A]"
plot 'id_trr_vp_tran.cir.prn' using 2:(-$3) t "Idio" w lp,\
     'id_trr_vp_tran.cir.prn' using 2:($4/5) t "Vdio/5" w lp