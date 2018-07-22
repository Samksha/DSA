#include <stdlib.h>
#include <stdio.h>
#include "BinTree.h"

Tree newTree(int key){
	return add(NULL, key);
}

Tree add(Tree t, int key){
	Node n = (Node)malloc(sizeof(struct _tree));
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	n->balance = 0;
	return AVL_add_node(t,n);
}

Tree add_node(Tree t, Node n){
	if(t == NULL)
		return n;
	else if(t->key == n->key)
		return t;
	else if(n->key < t->key)
		t->left = add_node(t->left,n);
	else
		t->right = add_node(t->right,n);
	return t;
}

Node find(Tree t, int key){
	while(t!=NULL){
		if(t->key == key)	break;
		else if(key < t->key)	t = t->left;
		else	t = t->right;
	}
	return t;
}

Tree inOrderSuccessor(Tree t, Node n){
	if(n->right != NULL){
		n = n->right;
		while(n->left != NULL){
			n = n->left;
		}
		return n;
	}
	Node succ = NULL;
	while(t != NULL){
		if(n->key < t->key){
			succ = t;
			t = t->left;
		}
		else if(n->key > t->key){
			t = t->right;
		}
		else
			break;
	}
	return succ;
}

Tree delete(Tree t, int key){
	if(t == NULL)	return t;
	if(key == t->key){
		if(t->right == NULL){
			Node n = t->left;
			free(t);
			return n;
		}
		else if(t->left == NULL){
			Node n = t->right;
			free(t);
			return n;
		}
		else{
			t->key = inOrderSuccessor(t,t)->key;
			t->right = delete(t->right, t->key);
			return t;
		}
	}
	else if(key < t->key){
		t->left = delete(t->left, key);
		return t;
	}
	else{
		t->right = delete(t->right, key);
		return t;
	}
}

void clearTree(Tree t){
	if(t == NULL)	return;
	else if(t->left != NULL){
		clearTree(t->left);
		free(t);
	}
	else if(t->right != NULL){
		clearTree(t->right);
		free(t);
	}
	else{
		free(t);
	}
}

void swap(Node x, Node y){
	Node a = (Node)malloc(sizeof(struct _tree));
	*a = *x;
	*x = *y;
	*y = *a;
	free(a);
}

int recursiveHeight(Tree t){
	if(t == NULL)
		return 0;
	int left = recursiveHeight(t->left);
	int right = recursiveHeight(t->right);
	if(left > right)	
		return left + 1;
	else
		return right + 1;
}

Tree rotate(Tree bt, Node X, Node Y, Node Z){
	Node a,b,c;
	Node T[4];
	a = X;
	b = Y;
	c = Z;
	if(a->key > b->key)	swap(a,b);
	if(a->key > c->key)	swap(a,c);
	if(b->key > c->key)	swap(b,c);
	int i=0;
	if(a->left != X && a->left != Y)	T[i++] = a->left;
	if(a->right != X && a->right != Y)	T[i++] = a->right;
	if(b->left != X && b->left != Y)	T[i++] = b->left;
	if(b->right != X && b->right != Y)	T[i++] = b->right;
	if(c->left != X && c->left != Y)	T[i++] = c->left;
	if(c->right != X && c->right != Y)	T[i++] = c->right;
	Tree t = bt;
	while(t->left != Z && t->right != Z){
		if(Z->key < t->key)
			t = t->left;
		else if(Z->key > t->key)
			t = t->right;
		else
			break;
	}
	if(t->left == Z)
		t->left = b;
	else if(t->right == Z)
		t->right = b;
	b->left = a;
	b->right = c;
	a->left = T[0];
	a->right = T[1];
	c->left = T[2];
	c->right = T[3];
	if(bt == Z)
		return b;
	else
		return bt;
}

Tree AVL_add_node(Tree t, Node n){
	if(t == NULL)
		return n;
	else if(t->key == n->key)
		return t;
	else if(n->key < t->key)
		t->left = AVL_add_node(t->left,n);
	else
		t->right = AVL_add_node(t->right,n);
	t->balance = recursiveHeight(t->right)-recursiveHeight(t->left);
	if(t->balance < -1 || t->balance >1 ){
		Node x,y,z = t;
		if(n->key < z->key)
			y = z->left;
		else
			y = z->right;
		if(n->key < y->key)
			x = y->left;
		else
			x = y->right;
		t = rotate(t,x,y,z);
	}
	return t;
}

Tree AVL_delete(Tree t, int key){
	if(t == NULL)	return t;
	if(key == t->key){
		if(t->right == NULL){
			Node n = t->left;
			free(t);
			t = n;
		}
		else if(t->left == NULL){
			Node n = t->right;
			free(t);
			t = n;
		}
		else{
			t->key = inOrderSuccessor(t,t)->key;
			t->right = delete(t->right, t->key);
		}
	}
	else if(key < t->key){
		t->left = delete(t->left, key);
	}
	else{
		t->right = delete(t->right, key);
	}
	t->balance = recursiveHeight(t->right)-recursiveHeight(t->left);
	if(t->balance < -1 || t->balance >1 ){
		Node x,y,z = t;
		if(recursiveHeight(z->left) > recursiveHeight(z->right))
			y = z->left;
		else
			y = z->right;
		if(recursiveHeight(y->left) > recursiveHeight(y->right))
			x = y->left;
		else
			x = y->right;
		t = rotate(t,x,y,z);
	}
	return t;
}

Node inOrder(Tree bt, int k){
	if(bt == NULL)
		return NULL;
	int n = 1;
	Tree t = bt;
	while(t->left != NULL)
		t = t->left;
	for(n = 1; n < k; ++n)
		t = inOrderSuccessor(bt,t);
	return t;
}


List inRange(Tree t, int k1, int k2){
	List s = newList();
	if(t == NULL)
		return s;
	if(t->key > k2){
		s = append(s,inRange(t->left,k1,k2));
	}
	else if(t->key < k1){
		s = append(s,inRange(t->right,k1,k2));
	}
	else{
		s = append(s,inRange(t->left,k1,t->key));
		s = pushBack(s,t);
		s = append(s,inRange(t->right,t->key,k2));
	}
	return s;
}