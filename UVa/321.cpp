#include<bits/stdc++.h>
#define inf 1e+9
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
using namespace std;

vector<int> vec[15],lamp[15];

bool vis[12][1<<12];
pair<int,int> bt[12][1<<12];
int step[12][1<<12];
priority_queue<pair<int,pair<int,int> > > pq;
int r,d,s;

void backtrack(int pos,int bit)
{
	int new_pos = bt[pos][bit].ff;
	int new_bit = bt[pos][bit].ss;
	if(new_pos == -1 && new_bit== -1)  return ;
	else backtrack(new_pos,new_bit);
	int num = (bit^new_bit);
	int tot = 0;
	while(num!=0)
	{
		tot++;
		num/=2;
	}
	if(new_pos!=pos) printf("- Move to room %d.\n",pos);
	else if(bit>new_bit)
	{
		printf("- Switch on light in room %d.\n",tot);
	}
	else if(bit<new_bit)
	{
		printf("- Switch off light in room %d.\n",tot);
	}
	return ;
}


void compute()
{
	while(!pq.empty()) pq.pop();
	step[1][1] = 0;
	bt[1][1] = mp(-1,-1);
	pq.push(mp(0,mp(-1,-1)));
	while(!pq.empty())
	{
		int val = -pq.top().ff;
		int pos = -pq.top().ss.ff;
		int bit = -pq.top().ss.ss;
		if(pos==r && bit == (1<<(r-1))) break;
		pq.pop();
		int sz = lamp[pos].size();
		int tar = vec[pos].size();
		for(int a=0;a<sz;a++)
		{
			int lamp_switch = lamp[pos][a];
			if(lamp_switch==0)
			{
				for(int b=0;b<tar;b++)
				{
					int next = vec[pos][b];
					if(((bit&(1<<(next-1)))!=0)&&val+1<step[next][bit])
					{
						step[next][bit] = val+1;
						bt[next][bit] = mp(pos,bit);
						pq.push(mp(-(val+1),mp(-next,-bit)));
					}
				}
			}
			else
			{
				int new_bit = (1<<(lamp_switch-1));
				if(((new_bit^bit)&(1<<(pos-1)))==0) continue;
				if(val+1<step[pos][new_bit^bit])
				{
					step[pos][new_bit^bit] = val+1;
					bt[pos][new_bit^bit] = mp(pos,bit);
					pq.push(mp(-(val+1),mp(-pos,-(new_bit^bit))));
				}
			}
		}
	}
}

int main()
{
	int k =0;
	while(1)
	{
		scanf("%d %d %d",&r,&d,&s);
		if(r==0 && d==0 &&s==0) break;
		k++;
		memset(vis,false,sizeof(vis));
		for(int a=0;a<12;a++)
			for(int b=0;b<(1<<12);b++)
			{
				step[a][b] = inf;
				bt[a][b] = mp(-1,-1);
			}
		for(int a=0;a<d;a++)
		{
			int t,f;
			scanf("%d %d",&t,&f);
			vec[t].pb(f);
			vec[f].pb(t);
		}
		for(int a=1;a<=r;a++) lamp[a].pb(0),vec[a].pb(a);
		for(int a=0;a<s;a++)
		{
			int t,f;
			scanf("%d %d",&t,&f);
			lamp[t].pb(f);
		}
		compute();
		printf("Villa #%d\n",k);
		if(step[r][(1<<(r-1))]==inf)
		{
			printf("The problem cannot be solved.\n");	
		}
		else
		{
			printf("The problem can be solved in %d steps:\n",step[r][(1<<(r-1))]);
			backtrack(r,(1<<(r-1)));
		}
		for(int a=1;a<=r;a++) vec[a].clear(),lamp[a].clear();
		printf("\n");
	}
}
