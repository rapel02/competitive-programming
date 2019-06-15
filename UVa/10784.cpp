#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k = 0;
	while(1)
	{
		k++;
		long long w;
		scanf("%lld",&w);
		if(w==0) break;
		long long a = 0;
		long long lo = 3;
		long long hi = 100000000;
		while(lo<=hi)
		{
			long long mid = (lo+hi)/2;
			if(mid*(mid-1)/2 - mid >=w)
			{
				a = mid;
				hi = mid - 1;
			}
			else lo = mid+1;
		}
		printf("Case %d: %lld\n",k,a);
	}
}
