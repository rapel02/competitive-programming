#include<bits/stdc++.h>
using namespace std;

int arr[10005];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		long long tot = 0;
		for(int a=0;a<n;a++)
		{
			scanf("%d",&arr[a]);
			tot+=arr[a];
		}
		if(tot%n!=0) printf("-1\n");
		else
		{
			long long ma = 0;
			for(int a=0;a<n;a++)
			{
				if(arr[a]>tot/n) ma+=(arr[a]-tot/n);
			}
			printf("%lld\n",ma+1);
		}
	}
}
