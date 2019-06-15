#include<bits/stdc++.h>
using namespace std;

struct Point{
	long long x,y;
	int idx;
}p[3500],hull[3500];

bool stt[3500];

int n,k;

inline bool cmp(Point a,Point b)
{
	if(a.x < b.x) return true;
	if(a.x == b.x) return a.y < b.y;
	return false;
}

inline long long cross(Point a,Point b,Point c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int tot = 0;

inline int CHULL()
{
	k = 0;
	for(int a=0;a<n;a++)
	{
		if(stt[p[a].idx] == true) continue;
		while(k>=2 && cross(hull[k-2],hull[k-1],p[a]) < 0) k--;
		hull[k++] = p[a];
	}
	int t = k+1;
	bool las = true;
	bool in = false;
	for(int a=n-1;a>=0;a--)
	{
		if(stt[p[a].idx] == true) continue;
		if(las==true)
		{
			las = false;
			continue;
		}
		while(k>=t && cross(hull[k-2],hull[k-1],p[a]) < 0) k--;
		hull[k++] = p[a];
		in = true;
	}
	if(in==true) k--;
	for(int a=0;a<k;a++)
	{
		if(stt[hull[a].idx]==false) tot++;
		stt[hull[a].idx] = true;
	}
	return k;
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(stt,false,sizeof(stt));
		for(int a=0;a<n;a++) 
		{
			cin>>p[a].x>>p[a].y;
			p[a].idx = a;
		}
		sort(p,p+n,cmp);
		tot = 0;
		int ans = 0;
		while(1)
		{
			CHULL();
			ans++;
			if(tot==n) break;
		}
		printf("%d\n",ans);
	}
}
