dylibjvav: lib/libjvav.c lib/libjvav.h
	 riscv64-unknown-linux-gnu-gcc -fPIC -shared -o libjvav.so ../lib/libjvav.c
libjvav: lib/libjvav.c lib/libjvav.h
	 riscv64-unknown-linux-gnu-gcc -c -o libjvav.o ../lib/libjvav.c -mabi=lp64 -static
	 riscv64-unknown-linux-gnu-ar -crv -f libjvav.a libjvav.o
test_case:
	../build/jvav_compiler case3.jvav case3.ll
out:test_case
	riscv64-unknown-linux-gnu-as case3.s -o case3.o -mabi=lp64
	riscv64-unknown-linux-gnu-gcc -o case3 case3.o -L. -ljvav -static
	qemu-riscv64 case3
all: libjvav out
clean:
	rm *.ll *.s *.o case3 test