GCC = gcc

tuneztest: linkedList.c musicLib.c main.c
	$(GCC) linkedList.c musicLib.c main.c -o tuneztest

run: tuneztest
	./tuneztest

clean:
	rm *~
