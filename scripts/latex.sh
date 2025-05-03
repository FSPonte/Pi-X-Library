#!/bin/sh

if [ ! -d "docs/" ]; then
	mkdir -p "docs/"
fi

if [ ! -d "docs/images/" ]; then
	mkdir -p "docs/images/"
fi

if [ ! -d "docs/manual.tex" ]; then
	touch "docs/manual.tex"
fi

pdflatex -output-directory="docs/" "docs/manual.tex"
