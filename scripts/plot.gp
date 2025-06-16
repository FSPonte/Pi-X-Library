set terminal png
set key outside right center vertical
set grid

set output "files/plot.png"
set title "Data Visualization"
set xlabel "x"
set ylabel "y"
plot \
	"files/dataset.dat" notitle with lines lw 3
