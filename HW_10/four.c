#include <stdio.h>

void insert(int hashTable[], int x)
{
	int hash = x%10, i=1;
	while(hashTable[hash] != -1 && hashTable[hash] != -2 && i <= 10){
		hash = (x+i*i)%10;
		i++;
	}
	hashTable[hash] = x;
}

void print(int hashTable[])
{
	int i;
	for(i=0; i<10; i++){
		printf("%d => ", i);
		if(hashTable[i] == -1 || hashTable[i] == -2){
			printf("NULL\n");
		}		
		else{
			printf("%d\n",hashTable[i]);
		}
	}
}

void search(int hashTable[], int x)
{
	int hash = x%10, i=1;
	while(hashTable[hash] != x && hashTable[hash] != -1 && i<= 10){
		hash = (x+i*i)%10;
		i++;
	}
	if(hashTable[hash] == x){
		printf("Element Found\n");
	}
	else{
		printf("Element Not Found\n");
	}
}

void delete(int hashTable[], int x)
{
	int hash = x%10, i=1;
	while(hashTable[hash] != x && hashTable[hash] != -1 && i <= 10){
		hash = (x+i*i)%10;
		i++;
	}
	if(hashTable[hash] == x){
		hashTable[hash] = -2;
		printf("%d deleted\n",x);
	}
	else{
		printf("Element Not Found\n");
	}
}

int main()
{
	int i, ele;
	char choice;
	int hashTable[10];
	for(i=0; i<10; i++)
		hashTable[i] = -1;
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
