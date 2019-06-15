#include<bits/stdc++.h>
#define pi acos(-1)
using namespace std;

int main()
{
	double l,n,c;
	while(scanf("%lf %lf %lf",&l,&n,&c)!=EOF)
	{
		if(n<0 || l<0 || c<0) break;
		double lo = 0;
		double hi = pi;
		double ll = (1 + n*c)*l;
		double rem = 0,r,mid;
		for(int a=0;a<200;a++)
		{
			mid = (lo+hi)/2.00;
			r = l/2.0/sin(mid);
			if(r*mid*2 <=ll) lo = mid;
			else hi = mid;
		}
		printf("%.3lf\n",r - r*cos(mid));
	}
}
