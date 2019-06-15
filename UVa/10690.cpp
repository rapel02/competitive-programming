#include<bits/stdc++.h>
using namespace std;

int dp[105][11000];

void compute(int num,int id)
{
	dp[0][50] = 1;
	for(int b=id;b>0;b--)
	{
		for(int a=0;a<=10500 ; a++)
		{
			if(dp[b-1][a]==1)
			{
				dp[b][a+num] = 1;
			}
		}
	}
}

int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		int tot = 0;
		memset(dp,0,sizeof(dp));
		for(int a=1;a<=n+m;a++)
		{
			int tmp;
			scanf("%d",&tmp);
			tot+=tmp;
			tmp+=50;
			compute(tmp,a);
		}
		long long maxi;
		long long mini;
		bool first = true;
		for(int a=0;a<=10500;a++)
		{
			if(dp[n][a]==1)
			{
				if(first==true)
				{
					maxi = (tot-a+n*50+50)*(a-n*50-50);
					mini = (tot-a+n*50+50)*(a-n*50-50);
				}
				maxi = max(maxi,(long long)(tot-a+n*50+50)*(a-n*50-50));
				mini = min(mini,(long long)(tot-a+n*50+50)*(a-n*50-50));
				first = false;
			}
		}
		printf("%lld %lld\n",maxi,mini);
	}
}
