#include<bits/stdc++.h>
using namespace std;

struct point{
	double x,y;
}p[5];

bool issame(point a,point b)
{
	if(a.x == b.x && a.y == b.y) return true;
	return false;
}

int main()
{
	while(cin>>p[0].x>>p[0].y)
	{
		for(int a=1;a<=3;a++) cin>>p[a].x>>p[a].y;
		if(issame(p[0],p[2])) ;
		else if(issame(p[0],p[3])) swap(p[2],p[3]);
		else if(issame(p[1],p[2])) swap(p[0],p[1]);
		else swap(p[0],p[1]),swap(p[2],p[3]);
		point diff;
		diff.x = p[1].x - p[0].x;
		diff.y = p[1].y - p[0].y;
		diff.x = p[3].x + diff.x;
		diff.y = p[3].y + diff.y;
		printf("%.3lf %.3lf\n",diff.x,diff.y);
	}
}
