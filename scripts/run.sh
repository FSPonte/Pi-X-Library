sh "scripts/build.sh"
mkdir -p "files/"
mkdir -p "logs/"

/usr/bin/time -v "build/pix_tester" | tee "logs/stdout.txt"
gnuplot "scripts/plot.gp"