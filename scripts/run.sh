sh "scripts/build.sh"
mkdir -p "files/"
mkdir -p "logs/"

time -f "\nuser\t%U\nsystem\t%S\nelapsed\t%e" "build/pix_tester"
gnuplot "scripts/plot.gp"
