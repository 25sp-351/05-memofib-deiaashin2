memofib: memofib.o
	clang memofib.o -o memofib

main.o: memofib.o
	clang -c memofib.c

clean:
	rm *.o memofib
	