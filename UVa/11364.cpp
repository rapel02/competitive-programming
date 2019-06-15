#include<bits/stdc++.h>
using namespace std;

int pos[10005];

int main()
{
	int test,par;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&par);
		for(int a=0;a<par;a++)
			scanf("%d",&pos[a]);
		sort(pos,pos+par);
		int ans=0;
		for(int a=0;a<par-1;a++)
		{
			ans+=(pos[a+1]-pos[a]);
		}
		//printf("%d\n",ans);
		ans+=(pos[par-1]-pos[0]);
		printf("%d\n",ans);
	}
}
