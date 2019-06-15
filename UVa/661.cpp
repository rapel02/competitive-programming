#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,c;
	int tc = 0;
	bool isf = true;
	while(1)
	{
		scanf("%d %d %d",&n,&m,&c);
		if(n + m + c == 0) break;
		if(!isf) printf("\n");
		int mark[25];
		int w[25];
		for(int a=1;a<=n;a++)
		{
			scanf("%d",&w[a]);
			mark[a] = 0;
		}
		int maxi = 0;
		int now = 0;
		for(int a=0;a<m;a++)
		{
			int c;
			scanf("%d",&c);
			if(mark[c] == 0) maxi = max(maxi,now+=w[c]),mark[c] = 1;
			else maxi = max(maxi,now-=w[c]),mark[c] = 0;
		}
		tc++;
		printf("Sequence %d\n",tc);
		if(maxi > c) printf("Fuse was blown.\n");
		else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n",maxi);
		printf("\n");
	}
}
