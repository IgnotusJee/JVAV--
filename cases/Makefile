dylibjvav: ../lib/libjvav.c ../lib/libjvav.h
	 riscv64-unknown-linux-gnu-gcc -fPIC -shared -o libjvav.so ../lib/libjvav.c
libjvav: ../lib/libjvav.c ../lib/libjvav.h
	 riscv64-unknown-linux-gnu-gcc -c -o ./libjvav.o ../lib/libjvav.c -mabi=lp64 -static
	 riscv64-unknown-linux-gnu-ar -crv -f libjvav.a libjvav.o
x86libjvav: ../lib/libjvav.c ../lib/libjvav.h
	gcc -fPIC -shared -o libjvavx86.so ../lib/libjvav.c
test_case:
	../build/jvav_compiler case$(CASEID).jvav
testriscv:test_case
	riscv64-unknown-linux-gnu-as case$(CASEID).s -o case$(CASEID).o -mabi=lp64
	riscv64-unknown-linux-gnu-gcc -o case$(CASEID) case$(CASEID).o -L. -ljvav -static
	qemu-riscv64 case$(CASEID)
testx86:test_case
	llc case$(CASEID).ll -filetype=obj -o case1x86.o
	clang case1x86.o -o case1x86 -L. -ljvavx86 -no-pie -Wl,-rpath=.
	./case1x86
riscv: libjvav out
x86: x86libjvav testx86
run: libjvav test_case
	qemu-riscv64 case$(CASEID)
clean:
	rm -f *.ll *.s *.o case1 case2 case3 *.a