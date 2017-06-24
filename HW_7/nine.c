#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
	int top, size;
	int* array;
}stack;

int prec(char ch)
{
	if(ch == '+' || ch == '-')
		return 1;
	else if(ch == '*' || ch == '/')
		return 2;
	else if(ch == '^')
		return 3;
	else
		return -1;
}

void push(stack* st, char ch)
{
	st->array[++st->top] = ch; 
}

char pop(stack* st)
{
	if(st->top >= 0)
		return st->array[st->top--];
	else
		return '$';
}

int isDigit(char ch)
{
	return (ch >= '0' && ch <= '9');
}

int isEmpty(stack* st)
{
    return st->top == -1;
}

int main()
{
	char infix[100], postfix[100];
	scanf("%s",infix);
	int len = strlen(infix), i, k=0;
	stack* st = (stack*)malloc(sizeof(stack));
	st -> top = -1;
	st -> size = 50;
	st -> array = (int*)malloc(len * sizeof(int));	
	for(i=0; i<len; i++){
		if(isDigit(infix[i]))
			postfix[k++] = infix[i];
		else if(infix[i] == '(')
			push(st, infix[i]);
		else if(infix[i] == ')'){
			while(!isEmpty(st) && st->array[st->top]!='(')
				postfix[k++] = pop(st);
			pop(st);
		}
		else{
			while(!isEmpty(st) && prec(infix[i]) <= prec(st->array[st->top]))
				postfix[k++] = pop(st);
			push(st, infix[i]);
		}
	}
	while(!isEmpty(st))
		postfix[k++] = pop(st);
	postfix[k] = '\0';
	printf("%s\n",postfix);
	len = k;
	st -> top = -1;
	for(i=0; i<k; i++){
		if(isDigit(postfix[i]))
			push(st, postfix[i]-'0');
		else{
			int val1 = pop(st);
			int val2 = pop(st);
			if(postfix[i] == '+')
				push(st, val2+val1);
			else if(postfix[i] == '-')
				push(st, val2-val1);
			else if(postfix[i] == '*')
				push(st, val2*val1);
			else if(postfix[i] == '/')
				push(st, val2/val1);
		}
	}
	printf("%d\n",pop(st));
	free(st -> array);
	free(st);
	return 0;
}
