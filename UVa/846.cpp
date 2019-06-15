#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		long long a,b;
		scanf("%lld %lld",&a,&b);
		long long res1 = (b-a)/2;
		long long lo = 0;
		long long hi = 1<<18;
		long long ans = 0;
		while(lo<=hi)
		{
			long long mid = (lo+hi)/2;
			if(mid*(mid+1)/2<res1) lo = mid+1;
			else hi = mid-1,ans = mid; 
		}
		long long res2 = (b-a) - ans*(ans+1)/2;
		lo = 0;
		hi = 1<<18;
		long long ans2=0;
		while(lo<=hi)
		{
			long long mid = (lo+hi)/2;
			if(mid*(mid+1)/2<res2) lo = mid+1;
			else hi = mid-1,ans2 = mid; 
		}
		printf("%lld\n",ans+ans2);
	}
}
