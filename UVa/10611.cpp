#include <bits/stdc++.h>
using namespace std;

int arr[50005];

int main()
{
	int n;
	scanf("%d",&n);
	for(int a=0;a<n;a++)
	{
		scanf("%d",&arr[a]);
	}
	int q;
	scanf("%d",&q);
	for(int a=0;a<q;a++)
	{
		int tar;
		scanf("%d",&tar);
		int lo = 0;
		int hi = n-1;
		int loo = n-1;
		int hii = n;
		while(lo<=hi)
		{
			int mid = (lo+hi)/2;
			//printf("%d %d\n",mid,tar);
			if(arr[mid]>tar)
			{
				hii = mid;
				hi = mid-1;
				//printf("%d %d\n",loo,hii);
			}
			else if(arr[mid]<tar)
			{
				lo = mid+1;
				loo = mid;
			}
			else
			{
				loo=mid;
				hii=mid;
				break;
			}
		}
		while(loo>=0 && arr[loo]==tar) loo--;
		while(hii<n && arr[hii] == tar) hii++;
		if(loo!=-1) printf("%d",arr[loo]);
		else printf("X");
		printf(" ");
		if(hii!=n) printf("%d",arr[hii]);
		else printf("X");
		printf("\n");
	}
}
