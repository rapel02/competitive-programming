#include<bits/stdc++.h>
using namespace std;

struct point{
	double l,r;
}p[15000];

double sqr(double x)
{
	return x*x;
}

bool cmp(point a,point b)
{
	return a.l < b.l;
}

int main()
{
	int n;
	double l,w;
	while(cin>>n>>w>>l)
	{
		l/=2.0;
		int ans = 0;
		double y = 0;
		double py = 0;
		bool ada = true;
		for(int a=0;a<n;a++)
		{
			double ll,r;
			cin>>ll>>r;
			if(l > r)
			{
				a--;
				n--;
				continue;
			}
			double d = sqrt(sqr(r) - sqr(l));
			p[a].l = ll - d;
			p[a].r = ll + d;
		}
		sort(p,p+n,cmp);
		for(int a=0;a<n;a++)
		{
			if(p[a].l > y)
			{
				ans++;
				y = py;
				if(y >= w) break;
				if(p[a].l > y) ada = false;
			}
			py = max(py,p[a].r);
		}
		if(y < w)
		{
			ans++;
			y = py;
			if(y < w) ada = false;
		}
		if(ada==false) ans = -1;
		cout<<ans<<"\n";
	}
}
