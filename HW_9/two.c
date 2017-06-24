#include <stdio.h>
#include <string.h>

int main()
{
	int fl[26] = {0};
	char str[100];
	scanf("%s",str);
	int len = strlen(str), i, ct=0, ans = 0, idx, j;
	for(i=0; i<len; i++){
		if(fl[str[i]-97]==0){
			fl[str[i]-97]=1;
			ct++;
		}
		else{
			if(ct > ans){
				ans = ct;
				idx = i-ct;
			}
			for(j=0; j<26; j++)
				fl[j] = 0;
			ct = 1;
			fl[str[j]-97]=1;
		}
	}
	if(ct > ans){
		ans = ct;
		idx = i-ct;
	}
	printf("%d\n",ans);
	for(i=idx; i<idx+ans; i++){
		printf("%c",str[i]);
	}
	printf("\n");
	return 0;
}
