#include <stdio.h>
#include <string.h>

int map[26][2] = {{2,1},{2,2},{2,3},{3,1},{3,2},{3,3},{4,1},{4,2},{4,3},{5,1},{5,2},{5,3},{6,1},{6,2},{6,3},{7,1},{7,2},{7,3},{7,4},{8,1},{8,2},{8,3},{9,1},{9,2},{9,3},{9,4}};

int main()
{
	char str[105], ans[305], i, j=0, k;
	scanf("%[^\n]",str);
	int len = strlen(str);
	for(i=0; i<len; i++){
		if(str[i] == ' '){
			ans[j++]='0';
		}
		int num = str[i]-97;
		if(i==0){
			for(k=0; k<map[num][1]; k++)
				ans[j++] = map[num][0]+48;
		}
		else{
			if(map[num][0] == map[str[i-1]-97][0])
				ans[j++]=' ';
			for(k=0; k<map[num][1]; k++)
				ans[j++] = map[num][0]+48;
		}
	}
	ans[j] = '\0';
	printf("%s\n",ans);
	return 0;
}
