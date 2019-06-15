#include<bits/stdc++.h>
using namespace std;

struct Rectangle{
	int x1,x2;
	int y1,y2;
}p[3];

void swap(Rectangle a,Rectangle b)
{
	Rectangle c;
	c = a;
	a = b;
	b = c;
}

bool Overlap(Rectangle a,Rectangle b)
{
//	printf("%d %d %d %d\n",a.x2,b.x1,a.y2,b.y1);
	if(a.x2 < b.x1 || b.x2 < a.x1) return false;
	if(a.y2 < b.y1 || b.y2 < a.y1) return false;
	return true;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	for(int tw=1;tw<=tc;tw++)
	{
		long long area,area1,area2,area3;
		area = 10000;
		area2 = 0;
		for(int a=0;a<2;a++)
		{
			scanf("%d %d %d %d",&p[a].x1,&p[a].y1,&p[a].x2,&p[a].y2);
		//	printf("%d %d %d %d\n",p[a].x1,p[a].y1 , p[a].x2 , p[a].y2);
			area2 += (p[a].x2 - p[a].x1 ) * (p[a].y2 - p[a].y1);
		}
	//	if(p[0].x1 < p[1].x1) swap(p[0],p[1]);
		area2 = abs(area2);
		int lx = max(p[0].x1, p[1].x1);
		int mx = min(p[0].x2 , p[1].x2);
		int ly = max(p[0].y1 , p[1].y1);
		int my = min(p[0].y2 , p[1].y2);
		if(Overlap(p[0],p[1])==true)
		{
		//	printf("%d\n",10);
			area3 = (mx - lx) * (my - ly);
			area2 -= 2 * area3;
		}
		else area3 = 0;
		area1 = area - area3 -area2;
		printf("Night %d: %lld %lld %lld\n",tw,area3,area2,area1);
	}
}
