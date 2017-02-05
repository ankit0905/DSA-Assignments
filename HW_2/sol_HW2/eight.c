#include <stdio.h>
#include <string.h>

int main()
{
	FILE *file;
	char code[1005], res[1005];
	file = fopen("input.txt", "r");
	char ch;
	int idx = 0;
	while(1){
		ch = (char)fgetc(file); 
		if(ch == EOF)
			break;
		code[idx++] = ch;
	}
	code[idx] = '\0';
	int len = strlen(code);
	int i, j = 0, fl1 = 0, fl2 = 0;
	for(i=0; i<len; i++){
		if(fl2 == 1 && code[i] == '\n'){
			fl2 = 0;
		}
		if(code[i]=='/' && code[i+1]=='*'){
			fl1 = 1;
			continue;
		} 
		else if(code[i]=='*' && code[i+1]=='/'){
			fl1 = 0;
			if(code[i+2]=='\n'){
				i+=2;
			}
			else{
				i++;
			}
			continue;
		}
		if(code[i]=='/' && code[i+1]=='/'){
			fl2 = 1;
		}
		if(fl1 == 0 && fl2 == 0){
			res[j++] = code[i];
		}
	}
	res[j]='\0';
	printf("%s",res);
	return 0;
}
