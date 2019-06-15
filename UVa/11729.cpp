#include<bits/stdc++.h>
using namespace std;

struct time{
	long long b;
	long long j;
}arr[1005];

bool cmp(struct time a,struct time b)
{
	return a.j>b.j;
}

int main()
{
	int n;
	int k = 0;
	while(1)
	{
		k++;
		scanf("%d",&n);
		if(n==0) break;
		for(int a=0;a<n;a++)
		{
			int a1,a2;
			scanf("%d %d",&a1,&a2);
			arr[a].b = a1;
			arr[a].j = a2;
		}
		sort(arr,arr+n,cmp);
		long long ans = 0;
		long long t_now = 0;
		for(int a=0;a<n;a++)
		{
			ans = max(ans,t_now+arr[a].b+arr[a].j);
			t_now+=arr[a].b;
		}
		printf("Case %d: %lld\n",k,ans);
	}
}
