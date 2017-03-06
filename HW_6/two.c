#include <stdio.h>

#define ll long long

ll n,m;
ll sum=0;
ll nop[104];

ll check(ll mid){
	ll pars=0;
	int i;
	for( i=0;i<n;i++){
		if(nop[i]>mid){
			pars+=mid;
		}
		else{
			pars+=nop[i];
		}
	}
	if(pars >= mid*m)
		return 1;
	else
		return 0;
}

int main()
{
	int i;
	scanf("%lld %lld",&n,&m);
	for(i = 0; i < n; i++){
		scanf("%lld",&nop[i]);
		sum+=nop[i];
	}
	ll l=0;
	ll r=100000000004;
	ll t=5;
	while(l<r){
		ll mid= (l+r)/2;
		if(check(mid)==1) {l=mid;}
		else
			r=mid-1;
	}
	printf("%lld\n",l);
	return 0;
}
