#include<bits/stdc++.h>
using namespace std;

queue<int> q;

int mm[105];
int num[105][105];
char in[105];

int w[105];

int main()
{
	int tc;
	scanf("%d",&tc);getchar();
	while(tc--)
	{
		int n,k;
		scanf("%d %d",&n,&k); getchar();
		for(int a=0;a<k;a++)
		{
			scanf("%d",&mm[a]);getchar();
			for(int b=0;b<2*mm[a];b++)
			{
				scanf("%d",&num[a][b]);getchar();
			}
			scanf("%c",&in[a]);
		}
		for(int a=1;a<=n;a++)
		{
			w[a] = 1;
			bool ada = true;
			for(int b=0;b<k;b++)
			{
				int ll =0,rr=0;
				for(int c=0;c<mm[b];c++)
				{
					ll+=w[num[b][c]];
				}
				for(int c=mm[b];c<2*mm[b];c++)
				{
					rr+=w[num[b][c]];
				}
				if(in[b]=='>')
				{
					if(ll<=rr) ada=false;
				}
				if(in[b]=='<')
				{
					if(ll>=rr) ada =false;
				}
				if(in[b]=='=')
				{
					if(ll!=rr) ada=false;
				}
				if(ada==false) break;
			}
			if(ada==true) q.push(a);
			if(ada==false)
			{
				w[a] = -1;
				ada=true;
				for(int b=0;b<k;b++)
				{
					int ll =0,rr=0;
					for(int c=0;c<mm[b];c++)
					{
						ll+=w[num[b][c]];
					}
					for(int c=mm[b];c<2*mm[b];c++)
					{
						rr+=w[num[b][c]];
					}
					if(in[b]=='>')
					{
						if(ll<=rr) ada=false;
					}
					if(in[b]=='<')
					{
						if(ll>=rr) ada =false;
					}
					if(in[b]=='=')
					{
						if(ll!=rr) ada=false;
					}
					if(ada==false) break;
				}
				if(ada==true) q.push(a);
			}
			w[a] = 0;
		}
		if(q.size()!=1) printf("%d\n",0);
		else printf("%d\n",q.front());
		while(!q.empty()) q.pop();
		if(tc!=0) printf("\n");
	}
}
