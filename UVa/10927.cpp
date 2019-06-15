#include<bits/stdc++.h>
using namespace std;

struct Point{
	long long x,y;
	long long h;
	long long sector;
}p;

vector<Point> in,br;

bool cmp(Point a,Point b){
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

long long sqr(long long x)
{
	return x*x;
}

bool cmpangle(Point a,Point b)
{
	long long le = a.y * b.x;
	long long ri = a.x * b.y;
	if(a.sector != b.sector) return a.sector < b.sector;
	if(le != ri) return le > ri;
	return sqr(a.x) + sqr(a.y) < sqr(b.x) + sqr(b.y);
}

bool issame(Point a,Point b)
{
	if(a.sector != b.sector) return false;
	return a.y * b.x == a.x * b.y;
}

int main()
{
	int tc = 0;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		tc++;
		in.clear(),br.clear();
		for(int a=0;a<n;a++)
		{
			cin>>p.x>>p.y>>p.h;
			if(p.x >= 0 && p.y >=0) p.sector = 1;
			if(p.x < 0 && p.y >=0) p.sector = 2;
			if(p.x >= 0 && p.y < 0) p.sector = 3;
			if(p.x < 0 && p.y < 0) p.sector = 4;
			in.push_back(p);
		}
		sort(in.begin(),in.end(),cmpangle);
		long long maxi = -1;
		for(int a=0;a<n;a++)
		{
			if(!issame(in[a-1],in[a])) maxi = -1;
			if(issame(in[a-1],in[a]) && maxi >= in[a].h) 
			{
				br.push_back(in[a]);
			}
			maxi = max(maxi,in[a].h);
		}
		printf("Data set %d:\n",tc);
		if(br.size()==0) printf("All the lights are visible.\n");
		else
		{
			sort(br.begin(),br.end(),cmp);
			printf("Some lights are not visible:\n");
			int sz = br.size();
			for(int a=0;a<sz;a++)
			{
				printf("x = %d, y = %d",br[a].x,br[a].y);
				if(a==sz-1) printf(".\n");
				else printf(";\n");
			}
		}
	}
}
