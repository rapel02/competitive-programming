#include<bits/stdc++.h>
using namespace std;

int w[50];

int main()
{
	int tc;
	scanf("%d",&tc);
	for(int tcc=1;tcc<=tc;tcc++)
	{
		int n,p,q;
		scanf("%d %d %d",&n,&p,&q);
		int tot = 0;
		for(int a=0;a<n;a++)
			scanf("%d",&w[a]);
		sort(w,w+n);
		int c = 0;
		for(int a=0;a<n;a++)
		{
			if(w[a]+tot>q)	break;
			c++;
			tot+=w[a];
		}
		printf("Case %d: %d\n",tcc,min(c,p));
	}
}
