#include<bits/stdc++.h>
using namespace std;

struct time{
	long long b;
	long long j;
}arr[1005];

bool cmp(struct time a,struct time b)
{
	if(a.j>b.j) return true;
	else if(a.j==b.j) return a.b>b.b;
	return false;
}

int main()
{
	int n;
	int k = 0;
	while(scanf("%d",&n)!=EOF)
	{
		k++;
		for(int a=0;a<n;a++)
			scanf("%d",&arr[a].b);
		for(int a=0;a<n;a++)
			scanf("%d",&arr[a].j);
		sort(arr,arr+n,cmp);
		long long ans = 0;
		long long t_now = 0;
		for(int a=0;a<n;a++)
		{
			t_now+=arr[a].b;
			ans = max(ans,t_now)+arr[a].j;
		}
		printf("%lld\n",ans);
	}
}
