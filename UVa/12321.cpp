#include<bits/stdc++.h>
using namespace std;

struct Point{
	int ll;
	int rr;
}p[100005];

bool cmp(Point a,Point b)
{
	if(a.ll<b.ll) return true;
	else if(a.ll == b.ll) return a.rr<b.rr;
	return false;
}

int main()
{
	int L,G;
	while(1)
	{
		scanf("%d %d",&L,&G);
		if(L+G==0) break;
		for(int a=0;a<G;a++)
		{
			int x,r;
			scanf("%d %d",&x,&r);
			p[a].ll = max(x-r,0);
			p[a].rr = x+r;
		}
		sort(p,p+G,cmp);
		int pos_now = 0;
		int val = 0;
		int ft = -1;
		for(int a=0;a<G;a++)
		{
			//cout<<p[a].ll<<" "<<p[a].rr<<" "<<pos_now<<endl;
			if(pos_now>=L) break;
			if(p[a].rr<=pos_now) continue;
			if(p[a].ll>pos_now)
			{
				if(ft==-1) break;
				pos_now = ft;
				val++;
				ft = -1;
				//if(p[a].rr>pos_now)ft = max(ft,p[a].rr);
			}
			if(p[a].rr>pos_now && p[a].ll<=pos_now)
			{
				ft = max(ft,p[a].rr);
			}
		}
		if(pos_now<L&&ft!=-1) pos_now = ft, val++;
		//cout<<"Pos_now"<<pos_now<<endl;
		if(pos_now<L) printf("-1\n");
		else printf("%d\n",G-val);
	}
}
