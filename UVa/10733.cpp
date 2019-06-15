#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0) break;
		long long ans = (n*n*n*n*n*n + 3*n*n*n*n + 12*n*n*n + 8*n*n)/24;
		printf("%lld\n",ans);
	}
}
