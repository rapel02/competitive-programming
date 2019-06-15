#include<bits/stdc++.h>
using namespace std;

int arr[100005],brr[100005];

int main()
{
	int n,m;
	while(1)
	{
		scanf("%d %d",&n,&m);
		if((n|m)==0) break;
		for(int a=0;a<n;a++) scanf("%d",&arr[a]);
		for(int b=0;b<m;b++) scanf("%d",&brr[b]);
		sort(arr,arr+n);
		sort(brr,brr+m);
		int dg = 0;
		int wr = 0;
		int tot = 0;
		while(1)
		{
			if(dg==n) break;
			if(wr==m) break;
			if(arr[dg]<=brr[wr])
			{
				tot+=brr[wr];
				dg++;
			}
			wr++;
		}
		if(dg==n) printf("%d\n",tot);
		else printf("Loowater is doomed!\n");
	}
}
