set terminal png
set key outside right center vertical
set grid

set output "files/plot.png"
set title "Data Visualization"
set xlabel "time"
set ylabel "amplitude"
plot "files/dataset.txt" title "Dataset", "files/aprox.txt" title "Aprox" with lines lw 3

set output "files/fourier.png"
set title "Fourier Transform"
set xlabel "frequency"
set ylabel "magnitude"
plot "files/fourier.txt" title "NDFT" with lines lw 3
