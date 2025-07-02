set terminal png
set key outside right center vertical
set grid

set output "files/plot.png"
set title "Data Visualization"
set xlabel "event"
set ylabel "probability"
plot \
	"files/dataset.dat" notitle with lines lw 3, \
	"files/probability.dat" title "Cumulative" with lines lw 3
