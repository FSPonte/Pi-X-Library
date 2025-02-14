set title "Data Visualization"
set xlabel "x"
set ylabel "y"
set grid
set key outside bottom center horizontal
set terminal png
set output "files/data.png"
plot "files/dataset.txt" title "Dataset", "files/model.txt" with lines title "Model" lw 3 lc rgb "black"
