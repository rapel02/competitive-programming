#include<bits/stdc++.h>
#define PI  acos(-1)
using namespace std;

int main()
{
	double l;
	while(scanf("%lf",&l)!=EOF)
	{
		double l1,l2,l3,nl2,nnl2;
		nl2 = 4*(l*l*PI/4 - l*l/2);
		l1 = 4*(l*l - l*l*sqrt(3)/4 - PI * l * l * 1/6 );
		nnl2 = l*l - l1;
		l3 = nl2 - nnl2;
		l2 = nnl2 - l3;
		printf("%.3lf %.3lf %.3lf\n",l3,l2,l1);
	}
}
