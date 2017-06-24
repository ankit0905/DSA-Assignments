#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

node* build(int preorder[], int* idx, int ele, int min, int max, int n)
{
	if(*idx >= n)
		return NULL;
	node* tmp = NULL;
	if(ele > min && ele < max){
		tmp = (node*)malloc(sizeof(node));
		tmp -> data = ele;
		(*idx)++; 
		if(*idx < n){
			tmp -> left = build(preorder, idx, preorder[*idx],min,ele,n);
			tmp -> right = build(preorder, idx, preorder[*idx],ele,max,n);
		}
	}
	return tmp;
}

void print(node* root)
{
	if(root == NULL)
		return;
	print(root -> left);
	printf("%d ",root -> data);
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
	int n, i;
	scanf("%d",&n);
	int preorder[n];
	for(i=0; i<n; i++)
		scanf("%d",&preorder[i]);
	int idx = 0;
	node* root = build(preorder, &idx, preorder[0], INT_MIN, INT_MAX,n);
	print(root);
	printf("\n");
	freeTree(root);
	return 0;
}
