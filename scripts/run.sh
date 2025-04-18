sh "scripts/build.sh"
time -v "build/pix_tester" | tee "logs/terminal_log.txt"

if [ ! -d "gnuplot" ]; then
	gnuplot "scripts/plot.gp"
fi
