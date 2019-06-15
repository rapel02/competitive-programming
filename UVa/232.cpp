#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long nm;
	while(1)
	{
		scanf("%lld",&nm);
		if(nm<0) break;
		long long ans = 0;
		ans = 2 + (nm-1) * 2 ;
		if(nm%2==1) ans += (nm-1)/2 * (nm-2);
		else ans += (nm-2)/2 * (nm-1);
		printf("%lld\n",ans);
	}
}
