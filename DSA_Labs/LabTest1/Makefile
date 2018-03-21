p1: main.o List.o List.h
	gcc List.o main.o -o p1Prog

List.o: List.c List.h
	gcc -c List.c

main.o: main.c List.h
	gcc -c main.c
