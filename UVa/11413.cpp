#include<bits/stdc++.h>
using namespace std;

int arr[1000005];

int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		long long tot =  0;
		for(int a=0;a<n;a++)
		{
			scanf("%d",&arr[a]);
			tot+=arr[a];
		}
		long long lo = 0;
		long long hi = 2*tot;
		long long ans = 0;
		while(lo<=hi)
		{
			int cont = 1;
			long long mid = (lo+hi)/2;
			long long temp = 0;
			long long maxn = 0;
			for(int a=0;a<n;a++)
			{
				if(arr[a]+temp>mid)
				{
					cont++;
					maxn = max(maxn,temp);
					temp = arr[a];
				}
				else temp+=arr[a];
			}
			maxn = max(maxn,temp);
			if(cont>m)
			{
				lo=mid+1;
			}
			else 
			{
				hi = mid-1;
				ans = maxn;
			}//printf("%lld %lld %d\n",mid,maxn,cont);
		}
		printf("%lld\n",ans);
	}
}
