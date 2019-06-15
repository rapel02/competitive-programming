#pragma G++ optimize("O3")
#include<bits/stdc++.h>
#define MOD 10000000000000007
using namespace std;

inline unsigned long long int multi(unsigned long long int a,unsigned long long int b)
{
	unsigned long long int c = a;
	unsigned long long int ans = 0;
	while(b!=0)
	{
		if(b%2==1) ans = (ans + c) %MOD;
		c = (c*2) %MOD;
		b/=2;
	}	
	return ans;
}

inline unsigned long long int fast(unsigned long long int a,unsigned long long int b)
{
	unsigned long long int c = a;
	unsigned long long int ans = 1;
	while(b!=0)
	{
		if(b%2==1) ans = multi(ans,c)%MOD;
		c=multi(c,c)%MOD;
		b/=2;
	}
	return ans;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		unsigned long long int r,c,rr,cc;
		scanf("%llu %llu",&r,&c);
		rr = (r*c)/2;
		cc = (r*c) - rr;
		r = rr;
		c = cc;
		printf("%llu\n",multi(fast(r,c-1)%MOD,(fast(c,r-1)%MOD))%MOD);
	}
}
