libjvav: lib/libjvav.c lib/libjvav.h
	gcc -fPIC -shared -o libjvav.so lib/libjvav.c
test_case:
	build/jvav_parser test/case3.jvav test/out.ll
out:test_case
	llc test/out.ll -filetype=obj -o out.o
	clang out.o -o out -L. -ljvav -no-pie -Wl,-rpath=.
	./out
all: libjvav out
clean:
	rm -rf build out out.o test/out.ll libjvav.so