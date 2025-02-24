memofib: memofib.o bn.o
	clang memofib.o bn.o -o memofib

memofib.o: memofib.c
	clang -c memofib.c

bn.o: bn.c
	clang -c bn.c

clean:
	rm *.o memofib
	