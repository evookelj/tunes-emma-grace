GCC = gcc

start: linkedList.c musicLib.c main.c
	$(GCC) linkedList.c -c LL
	$(GCC) musicLib.c -c ML
	$(GCC) main.c -c main

tuneztest: linkedList.c musicLib.c main.c
	$(GCC) linkedList.c musicLib.c main.c -o tuneztest

linkedList: linkedList.c
	$(GCC) linkedList.c -o LL

musicLib: musicLib.c
	$(GCC) musicLib.c -o ML

main: main.c
	$(GCC) main.c -o main

run: tuneztest
	./tuneztest

clean:
	rm *~
