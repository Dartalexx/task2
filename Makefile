all: staticLib test.o
	gcc test.o -L. -lsquare -lm -o prog

staticLib: square.o
	ar rc libsquare.a square.o
	ranlib libsquare.a

test.o: test.c
	gcc -c test.c

square.o: square.c
	gcc -c square.c

clean: 
	rm prog *.o *.a