#include<bits/stdc++.h>
using namespace std;

char inp[1000005];
int val[1000005];
int main()
{
	int test=1;
	while(scanf("%s",inp)!=EOF)
	{
		bool fin=false;
		printf("Case %d:\n",test);
		test++;
		int len=strlen(inp);
		val[0]=0;
		for(int a=1;a<len;a++)
		{
			if(inp[a]!=inp[a-1]) val[a]=val[a-1]+1;
			else val[a]=val[a-1];
		}
		int que,n,m;
		scanf("%d",&que);
		for(int a=0;a<que;a++)
		{
			scanf("%d %d",&n,&m);
			if(val[n]==val[m]) printf("Yes\n");
			else printf("No\n");
		}
	}
}
