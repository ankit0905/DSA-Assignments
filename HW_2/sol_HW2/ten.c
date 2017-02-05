#include <stdio.h>

int strlen_(char* str)
{
	int len = 0;
	while(*str){
		*str++;
		len++;
	}
	return len;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		char number[1005];
		scanf("%s", number);
		int len = strlen_(number);
		int lo = 0, hi = len-1, fl = 0, st1, st2;
		while(lo<hi){
			if(number[lo] != number[hi]){
				if(number[hi] < number[lo])
					fl = 1;
				else
					fl = 0;
				number[hi] = number[lo];
			}
			lo++;
			hi--;
		}
		if(fl == 1){
			printf("%s\n",number);
			return 0;
		}
		if(len%2==1){
			st1 = st2 = len/2;
		}
		else{
			st2 = len/2;
			st1 = st2-1;
		}
		fl = 0;
		while(st1 >= 0){
			if(number[st1]=='9'){
				number[st1]=number[st2]='0';
				st1--;
				st2++;
			}
			else{
				if(st1 == st2)
					number[st1]++;
				else{
					number[st1]++;
					number[st2]++;
				}
				fl = 1;
				break;
			}
		}
		if(fl == 1)
			printf("%s\n",number);
		else{
			number[len-1]='\0';
			printf("1");
			printf("%s",number);
			printf("1\n");
		}
	}
	return 0;
}
