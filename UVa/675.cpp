#include<bits/stdc++.h>
#define mp make_pair
using namespace std;

struct point{
	long long x,y;
	int app;
};

vector<point> p,hull;
map<pair<long long,long long>,int> mmap;

string in;

bool cmp(point a,point b)
{
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

long long cross(point a,point b,point c)
{
	return (b.x-a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

void print()
{
	int MAXN = 1e+9;
	int idx = 0;
	int sz = hull.size();
	for(int a=0;a<sz;a++)
	{
		if(MAXN >= hull[a].app)
		{
			idx = a;
			MAXN = hull[a].app;
		}
	}
	for(int a=0;a<=sz;a++)
		printf("%lld, %lld\n",hull[(a+idx)%sz].x,hull[(a+idx)%sz].y);
}

void process()
{
	int n = p.size();
	sort(p.begin(),p.end(),cmp);
	int k = 0;
	for(int a=0;a<n;a++)
	{
		while(k>=2 && cross(hull[k-2],hull[k-1],p[a]) <= 0) hull.pop_back(),k--;
		hull.push_back(p[a]);
		k++;
	}
	int t = k + 1;
	for(int a=n-2;a>=0;a--)
	{
		while(k>=t && cross(hull[k-2],hull[k-1],p[a]) <= 0) hull.pop_back(),k--;
		hull.push_back(p[a]);
		k++;
	}
	hull.pop_back();
	print();
}

int main()
{
	bool err = true;
	bool isnf = false;
	int k = 0;
	while(getline(cin,in))
	{
		int len = in.length();
		if(err && isnf) printf("\n");
		if(len == 0)
		{
			isnf = true;
			process();
			err = true;
			p.clear();
			hull.clear();
			mmap.clear();
			k = 0;
			continue;
		}
		err = false;
		point temp;
		temp.x = temp.y = 0;
		bool isx = true;
		for(int a=0;a<len;a++)
		{
			if(in[a]==',') isx = false;
			else
			{
				if(in[a]>='0' && in[a]<='9')
				{
					if(isx==true) temp.x = temp.x * 10 + (in[a]-'0');
					else temp.y = temp.y * 10 + (in[a]-'0');
				}
			}
		}
		if(mmap[mp(temp.x,temp.y)] == 1) continue;
		mmap[mp(temp.x,temp.y)] = 1;
		temp.app = k++;
		p.push_back(temp);
	}
	if(err==false) process();
}
