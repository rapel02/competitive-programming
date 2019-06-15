#include<bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

double toRad(double x)
{
	return x*PI/180.0;
}

double backToLength(int n,double A,double X)
{
	A = A/(1.0 * n);
	double R = sqrt(2*A/sin(X));
	return sqrt(R*R + R*R - 2*R*R*cos(X));
}

int main()
{
	int tc = 0;
	double A;
	int n;
	while(cin>>n>>A)
	{
		if(n < 3) break;
		tc++;
		double X = toRad(360.0/n);
		A = backToLength(n,A,X);
		double R = sqrt( (A*A) / (2.0 - 2.0*cos(X)) );
		double r = sqrt(R*R - A/2*A/2);
		double Area1 = PI * r * r;
		double Area2 = R*R*sin(X)/2.0 * n;
		double Area3 = PI * R * R;
		printf("Case %d: %.5lf %.5lf\n",tc,Area3 - Area2,Area2 - Area1);
	}
}
