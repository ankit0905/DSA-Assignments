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

int strcmp_(char s1[], char s2[])
{
	int l1 = strlen_(s1), l2 = strlen_(s2);
	int i = 0;
	while(i<=l1 && i<=l2){
		if(s1[i]<s2[i])
			return -1;
		else if(s1[i]>s2[i])
			return 1;
		i++;
	}
	return 0;
}

int main()
{
	int i,x;
	scanf("%d",&x);
	char key[105];
	scanf(" %s",key);
	char str[x][105];
	for(i=0; i<x; i++){
		scanf(" %s",str[i]);
	}
	int lo = 0, hi = x-1, fl = 0;
	int min=1000000,max=-1;
	while(lo < hi){
		int mid = (lo+hi)/2;
		if(strcmp_(str[mid],key)==0){
			hi = mid;
			fl = 1;
			if(mid < min)
				min = mid;
		}
		else if(strcmp_(str[mid],key)==-1){
			lo = mid+1;
		}
		else{
			hi = mid-1;
		}
	}
	//printf("%d %d\n",lo,hi);
	if(fl == 0){
		printf("0\n");
		return 0;
	}
	lo = 0, hi = x-1;
	while(lo <= hi){
		int mid = (lo+hi)/2;
		if(strcmp_(str[mid],key)==0){
			lo = mid+1;
			if(mid > max)
				max = mid;
		}
		else if(strcmp_(str[mid],key)==-1){
			lo = mid+1;
		}
		else{
			hi = mid-1;
		}
	}
	printf("%d\n",max-min+1);
	return 0;
}
