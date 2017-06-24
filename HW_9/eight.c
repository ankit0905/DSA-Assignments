#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
	struct node* left;
	struct node* right;
	struct node* parent;
}node;

void reverse(char original[])
{
	int len = strlen(original);
	int i = 0, j = len-1;
	while(i < j){
		char tmp = original[i];
		original[i] = original[j];
		original[j] = tmp;
		i++;
		j--;
	}
}

char prefix[105];

void toPrefix(char infix[])
{
	int i,len = strlen(infix), top = -1, curr = 0;
	char stack[len];
	reverse(infix);
	//printf("%s\n",infix);
	for(i=0; i<len; i++){
		char ch = infix[i];
		//printf("%c",ch);
		if(ch == '(')
			ch = infix[i] = ')';
		else if(ch == ')')
			ch = infix[i] = '(';
		if(ch == '+' || ch == '*' || ch == '-' || ch == '/'){
			while(top != -1 && stack[top] != '('){
				prefix[curr++] = stack[top];
				top--;
			}
			top++;
			stack[top] = ch;
		}
		else if(ch == '('){
			top++;
			stack[top] = ch;
		}
		else if(ch == ')'){
			while(stack[top] != '('){
				prefix[curr++] = stack[top];
				top--;
			}
			top--;
		}
		else{
			prefix[curr++] = ch;
		}
	}
	reverse(infix);
	while(top != -1){
		prefix[curr++] = stack[top];
		top--;
	}
	prefix[curr] = '\0';
	reverse(prefix);
}

int isOperand(char ele)
{
    if(ele >= 97 && ele <= 122 || ele >= 65 && ele <= 90)
        return 1;
    else
        return 0;
}

void build(node** root)
{
	int i, len = strlen(prefix);
	node* curr = *root;
	for(i=0; i<len; i++){
		node* tmp = (node*)malloc(sizeof(node));
		tmp -> data = prefix[i];
		tmp -> left = NULL;
		tmp -> right = NULL;
		if(!*root){
			tmp -> parent = NULL;
			*root = tmp;
			curr = tmp;
		}
		else if(isOperand(prefix[i])){
			if(curr -> left == NULL){
				tmp -> parent = curr;
				curr -> left = tmp;
				curr = curr -> left;
			}
			else{
				tmp -> parent = curr;
				curr -> right = tmp;
				curr = curr -> right;
			}
			while(1){
				curr = curr -> parent;
				if(curr == *root || curr -> right == NULL){
					break;
				}
			}
		}
		else{
			if(curr -> left == NULL){
				tmp -> parent = curr;
				curr -> left = tmp;
				curr = curr -> left;
			}
			else{
				tmp -> parent = curr;
				curr -> right = tmp;
				curr = curr -> right;
			}
		}
	}
}

void printInfix(node* root)
{
	if(root == NULL)
		return;
	printInfix(root -> left);
	printf("%c",root -> data);
	printInfix(root -> right);
}

void printPrefix(node* root)
{
	if(root == NULL)
		return;
	printf("%c",root -> data);
	printPrefix(root -> left);
	printPrefix(root -> right);
}

void printPostfix(node* root)
{
	if(root == NULL)
		return;
	printPostfix(root -> left);
	printPostfix(root -> right);
	printf("%c",root -> data);
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
	node* root = NULL;
	char infix[105], option;
	while(1){
		printf("Choose Option: ");
		scanf(" %c",&option);
		if(option == 'a'){
			freeTree(root);
			printf("Input Expression: ");
			scanf(" %s",infix);
			toPrefix(infix);
			build(&root);
			//printInfix(root);
		}
		else if(option == 'b'){
			if(root == NULL){
				printf("No expression present\n");
				continue;
			}
			printf("Prefix Expression: ");
			printPrefix(root);
			printf("\n");
		}
		else if(option == 'c'){
			if(root == NULL){
				printf("No expression present\n");
				continue;
			}
			printf("Postfix Expression: ");
			printPostfix(root);
			printf("\n");
		}
		else{
			printf("Quitting\n");
			break;
		}
	}	
	freeTree(root);
	return 0;
}
