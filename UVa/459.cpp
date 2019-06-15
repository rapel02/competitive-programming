#include<bits/stdc++.h>
using namespace std;

bool vis[150];
int par[150];
int h[150];

int find(int a)
{
	if(a==par[a]) return a;
	return par[a] = find(par[a]);
}

bool issame(int a,int b)
{
	return find(a) == find(b);
}

void disjoint(int a,int b){
	if(issame(a,b)==true) return ;
	int x = find(a);
	int y = find(b);
	if(h[x] > h[y]) par[y] = x;
	else par[x] = y, (h[x]==h[y])?h[y]++:h[y];
}

string in;

int main()
{
	int tc;
	bool ff = true;
	cin>>tc;
	getchar();
	getchar();
	while(tc--)
	{
		if(ff==false) printf("\n");
		ff = false;
		getline(cin,in);
		int idx = in[0]-'A';
		for(int a=0;a<30;a++) par[a] = a,h[a] = 1,vis[a] = false;
		while(getline(cin,in))
		{
			if(in.length()==0) break;
			int p1 = in[0] - 'A';
			int p2 = in[1] - 'A';
			disjoint(p1,p2);
		}
		int tot = 0;
		for(int a=0;a<=idx;a++)
		{
			if(vis[find(a)]==false) tot++;
			vis[find(a)] = true;
		}
		printf("%d\n",tot);
	}
}
