#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
	char data;
	struct node* left;
	struct node* right;	
}node;	

node* build(char inorder[], char postorder[], int st, int en, int* postIdx)
{
	if(st > en)
		return NULL;
	node* tmp = (node*)malloc(sizeof(node));
	tmp -> data = postorder[*postIdx];
	tmp -> left = tmp -> right = NULL; 
	(*postIdx)--;
	if(st == en)
		return tmp;
	int index, i;
	for(i=st; i<=en; i++){
		if(inorder[i] == tmp -> data)
			break;
	}
	index = i;
	tmp -> right = build(inorder, postorder, index+1, en, postIdx);
	tmp -> left = build(inorder, postorder, st, index-1, postIdx);
	return tmp;
}

void print(node* root)
{
	if(root == NULL)
		return;
	printf("%c",root->data);
	print(root -> left);
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
	char inorder[100], postorder[100];
	scanf("%s %s",inorder,postorder);
	int len = strlen(inorder);
	int postIdx = len-1;
	node* root = build(inorder, postorder, 0, len-1, &postIdx);
	print(root);
	freeTree(root);
	return 0;
}

