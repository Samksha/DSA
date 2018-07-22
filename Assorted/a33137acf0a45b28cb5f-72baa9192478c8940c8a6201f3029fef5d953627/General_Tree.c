/*
  Author: Elizabeth Sander
  Date: 4/9/15
  
  This code contains a recursive implementations of the DFS
  algorithm for a general tree. Here, I am storing the general
  tree as a binary tree by giving each node a pointer to its
  first child and the next sibling.

  For details, see
  http://en.wikipedia.org/wiki/Binary_tree#Encoding_general_trees_as_binary_trees
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char *val;
	struct node *firstChild;
	struct node *nextSibling;
} node;

node *insertSibling(node *tree, char *val)
{
	node *newnode = malloc(sizeof(node*));  

	newnode->val = val;
	newnode->firstChild = NULL;
	newnode->nextSibling = tree;

	return newnode;
}

node *insertParent(node *tree, char *val)
{
	node *newnode = malloc(sizeof(node*));

	newnode->val = val;
	newnode->firstChild = tree;
	newnode->nextSibling = NULL;

	return newnode;
}

// The printing format is a little bit wonky, but it is
// serviceable for debugging purposes.
void printTree(node *tree)
{
	if((tree->firstChild) != NULL){
		fprintf(stderr, "%s->", tree->val);
		printTree(tree->firstChild);
	}
	if((tree->nextSibling) != NULL){
		fprintf(stderr, "%s", tree->val);
		fprintf(stderr, "\n%s--", tree->val);
		printTree(tree->nextSibling);
	}
	if(!(tree->firstChild) && !(tree->nextSibling)){
		fprintf(stderr, "%s", tree->val);
	}
}

void deleteTree(node *tree)
{
	//delete a tree from memory
	if((tree->firstChild) != NULL){
		deleteTree(tree->firstChild);
	}
	if((tree->nextSibling) != NULL){
		deleteTree(tree->nextSibling);
	}
	free(tree);
}

node *exampleTree()
{
	// This generates a small example tree for testing the DFS
	// example taken from recurse code samples
	node *root = malloc(sizeof(node*));
	node *tmp = malloc(sizeof(node*));
	root->val = "h";
	root->firstChild = NULL;
	root->nextSibling = NULL;


	// Left half of the tree
	tmp->val = "f";
	tmp->firstChild = NULL;
	tmp->nextSibling = NULL;
	char *label = "e";
	tmp = insertSibling(tmp, label);
	label = "d";
	tmp = insertSibling(tmp, label);
	label = "b";
	tmp = insertParent(tmp, label);

	// Right half of the tree
	label = "g";
	root = insertParent(root, label);
	label = "c";
	root = insertParent(root, label);
	// b is sibling of c
	root->nextSibling = tmp;
	label = "a";
	root = insertParent(root, label);

	return(root);
}

node *DFS(node *tree, char *targetval)
{
	// allocate space for the tree we want to return
	node *outtree = malloc(sizeof(node*));
	outtree->val = NULL;
	outtree->firstChild = NULL;
	outtree->nextSibling = NULL;
	//fprintf(stderr, "label: %s target: %s\n", tree->val, targetval);
	//fprintf(stderr, "match? %d\n", strcmp(tree->val, targetval));
	
	if(strcmp(tree->val, targetval) == 0){
		// we found the node we're looking for!
		fprintf(stderr, "Node found!\n");
		return(tree);
	}
	else {
		// it's depth first, so first let's look for children
		if((tree->firstChild) != NULL){
			outtree = DFS(tree->firstChild, targetval);
		}
		// return if the return tree isn't null
		if((outtree->val) != NULL){
			return(outtree);
		}
		else {
			// next, let's look for siblings
			if((tree->nextSibling) != NULL){
				outtree = DFS(tree->nextSibling, targetval);
			}
			// return the tree, which will be NULL if the target node
			// was not found
			return(outtree);
		}
	}
}

// main takes in a node name and looks for it in the
// given example tree
int main(int argc, char *argv[])
{
	char *label = argv[1];
	node *tree = exampleTree();
	node *outtree = malloc(sizeof(node*));
	// print original tree
	printTree(tree);
	fprintf(stderr, "\n");
	outtree = DFS(tree, label);
	// print subtree found by DFS if found
	if((outtree->val) != NULL){
		printTree(outtree);
		fprintf(stderr, "\n");
	}
	else {
		fprintf(stderr, "No node found with the input label\n");
	}

	return 0;
}
