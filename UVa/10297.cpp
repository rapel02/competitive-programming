#include<bits/stdc++.h>
#define PI acos(-1)
#define EPS 1e-9
using namespace std;

int main()
{
	int D,V;
	while(1)
	{
		scanf("%d %d",&D,&V);
		if(D+V==0) break;
		double x = 1.0* D*D*D / 4.000 - 1.0* V / PI;
		double d = 0;
		double lo = 0;
		double hi = D;
		for(int a=1;a<=1000;a++)
		{
			double mid = (lo+hi)/2.0;
			double tot = (mid *mid *mid / 6 + 1.0*D*D*D / 12 );
			if(tot-x<-EPS)
			{
				lo = mid;
				d = mid;
			}
			else hi = mid;
		}
		printf("%.3lf\n",d);
	}
}
