#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}node;

void insertAtBeg(node** head, int x)
{
	node* tmp = (node*)malloc(sizeof(node));
	tmp -> data = x;
	if(*head == NULL){
		tmp -> next = NULL;
		tmp -> prev = NULL;
		*head = tmp;
		return;
	}
	(*head) -> prev = tmp;
	tmp -> next = *head;
	tmp -> prev = NULL;
	*head = tmp;
}

void insertAtEnd(node** head, int x)
{
	node* tmp = (node*)malloc(sizeof(node));
	tmp -> data = x;
	if(*head == NULL){
		tmp -> next = NULL;
		tmp -> prev = NULL;
		*head = tmp;
		return;
	}
	node *curr = *head;
	while(curr -> next != NULL){
		curr = curr -> next;
	}
	tmp -> next = NULL;
	tmp -> prev = curr;
	curr -> next = tmp;
}

void reverse(node** head)
{
	node *tmp = NULL;
	node *curr = *head;
	while(curr != NULL){
		tmp = curr -> prev;
		curr -> prev = curr -> next;
		curr -> next = tmp;
		curr = curr -> prev;
	}
	if(tmp != NULL)
		*head = tmp -> prev;
}

void rec_reverse(node** head, node* curr, node* prev)
{
	if(*head == NULL)
		return;
	else if(curr -> next == NULL){
		*head = curr;
		curr -> next = prev;
		curr -> prev = NULL;
		return;
	}
	node* tmp = curr -> next;
	curr -> prev = curr -> next;
	curr -> next = prev;
	rec_reverse(head, tmp, curr);
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

int main()
{
	node *head = NULL;
	printf("Menu Options: \n");
	printf("a. Insert an element at the beginning\n");
	printf("b. Insert an element at the end\n");
	printf("c. Reverse the elements (1. Iterative method and 2. Recursive method)\n");
	printf("d. Print the elements of the list\n");
	printf("e. Quit Program\n\n");
	char choice;
	int ele, idx;
	while(1){
		scanf(" %c",&choice);
		if(choice == 'a'){
			printf("Enter element to insert: ");
			scanf("%d",&ele);
			insertAtBeg(&head,ele);
		}
		else if(choice == 'b'){
			printf("Enter element to insert: ");
			scanf("%d",&ele);
			insertAtEnd(&head,ele);
		}
		else if(choice == 'c'){
			int type;
			printf("Print type: ");
			scanf("%d",&type);
			if(type==1){
				reverse(&head);
			}
			else{
				rec_reverse(&head, head, NULL);
			}
			printf("List reversed\n");
		}
		else if(choice == 'd'){
			printList(&head);
		}
		else if(choice == 'e'){
			printf("Qutting\n");
			break;
		}
		else{
			printf("Invalid Choice.\n");
		}
	}
	return 0;
}
