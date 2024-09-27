set title "Data Visualization"
set xlabel "x"
set ylabel "y"
set grid
set terminal png
set output "files/data.png"
plot "files/data.txt"