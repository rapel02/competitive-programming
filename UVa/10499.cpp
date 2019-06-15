#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	while(1)
	{
		scanf("%lld",&n);
		long long ans;
		if(n<0) break;
		if(n>1) ans = 50 + (n-2)*25;
		else ans=0;
		printf("%lld%%\n",ans);
	}
}
