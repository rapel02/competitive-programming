#include<bits/stdc++.h>
using namespace std;

struct Point{
	int x,y;
};

struct Rectangle{
	Point ll,rr;
}p[2];

bool isintersect(Rectangle p1,Rectangle p2)
{
	if(p1.ll.x >= p2.rr.x || p2.ll.x >= p1.rr.x) return false;
	if(p1.ll.y >= p2.rr.y || p2.ll.y >= p1.rr.y) return false;
	return true;
}

int main()
{
	int tc;
	cin>>tc;
	while(tc--){
		for(int a=0;a<2;a++) cin>>p[a].ll.x>>p[a].ll.y>>p[a].rr.x>>p[a].rr.y;
		if(isintersect(p[0],p[1]) == true) printf("%d %d %d %d\n",max(p[1].ll.x,p[0].ll.x),max(p[1].ll.y,p[0].ll.y),min(p[1].rr.x,p[0].rr.x),min(p[1].rr.y,p[0].rr.y));
		else printf("No Overlap\n");
		if(tc!=0) printf("\n");
	}
}
