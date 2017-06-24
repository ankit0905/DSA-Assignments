#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[n], w[n], fl1[n], fl2[n], ct = 0;
	for(int i=0; i<n; i++){
		scanf("%d%d",&a[i],&w[i]);
		fl1[i] = fl2[i] = 0;
	}
	for(int i=0; i<n; i++){
		int ele = a[i];
		for(int j=0; j<n; j++){
			if(ele == w[j] && i<=j && fl1[i]==0 && fl2[j]==0){
				fl1[i] = fl2[j] = 1;
				//printf("%d %d => %d\n",i,j,a[i]);
			}
		}
	}
	for(int i=0; i<n; i++){
		int ele = w[i];
		if(fl2[i] == 1)
			continue;
		for(int j=0; j<n; j++){
			if(fl1[j] == 0 && fl2[i] == 0){
				ct++;
				fl1[j] = 1;
				fl2[i] = 1;
			}
		}		
	}
	printf("%d\n",ct);
	return 0;
}
