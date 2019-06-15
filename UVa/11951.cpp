#include<bits/stdc++.h>
using namespace std;

long long pref[150][150];

int main()
{
	int ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		int r,c,m;
		scanf("%d %d %d",&r,&c,&m);
		for(int a=1;a<=r;a++) for(int b=1;b<=c;b++)
		{
			long long t;
			scanf("%lld",&t);
			pref[a][b] = pref[a][b-1] + t;
		}
		long long area = 0, cost = 0;
		for(int i=1;i<=c;i++)
		{
			for(int j=i;j<=c;j++)
			{
				long long temp = 0;
				long long aa = 0;
				int rem = 1;
				for(int k=1;k<=r;k++)
				{
					temp = temp + pref[k][j] - pref[k][i-1];
					aa += j - i + 1;
					while(temp > m)
					{
						temp = temp - (pref[rem][j] - pref[rem][i-1]);
						aa -= (j-i+1);
						rem++;
					}
					if(aa > area)
					{
						area = aa;
						cost = temp;
					}
					else if(aa == area && cost > temp)
					{
						area = aa;
						cost = temp;
					}
				}
			}
		}
		printf("Case #%d: %lld %lld\n",tc,area,cost);
	}
}
