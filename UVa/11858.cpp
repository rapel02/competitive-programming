#include<bits/stdc++.h>
using namespace std;


int arr[1000005],bit[1000005];
pair<int,int> temp[1000005];
void update(int val,int tot)
{
	for(int a=val;a<=1000000;a+=a&(-a))
	{
		bit[a]+=tot;
	}
}

int query(int val)
{
	int tot =0 ;
	for(int a=val;a>0;a-=a&(-a))
		tot+=bit[a];
	return tot;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(bit,0,sizeof(bit));
		for(int a=0;a<n;a++)
		{
			scanf("%d",&arr[a]);
			arr[a]++;
			temp[a] = make_pair(arr[a],a);
		}
		sort(temp,temp+n);
		for(int a=0;a<n;a++)
		{
			arr[temp[a].second] = a+1;
		}
		for(int a=0;a<n;a++)
			update(arr[a],1);
		long long ans = 0;
		for(int a=0;a<n;a++)
		{
			ans += query(arr[a]-1);
			//printf("%d\n",a);
			update(arr[a],-1);
		}
		printf("%lld\n",ans);
	}
}
