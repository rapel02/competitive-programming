#include<bits/stdc++.h>
using namespace std;

bool stat[10000];

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int tot,ty,we;
		memset(stat,false,sizeof(stat));
		scanf("%d",&tot);
		scanf("%d",&ty);
		stat[0]=true;
		for(int a=0;a<ty;a++)
		{
			scanf("%d",&we);
			for(int b=tot;b>=we;b--)
			{
				if(stat[b-we]==true)stat[b]=true;
			}
		}
		if(stat[tot]==true) printf("YES\n");
		else printf("NO\n");
	}
}
