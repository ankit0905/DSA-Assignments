#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	char str[200];
	printf("enter the string: ");
	scanf("%s",str);
	int l=strlen(str);
	int i=0,j=l-1;
	int flag1,flag2,k;
	while(i<l)
	{
		int ex=1;
		flag1=i,flag2=i;
		k=i;
		while(i<=j && (ex==1 || k<j))
		{	
			if(k<j || ex==0)
			{
				if(str[k]==str[j] && ex==1)
				{
					flag1=i;
					flag2=j;
					k++;
					j--;
					ex=0;
				}	
				else if(str[k]==str[j] && ex==0)
				{
					k++;
					j--;
				}
				else
				{
					ex=1;
					j--;
				}
			}
			else
			{
				if(str[i]==str[j] && ex==1)
				{
					flag1=i;
					flag2=j;
					ex=0;
				}
				else if(str[i]==str[j] && ex==0)
				{
					j--;
				}
				else
				{
					ex=1;
					j--;
				}
			}
		}
		for(i=flag1;i<=flag2;i++)
		{
			printf("%c",str[i]);
		}
		printf(" ");
		i=flag2+1;
		j=l-1;
	}
	printf("\n");
	return 0;
}
