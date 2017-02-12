#include <stdio.h>
#include <string.h>
#include <math.h>

char str[105];

void solve()
{
	int i,j,len = strlen(str);
	double root = sqrt((double)len);
	if(root != (int)root){
		printf("NO\n");
		return;
	}
	int sz = (int)root;
	char arr[sz+1][sz+1];
	int r=0,c=0,idx=0;
	while(r<sz){
		arr[r][c]=str[idx];
		idx++;
		if(c==sz-1){
			c=0;
			r++;
		}
		else{
			c++;
		}
	}
	char str1[len+1], str2[len+1], str3[len+1];
	r=c=idx=0;
	while(c<sz){
		str1[idx]=arr[r][c];
		idx++;
		if(r==sz-1){
			r=0;
			c++;
		}
		else{
			r++;
		}
	}
	str1[idx]='\0';
	idx = 0;
	r=c=sz-1;
	while(r>=0){
		str2[idx]=arr[r][c];
		idx++;
		if(c==0){
			r--;
			c=sz-1;
		}
		else{
			c--;
		}
	}
	str2[idx]='\0';
	idx = 0;
	r=c=sz-1;
	while(c>=0){
		str3[idx]=arr[r][c];
		idx++;
		if(r==0){
			c--;;
			r=sz-1;
		}
		else{
			r--;
		}
	}
	str3[idx]='\0';
	if(strcmp(str,str1)==0 && strcmp(str,str2)==0 && strcmp(str,str3)==0){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}

int main()
{
	int n,i;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%s", str);
		solve();
	}
	return 0;
}
