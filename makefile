GCC = gcc

tuneztest: linkedList.c musicLib.c
	$(GCC) linkedList.c musicLib.c -o tuneztest

run: tuneztest
	./tuneztest

clean:
	rm *~
