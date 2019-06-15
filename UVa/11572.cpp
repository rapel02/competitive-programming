#include<bits/stdc++.h>
using namespace std;

map<long long,int > mmap;

int arr[1500000];

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		for(int a=0;a<n;a++) scanf("%d",&arr[a]);
		int l = 0;
		int r = -1;
		int ans = 0;
		mmap.clear();
		while(l<n && r<n)
		{
			if(r < l)
			{
				r++;
				continue;
			}
			if(mmap[arr[r]]==0)
			{
				mmap[arr[r]]++;
				ans = max(ans,r-l+1);
				r++;
				continue;
			}
			if(mmap[arr[r]]!=0)
			{
				mmap[arr[l]]--;
				l++;
				continue;
			}
		}
		printf("%d\n",ans);
	}
}
