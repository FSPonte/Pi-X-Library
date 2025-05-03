#!/bin/sh

rm -rf "build/"
mkdir "build/"

cd "build/"
cmake ".."
cd "../"

cmake --build "build/"
hexdump -C -v "build/pix_tester" > "build/hexdump.txt"
objdump -D "build/pix_tester" > "build/objdump.txt"
size -A "build/pix_tester" > "build/size.txt"
apt list > "build/packages.txt"
tree -I "build/" > "build/tree.txt"
