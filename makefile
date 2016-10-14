GCC = gcc

tuneztest: tunez.c tunez.h
	$(GCC) tunez.c -o tuneztest

run: tuneztest
	./tuneztest

clean:
	rm *~
