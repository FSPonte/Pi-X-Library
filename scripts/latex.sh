#!/bin/sh

mkdir -p "docs/"
mkdir -p "docs/images/"

pdflatex -output-directory="docs/" "docs/manual.tex"
