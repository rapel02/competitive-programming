#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long r = 1;
	long long c = 1;
	long long n;
	while(scanf("%lld",&n)==1)
	{
		c = 1;
		r = 1;
		if(n<1 || n>10000000) continue;
		while(r*(r+1)/2 <n)  r++;
		long long rem = r;
		long long res = r*(r+1)/2 - n;
			r-=res;
			c+=res;
			if(rem%2==1) swap(r,c);
		printf("TERM %lld IS %lld/%lld\n",n,r,c);
	}
}
