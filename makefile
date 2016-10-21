GCC = gcc -c

tuneztest: linkedList.c musicLib.c main.c
	$(GCC) linkedList.c musicLib.c
	gcc -o tuneztest main.c linkedList.o musicLib.o

run: tuneztest
	./tuneztest

clean:
	rm *~
	rm *.o
