#include<bits/stdc++.h>
using namespace std;

struct point{
	double x,y;
}p[150];

double cross(point a,point b,point c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main()
{
	int n;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin>>n)
	{
		if(n==0) break;
		for(int a=0;a<2*n;a++) cin>>p[a].x>>p[a].y;
		int X,Y;
		X = 0, Y = 0;
		int te = 150000;
		for(int a=-500;a<=500;a++)
		{
			bool fin = false;
			for(int b=-500;b<=500;b++)
			{
				if(a == 0 && b == 0) continue;
				bool ada = true;
				int t1 = 0;
				int t2 = 0;
				point p1,p2;
				p1.x = 0;
				p1.y = 0;
				if(a == 0)
				{
					p2.x = 5;
					p2.y = 0;
				}
				else if(b == 0)
				{
					p2.x = 0;
					p2.y = 5;
				}
				else
				{
					p2.x = b;
					p2.y = -a;
				}
				for(int c=0;c<2*n;c++)
				{
					double v = cross(p[c],p1,p2);
					if(v < 0) t1++;
					else if(v > 0) t2++;
					else ada = false;
				}
				if(ada==true && t1 == t2)
				{
					X = a;
					Y = b;
					fin = true;
					break;
				}
			}
			if(fin) break;
		}
		printf("%d %d\n",X,Y);
	}
}
