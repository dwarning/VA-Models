#set terminal postscript eps color
#set output "test_mosvar.eps"

set title "test mosvar"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "Vc [V]"
set ylabel "Capacitance [F]"
plot 'test_mosvar.cir.prn' using 3:($4) t "Cmosvar" w lines
