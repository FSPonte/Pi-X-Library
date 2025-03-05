sh scripts/build.sh
echo
time -f "\nTime (s):\n\treal: %e\n\tuser: %U\n\tsys: %S\n\nMemory (KB):\n\tmax: %M\n\tavg: %t\n\tavg total: %K" \
	build/pix_tester | tee logs/terminal_log.txt
open files/plot.png
