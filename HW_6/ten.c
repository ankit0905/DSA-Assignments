#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

void InsertAtBeg(node **root, int x)
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp -> data = x;
	tmp -> next = (*root);
	*root = tmp;
} 

void reverse(node **head)
{
	node *prev = NULL, *curr = *head, *next;
	while(curr != NULL){
		next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

void Print(node *root)
{
	node *curr = root;
	while(curr != NULL){
		printf("%d ", curr -> data);
		curr = curr -> next;
	}
	printf("\n");
}

void freeList(node **root)
{
	node *curr = *root;
	node *tmp;
	while(curr != NULL){
		tmp = curr;
		curr = curr -> next;
		free(tmp);
	}
}

int main()
{
	node *head=NULL;
	InsertAtBeg(&head, 8);
	InsertAtBeg(&head, 6);
	InsertAtBeg(&head, 3);
	InsertAtBeg(&head, 2);
	InsertAtBeg(&head, 9);
	InsertAtBeg(&head, 7);
	InsertAtBeg(&head, 4);
	InsertAtBeg(&head, 1);
	Print(head);
	reverse(&head);
	Print(head);
	freeList(&head);
	return 0;
}
