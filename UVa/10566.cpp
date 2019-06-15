#include<bits/stdc++.h>
#define eps 1e-8
using namespace std;

int main()
{
	double x,y,c;
	while(scanf("%lf %lf %lf",&x,&y,&c)!=EOF)
	{
		double rem=0;
		double lo=0;
		double hi=min(x,y);
		for(int a=1;a<=200;a++)
		{
			double mid=(lo+hi)/2;
			double v=c*mid/sqrt(x*x-mid*mid);
			double w=c*mid/sqrt(y*y-mid*mid);
			if(v+w-mid>eps)
			{
				hi=mid;
				rem=mid;
			}
			else lo=mid;
			//printf("%lf %lf %lf\n",lo,hi,v+w-mid);
		}
		printf("%.3lf\n",rem);
	}
}
