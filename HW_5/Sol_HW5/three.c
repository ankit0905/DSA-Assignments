#include <stdio.h>

int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n], ele, ct=0;
	for(i=0; i<n; i++){
		scanf("%d",&arr[i]);
		if(ct==0){
			ele = arr[i];
			ct = 1;
		}
		else{
			if(arr[i] == ele)
				ct++;
			else
				ct--;
		}
	}
	if(ct == 0){
		printf("None\n");
	}
	else{
		ct = 0;
		for(i=0; i<n; i++){
			if(arr[i] == ele)
				ct++;
		}
		if(ct > n/2)
			printf("%d\n",ele);
		else
			printf("None\n");
	}
	return 0;
}
