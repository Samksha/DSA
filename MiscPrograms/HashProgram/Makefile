hashCmp: hashDr.o hash.o hash.h
	gcc hash.o hashDr.o -o hashProg

hashDr.o: hashDr.c hash.h
	gcc -c hashDr.c

hash.o: hash.c hash.h
	gcc -c hash.c
