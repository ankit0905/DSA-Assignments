#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

typedef struct qNode{
	node* data;
	struct qNode* next;
}qNode;

typedef struct queue{
	qNode *front, *rear;
}queue;

node* newNode(int x)
{
	node* tmp = (node*)malloc(sizeof(node));
	tmp -> data = x;
	tmp -> left = tmp -> right = NULL;
	return tmp;
}

void enqueue(queue* q, node* data)
{
	qNode* tmp = (qNode*)malloc(sizeof(qNode));
	tmp -> data = data;
	tmp -> next = NULL;
	if(q -> rear == NULL){
		q -> front = q -> rear = tmp;
		return;
	}
	q -> rear -> next = tmp;
	q -> rear = tmp;
}

qNode* dequeue(queue* q)
{
	if(q -> front == NULL)
		return NULL;
	qNode* tmp = q -> front;
	q -> front = q -> front -> next;
	if(q -> front == NULL)
		q -> rear = NULL;
	return tmp;
}

int empty(queue* q)
{
	return (q -> front == NULL);
}

void printLevelOrder(node* root)
{
	queue *q = (queue*)malloc(sizeof(queue));
	q -> front = q -> rear = NULL;
	if(root){
		enqueue(q, root);
	}
	printf("Level Order: ");
	for(; !empty(q); dequeue(q)){
		printf("%d ", ((q -> front) -> data) -> data);
		if(((q -> front) -> data) -> left)
			enqueue(q, ((q -> front) -> data) -> left);
		if(((q -> front) -> data) -> right)
			enqueue(q, ((q -> front) -> data)-> right);
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
	printLevelOrder(root);
	freeTree(root);
	return 0;	
}
