#include<bits/stdc++.h>
using namespace std;

map<long long,int> mmap;

int arr[20005];

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		mmap.clear();
		memset(arr,0,sizeof(arr));
		int n,m;
		scanf("%d %d",&n,&m);
		int k =1;
		long long w;
		for(int a=0;a<n;a++)
		{
			scanf("%lld",&w);
			if(mmap[w]==0)
			{
				mmap[w] = k;
				k++;
			}
			arr[mmap[w]]++;
		}
		for(int a=0;a<m;a++)
		{
			scanf("%lld",&w);
			if(mmap[w]==0)
			{
				mmap[w] = k;
				k++;
			}
			arr[mmap[w]]--;
		}
		int tot = 0;
		for(int a=1;a<k;a++)
		{
			tot+=abs(arr[a]);
		}
		printf("%d\n",tot);
	}
}
