#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <curl/curl.h>

#include "Graph_AdjList.h"
#include "Queue.h"
#include "toDot.h"

int globalCount;

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

Vertex* parseLinks(FILE * fp){
	if(fp == NULL){
		return NULL;
	}	
	char temp[1024];
	Vertex *arr = (Vertex*)malloc(sizeof(Vertex)*100);
	arr[0]=NULL;
	int count = 0;
	char str[] = "<a href=\"";
	char url[200];
	char name[100];

	while(fgets(temp,1023,fp)) {
		while((strstr(temp, str)) != NULL) {
			int i;
			for(i=0; temp[i]!='\0' && (temp[i]!='<' || temp[i+1]!='a' || temp[i+2]!=' ' || temp[i+3]!='h' || temp[i+4]!='r' || temp[i+5]!='e' || temp[i+6]!='f' || temp[i+7]!='=' || temp[i+8]!='"'); ++i);
			i+=9;
			int j;
			for(j=0; temp[i]!='\0' && temp[i]!='"'; ++i,++j)
				url[j] = temp[i];
			url[j]='\0';
			printf("\nURL: %s\t",url);
			for(; temp[i]!='>'; ++i);
			++i;
			for(j=0; temp[i]!='\0' && temp[i]!='<'; ++i,++j)
				name[j] = temp[i];
			name[j]='\0';
			printf("Name: %s\n",name);
			if((count+1)%100 == 0)
				arr = (Vertex*)realloc(arr, sizeof(Vertex)*(count+101));
			printf("Count = %d\nGlobal count = %d\n",count,globalCount);
			arr[count] = (Vertex)malloc(sizeof(struct _vertex));
			arr[count]->name = (char*)malloc(sizeof(char)*100);
			strcpy(arr[count]->name,name);
			arr[count]->url = (char*)malloc(sizeof(char)*100);
			strcpy(arr[count]->url,url);
			++count;
			arr[count] = NULL;
			for(j=0; temp[i]!='\0'; ++i,++j)
				temp[j] = temp[i];
			temp[j]='\0';
			if(count > 1000)
				break;
		}
	}	
	//Close the file if still open.
	if(fp) {
		fclose(fp);
	}
   	return arr;
}

int main(int argc, char *args[]){
	globalCount = 0;
	if(argc < 2){
		printf("Too few arguments!\n");
		return -1;
	}
	CURL *curl_handle;
	static char *webfilename = "mylocalfile";
	FILE *webfile;
	Graph g = newGraph();
	Queue q = newQueue();
//	char url[50];
	Vertex *v;
	Vertex current = (Vertex)malloc(sizeof(struct _vertex));
	current->name = "Root";
	current->url = args[1];
	g = addNode(g,current);
	q = push(q,0);
//	strcpy(url,args[1]);

	do{
		int index = pop(q);
		current = g->vertices[index];
  		curl_global_init(CURL_GLOBAL_ALL);
  		/* init the curl session */
	  	curl_handle = curl_easy_init();

  		/* set URL to get */
		curl_easy_setopt(curl_handle, CURLOPT_URL, current->url);

		printf("URL: %s\n",current->url);

  		/* no progress meter please */
	  	curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);

  		/* send all data to this function  */
	  	curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);

  		/* open the web file */
	  	webfile = fopen(webfilename, "wb");
	  	if(!webfile) {
	    	curl_easy_cleanup(curl_handle);
	    	BROKEN(current);
	    	continue;
  		}

  		/* we want the body be written to this file handle instead of stdout */
		curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, webfile);

  		/* get it! */
		curl_easy_perform(curl_handle);

  		/* close the web file */
	  	fclose(webfile);

  		/* cleanup curl stuff */
	  	curl_easy_cleanup(curl_handle);

	  	webfile = fopen(webfilename,"rb");

	  	v = parseLinks(webfile);

	  	int i;

	  	for(i=0; v[i]!=NULL; ++i){
	  		if(getIndex(g,v[i]) == -1){
	  			q = push(q,g->numV);
	  			g = addNode(g,v[i]);
	  			++globalCount;
	  		}
	  		g = addEdge(g,current,v[i]);
	  		if(globalCount >= 1000)
	  			break;
	  	}
	  	FILE * fptr;
		fptr = fopen("graph.dot","w");	
		bst_print_dot(g,fptr);
		fclose(fptr);
		if(globalCount >= 1000){
	  		break;
	  	}

	}while(!isEmptyQ(q));

	FILE * fptr;
	fptr = fopen("graph.dot","w");	
	bst_print_dot(g,fptr);
	fclose(fptr);
	system("dot -Tpng graph.dot -o graph.png > 1.txt");
	system("rm 1.txt");
	system("eog graph.png&");
	system("clear");
	printf("%d Nodes Created!\n",globalCount);
  	return 0;
}