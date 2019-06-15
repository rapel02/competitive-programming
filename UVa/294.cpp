#include<bits/stdc++.h>
using namespace std;

int num[100005];
int prime[100005];
int k = 0;

void cprime()
{
	for(long long a=2;a<=100000;a++)
	{
		if(num[a]==0)
		{
			for(long long b=a*a;b<=100000;b+=a) num[b] = a;
			prime[k++] = a;
		}
	}
}

int main()
{
	cprime();
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		long long l,r;
		scanf("%lld %lld",&l,&r);
		long long rem = 0 ;
		long long tot = 0;
		for(long long a=l;a<=r;a++)
		{
			long long c = a;
			long long ans = 1;
			for(int b=0;b<k;b++)
			{
				if(c==1) break;
				long long tot = 1;
				if(c%prime[b]==0)
				{
					while(c%prime[b]==0)
					{
						c/=prime[b];
						tot++;
					}
					ans = ans*tot;
				}
			}
			if(c!=1) ans = ans*2;
			if(ans>tot)
			{
				tot = ans;
				rem = a;
			}
		}
		printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",l,r,rem,tot);
	}
}
