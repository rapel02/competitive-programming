#include<bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

double torad(double x)
{
	return x*PI/180.0;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		double l,w,t;
		cin>>l>>w>>t;
		t = torad(t);
		double A = l / cos(t);
		double x = tan(t) * l;
		double s = fmod(x,(2*w));
		if(s > w) s = 2*w - s;
		double B = sqrt(l*l + s*s);
		printf("%.3lf\n",A/B);
	}
}
