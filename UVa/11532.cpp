#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc = 0;
	scanf("%d",&tc);
	while(tc--)
	{
		int n,m;
		long long ans = 0;
		scanf("%d %d",&n,&m);
		if(n>0)
		{
			n--;
			ans = 1;
		}
		int ct = 1;
		while(n!=0)
		{
			if(ct%3==2 ||ct%3==0)
			{
				ans += (1LL<<(ct));
				n--;
			}
			ct++;
		}
		printf("%lld\n",ans);
	}
}
