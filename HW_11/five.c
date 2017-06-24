#include <stdio.h>

int power(int x, int y)
{
	int res = 1;
	while(y > 0){
		if (y % 2 == 1)
            res = res*x;
        y = y/2; 
        x = x*x;  
	}
	return res;
}

int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	printf("%d\n",power(x,y));
	return 0;
}
