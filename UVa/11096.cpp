#include<bits/stdc++.h>
using namespace std;

struct Point{
	double x,y;
}p[150],hull[150];

int k = 0;
int n;

bool cmp(Point a,Point b){
	if(a.x < b.x) return true;
	if(a.x == b.x) return a.y < b.y;
	return false;
}

double cross(Point a,Point b,Point c){
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double sqr(double x){
	return x*x;
}

double dist(Point a,Point b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

void CHULL()
{
	sort(p,p+n,cmp);
	k = 0;
	for(int a=0;a<n;a++)
	{
		while(k>=2 && cross(hull[k-2],hull[k-1],p[a]) <=0 )k--;
		hull[k++] = p[a];
	}
	int t = k+1;
	for(int a=n-2;a>=0;a--)
	{
		while(k>=t && cross(hull[k-2],hull[k-1],p[a]) <=0) k--;
		hull[k++] = p[a];
	}
	k--;
}


int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		double l;
		cin>>l>>n;
		for(int a=0;a<n;a++) cin>>p[a].x>>p[a].y;
		CHULL();
		double tot = 0;
		for(int a=0;a<k;a++)
		{
			tot += dist(hull[a],hull[(a+1)%k]);
		}
		printf("%.5lf\n",max(tot,l));
	}
}
