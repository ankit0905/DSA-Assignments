#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prime[26];

int isprime(int n)
{
	if(n <= 1)
		return 0;
	else if(n == 2)
		return 1;
	else{
		int i;
		for(i=2; i*i<=n; i++){
			if(n%i == 0)
				return 0;
		}
		return 1;
	}
}

void init()
{
	int i = 2, ct = 0;
	while(ct != 26){
		if(isprime(i)){
			prime[ct] = i;
			ct++;
		}
		i++;
	}
}

long long int hash(char* word)
{
	long long int hash = 1;
	int len = strlen(word), i;
	for(i=0; i<len; i++){
		hash = hash * (long long int)prime[word[i]-97];
	}
	return hash;
}

int main()
{	
	
	return 0;
}
