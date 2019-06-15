#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;

map<pair<double,double>,int> mmap;

struct point{
	double x,y;
}p[150];

double grad(point a,point b)
{
	if(a.x == b.x) return 1e+10;
	return (b.y - a.y) / (b.x - a.x);
}

int main()
{
	int ntc;
	cin>>ntc;
	for(int tc=1;tc<=ntc;tc++)
	{
		int n;
		cin>>n;
		mmap.clear();
		for(int a=0;a<n;a++)
		{
			cin>>p[a].x>>p[a].y;
			if(mmap[mp(p[a].x,p[a].y)] == 1)
			{
				n--;
				a--;
			}
			mmap[mp(p[a].x,p[a].y)] = 1;
		}
		printf("Data set #%d contains ",tc);
		if(n==1)
		{
			printf("a single gnu.\n");
			continue;
		}
		else
		{
			printf("%d gnus, ",n);
			int maxi = 0;
			for(int a=0;a<n;a++)
			{
				map<double,int> mgrad;
				for(int b=0;b<n;b++)
				{
					if(b==a) continue;
					double dg = grad(p[a],p[b]);
					mgrad[dg]++;
					maxi = max(maxi,mgrad[dg]);
				}
			}
			printf("out of which a maximum of %d are aligned.\n",maxi+1);
		}
	}
}
