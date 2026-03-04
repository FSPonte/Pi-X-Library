sh "scripts/build.sh"
mkdir -p "files/"
mkdir -p "logs/"

time -v "build/pix_tester"
gnuplot "scripts/plot.gp"
