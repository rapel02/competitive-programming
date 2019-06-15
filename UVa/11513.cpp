#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;

int arr[4][4];

stack<pair<pair<int,int> , pair<int,int> > > s;

int ans[10],temp[10];

int ttr[3][3]={{1,2,3},{4,5,6},{7,8,9}};

bool check(int vv,int hh)
{
	for(int a=0;a<3;a++)
	{
		for(int b=0;b<3;b++)
		{
			if(arr[(a-(vv%3)+3)%3][(b+(hh%3))%3]!=ttr[a][b]) return false;
		}
	}
	return true;
}

int main()
{
	while(1)
	{
		scanf("%d",&arr[0][0]);
		if(arr[0][0]==0) break;
		scanf("%d %d",&arr[0][1],&arr[0][2]);
		for(int a=1;a<=2;a++)
			for(int b=0;b<=2;b++) scanf("%d",&arr[a][b]);
		int step=8;
		bool solve=false;
		if(check(0,0)==true)
		{
			step=0;
			solve=true;
		}
		for(int a=1;a<7;a++)
		{
			int yy=0,xx=0;
			if(a>3) yy=a-3;
			else if(a>0) xx=a;
			s.push(mp(mp(1,a),mp(yy,xx)));
			while(!s.empty())
			{
				int id=s.top().ff.ff;
				int val=s.top().ff.ss;
				int vv=s.top().ss.ff;
				int hh=s.top().ss.ss;
				temp[id]=val;
				s.pop();
				//printf("%d %d %d %d\n",id,val,vv,hh);
				if(check(vv,hh)==true && id<step)
				{
					solve=true;
					step=id;
					for(int b=1;b<=id;b++) ans[b]=temp[b];
				}
				if(id>=step) continue;
				else
				{
					for(int a=1;a<7;a++)
					{
						int yy=0,xx=0;
						if(a>3) yy=a-3;
						else if(a>0) xx=a;
						s.push(mp(mp(id+1,a),mp(vv+yy,hh+xx)));
					}
				}
			}
		}
		if(solve==false) printf("Not solvable\n");
		else
		{
			printf("%d ",step);
			for(int b=1;b<=step;b++)
			{
				//printf("%d ",ans[b]);
				if(ans[b]>=4) printf("V%d",ans[b]-3);
				else if(ans[b]>0) printf("H%d",ans[b]);
			}
			printf("\n");
		}
	}
}
