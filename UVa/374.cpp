#include<bits/stdc++.h>
using namespace std;

long long mulmod(long long a,long long b,long long mod)
{
	long long c = a;
	long long ans = 0;
	while(b!=0)
	{
		if(b%2==1) ans = (ans + c) % mod;
		c = (c + c) % mod;
		b/=2;
	}
	return ans;
}

long long fast(long long a,long long b,long long mod)
{
	long long c = a;
	long long ans = 1;
	while(b!=0)
	{
		if(b%2==1) ans = mulmod(ans,c,mod);
		c = mulmod(c,c,mod);
		b/=2;
	}
	return ans;
}

int main()
{
	long long b,p,mod;
	while(scanf("%lld %lld %lld",&b,&p,&mod)!=EOF)
	{
		printf("%lld\n",fast(b,p,mod));
	}
}
