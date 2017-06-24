#include <stdio.h>
#include <string.h>

int main(){
	char s[100];
	scanf("%s",s);
	char w[100][100];
	char subs[1000][1000];
	int n,i,j;
	scanf("%d",&n);
	int tot_len=0;
	for (i=0;i<n;i++){
		scanf("%s",w[i]);
		tot_len+=strlen(w[i]);
	}
	for (i=0;i<=strlen(s)-tot_len;i++){
		for (j=0;j<tot_len;j++){
			subs[i][j]=s[j+i];
		}
	}
	for (i=0;i<=strlen(s)-tot_len;i++){
		int flag=0;
		char tempw[100];
		for (j=0;j<strlen(subs[i]);j++){
			tempw[j]=subs[i][j];
		}
		for (j=0;j<n;j++){
			if (strstr(tempw,w[j])!=NULL){
				char* start = strstr(tempw,w[j]);
				int l = strlen(w[j]);
				while(l){
					*start='*';
					start++;
					l--;
				}
			}
			else{
				flag=1;
				break;
			}
		}
		if (flag==0){
			printf("%d %d %s\n", i, i+tot_len-1, subs[i]);
		}
	}
}
