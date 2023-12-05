#set terminal postscript eps color
#set output "ECL-OR-NOR-gate.eps"

set title "ECL-OR-NOR-gate"

set grid
set key left top
set format x "%.1s%c"
set format y "%.1s%c"
set xlabel "time"
set ylabel "Voltage"
plot 'ECL-OR-NOR-gate.cir.prn' using 2:($3) t "a1-or" w lines,\
     'ECL-OR-NOR-gate.cir.prn' using 2:($4) t "a2-nor" w lines,\
     'ECL-OR-NOR-gate.cir.prn' using 2:($5) t "in1" w lines,\
     'ECL-OR-NOR-gate.cir.prn' using 2:($6) t "in2" w lines
