#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;

int stt[65000];
pair<int,int> p[65000];

int BIT[65000];
int n,P,Q;

int query(int x)
{
	int maxi = 0;
	for(int a=x;a>0;a=a - (a&(-a))) maxi = max(maxi,BIT[a]);
	return maxi + 1;
}

void update(int pos,int val,int n)
{
	for(int a=pos;a<=n;a = a+(a&(-a))) BIT[a] = max(BIT[a],val);
}

int main()
{
	int ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		memset(stt,-1,sizeof(stt));
		memset(BIT,0,sizeof(BIT));
		scanf("%d %d %d",&n,&P,&Q);
		P++;
		Q++;
		for(int a=0;a<P;a++)
		{
			int num;
			scanf("%d",&num);
			stt[num] = a;
		}
		for(int a=0;a<Q;a++)
		{
			int num;
			scanf("%d",&num);
			if(stt[num] == -1)
			{
				a--;
				Q--;
				continue;
			}
			p[a].ff = stt[num];
			p[a].ss = a+1;
		}
		sort(p,p+Q);
		int ans = 0;
		for(int a=0;a<Q;a++)
		{
			int pos = p[a].ss;
			int v = query(pos);
			ans = max(ans,v);
			update(pos,v,n*n);		
		}
		printf("Case %d: %d\n",tc,ans);
	}
}
