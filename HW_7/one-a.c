#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next; 
}node;

void modify(node** root)
{
	node *curr = *root;
	node *prev = NULL, *tmp;
	if(curr == NULL || curr -> next == NULL)
		return;
	int num, len;
	tmp = curr;
	while(tmp != NULL){
		len++;
		tmp = tmp -> next;
	}
	while(len--){
		tmp = curr;
		while(tmp != NULL){
			num = tmp -> data;
			if(num % 2 == 1){
				if(tmp -> next != NULL && ((tmp -> next) -> data) % 2 == 0){
					tmp -> data = (tmp -> next) -> data;
					(tmp -> next) -> data = num;
				}
			}
			tmp = tmp -> next;
		}
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
	int n, i;
	scanf("%d",&n);
	for(i=0; i<n; i++){
		int x;
		scanf("%d",&x);
		insertAtEnd(&head,x);
	}
	/*insertAtEnd(&head,1);
	insertAtEnd(&head,2);
	insertAtEnd(&head,3);
	insertAtEnd(&head,4);
	insertAtEnd(&head,5);
	insertAtEnd(&head,6);
	*/
	printList(&head);
	modify(&head);
	printList(&head);
	freeList(&head);
	return 0;
}



// 1 2 3 4 5 6





















