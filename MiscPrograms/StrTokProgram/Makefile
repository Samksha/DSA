read: readfile.o readDr.o readfile.h
	gcc readfile.o readDr.o -o rProg

readfile.o: readfile.c readfile.h
	gcc -c readfile.c

readDr.o: readDr.c readfile.h
	gcc -c readDr.c

