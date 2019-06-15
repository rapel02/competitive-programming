#include<bits/stdc++.h>
#define pi acos(-1)
using namespace std;

int main()
{
	int tc = 0;
	double r,c;
	while(scanf("%lf : %lf",&r,&c)!=EOF)
	{
		tc++;
		double lo1 = 0;
		double hi1 = 500;
		for(int a=0;a<=100;a++)
		{
			double mid1 = (lo1+hi1)/2.0;
			double wi = r*mid1;
			double he = c*mid1;
			//printf("%lf %lf %lf\n",lo1,mid1,hi1);
			bool large = false;
			double lo2 = 0;
			double hi2 = pi/2;
			bool ada = false;
//			for(int b=0;b<=100;b++)
//			{
//				double mid2 = (lo2 + hi2)/2.0;
//				double r = he / 2 / sin(mid2);
//				double L = r*mid2;
//				double tot = wi*2 + L*2;
//				if(tot >= 400)
//				{
//					ada = true;
//					hi2 = mid2;
//				}
//				else lo2 = mid2;
//			}
//			printf("%lf %s\n",lo2,(ada==true)?"yes":"no");	
			double r = sqrt((wi*wi)/4 + he*he/4);
			double ang = acos((2*r*r - he*he) / (2*r*r));
			double L = r * ang;
			if(2 * L + 2 * wi >= 400) ada = true;
			if(ada==true) hi1 = mid1;
			else lo1 = mid1;
		}
		printf("Case %d: %.5lf %.5lf\n",tc,r * lo1,c * lo1);
	}
}
