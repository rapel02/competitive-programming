#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--){
		double d,l;
		cin>>d>>l;
		const double PI = acos(-1);
		double s = (d+l+l)/2.0;
		double area = 2*sqrt(s*(s-d) * (s-l) * (s-l));
		double ang = 2*acos((d*d)/(2*l*d));
		double vt =  l * l * ang;
		printf("%.3lf\n",vt - area);
	}
}
