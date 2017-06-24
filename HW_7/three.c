#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}node;

void insertAtBeg(node** head, node** tail, int x)
{
	node* tmp = (node*)malloc(sizeof(node));
	tmp -> data = x;
	if(*head == NULL){
		*head = tmp;
		*tail = tmp;
		tmp -> next = *head;
		tmp -> prev = tmp;
		return;
	}
	tmp -> next = (*head);
	tmp -> prev = *tail;
	*head = tmp;
	(*tail) -> next = *head;
}

void insertAtEnd(node** head, node** tail, int x)
{
	node* tmp = (node*)malloc(sizeof(node));
	tmp -> data = x;
	if(*head == NULL){
		*head = tmp;
		*tail = tmp;
		tmp -> next = tmp;
		tmp -> prev = tmp;
		return;
	}
	node* curr = *head;
	(*tail) -> next = tmp;
	tmp -> prev = *tail;
	tmp -> next = *head;
	*tail = tmp;
	(*head) -> prev = *tail;
}

void insertAfterIndex(node** head, node** tail, int i, int x)
{
	node* curr = *head;
	node* tmp = (node*)malloc(sizeof(node));
	tmp -> data = x;
	int idx = 0;
	while(idx != i){
		curr = curr -> next;
		idx++;
	}
	if(curr == *tail){
		*tail = tmp;
	}
	tmp -> next = curr -> next;
	curr -> next = tmp;
	tmp -> prev = curr;
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
		}while(curr != *head);
	}
	printf("\n");
}

int main()
{
	node *head = NULL;
	node *tail = NULL;
	printf("Menu Options: \n");
	printf("a. Insert an element at the beginning\n");
	printf("b. Insert an element at the end\n");
	printf("c. Insert an element after an index (input i - index\n");
	printf("d. Print the elements of the list\n");
	printf("e. Quit Program\n\n");
	char choice;
	int ele, idx;
	while(1){
		scanf(" %c",&choice);
		if(choice == 'a'){
			printf("Enter element to insert: ");
			scanf("%d",&ele);
			insertAtBeg(&head,&tail,ele);
		}
		else if(choice == 'b'){
			printf("Enter element to insert: ");
			scanf("%d",&ele);
			insertAtEnd(&head,&tail,ele);
		}
		else if(choice == 'c'){
			printf("Enter index followed by element: ");
			scanf("%d %d",&idx,&ele);
			insertAfterIndex(&head,&tail,idx,ele);
		}
		else if(choice == 'd'){
			printList(&head);
		}
		else{
			break;
		}
	}
	return 0;
}
