#set terminal postscript eps color
#set output ""NuV-test.eps"

set title "NuV-test"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'NuV-test.cir.prn' using 2:($3) t "vin" w lines,\
     'NuV-test.cir.prn' using 2:($4) t "outA" w lines,\
     'NuV-test.cir.prn' using 2:($5) t "outB" w lines,\
     'NuV-test.cir.prn' using 2:($6) t "outC" w lines,\
     'NuV-test.cir.prn' using 2:($7) t "outD" w lines,\
     'NuV-test.cir.prn' using 2:($8) t "outE" w lines,\
     'NuV-test.cir.prn' using 2:($9) t "outF" w lines
