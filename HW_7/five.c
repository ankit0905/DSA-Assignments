#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next; 
}node;

void InsertAtBeg(node **root, int x)
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp -> data = x;
	tmp -> next = (*root);
	*root = tmp;
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

void reverse(node** head)
{
	node* prev = NULL, *curr = *head, *next;
	while(curr != NULL){
		next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

int compare(node* head1, node* head2)
{
	node* tmp1 = head1;
	node* tmp2 = head2;
	while(tmp1 && tmp2){
		if(tmp1 -> data == tmp2 -> data){
			tmp1 = tmp1 -> next;
			tmp2 = tmp2 -> next;
		}
		else{
			return 0;
		}
	}
	if(tmp1 == NULL && tmp2 == NULL)
		return 1;
	return 0; 
}

int checkPalin(node** head)
{
	int res;
	node* slow = *head, *fast = *head, *mid = NULL, *prev;
	if(*head != NULL && (*head)->next != NULL){
		while(fast != NULL && fast->next != NULL){
			fast = fast->next->next;
			prev = slow;
			slow = slow->next;
		}
		if(fast != NULL){
			mid = slow;
			slow = slow->next;
		}
		node* head2 = slow;
		prev -> next = NULL;
		reverse(&head2);
		res = compare(*head, head2);
		reverse(&head2);
		if(mid != NULL){
			prev -> next = mid;
			mid -> next = head2;
		}
		else{
			prev -> next = head2;
		}
	}
	return res;
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
	InsertAtBeg(&head, 1);
	InsertAtBeg(&head, 2);
	InsertAtBeg(&head, 3);
	InsertAtBeg(&head, 4);
	InsertAtBeg(&head, 2);
	InsertAtBeg(&head, 1);
	if(checkPalin(&head))
		printf("Palindrome\n");
	else
		printf("Not Palindrome\n");
	freeList(&head);
	return 0;
}
