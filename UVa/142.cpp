#include<bits/stdc++.h>
using namespace std;

struct Point{
	int x,y;
}point[55],temp;

bool visible[55];

struct Rect{
	Point tl;
	Point br;
}rect[28];
	
int p = 0, r= 0;

vector<Point> query;

bool inside(Rect a,Point b)
{
	if(a.tl.x <= b.x && a.tl.y <= b.y && a.br.x >= b.x && a.br.y >=b.y) return true;
	return false;
}

void visibility()
{
	for(int a=0;a<p;a++)
	{
		for(int b=0;b<r;b++)
		{
			if(inside(rect[b],point[a]))
			{
				visible[a] = true;
				break;
			}
		}
	}
}

int sqr(int x)
{
	return x*x;
}

int dist(Point a,Point b)
{
	return sqr(a.x - b.x) + sqr(a.y - b.y);
}

int main()
{
	char in[15];
	while(scanf("%s",in)!=EOF)
	{
		if(in[0]=='#') break;
		if(in[0]=='I')
		{
			scanf("%d %d",&point[p].x,&point[p].y);
			p++;
		}
		if(in[0]=='R')
		{
			scanf("%d %d %d %d",&rect[r].tl.x,&rect[r].tl.y,&rect[r].br.x,&rect[r].br.y);
			r++;
		}
		if(in[0]=='M')
		{
			scanf("%d %d",&temp.x,&temp.y);
			query.push_back(temp);
		}
	}
	int size = query.size();
	visibility();
	for(int a=0;a<size;a++)
	{
		int idx = -1;
		Point temp = query[a];
		for(int b=0;b<r;b++) if(inside(rect[b],temp)) idx = b;
		if(idx!=-1) printf("%c\n",idx + 'A');
		else
		{
			int d = 10000000;
			vector<int> v;
			for(int c=0;c<p;c++)
			{
				if(visible[c]) continue;
				int tp = dist(point[c],temp);
				if(d > tp)
				{
					d = tp;
					v.clear();
					v.push_back(c+1);
				}
				else if(d==tp)
				{
					v.push_back(c+1);
				}
			}
			int sz = v.size();
			for(int c=0;c<sz;c++) printf("%3d",v[c]);
			printf("\n");
		}
	}
}
