#include <stdio.h>
#include <math.h>
#include <string.h>

int res[15]={0};

void init()
{
	int i;
	res[0] = 0;
	for(i=1; i<=12; i++){
		res[i] = res[i-1]+(int)pow(3,i);
	}
}

int check(char num[], int len)
{
	int i;
	for(i=0; i<len; i++){
		int digit = num[i]-48;
		if(digit!=1 && digit!=7 && digit!=9)
			return 0;
	}
	return 1;
}

int main()
{	
	init();
	char number[15];
	scanf("%s",number);
	int i,len = strlen(number);
	int fl = check(number,len);
	long long int ans = res[len-1];
	for(i=0; i<len; i++){
		int digit = number[i]-48;
		if(digit == 7){
			ans += (int)pow(3,len-i-1);
		}
		else if(digit == 9){
			ans += (2*(int)pow(3,len-i-1));
		}
	}
	if(fl)
		ans++;
	printf("%lld\n",ans);
	return 0;
}
