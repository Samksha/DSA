myProgram :	driver.o BinTree.o toDot.o list.o
	gcc driver.o BinTree.o toDot.o list.o -o myProgram

BinTree.o :	BinTree.c BinTree.h
	gcc -c BinTree.c

list.o :	list.c list.h BinTree.h
	gcc -c list.c

toDot.o	:	toDot.c BinTree.h
	gcc -c toDot.c

driver.o:	driver.c BinTree.h toDot.h
	gcc -c driver.c