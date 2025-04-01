set terminal png
set key outside right center vertical
set grid

set output "files/plot.png"
set title "Data Visualization"
set xlabel "Time (s)"
set ylabel "Amplitude (dB)"
plot "files/signal.txt" title "Signal" with lines lw 3, "files/adjust.txt" title "Adjusted" with lines lw 3

set output "files/fourier.png"
set title "Fourier Transform"
set xlabel "Frequency (Hz)"
set ylabel "Magnitude"
plot "files/fourier.txt" title "DFT" with lines lw 3
