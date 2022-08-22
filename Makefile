all: dynamicLib test.o
	gcc test.o -L. -lsquaredyn -lm -o prog

dynamicLib: square.o
	gcc -shared -o libsquaredyn.so square.o

test.o: test.c
	gcc -c test.c

square.o: square.c
	gcc -fPIC -c square.c

clean: 
	rm prog *.o *.so