#include<bits/stdc++.h>
using namespace std;

int main()
{
	double n,p;
	while(scanf("%lf %lf",&n,&p)!=EOF)
	{
		double ans = pow(p,1/n);
		printf("%.0lf\n",ans);
	}
}
