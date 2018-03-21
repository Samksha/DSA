compileAll: bank.o bankDr.o
	gcc bank.o bankDr.o -o bankProg

bank.o: bank.c bank.h
	gcc -c bank.c

bankDr.o: bankDr.c bank.h
	gcc -c bankDr.c
