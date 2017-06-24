#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

typedef struct stack{
	int size;
	int top;
	node* *array;
}stack;

/*void insert(node** root, int x)
{
	node* tmp = (node*)malloc(sizeof(node));
	tmp -> data = x;
	tmp -> left = NULL;
	tmp -> right = NULL;
	if(*root == NULL){
		*root = tmp;
	}
	else{
		node* curr = *root;
		while(1){
			if(x <= (curr -> data)){
				if(curr -> left == NULL){
					curr -> left = tmp;
				}
				else{
					curr = curr -> left;
				}
			}
			else{
				if(curr -> right == NULL){
					curr -> right = tmp;
				}
				else{
					curr = curr -> right;
				}
			}
		}
	}
}*/

node* newNode(int x)
{
	node* tmp = (node*)malloc(sizeof(node));
	tmp -> data = x;
	tmp -> left = tmp -> right = NULL;
	return tmp;
}

void push(stack* st, node* tmp)
{
	st -> array[++st -> top] = tmp;
}

node* pop(stack* st)
{
	if(st -> top == -1)
		return NULL;
	return st -> array[(st->top)--];
}

void printPostOrder(node* root)
{
	if(root == NULL)
		return;
	stack* s1 = (stack*)malloc(sizeof(stack));
	stack* s2 = (stack*)malloc(sizeof(stack));
	s1 -> size = s2 -> size = 100;
	s1 -> top = s2 -> top = -1;
	s1 -> array = (node**)malloc((100)*(sizeof(node*)));
	s2 -> array = (node**)malloc((100)*(sizeof(node*)));
	node* tmp;
	push(s1, root);
	while(s1 -> top != -1){
		tmp = pop(s1);
		push(s2, tmp);
		if(tmp -> left)
			push(s1, tmp -> left);
		if(tmp -> right)
			push(s1, tmp -> right);
	}
	while(s2 -> top != -1){
		tmp = pop(s2);
		printf("%d ", tmp -> data);
	}
	printf("\n");
}

void freeTree(node* root)
{
	if(root == NULL){
		return;
	}
	freeTree(root -> left);
	freeTree(root -> right);
	free(root);
}

int main()
{
	node* root = NULL;
	root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
	printPostOrder(root);
	freeTree(root);
	return 0;	
}
