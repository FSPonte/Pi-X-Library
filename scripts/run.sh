#!/bin/bash

sh "scripts/build.sh"

if [ ! -d "files/" ]; then
	mkdir -p "files/"
fi

if [ ! -d "logs/" ]; then
	mkdir -p "logs/"
fi

/usr/bin/time -v "build/pix_tester" | tee "files/stdout.txt"

if [ ! -d "gnuplot" ]; then
	gnuplot "scripts/plot.gp"
fi
