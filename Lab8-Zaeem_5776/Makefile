all: matrix

matrix: main.o init.o multiply.o 
	gcc -std=c99 -Wall main.o init.o multiply.o -o matrix -lpthread

main.o: main.c
	gcc -std=c99 -c -Wall main.c -lpthread

init.o: init.c
	gcc -std=c99 -c -Wall init.c

multiply.o: multiply.c
	gcc -std=c99 -c -Wall multiply.c

clean:
	rm -rf *.o matrix

