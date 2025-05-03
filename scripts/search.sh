#!/bin/sh

if [ ! -d "fzf" ]; then
	fzf -e --preview="cat {}"
fi
