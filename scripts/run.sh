#!/bin/bash

sh "scripts/build.sh"
/usr/bin/time -v "build/pix_tester" | tee "files/terminal_log.txt"

if [ ! -d "gnuplot" ]; then
	gnuplot "scripts/plot.gp"
fi
