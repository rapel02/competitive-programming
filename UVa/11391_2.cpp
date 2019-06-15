#include<bits/stdc++.h>
using namespace std;

long long dp[1<<17];

int r,c,n;

bool check(int bit)
{
	int k = 0;
	while(bit!=0)
	{
		if(bit%2==1) k++;
		bit/=2;
	}
	return (k==1);
}

long long compute(int bit)
{
	if(check(bit)==true) return 1;
	if(dp[bit]!=-1) return dp[bit];
	dp[bit] = 0;
	for(int a=0;a<r*c;a++)
	{
		if((bit & (1<<a))!=0)
		{
			int yy = a/c;
			int xx = a%c;
			if(yy>1 && (bit & (1<<((yy-1) *c  + xx)))!=0 && (bit & (1<<((yy-2) *c  + xx)) )==0)
			{
				int nbit = (bit ^ (1<<a) ^ ((1<<((yy-1) *c  + xx))) ^(1<<((yy-2) *c  + xx)));
				dp[bit] += compute(nbit);
			}
			if(xx>1 && (bit & (1<<(yy*c  + xx-1)))!=0 && (bit & (1<<(yy *c  + xx-2)) )==0)
			{
				int nbit = (bit ^ (1<<a) ^(1<<(yy*c + xx-1)) + (1<<(yy*c + xx-2)));
				dp[bit] += compute(nbit);
			}
			if(yy<r-2 && (bit & (1<<((yy+1) *c  + xx)))!=0 && (bit & (1<<((yy+2) *c  + xx) ) )==0)
			{
				int nbit = (bit ^ (1<<a) ^ ((1<<((yy+1) *c  + xx))) ^(1<<((yy+2) *c  + xx)));
				dp[bit] += compute(nbit);
			}
			if(xx<c-2 && (bit & (1<<(yy*c  + xx+1)))!=0 && (bit & (1<<(yy *c  + xx+2)) )==0)
			{
				int nbit = (bit ^ (1<<a) ^(1<<(yy*c + xx+1)) + (1<<(yy*c + xx+2)));
				dp[bit] += compute(nbit);
			}
			if(yy>1 && xx>1 && (bit & (1<<((yy-1) *c  + xx-1)))!=0 && (bit & (1<<((yy-2) *c  + xx-2)) )==0)
			{
				int nbit = (bit ^ (1<<a) ^ ((1<<((yy-1) *c  + xx-1))) ^(1<<((yy-2) *c  + xx-2)));
				dp[bit] += compute(nbit);
			}
			if(yy>1 && xx<c-2 && (bit & (1<<((yy-1) *c  + xx+1)))!=0 && (bit & (1<<((yy-2) *c  + xx+2)) )==0)
			{
				int nbit = (bit ^ (1<<a) ^ ((1<<((yy-1) *c  + xx+1))) ^(1<<((yy-2) *c  + xx+2)));
				dp[bit] += compute(nbit);
			}
			if(yy<r-2 && xx>1 && (bit & (1<<((yy+1) *c  + xx-1)))!=0 && (bit & (1<<((yy+2) *c  + xx-2) ))==0)
			{
				int nbit = (bit ^ (1<<a) ^ ((1<<((yy+1) *c  + xx-1))) ^(1<<((yy+2) *c  + xx-2)));
				dp[bit] += compute(nbit);
			}
			if(yy<r-2 && xx<c-2 && (bit & (1<<((yy+1) *c  + xx+1)))!=0 && (bit & (1<<((yy+2) *c  + xx+2) ))==0)
			{
				int nbit = (bit ^ (1<<a) ^ ((1<<((yy+1) *c  + xx+1))) ^(1<<((yy+2) *c  + xx+2)));
				dp[bit] += compute(nbit);
			}
		}
	}
	return dp[bit];
}

int main()
{
	for(r=1;r<=4;r++)
	{
		for(c=1;c<=4;c++)
		for(int tc=0;tc<(1<<(r*c));tc++)
		{
			memset(dp,-1,sizeof(dp));
			printf("dp[%d][%d][%d] = %lld;\n",r,c,tc,compute(tc));
		}
	}
}
