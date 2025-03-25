sh "scripts/build.sh"
time -v "build/pix_tester" | tee "logs/terminal_log.txt"
gnuplot "scripts/plot.gp"
