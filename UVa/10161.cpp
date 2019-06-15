#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	while(scanf("%lld",&n),n)
	{
		long long num = sqrt(n);
		if(num*num!=n) num++;
		long long res = num*num - n;
		long long r = num, c = 1;
		if(num%2==1)
		{
			swap(r,c);
			r+= min(num-1,res);
			res= res-num+1;
			c-= max(0LL,res);
		}
		else
		{
		 	c+= min(num-1,res);
		 	res = res-num+1;
		 	r-= max(0LL,res);
		}
		 printf("%lld %lld\n",r,c);
	}
}
