#include<bits/stdc++.h>
using namespace std;

int prime[1000005];
int num[1000005];
int k = 0 ;

void cprime()
{
	num[1] = 1;
	num[0] = 1;
	for(long long a=2;a<=1000000;a++)
	{
		if(num[a]==0)
		{
			prime[k++]  = a;
			for(long long b = a*a ;b<=1000000;b+=a) num[b] = a;
		}
	}
}

int main()
{
	cprime();
	int n;
	while(scanf("%d",&n),n)
	{
		int tot = 0;
		bool ans = false;
		for(int a=0;prime[a]<=n/2&&a<k;a++)
		{
			if(prime[a]%2==0) continue;
			if( num[n - prime[a]] ==0)
			{
				ans = true;
				printf("%d = %d + %d\n",n,prime[a],n-prime[a]);
				break;
			}
		}
		if(ans==false) printf("Goldbach's conjecture is wrong.\n");
	}
}
