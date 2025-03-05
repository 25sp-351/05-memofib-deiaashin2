fibonacci: fibonacci.o main.o tests.o
	clang main.o tests.o fibonacci.o -o fibonacci_test

fibonacci.o: fibonacci.o
	clang -c fibonacci.c

main.o: main.o
	clang -c main.c

test.o: tests.o
	clang -c tests.c

clean:
	rm *.o fibonacci_test