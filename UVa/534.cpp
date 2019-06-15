#include<bits/stdc++.h>
using namespace std;


bool vis[250];

struct Point{
	double x;
	double y;
}p[250];

double sqr(double x)
{
	return x*x;
}

double dist(Point a,Point b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

int main()
{
	int n;
	int tc = 0;
	while(cin>>n && n!=0)
	{
		tc++;
		for(int a=0;a<n;a++) cin>>p[a].x>>p[a].y;
		double lo = 0;
		double hi = 3000;
		for(int a=1;a<=50;a++)
		{
			double mid = (lo + hi)/2.0;
			memset(vis,false,sizeof(vis));
			vis[0] = true;
			queue<int> q;
			q.push(0);
			while(!q.empty())
			{
				int pos = q.front();
				q.pop();
				for(int b=0;b<n;b++){
					if(vis[b]==true) continue;
					if(dist(p[pos],p[b]) <= mid)
					{
						vis[b] = true;
						q.push(b);
					}
				}
			}
			if(vis[1]==true) hi = mid;
			else lo = mid;
		}
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",tc,lo);
	}
}
