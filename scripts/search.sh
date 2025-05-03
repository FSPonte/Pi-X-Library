#!/bin/bash

if [ ! -d "fzf" ]; then
	fzf -e --preview="cat {}"
fi
