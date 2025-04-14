if [-f "build/pix_tester"]; then
	rm "build/pix_tester"
fi

cmake --build "build"
hexdump -C -v "build/pix_tester" > "logs/hexdump.txt"
objdump -D "build/pix_tester" > "logs/objdump.txt"
size -A "build/pix_tester" > "logs/size.txt"
apt list > "logs/packages.txt"
tree -I "build" > "logs/tree.txt"
