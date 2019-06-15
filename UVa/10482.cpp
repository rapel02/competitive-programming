#include<bits/stdc++.h>
using namespace std;

int n;
long long num[650];
int arr[33];

int main()
{
	int ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		int n;
		int tot = 0;
		scanf("%d",&n);
		memset(num,0,sizeof(num));
		for(int a=1;a<=n;a++)
		{
			scanf("%d",&arr[a]);
			tot+=arr[a];
		}
		num[0] = 1;
		for(int a=1;a<=n;a++)
		{
			for(int b=tot;b>=arr[a];b--)
			{
				if(num[b-arr[a]]!=0)
				{
					num[b] = (num[b] |num[b-arr[a]] | (1LL<<a) );
				}
			}
		}
		int ans = 1000000;
		for(int a=0;a<=tot;a++)
		{
			if(num[a]==0) continue;
			for(int b=a+1;b<=tot;b++)
			{
				if(num[b]==0) continue;
				if((num[b]&num[a])==num[a])
				{
					int c = tot - b;
					int bb = b-a;
					int w = max(abs(a-bb),max(abs(a-c),abs(bb-c)));
					if(ans > w)
					{
						ans = w;
						printf("%d %d %d\n",a,bb,c);
						printf("%lld %lld %lld\n",num[a],num[b],(num[a] & num[b]));
					}
				}
			}
		}
		printf("Case %d: %d\n",tc,ans);
	}
}
