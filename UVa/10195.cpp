#include<bits/stdc++.h>
using namespace std;

int main()
{
	double a,b,c;
	while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF)
	{
		double s = (a+b+c) / 2;
		double L = sqrt(s*(s-a)*(s-b)*(s-c));
		double ans = 0;
		if(a+b+c!=0)ans = L/s;
		printf("The radius of the round table is: %.3lf\n",ans);
	}
}
