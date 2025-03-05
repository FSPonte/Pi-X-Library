set title "Data Visualization"
set xlabel "x"
set ylabel "y"
set grid
set key outside right center vertical
set terminal png
set output "files/plot.png"
plot "files/data.txt" title "Dataset", "files/aprox.txt" title "Aprox" with lines lw 3 lc rgb "black", "files/der.txt" title "Derivative" with lines lw 3 lc rgb "red
