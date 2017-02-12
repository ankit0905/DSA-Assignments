#include <stdio.h>
#include <string.h>

typedef struct{
	char name[100];
	int id;
	int sal;
}emp;

int main()
{
	int n,i,j;
	scanf("%d",&n);
	emp list[n];
	int max = 0;
	char* ans;
	for(i=0; i<n; i++){
		scanf(" %s %d %d",list[i].name, &list[i].id, &list[i].sal);
	}
	for(i=0; i<n; i++){
		int ct = 0;
		for(j=0; j<n; j++){
			if(strcmp(list[i].name,list[j].name)==0){
				ct++;
			}
		}
		if(ct>max){
			ans = list[i].name;
			max = ct;
		}
	}
	printf("%s %d\n",ans,max);
	return 0;
}
