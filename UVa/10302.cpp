#include<bits/stdc++.h>
using namespace std;

long long pow(long long a)
{
	return a*a;
}

int main()
{
	long long n;
	while(scanf("%lld",&n)!=EOF)
	{
		printf("%lld\n",pow(n*(n+1)/2));
	}
}
