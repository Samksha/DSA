
#include <stdio.h>
#include <stdlib.h>
#include "Graph_AdjList.h"
#include "toDot.h"

int main(){
	int choice = 0,i;
	Graph g = NULL;
	FILE * fptr;
	Vertex v1;
	Vertex v2;
	Vertex v3 = (Vertex)malloc(sizeof(struct _vertex));
	v3->name = (char*)malloc(sizeof(char)*20);
	while(choice != 7){
		printf("1. Create empty graph/Clear graph \n2. Add a node\n3. Add an edge\n4. Get degree of vertices\n5. Get adjacent vertices\n6. View graph\n7. Exit\n\nYour choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				if(g!=NULL)
					free(g);
				g = newGraph();
				printf("New empty graph created!\n");
				break;
			case 2:
				if(g == NULL)
					g = newGraph();
				printf("Enter name of node: ");
				v1 = (Vertex)malloc(sizeof(struct _vertex));
				v1->name = (char*)malloc(sizeof(char)*20);
				scanf("%s",v1->name);
				g = addNode(g,v1);
				break;
			case 3:
				printf("Enter v1 & v2:");
				v1 = (Vertex)malloc(sizeof(struct _vertex));
				v1->name = (char*)malloc(sizeof(char)*20);
				v2 = (Vertex)malloc(sizeof(struct _vertex));
				v2->name = (char*)malloc(sizeof(char)*20);
				scanf("%s",v1->name);
				scanf("%s",v2->name);
				g = addEdge(g,v1,v2);
				break;
			case 4:
				printf("Enter vertex: ");
				scanf("%s",v3->name);
				printf("Degree is %d\n",degree(g,v3));
				break;
			case 5:
				printf("Enter vertex: ");
				scanf("%s",v3->name);
				int *arr = getAdjacent(g,v3);
				for(i = 0; arr[i]!=-1; ++i){
					printf("%s\t",g->vertices[arr[i]]->name);
				}
				printf("\n");
				break;
	/*		case 6:
				printf("Enter vertex: ");
				scanf("%s",v3->name);
				BFT(g,v3);
				break;
	*/		case 6:
				fptr = fopen("graph.dot","w");	
				bst_print_dot(g,fptr);
				fclose(fptr);
				system("dot -Tpng graph.dot -o graph.png > 1.txt");
				system("rm 1.txt");
				system("eog graph.png&");
				break;
			case 7:
				break;
			default:
				printf("Invalid Entry!\n");
		}
	}
	free(v3);
	return 0;
}
