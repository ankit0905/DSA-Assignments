#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, fl;
char dict[105][105];
char ans[105];

void longestPrefix(char* str)
{
	int i,j,len = strlen(str), l, max = 0, ct;
	char ch;
	fl = 0;
	for(i=0; i<n; i++){
		ct = 0;
		l = strlen(dict[i]);
		for(j=0; j<l && j<len; j++){
			if(dict[i][j] != str[j])
				break;
			else
				ct++;
		}
		ch = dict[i][j];
		if(ct > max){
			max = ct;
			dict[i][j] = 0;
			strcpy(ans, dict[i]);
			dict[i][j] = ch;
			fl = 1;
		}
	}
}

int main()
{
	int i,j;
	scanf("%d",&n);
	char tmp[105];
	for(i=0; i<n; i++){
		scanf(" %s",dict[i]);
	}
	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			if(strcmp(dict[i], dict[j]) > 0){
				strcpy(tmp, dict[i]);
				strcpy(dict[i], dict[j]);
				strcpy(dict[j], tmp);
			}
		}
	}
	char str[105];
	scanf(" %s",str);
	longestPrefix(str);
	if(fl == 1)
		printf("%s\n",ans);
	return 0;
}
