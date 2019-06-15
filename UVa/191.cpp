#include<bits/stdc++.h>
#define EPS 1e-9
using namespace std;

struct Point{
	double x;
	double y;
}p,q,r[5];

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&p.x,&p.y,&q.x,&q.y,&r[0].x,&r[0].y,&r[2].x,&r[2].y);	
		r[1].x = r[2].x;
		r[1].y = r[0].y;
		r[3].x = r[0].x;
		r[3].y = r[2].y;
		if(p.x>q.x) swap(p,q);
		double diffx = p.x - q.x;
		double diffy = p.y - q.y;
		bool ada=false;
		for(int a=0;a<4;a++)
		{
			//cout<<r[a].x<<" "<<r[a].y<<endl;
			if(diffx*(r[a].y - r[(a+1)%4].y)==diffy*(r[a].x-r[(a+1%4)].x)) continue;
			double psx = (r[(a+1)%4].y - q.y) * (r[a].x - r[(a+1)%4].x) * (p.x - q.x) + q.x * (r[a].x - r[(a+1)%4].x) * (p.y - q.y) - r[(a+1)%4].x * (r[a].y - r[(a+1)%4].y) * (p.x - q.x); 
			psx = psx / ((r[a].x - r[(a+1)%4].x)*(p.y - q.y) - (r[a].y - r[(a+1)%4].y)*(p.x - q.x));
			double psy = q.y  +(p.y - q.y ) *(psx - q.x) / (p.x - q.x);
			//cout<<psx<<endl;
			double lo = r[a].x ;
			double hi = r[(a+1)%4].x;
			double loy = r[a].y;
			double hiy = r[(a+1)%4].y;
			if(lo<hi) swap(lo,hi);
			//cout<<p.x<<" "<<q.x<<" "<<lo<<" "<<hi<<" "<<psx<<endl;
			if(psx - p.x>EPS && q.x-psx>EPS && psx - lo >EPS  && hi-psx > EPS && psy -p.y>EPS && q.y - psy > EPS && psy - loy > EPS  && hiy - psy > EPS) ada = true;
			
		}
		if(ada==true) cout<<"T"<<endl;
		else cout<<"F"<<endl;
	}
}
