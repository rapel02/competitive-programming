#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	scanf("%d",&tc);
	long long n,m;
	while(tc--)
	{
		scanf("%lld %lld",&n,&m);
		if(n-1>=m) printf("%d\n",m);
		else
		{
			int lo = 3;
			int hi = n;
			int ans = 0;
			while(lo<=hi)
			{
				int mid = (lo+hi)/2;
				long long temp = mid;
				temp = temp * (mid-1)/2;
				//printf("%lld %d\n",temp,mid);
				if(temp + n-mid >=m)
				{
					hi = mid-1;
					ans = n-mid;
				}
				else lo = mid+1;
			}
			printf("%d\n",ans);
		}
	}
}
