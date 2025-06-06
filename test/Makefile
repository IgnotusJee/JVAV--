dylibjvav: ../lib/libjvav.c ../lib/libjvav.h
	 riscv64-unknown-linux-gnu-gcc -fPIC -shared -o libjvav.so ../lib/libjvav.c
libjvav: ../lib/libjvav.c ../lib/libjvav.h
	 riscv64-unknown-linux-gnu-gcc -c -o libjvav.o ../lib/libjvav.c -mabi=lp64 -static
	 riscv64-unknown-linux-gnu-ar -crv -f libjvav.a libjvav.o
x86libjvav: ../lib/libjvav.c ../lib/libjvav.h
	gcc -fPIC -shared -o libjvavx86.so ../lib/libjvav.c
test_case:
	../build/jvav_compiler case3.jvav
out:test_case
	riscv64-unknown-linux-gnu-as case3.s -o case3.o -mabi=lp64
	riscv64-unknown-linux-gnu-gcc -o case3 case3.o -L. -ljvav -static
	qemu-riscv64 case3
test:test_case
	llc case3.ll -filetype=obj -o case3x86.o
	clang case3x86.o -o case3x86 -L. -ljvavx86 -no-pie -Wl,-rpath=.
	./case3x86
all: libjvav out
x86: x86libjvav test
clean:
	rm *.ll *.s *.o case3 test