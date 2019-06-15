#include<bits/stdc++.h>
using namespace std;

int hub[22][22];

int main()
{
	int t;
	long long q=0;
	bool fff=true;
	for(int a=1;a<=20;a++)
	{
		for(int b=1;b<=20;b++)
		{
			if(a!=b) hub[a][b]=10000;
			else hub[a][b]=0;
		}
	}
	while(scanf("%d",&t)!=EOF)
	{
		q++;
		fff=false;
		for(int a=1;a<=t;a++)
		{
			int k;
			scanf("%d",&k);
			hub[1][k]=1;
			hub[k][1]=1;
		}
		for(int a=2;a<=19;a++)
		{
			int n;
			scanf("%d",&n);
			for(int b=0;b<n;b++)
			{
				int k;
				scanf("%d",&k);
				hub[a][k]=1;
				hub[k][a]=1;
			}
		}
		for(int k=1;k<=20;k++)
			for(int i=1;i<=20;i++)
				for(int j=1;j<=20;j++)
					hub[i][j]=min(hub[i][k]+hub[k][j],hub[i][j]);
		printf("Test Set #%lld\n",q);
		int que;
		scanf("%d",&que);
		for(int a=1;a<=que;a++)
		{
			int tt,fr;
			scanf("%d %d",&fr,&tt);
			printf("%2d to %2d: %d\n",fr,tt,hub[fr][tt]);
		}
		for(int a=1;a<=20;a++)
		{
			for(int b=1;b<=20;b++)
			{
			if(a!=b) hub[a][b]=10000;
			else hub[a][b]=0;
			}
		}
		printf("\n");
	}
}
