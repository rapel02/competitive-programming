#include<bits/stdc++.h>
using namespace std;

int arr[100005];

int main()
{
	int n,s;
	while(scanf("%d %d",&n,&s)!=EOF)
	{
		for(int a=0;a<n;a++) scanf("%d",&arr[a]);
		int lo = 0;
		int hi = 0;
		int tot = arr[0];
		int ans = 100005;
		while(lo<n)
		{
			//if(hi==n) break;
			if(hi==n-1)
			{
				if(tot<s)
				{
					break;
				}
				else if(tot>=s)
				{
					ans = min(ans,hi-lo+1);
					tot -= arr[lo];
					lo++;
					//printf("ere\n");
				}
			}
			else if(hi<lo) hi++;
			else if(tot<s)
			{
				hi++;
				tot+=arr[hi];
			}
			else if(tot>=s)
			{
				ans = min(ans,hi-lo+1);
				tot -= arr[lo];
				lo++;
			}
			//printf("%d %d %d\n",lo,hi,tot);
		}
		printf("%d\n",ans);
	}
}
