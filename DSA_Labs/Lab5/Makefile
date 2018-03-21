compileAll: sortDr.o sort.o sort2.h
	gcc sort.o sortDr.o -o sortProg

sortDr.o: sortDr.c sort2.h
	gcc -c sortDr.c

sort.o: sort.c sort2.h
	gcc -c sort.c
