set terminal png size 1080, 720
set key outside right center vertical
set grid

set output "output/plot.png"
set title "Data Visualization"
set xlabel "Event"
set ylabel "Probability"
plot \
	"input/dataset.dat" notitle with lines lw 3, \
	"input/probability.dat" title "Cumulative" with lines lw 3
