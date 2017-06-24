#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	int fl[256]={0}, i;
	scanf("%s",str);
	int len = strlen(str);
	for(i=0; i<len; i++){
		if(fl[str[i]]==0){
			printf("%c",str[i]);
			fl[str[i]]=1;
		}
	}
	printf("\n");
	return 0;
}
