#include<bits/stdc++.h>
#define PI  acos(-1)
using namespace std;

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		double l,r,w,cr;
		scanf("%lf",&l);
		w = l/10 * 6;
		r = l/10 * 2;
		cr = r*r* PI;
		printf("%.2lf %.2lf\n",cr,w*l-cr);
	}
}
