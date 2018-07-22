cmp: dfs.o list.o listIter.o dfsDr.o dfs.h 
	gcc dfs.o list.o listIter.o dfsDr.o -o dfsProg

dfs.o: dfs.c dfs.h
	gcc -c dfs.c

dfsDr.o: dfsDr.c dfs.h
	gcc -c dfsDr.c

que.o: que.c que.h
	gcc -c que.c

list.o: list.c list.h
	gcc -c list.c

listIter.o: listIter.c list.h
	gcc -c listIter.c
