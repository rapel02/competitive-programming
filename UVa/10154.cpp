#include<bits/stdc++.h>
#define inf 1e+9
using namespace std;

struct Turtle{
	int w,str;
}arr[6000];

int dp[6000];

int k = 0;

bool cmp(Turtle a,Turtle b)
{
	if(a.str < b.str ) return true;
	if(a.str == b.str) return a.w < b.w;
	return false;
}

int main()
{
	int temp;
	while(scanf("%d %d",&arr[k].w,&arr[k].str)!=EOF) k++;
	sort(arr,arr+k,cmp);
	for(int a=1;a<6000;a++) dp[a] = inf;
	int ans = 0;
	for(int a=0;a<k;a++)
	{
		for(int b=ans;b>=0;b--)
		{
			if(arr[a].str >= dp[b] + arr[a].w && arr[a].w + dp[b] <dp[b+1])
			{
				dp[b+1] = dp[b] + arr[a].w;
				ans = max(ans,b+1);
			}
		}
	}
	printf("%d\n",ans);
}
