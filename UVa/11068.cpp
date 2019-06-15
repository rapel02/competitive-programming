#include<bits/stdc++.h>
using namespace std;


struct line{
	double a,b,c;
}l[2];

bool isParallel(line a,line b)
{
	if(a.a * b.b == a.b * b.a) return true;
	return false;
}

const double EPS = 1e-9;

int main()
{
	while(1)
	{
		bool isz = true;
		for(int a=0;a<2;a++)
		{
			cin>>l[a].a>>l[a].b>>l[a].c;
			if(l[a].a != 0 || l[a].b !=0 || l[a].c !=0) isz = false;
		}
		if(isz == true) break;
		if(isParallel(l[0],l[1]) == true) printf("No fixed point exists.\n");
		else
		{
			double D = l[0].a * l[1].b - l[0].b * l[1].a;
			double D1 = l[0].c * l[1].b - l[0].b * l[1].c;
			double D2 = l[0].a * l[1].c - l[0].c * l[1].a;
			double x = D1/D;
			double y = D2/D;
			printf("The fixed point is at %.2lf %.2lf.\n",x + EPS,y + EPS);
		}
	}
}
