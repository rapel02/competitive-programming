#include<bits/stdc++.h>
using namespace std;


int n,k;
struct Point{
	int x,y;
}p[150000],hull[15000];

string in;
string name;

bool cmp(Point a,Point b)
{
	if(a.x > b.x) return true;
	if(a.x == b.x) return a.y < b.y;
	return false;
}

double cross(Point a,Point b,Point c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

void CHULL()
{
	k = 0;
	sort(p,p+n,cmp);
	int i,j;
	for(i=1,j = 0;i<n;i++) if(p[j].x != p[i].x || p[j].y !=p[i].y) p[++j] = p[i];
	n = j+1;
	for(int a=0;a<n;a++)
	{
		while(k>=2 && cross(hull[k-2],hull[k-1],p[a]) < 0 ) k--;
		hull[k++] = p[a];
	}
	int t = k+1;
	for(int a=n-2;a>=0;a--)
	{
		while(k>=t && cross(hull[k-2],hull[k-1],p[a]) < 0) k--;
		hull[k++] = p[a];
	}
	k--;
}


int main()
{
	bool ff = true;
	while(cin>>in)
	{
		if(in=="S" || in=="END")
		{
			if(ff==false)
			{
				CHULL();
				int len = name.length();
				bool issp = false;
				for(int a=1;a<len;a++) 
				{
					if(name[a]==' ' && issp==false) continue;
					issp = true;
					printf("%c",name[a]);
				}
				printf(" convex hull:\n");
				for(int a=0;a<k;a++)
				{
					printf(" (%d,%d)",hull[a].x,hull[a].y);
				}
				printf("\n");
				n = 0;
			}
			if(in=="S") getline(cin,name);
			ff = false;
			if(in=="END") break;
		}
		else
		{
			int t;
			cin>>t;
			for(int a=0;a<t;a++)
			{
				cin>>p[n].x>>p[n].y;
				n++;
			}
		}
	}
}
