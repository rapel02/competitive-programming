#include<bits/stdc++.h>
using namespace std;

char in[155][155];

pair<int,int> ppi[155];
pair<char,int> ppc[155];


int bit[150];
int r,c;

void update(int a)
{
	for(int b=a;b<=c;b += b&(-b)) bit[b]++;
}

int query(int a)
{
	int tot =0;
	for(int b=a;b>0;b -= b&(-b)) tot+=bit[b];
	return tot;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	bool fw = true;
	while(tc--)
	{
		if(!fw) printf("\n");
		fw = false;
		scanf("%d %d",&c,&r);
		for(int a=0;a<r;a++)
		{
			scanf("%s",in[a]);
			int tot = 0;
			memset(bit,0,sizeof(bit));
			for(int b=0;b<c;b++) ppc[b].first = in[a][b], ppc[b].second = b+1;
			sort(ppc,ppc+c);
			for(int b=0;b<c;b++)
			{
				tot += query(c) - query(ppc[b].second);
				update(ppc[b].second);
			}
			ppi[a].first = tot;
			ppi[a].second = a;
		}
		sort(ppi,ppi+r);
		for(int a=0;a<r;a++)
		{
			printf("%s\n",in[ppi[a].second]);
		}
	}
}
