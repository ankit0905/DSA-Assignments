#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

void insert(node* hashTable[], int x)
{
	int hash = x%10;
	node* tmp = (node*)malloc(sizeof(node));
	tmp -> data = x;
	if(hashTable[hash] == NULL){
		tmp -> next = NULL;
		hashTable[hash] = tmp;	
	}
	else{
		node* head = hashTable[hash];
		tmp -> next = head;
		hashTable[hash] = tmp;
	}
}

void print(node* hashTable[])
{
	int i;
	node* curr;
	for(i=0; i<10; i++){
		printf("%d => ",i);
		if(hashTable[i] == NULL){
			printf("NULL\n");
		}
		else{
			curr = hashTable[i];
			while(curr -> next != NULL){
				printf("%d ", curr -> data);
				curr = curr -> next;
			}
			printf("%d\n",curr -> data);
		}
	}
}

void search(node* hashTable[], int x)
{
	int hash = x%10;
	node* curr = hashTable[hash];
	while(curr != NULL){
		if(curr -> data == x){
			printf("Element Found\n");
			return;
		}
		curr = curr -> next;
	}
	printf("Element Not Found\n");
}

void delete(node* hashTable[], int x)
{
	int hash = x%10;
	node* curr = hashTable[hash];
	if(curr != NULL && curr -> data == x){
		hashTable[hash] = curr -> next;
		free(curr);
		printf("%d deleted\n",x);
		return;
	}
	node* prev = NULL;
	while(curr != NULL && curr -> data != x){
		prev = curr;
		curr = curr -> next;
	}
	if(curr != NULL && curr -> data == x){
		prev -> next = curr -> next;
		free(curr);
		printf("%d deleted\n",x);
		return;
	}
	printf("%d not found\n",x);
}

int main()
{
	int i, ele;
	char choice;
	node* hashTable[10];
	for(i=0; i<10; i++)
		hashTable[i] = NULL;
	do{
		printf("Enter Choice: ");
		scanf(" %c",&choice);
		switch(choice){
			case 'a': printf("Input element to insert: ");
					  scanf("%d",&ele);
					  insert(hashTable, ele);
					  break;
	    	case 'b': printf("Printing Hash Table\n");
	    			  print(hashTable);
    				  break;
			case 'c': printf("Input element to search: ");
					  scanf("%d",&ele);
					  search(hashTable, ele);
					  break;
			case 'd': printf("Input element to delete: ");
					  scanf("%d",&ele);
					  delete(hashTable, ele);
					  break;
			case 'e': printf("Quitting\n");
					  break;
			default: printf("Invalid Choice\n");
					  break;
		}
	}while(choice != 'e');
	return 0;
}
