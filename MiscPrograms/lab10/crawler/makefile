crawler:	crawler.o Graph_AdjList.o List.o Queue.o toDot.o
	gcc Graph_AdjList.o List.o Queue.o toDot.o crawler.o -o crawler -lcurl

test:		driver.o Graph_AdjList.o List.o Queue.o toDot.o
	gcc driver.o Graph_AdjList.o List.o Queue.o toDot.o -o test

driver.o:	driver.c Graph_AdjList.h List.h
	gcc -c driver.c

crawler.o:	crawler.c Graph_AdjList.h Queue.h toDot.h
	gcc -c crawler.c

Graph_AdjList.o:	Graph_AdjList.c Graph_AdjList.h List.h
	gcc -c Graph_AdjList.c

List.o:		List.c List.h
	gcc -c List.c

Queue.o:	Queue.c Queue.h
	gcc -c Queue.c

toDot.o:	toDot.c toDot.h
	gcc -c toDot.c