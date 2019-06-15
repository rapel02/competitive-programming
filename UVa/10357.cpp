#include<bits/stdc++.h>
using namespace std;


struct player{
	double x,y,v;
}p[50];

double sqr(double x)
{
	return x*x;
}

double dist(player a,double x,double y)
{
	return sqrt(sqr(a.x - x) + sqr(a.y - y));
}

double EPS = 1e-9;

double check(double d1,double d2)
{
	if(d1 < EPS) return ceil(d2);
	if(d2 < EPS) return ceil(d1);
	if(ceil(d1) - d1 > ceil(d2) - d2) return ceil(d1);
	if(ceil(d1) - d1 == ceil(d2) - d2) return min(ceil(d1),ceil(d2));
	return ceil(d2);
}

int main()
{
	string in;
	cin>>in;
	int len = in.length();
	int tot = 0;
	int mul = 1;
	for(int a=len-1;a>=0;a--)
	{
		if(in[a]>='0' && in[a]<='9')
		{
			int val = in[a]-'0';
			tot = tot + mul * val;
			mul*=10;
		}
		else break;
	}
	for(int a=0;a<tot;a++) cin>>p[a].x>>p[a].y>>p[a].v;
	cin>>in;
	int tc = 0;
	double A,B,C,D,E,F,G;
	while(cin>>A)
	{
		cin>>B>>C>>D>>E>>F>>G;
		tc++;
		
		double d = sqrt(B*B - 4*A*C);
		double d1 = (-B + d)/(2*A);
		double d2 = (-B - d)/(2*A);
		double lo = check(d1,d2);
		double px = D*lo + E;
		double py = F*lo + G;
		int val = 0;
		if(px < 0 || py < 0) val = 2;
		for(int a=0;a<tot;a++)
		{
			if(dist(p[a],px,py) <= lo * p[a].v) val = max(val,1);
		}
		char ans[150];
		if(val == 2) strcpy(ans,"foul");
		else if(val == 1) strcpy(ans,"caught");
		else strcpy(ans,"safe");
		printf("Ball %d was %s at (%.0lf,%.0lf)\n",tc,ans,px,py);
	}
}
