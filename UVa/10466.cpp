#include<bits/stdc++.h>
using namespace std;

struct point{
	double x,y;
}p[1500];

const double PI = acos(-1);

int main()
{
	int n,t;
	while(cin>>n>>t)
	{
		p[0].x = 0;
		p[0].y = 0;
		for(int a=1;a<=n;a++)
		{
			int tt;
			double r;
			cin>>r>>tt;
			double tres = t%tt;
			double deg = tres * 2*PI / tt;
			double x = r * cos(deg);
			double y = r * sin(deg);
			p[a].x = p[a-1].x + x;
			p[a].y = p[a-1].y + y;
		}
		for(int a=1;a<=n;a++)
		{
			if(a!=1) printf(" ");
			printf("%.4lf",sqrt(p[a].x*p[a].x + p[a].y * p[a].y));
		}
		printf("\n");
	}
}
