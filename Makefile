all: dynamicLib
	gcc test.c -o prog -ldl -lm

dynamicLib: square.o
	gcc -shared square.o -o libsquaredynamic.so -lm 

square.o: square.c
	gcc -fPIC -c square.c

clean:
	rm prog *.o *.so
