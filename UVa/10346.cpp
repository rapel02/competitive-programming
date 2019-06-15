#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,k;
	while(scanf("%lld %lld",&n,&k)!=EOF)
	{
		long long tot = n;
		while(n>=k)
		{
			tot+=n/k;
			n = n/k + n%k;
		}
		printf("%lld\n",tot);
	}
	
}
