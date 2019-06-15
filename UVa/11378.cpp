#include<bits/stdc++.h>
#define ff first
#define mp make_pair
#define ss second
using namespace std;

int ans = 10000000;

pair<int,int> p[150000];

int diff(int a,int b,int k)
{
	if(k==0) return abs(p[a].ff-p[b].ff);
	else return abs(p[a].ss - p[b].ss);
}

void precom(int l,int r)
{
	if(l + 2 >=r)
	{
		for(int a=l;a<=r;a++)
		{
			for(int b=a+1;b<=r;b++)
			{
				ans = min(ans,max(diff(a,b,0),diff(a,b,1)));
			}
		}
		return ;
	}
	int mid = (l+r)/2;
	precom(l,mid);
	precom(mid+1,r);
	int id = mid;
	int k = mid+1;
	while(diff(id,k,0) < ans || diff(id,k,1) < ans)
	{
		ans = min(ans,max(diff(id,k,0),diff(id,k,1)));
		k++;
	}
	id = mid + 1;
	k = mid;
	while(diff(id,k,0) < ans || diff(id,k,1) < ans)
	{
		ans = min(ans,max(diff(id,k,0),diff(id,k,1)));
		k--;
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		ans = 10000000;
		for(int a=0;a<n;a++) scanf("%d %d",&p[a].ff,&p[a].ss);
		sort(p,p+n);
		precom(0,n-1);
		printf("%d\n",ans);
	}
}
