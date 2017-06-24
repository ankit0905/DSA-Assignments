#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next; 
}node;

void modify(node** root)
{
	node *curr = *root;
	if(curr == NULL)
		return;
	while(curr != NULL && curr -> next != NULL){
		int tmp = curr -> data;
		curr -> data = (curr -> next) -> data;
		(curr -> next) -> data = tmp;
		curr = curr -> next -> next;
	}
}

void insertAtEnd(node **root, int x)
{
	node *curr = *root;
	node *tmp = (node*)malloc(sizeof(node));
	tmp -> data = x;
	tmp -> next = NULL;
	if(curr == NULL){
		*root = tmp;
		return;
	}
	while(curr -> next != NULL){
		curr = curr -> next;
	}
	curr -> next = tmp;
}

void printList(node** head)
{
	node* curr = *head;
	if(curr == NULL){
		printf("Empty List\n");
	}
	else{
		do{
			printf("%d ",curr->data);
			curr = curr->next;
		}while(curr != NULL);
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
	node* head = NULL;
	insertAtEnd(&head,1);
	insertAtEnd(&head,2);
	insertAtEnd(&head,3);
	insertAtEnd(&head,4);
	insertAtEnd(&head,5);
	insertAtEnd(&head,6);
	insertAtEnd(&head,7);
	insertAtEnd(&head,8);
	printList(&head);
	modify(&head);
	printList(&head);
	freeList(&head);
	return 0;
}
