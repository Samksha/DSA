#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BinTree.h"
#include "list.h"
#include "toDot.h"

int main(){
	srand(time(0));
	int choice = 0;
	Tree t = NULL;
	int m,n,i;
	FILE * fptr;
	Node temp;
	List s;
	while(choice !=8){
		printf("\n1. Make graph with n random values\n2. Insert element\n3. Delete element\n4. Find element\n5. Find Kth smallest element\n6. Find in range\n7. View graph\n8. Exit\n\nYour choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter n: ");
				scanf("%d",&n);
				clearTree(t);
				for(i=0; i<n; ++i){
					int k = rand()%100;
					t = add(t,k);
				}
				printf("Tree created!\n");
				break;
			case 2:
				printf("Enter element to be inserted: ");
				scanf("%d",&n);
				t = add(t,n);
				printf("Element added!\n");
				break;
			case 3:
				printf("Enter element to be deleted: ");
				scanf("%d",&n);
				t = AVL_delete(t,n);
				printf("Element deleted!\n");
				break;
			case 4:
				printf("Enter element to be searched for: "); 
				scanf("%d",&n);
				if(find(t,n)!=NULL)
					printf("Element found!\n");
				else
					printf("Element not found!\n");
				break;
			case 5:
				printf("Enter value of K: "); 
				scanf("%d",&n);
				temp = inOrder(t,n);
				if(temp!=NULL)
					printf("Kth smallest element is: %d\n",temp->key);
				else
					printf("Element not found!\n");
				break;
			case 6:
				printf("Enter values of K1 & K2: ");
				scanf("%d%d",&m,&n);
				if(m > n){
					m += n;
					n = m - n;
					m = m - n;
				}
				s = inRange(t,m,n);
				printList(s);
				break;
			case 7:
				fptr = fopen("tree.dot","w");	
				bst_print_dot(t,fptr);
				fclose(fptr);
				system("dot -Tpng tree.dot -o tree.png > 1.txt");
				system("rm 1.txt");
				system("eog tree.png&");
				break;
			case 8:
				fptr = fopen("tree.dot","w");
				bst_print_dot(t,fptr);
				fclose(fptr);
				break;
			default:
				printf("Enter a valid choice!\n");
		}
	}
	return 0;
}