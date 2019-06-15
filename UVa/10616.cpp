#include<bits/stdc++.h>
using namespace std;

long long num[2005];
long long dp[4001][30];
long long bum[2005];
long long di,pic;
long long tt,que;

long long count()
{
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(long long c=0;c<tt;c++)
		for(long long b=pic-1;b>=0;b--)
		{
			for(long long a=0;a<=2500;a++)
			{
				if(dp[a][b]>0)
				{
					dp[a+bum[c]][b+1]+=dp[a][b];
					//prlong longf("%d %d %d\n",a,b,num[c]);
				}
			}
		}
	long long cc=0;
	for(long long a=0;a<=2500;a+=di)
	{
		//if(a<40)prlong longf("%d %d %d\n",a,dp[a][pic],cc);
		cc+=dp[a][pic];
	}
	//prlong longf("%d\n",cc);
	return cc;
}

int main()
{
	long long k=0;
	while(1)
	{
		long long l=0;
		k++;
		scanf("%lld %lld",&tt,&que);
		if(tt==0 && que==0) break;
		for(long long a=0;a<tt;a++)
		{
			scanf("%lld",&num[a]);
			bum[a]=num[a];
		}
		printf("SET %lld:\n",k);
		for(long long a=0;a<que;a++)
		{
			l++;
			scanf("%lld %lld",&di,&pic);
			for(long long b=0;b<tt;b++)
			{
				bum[b]=bum[b]%di;
				if(bum[b]<0) bum[b]+=di;
			}
			printf("QUERY %lld: %lld\n",l,count());
			for(long long b=0;b<tt;b++)
				bum[b]=num[b];
		}
	}
}
