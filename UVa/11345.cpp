#include<bits/stdc++.h>
using namespace std;

struct Point{
	int x,y;
};

struct Rectangle{
	Point ll,rr;
}mn,temp;

int main(){
	int ntc;
	cin>>ntc;
	for(int tc=1;tc<=ntc;tc++)
	{
		int n;
		cin>>n;
		mn.ll.x = -10000;
		mn.ll.y = -10000;
		mn.rr.x = 10000;
		mn.rr.y = 10000;
		for(int a=0;a<n;a++)
		{
			cin>>temp.ll.x>>temp.ll.y>>temp.rr.x>>temp.rr.y;
			mn.ll.x = max(mn.ll.x,temp.ll.x);
			mn.ll.y = max(mn.ll.y,temp.ll.y);
			mn.rr.x = min(mn.rr.x,temp.rr.x);
			mn.rr.y = min(mn.rr.y,temp.rr.y);
		}
		int area = (mn.rr.x - mn.ll.x) * (mn.rr.y - mn.ll.y);
		if(mn.rr.x < mn.ll.x) area = 0;
		printf("Case %d: %d\n",tc,max(area,0));
	}
}
