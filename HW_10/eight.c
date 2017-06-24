#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data, freq, count;
	char color;
	struct node* left;
	struct node* right;
	struct node* parent;
}node;

node* newNode(int ele)
{
	node* tmp = (node*)malloc(sizeof(node));
	tmp -> data = ele;
	tmp -> freq = 1;
	tmp -> color = 'R';
	tmp -> left = tmp -> right = tmp -> parent = NULL;
	return tmp;
}

void leftRotate(node** root, node* x)
{
	node* y = x -> right;
	x -> right = y -> left;
	if(y -> left != NULL)
		y -> left -> parent = x;
	y -> parent = x -> parent;
	if(x -> parent == NULL)
		*root = y;
	else if(x == x -> parent -> left)
		x -> parent -> left = y;
	else
		x -> parent -> right = y;
	y -> left = x;
	x -> parent = y;
}

void rightRotate(node** root, node* y)
{
	node* x = y -> left;
	y -> left = x -> right;
	if(x -> right != NULL)
		x -> right -> parent = y;
	x -> parent = y -> parent;
	if(y -> parent == NULL)
		*root = x;
	else if(y == y -> parent -> left)
		y -> parent -> left = x;
	else
		y -> parent -> right = x;
	x -> right = y;
	y -> parent = x;	
}

void RBInsertFixup(node** root, node* z)
{
	while(z -> parent && (z -> parent) -> color == 'R'){
		if(z -> parent -> parent == NULL)
			break;
		if(z -> parent == ((z -> parent) -> parent) -> left){
			printf("%d\n", z -> data);
			node* y = z -> parent -> parent -> right;
			if(y != NULL && y -> color == 'R'){
				z -> parent -> color = 'B';
				y -> color = 'B';
				z -> parent -> parent -> color = 'R';
				z = z -> parent -> parent;
			}
			else if(z == z -> parent -> right){
				z = z -> parent;
				leftRotate(root,z);
			}
			else{
				z -> parent -> color = 'B';
				z -> parent -> parent -> color = 'R';
				rightRotate(root,z -> parent -> parent);
			}
		}
		else{
			node* y = z -> parent -> parent -> left;
			if(y != NULL && y -> color == 'R'){
				z -> parent -> color = 'B';
				y -> color = 'B';
				z -> parent -> parent -> color = 'R';
				z = z -> parent -> parent;
			}
			else if(z == z -> parent -> left){
				z = z -> parent;
				rightRotate(root,z);
			}
			else{
				z -> parent -> color = 'B';
				z -> parent -> parent -> color = 'R';
				leftRotate(root,z -> parent -> parent);
			}
		}
	}
	(*root) -> color = 'B';
}

void insert(node** root, int data)
{
	node* y = NULL;
	node* x = *root;
	while(x != NULL){
		y = x;
		if(data < (x -> data))
			x = x -> left;
		else if(data > (x -> data))
			x = x -> right;
		else{
			(x -> freq)++;
			return;
		}
	}
	//printf("%p\n",x);
	node* z = newNode(data);
	z -> parent = y;
	//printf("%d\n",z -> data);
	if(y == NULL){
		z -> color = 'B';
		z -> count = 0;
		*root = z;
		return;
	}
	else if(data < (y -> data))
		y -> left = z;
	else
		y -> right = z;
	RBInsertFixup(root, z);
}

void RBTransplant(node** root, node* u, node* v)
{
	if(u -> parent == NULL)
		*root = v;
	else if(u == u -> parent -> left){
		u -> parent -> left = v;
	}
	else{
		u -> parent -> right = v;
	}
	if(v != NULL)
		v -> parent = u -> parent;
}

node* treeMin(node* x)
{
	node* z = x;
	while(x != NULL){
		z = x;
		x = x -> left;
	}
	return z;
}

void RBDeleteFixup(node** root, node* x)
{
	node* w;
	while(x != *root && x -> color == 'B'){
		if(x == x -> parent -> left){
			w = x -> parent -> right;
			if(w -> color == 'R'){
				w -> color = 'B';
				x -> parent -> color = 'R';
				leftRotate(root,x -> parent);
				w = x -> parent -> right;
			}
			if(w -> left -> color == 'B' && w -> right -> color == 'B'){
				w -> color = 'R';
				x = x -> parent;
			}
			else if(w -> right -> color == 'B'){
				w -> left -> color = 'B';
				w -> color = 'R';
				rightRotate(root,w);
				w = x -> parent -> right;
			}
			else{
				w -> color = x -> parent -> color;
				x -> parent -> color = 'B';
				w -> right -> color = 'B';
				leftRotate(root, x -> parent);
				x = *root;
			}
		}
		else{
			w = x -> parent -> left;
			if(w -> color == 'R'){
				w -> color = 'B';
				x -> parent -> color = 'R';
				rightRotate(root,x -> parent);
				w = x -> parent -> left;
			}
			if(w -> right -> color == 'B' && w -> left -> color == 'B'){
				w -> color = 'R';
				x = x -> parent;
			}
			else if(w -> left -> color == 'B'){
				w -> right -> color = 'B';
				w -> color = 'R';
				leftRotate(root,w);
				w = x -> parent -> left;
			}
			else{
				w -> color = x -> parent -> color;
				x -> parent -> color = 'B';
				w -> left -> color = 'B';
				rightRotate(root, x -> parent);
				x = *root;
			}
		}
	}
	x -> color = 'B';
}

void delete(node** root, int data)
{
	node* y = *root, *z, *x;
	while(y != NULL && y -> data != data){
		if(y -> data < data){
			y = y -> right;
		}
		else if(y -> data > data){
			y = y -> left;
		}
	}
	if(y == NULL){
		return;
	}
	else{
		if(y -> freq > 1){
			(y -> freq)--;
			return;
		}
		else{
			z = y;
		}
	}
	if(z == *root && z -> left == NULL && z -> right == NULL){
		*root = NULL;
		return;
	}
	char col = y -> color;
	if(z -> left == NULL){
		x = z -> right;
		RBTransplant(root,z,z -> right);
		if(x == NULL){
			x = z -> parent;
			leftRotate(root,x);
		}
	}
	else if(z -> right == NULL){
		x = z -> left;
		RBTransplant(root,z,z -> left);
	}
	else{
		y = treeMin(z -> right);
		col = y -> color;
		x = y -> right;
		if(y -> parent == z)
			x -> parent = y;
		else{
			RBTransplant(root,y,y -> right);
			y -> right = z -> right;
			y -> right -> parent = y;
		}
		RBTransplant(root,z,y);
		y -> left = z -> left;
		y -> left -> parent = y;
		y -> color = z -> color;
	}
	if(col == 'B'){
		RBDeleteFixup(root, x);
	}
}

void print(node* root)
{
	if(root == NULL)
		return;
	print(root -> left);
	printf("%d %c ", root -> data, root -> color);
	print(root -> right);
}

void freeTree(node* root)
{
	if(root == NULL)
		return;
	freeTree(root -> left);
	freeTree(root -> right);
	free(root);
}

int main()
{
	node* root = NULL;
	insert(&root, 41);
	insert(&root, 38);
	insert(&root, 31);
	insert(&root, 12);
	delete(&root, 31);
	insert(&root, 19);
	insert(&root, 8);
	delete(&root, 41);
	print(root);
	printf("\n");
	freeTree(root);
	return 0;
}
