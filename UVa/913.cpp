#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	while(scanf("%lld",&n)!=EOF)
	{
		long long k = (n+1)/2;
		long long w = 1 + (k-1) * 6 + (k-1)*(k-2) *2;
		printf("%lld\n",3*w - 6);
	}
}
