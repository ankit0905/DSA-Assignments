#include <stdio.h>
#include <math.h>
//#include <time.h>

int isprime(int n)
{
	if(n<=1)
		return 0;
	else if(n==2)
		return 1;
	else{
		int i, max = sqrt(n);
		for(i=2; i<=max; i++){
			if(n%i==0)
				return 0;
		}
		return 1;
	}
}

int main()
{
	//clock_t begin = clock();
	int n;
	scanf("%d",&n);
	int max = sqrt(n), i, ans = 0;
	for(i=2; i<=max; i++){
		if(n%i==0 && isprime(i)){
			int fact1 = i;
			int fact2 = n/i;
			while(n%fact1==0){
				n=n/fact1;
				ans++;
			}
			if(fact1!=fact2 && isprime(fact2)){
				while(n%fact2==0){
					n=n/fact2;
					ans++;
				}
			}
		}
	}
	printf("%d\n",ans);
	//clock_t end = clock();
	//double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
	//printf("Execution time : %lf\n", time_spent);
	return 0;
}
