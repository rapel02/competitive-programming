#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;

map<pair<pair<int,int>,int>,vector<int> > mmap[2];

pair<pair<int,int>,int> p[35];
char in[35][2500];

vector<int> err;

void execute(int idx,int add = 0)
{
	int rem = idx;
	pair<pair<int,int>,int> tot;
	tot.ff.ff = 0;
	tot.ff.ss = 0;
	tot.ss = 0;
	int pos = add;
	while(idx)
	{
		if(idx&1)
		{
			tot.ff.ff += p[pos].ff.ff;
			tot.ff.ss += p[pos].ff.ss;
			tot.ss += p[pos].ss;
		}
		idx/=2;
		pos++;
	}
	if(add==0) mmap[0][tot].push_back(rem);
	else mmap[1][tot].push_back(rem<<add);
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int X,A,D,m;
		scanf("%d %d %d %d",&X,&A,&D,&m);
		mmap[0].clear();
		mmap[1].clear();
		err.clear();
		for(int a=0;a<m;a++) scanf("%s %d %d %d",in[a],&p[a].ff.ff,&p[a].ff.ss,&p[a].ss);
		for(int a=0;a<m;a++)
		{
			for(int b=a+1;b<m;b++)
			{
				if(strcmp(in[a],in[b]) == 0)
				{
					err.push_back((1<<a) + (1<<b));
				}
			}
		}
		int sz = err.size();
		int l = m/2;
		for(int a=0;a<(1<<l);a++) execute(a);
		int r = m - l;
		for(int a=0;a<(1<<r);a++) execute(a,l);
		bool ada = false;
		for(map<pair<pair<int,int>,int>,vector<int> >::iterator a = mmap[0].begin();a!=mmap[0].end();a++)
		{
			pair<pair<int,int>,int> tot = a->ff;
			tot.ff.ff = X - tot.ff.ff;
			tot.ff.ss = A - tot.ff.ss;
			tot.ss = D - tot.ss;
			if(mmap[1][tot].size()!= 0)
			{
				int sz1 = a->ss.size();
				int sz2 = mmap[1][tot].size();
				vector<int> te = mmap[1][tot];
				for(int b=0;b<sz1;b++)
				{
					for(int c=0;c<sz2;c++)
					{
						int tot = a->ss[b] + te[c];
						bool wow = false;
						for(int d=0;d<sz;d++)
						{
							if( (tot & err[d]) == err[d])
							{
								wow = true;
							}
						}
						if(!wow) ada = true;
					}
				}
			}
			if(ada==true) break;
		}
		printf("%s\n",(ada==true)?"POSSIBLE":"IMPOSSIBLE");
	}
}
