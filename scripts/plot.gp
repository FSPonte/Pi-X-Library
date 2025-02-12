set title "Data Visualization"
set xlabel "x"
set ylabel "y"
set grid
set key outside bottom center horizontal
set terminal png
set output "files/data.png"
plot "files/data.txt" title "Raw data", "files/aprox.txt" with lines title "Aprox." lw 3 lc rgb "black", "files/derivative.txt" with lines title "Derivative" lw 3
