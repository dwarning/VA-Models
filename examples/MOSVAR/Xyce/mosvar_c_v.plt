#set terminal postscript eps color
#set output "mosvar_c_v.eps"

set title "test mosvar"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Vc [V]"
set ylabel "Capacitance [F]"
plot 'mosvar_c_v.cir.prn' using 3:($4) t "Cmosvar" w lines
