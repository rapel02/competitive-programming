#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,bw,h,w;
	int p,c;
	while(scanf("%d %d %d %d",&n,&bw,&h,&w)!=EOF)
	{
		int tot = 1000000000;
		for(int a=0;a<h;a++)
		{
			scanf("%d",&p);
			for(int b=0;b<w;b++)
			{
				scanf("%d",&c);
				if(c>=n)
				{
					tot = min(tot,p*n);
				}
			}
		}
		if(tot>bw) printf("stay home\n");
		else printf("%d\n",tot);
	}
}
