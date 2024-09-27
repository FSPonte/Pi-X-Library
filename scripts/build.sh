rm build/pix_tester
clear
cmake --build build/
hexdump -C -v build/pix_tester > files/hexdump.txt
objdump -D build/pix_tester > files/objdump.txt
size -A build/pix_tester > files/size.txt
tree -a > files/tree.txt
sudo apt list > files/packages.txt