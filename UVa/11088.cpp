#include<bits/stdc++.h>
using namespace std;

int arr[20];
int dp[1<<15];
int val[500];

int X[150];

bool check(int a)
{
	int k = 0;
	int w = 0;
	while(a!=0)
	{
		if(a%2==1) X[w] = k,w++;
		a/=2;
		k++;
	}
	if(w==3) return true;
	return false;
}

int main()
{
	int n;
	int k = 0;
	while(scanf("%d",&n),n)
	{
		k++;
		memset(dp,0,sizeof(dp));
		for(int a=0;a<n;a++) scanf("%d",&arr[a]);
		int w = 0;
		for(int a=0;a<(1<<n);a++)
		{
			if(check(a))
			{
			//	printf("%d\n",a);
				int tot = 0;
				for(int b=0;b<3;b++) tot+=arr[X[b]];
				if(tot>=20) val[w] = a,w++;
			}
		}
		//for(int a=0;a<w;a++) printf("%d\n",val[a]);
		dp[0] = 0;
		for(int a=0;a<w;a++)
		{
			for(int b=0;b<(1<<n);b++)
			{
				if( (b & val[a]) ==0)
				{
					dp[b + val[a]] = max(dp[b + val[a]],dp[b] + 1);
				}
			}
		}
		printf("Case %d: %d\n",k,dp[(1<<n) - 1]);
	}
	
}
