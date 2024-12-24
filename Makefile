output: main.o grep.o parser.o
	gcc -o output main.o grep.o parser.o

main.o: main.c parser.h grep.h
	gcc -c main.c

grep.o: grep.c parser.h
	gcc -c grep.c

parser.o: parser.c parser.h
	gcc -c parser.c

clean:
	rm *.o output