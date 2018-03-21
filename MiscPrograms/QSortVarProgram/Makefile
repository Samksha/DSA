qRec: qsortDr.o qsort.o qsortRec.o qsort.h
	gcc qsort.o qsortRec.o qsortDr.o -o qRecProg

qIter: qsortDr.o qsort.o qsortIter.o qsort.h
	gcc qsort.o qsortIter.o qsortDr.o -o qIterProg

qsortRec.o: qsortRec.c qsort.h
	gcc -c qsortRec.c

qsort.o: qsort.c qsort.h
	gcc -c qsort.c

qsortDr.o: qsortDr.c qsort.h
	gcc -c qsortDr.c

qsortIter.o: qsortIter.c qsort.h
	gcc -c qsortIter.c
