#include<bits/stdc++.h>
using namespace std;
int tot[1005][1005];

int main()
{
	int n;
	scanf("%d",&n);
	for(int a=1;a<=n;a++)
	{
		for(int b=1;b<=n;b++)
		{
			scanf("%d",&tot[a][b]);
			tot[a][b]+= tot[a][b-1];
		}
	}
	int ans = -128000000;
	for(int a=1;a<=n;a++)
	{
		for(int b=a;b<=n;b++)
		{
			int temp = 0;
			for(int c=1;c<=n;c++)
			{
				temp+=tot[c][b] - tot[c][a-1];
				if(temp<0) temp = 0;
				ans = max(ans,temp);
			}
		}
	}
	printf("%lld\n",ans);
}
