#include<bits/stdc++.h>
using namespace std;


struct Point{
	double x,y;
}p[15000],ans[15005];

int n,k;

bool cmp(Point a,Point b)
{
	if(a.y<b.y) return true;
	if(a.y ==b.y ) return a.x<b.x;
	return false;
}

double cross(Point a,Point b,Point c)
{
	return (b.x - a.x) *(c.y - a.y) - (b.y - a.y) *(c.x - a.x);
}

void CHULL(){
	sort(p,p+n,cmp);
	k = 0;
	for(int a=0;a<n;a++)
	{
		while(k>=2 && (cross(ans[k-2],ans[k-1],p[a])<=0) ) k--;
		ans[k++] = p[a];
	}
	for(int a=n-2,t=k+1;a>=0;a--)
	{
		while(k>=t && ( cross(ans[k-2],ans[k-1],p[a])<=0) ) k--;
		ans[k++] = p[a];
	}
}

int main()
{
	int tc,tp;
	scanf("%d",&tc);
	printf("%d\n",tc);
	for(int w=1;w<=tc;w++)
	{
		scanf("%d",&n);
		for(int a = 0;a<n;a++)
			scanf("%lf %lf",&p[a].x,&p[a].y);
		CHULL();
	//	k--;
		printf("%d\n",k);
		for(int a=0;a<k;a++)
			printf("%.0lf %.0lf\n",ans[a].x,ans[a].y);
		if(w!=tc) 
		{
			scanf("%d",&tp);
			printf("-1\n");
		}
	}
}
