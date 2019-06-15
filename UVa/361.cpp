#include<bits/stdc++.h>
using namespace std;

struct Point{
	long long x,y;
}cops[350],robs[350],hcops[350],hrobs[350];

int co,ro;

bool cmp(Point a,Point b)
{
	if(a.x < b.x) return true;
	if(a.x == b.x) return a.y < b.y;
	return false;
}

long long cross(Point a,Point b,Point c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

void hull(Point fr[],Point hull[],int &k,int n)
{
	k = 0;
	for(int a=0;a<n;a++)
	{
		while(k>=2 && cross(hull[k-2],hull[k-1],fr[a]) <= 0) k--;
		hull[k++] = fr[a];
	}
	int t = k+1;
	for(int a=n-2;a>=0;a--)
	{
		while(k>=t && cross(hull[k-2],hull[k-1],fr[a]) <= 0) k--;
		hull[k++] = fr[a]; 
	}
	k--;
}

char ans[20];

bool passing(Point a,Point b,Point c)
{
	if((c.y - a.y) * (b.x - a.x) != (c.x - a.x) * (b.y - a.y)) return false;
	long long l = min(a.x,b.x);
	long long r = max(a.x,b.x);
	long long ly = min(a.y,b.y);
	long long ry = max(a.y,b.y);
	if(l <= c.x && c.x <=r && ly <= c.y && c.y <= ry) return true;
	return false;
}

bool isinside(Point hull[],int n,Point p)
{
	if(n == 0) return false;
	if(n == 1)
	{
		if(hull[0].x == p.x && hull[0].y == p.y) return true;
		return false;
	}
	if(n == 2)
	{
		for(int a=0;a<n;a++)
		{
			if(passing(hull[a],hull[(a+1)%n],p)==true) return true;
		}
		return false;
	}
	if(n >= 3)
	{
		for(int a=0;a<n;a++)
		{
			if(cross(p,hull[a],hull[(a+1)%n]) < 0 ) return false;
			if(cross(p,hull[a],hull[(a+1)%n]) == 0 && passing(hull[a],hull[(a+1)%n],p)==false) return false;
		}
		return true;
	}
}

int main()
{
	int c,r,o;
	int tc = 0;
	while(cin>>c>>r>>o)
	{
		if(c==0 && r==0 && o==0) break;
		tc++;
		co = 0,ro = 0;
		for(int a=0;a<c;a++) cin>>cops[a].x>>cops[a].y;
		for(int a=0;a<r;a++) cin>>robs[a].x>>robs[a].y;
		sort(cops,cops+c,cmp);
		sort(robs,robs+r,cmp);
		hull(cops,hcops,co,c);
		hull(robs,hrobs,ro,r);
		printf("Data set %d:\n",tc);
		for(int a=0;a<o;a++)
		{
			Point temp;
			cin>>temp.x>>temp.y;
			bool cps = false;
			bool rps = false;
			if(isinside(hcops,co,temp)==true) cps = true;
			if(isinside(hrobs,ro,temp)==true) rps = true;
			//printf("%s %s\n",(cps==true)?"yes":"no",(rps==true)?"yes":"no");
			if(c > 2 && cps==true) strcpy(ans,"safe");
			else if(r > 2 && rps==true) strcpy(ans,"robbed");
			else strcpy(ans,"neither");
			printf("     Citizen at (%lld,%lld) is %s.\n",temp.x,temp.y,ans);
		}
		printf("\n");
	}
}
