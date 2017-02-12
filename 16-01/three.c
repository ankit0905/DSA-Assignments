#include <stdio.h>
#include <string.h>

int fib[25],rand[25];

int find(int key)
{
	int i;
	for(i=0; i<25; i++){
		if(fib[i]==key)
			return i;
	}
}

void encrypt(char input[], int n, int k)
{
	int i;
	char output[n+1];
	for(i=0; i<n; i++){
		int idx = find(rand[i]);
		char ch = (((input[i]-97)+k)%26)+97;
		output[idx] = ch;
	}
	output[n]='\0';
	printf("%s\n",output);
}

int main()
{
	int i,n,k;
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d", &rand[i]);
	}
	fib[0] = 1;
	fib[1] = 2;
	for(i=2; i<n; i++){
		fib[i] = fib[i-1]+fib[i-2];
	}
	char message[25];
	scanf(" %s",message);
	scanf("%d", &k);
	encrypt(message, n, k);
	return 0;
}
