#include<bits/stdc++.h>
using namespace std;

struct Point{
	int ll;
	int rr;
}p[100005];

queue<int> q;

bool cmp(Point a,Point b)
{
	if(a.ll<b.ll) return true;
	if(a.ll==b.ll) return a.rr<b.rr;
	return false;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int l;
		scanf("%d",&l);
		int k = 0;
		while(1)
		{
			int l,r;
			scanf("%d %d",&l,&r);
			if(l==0 && r==0) break;
			p[k].ll = l;
			p[k].rr = r;
			k++;
		}
		p[k].ll = 1e+8 , p[k].rr = 1e+8;
		sort(p,p+k+1,cmp);
		int pos_now = 0;
		int ft = -1;
		int rem = -1;
		int val = 0;
		for(int a=0;a<=k;a++)
		{
			if(pos_now>=l) break;
			if(p[a].ll>pos_now)
			{
				if(ft==-1) break;
				pos_now =  ft;
				ft = -1;
				q.push(rem);
				rem = -1;
				val++;
			}
			if(p[a].rr>pos_now)
			{
				if(ft<p[a].rr)
				{
					ft = p[a].rr;
					rem = a;
				}
			}
		}
		if(pos_now<l)
		{
			printf("%d\n",0);
			while(!q.empty()) q.pop();
		}
		else
		{
			printf("%d\n",val);
			while(!q.empty())
			{
				int f = q.front();
				q.pop();
				printf("%d %d\n",p[f].ll,p[f].rr);
			}
		}
		if(tc!=0) printf("\n");
	}
}
