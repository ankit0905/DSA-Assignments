#include <stdio.h>

int main()
{
	FILE* fp = fopen("input.txt","r");
	char inp[505], ch;
	int idx = 0, nl = 0, nw = 0, nc = 0, state = 0;
	while((ch=(char)getc(fp)) != EOF){
		nc++;
		if(ch == '\n')
			nl++;
		if(ch == ' ' || ch == '\n' || ch == '\t')
			state = 0;
		else if(state == 0){
			state = 1;
			nw++;
		}
	}
	printf("Number of Lines: %d\n",nl);
	printf("Number of Words: %d\n",nw);
	printf("Number of Characters: %d\n",nc);
	return 0;
}
