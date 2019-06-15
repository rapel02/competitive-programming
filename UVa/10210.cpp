#include<bits/stdc++.h>
using namespace std;

double sqr(double x)
{
	return x*x;
}

const double PI = acos(-1);

double toRad(double x)
{
	return x * PI / 180.0;
}

int main()
{
	double x,x2,y,y2,M,N;
	while(cin>>x>>y>>x2>>y2>>M>>N)
	{
		double d = sqrt(sqr(x - x2) + sqr(y - y2));
		printf("%.3lf\n",d * (tan(toRad(90 - M)) + tan(toRad(90 - N))));
	}
}
