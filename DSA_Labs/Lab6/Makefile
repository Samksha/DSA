sort: qsort.o sortDr.o insSort.o sort.h
	gcc qsort.o sortDr.o insSort.o -o sortProg

qsortIter: qsort.o sortDr.o sort.h
	gcc qsort.o sortDr.o -o qProg

qsort.o: qsort.c sort.h
	gcc -c qsort.c

qsortDr.o: sortDr.c sort.h
	gcc -c sortDr.c

insSort: insSort.o qsort.o sortDr.o sort.h
	gcc insSort.o qsort.o sortDr.o -o insProg

insSort.o: insSort.c sort.h
	gcc -c insSort.c
