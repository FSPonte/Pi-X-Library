rm build/pix_tester
clear
cmake --build build/
hexdump -C -v build/pix_tester > logs/hexdump.txt
objdump -D build/pix_tester > logs/objdump.txt
size -A build/pix_tester > logs/size.txt
tree -I build/ > logs/tree.txt
apt list > logs/packages.txt
