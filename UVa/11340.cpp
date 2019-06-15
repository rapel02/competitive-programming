#include<bits/stdc++.h>
using namespace std;

int val[300];

char in[15000];

int main()
{
	int t;
	int n;
	scanf("%d",&t); getchar();
	while(t--)
	{
		scanf("%d",&n); getchar();
		memset(val,0,sizeof(val));
		for(int a=0;a<n;a++)
		{
			char tp;
			int k;
			scanf("%c %d",&tp,&k); getchar();
			val[tp] = k;
		}
		scanf("%d",&n); getchar();
		int tot = 0;
		for(int a=0;a<n;a++)
		{
			gets(in);
			int len = strlen(in);
			for(int b=0;b<len;b++)
			{
				tot+=val[in[b]];
			}
		}
		printf("%.2lf$\n",1.0*tot/100);
	}
}
