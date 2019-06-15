#include<bits/stdc++.h>
using namespace std;

int mis[150000];
int arr[150000];

int main()
{
	int k = 0;
	bool first = true;
	while(1)
	{
		k++;
		int l = 0;
		int tot = 0;
		scanf("%d",&arr[l]);
		memset(mis,0,sizeof(mis));
		if(arr[0]==-1) break;
		if(first==false) printf("\n");
		first = false;
		mis[tot] = arr[0];
		tot++;
		while(1)
		{
			l++;
			scanf("%d",&arr[l]);
			if(arr[l]==-1) break;
			int lo = 0;
			int hi = tot-1;
			sort(mis,mis+tot);
			if(mis[lo]>arr[l])
			{
				mis[tot] = arr[l];
				tot++;
			}
			else
			{
				int rem = 0;
				while(lo<=hi)
				{
					int mid = (lo+hi)/2;
					if(mis[mid]<=arr[l])
					{
						rem = mid;
						lo = mid+1;
					}
					else hi = mid-1;
				}
				mis[rem] = arr[l];
			}
		}
		printf("Test #%d:\n",k);
		printf("  maximum possible interceptions: %d\n",tot);
	}
}
