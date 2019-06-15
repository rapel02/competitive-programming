#include<bits/stdc++.h>
#define pi acos(-1)
using namespace std;

long double angle_to_rad(long double deg)
{
	return pi/180.00 * deg;
}

int main()
{
	long double r,n;
	while(scanf("%Lf %Lf",&r,&n)!=EOF)
	{
		long double deg = 360.0 / n;
		long double len = sqrt(2*r*r - 2*r*r*cos(angle_to_rad(deg)));
		long double s = (r+r+len)/2;
		long double area = sqrt(s*(s-r)*(s-r) * (s-len));
		printf("%.3Lf\n",area*n);
	}
}
