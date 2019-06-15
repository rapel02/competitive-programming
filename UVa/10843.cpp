#include<bits/stdc++.h>
#define MOD 2000000011
using namespace std;


long long Multiply(long long a,long long b)
{
	long long ans = 0;
	long long c = a;
	while(b!=0)
	{
		if(b%2==1)
		{
			ans = (ans + c) % MOD;
		}
		c = 2*c %MOD;
		b/=2;
	}
	return ans;
}

long long compute(long long a,long long b)
{
	if(a==1) return 1;
	long long c = a;
	long long ans = 1;
	while(b!=0)
	{
		if(b%2==1) ans = Multiply(ans,c)%MOD;
		c = Multiply(c,c)%MOD;
		b/=2;
	}
	return ans %MOD;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	for(int a=1;a<=tc;a++)
	{
		int n;
		scanf("%d",&n);
		printf("Case #%d: %lld\n",a,compute(n,n-2)%MOD);
	}
}
