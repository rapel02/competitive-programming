#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	int ans;
	scanf("%d",&test);
	for(int a=1;a<=test;a++)
	{
		ans=0;
		int ban,w;
		scanf("%d",&ban);
		for(int b=1;b<=ban;b++)
		{
			scanf("%d",&w);
			if(w>ans) ans=w;
		}
		printf("Case %d: %d\n",a,ans);
	}
}
