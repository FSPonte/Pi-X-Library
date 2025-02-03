set title "Data Visualization"
set xlabel "x"
set ylabel "y"
set key outside bottom center horizontal
set grid
set terminal png
set output "files/data.png"
plot "files/data.txt" title "Raw data", "files/aprox.txt" with lines title "Aprox."
