GCC = gcc -c

start: linkedList.c musicLib.c main.c
	$(GCC) linkedList.c musicLib.c
	gcc -o tuneztest main.c linkedList.o musicLib.o

tuneztest: linkedList.c musicLib.c main.c
	$(GCC) linkedList.c musicLib.c main.c tuneztest

run: tuneztest
	./tuneztest

clean:
	rm *~
