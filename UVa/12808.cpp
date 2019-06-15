#include<bits/stdc++.h>
using namespace std;

const double g = 9.81;

int check(double p,double l,double d)
{
	if(d - 0.5 > p) return 0;
	if(d + 0.5 >= p) return 1;
	if(d + l - 0.5 > p) return 2;
	if(d + l + 0.5 >= p) return 1;
	return 0;
}

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		double L,D,H,V;
		cin>>L>>D>>H>>V;
		L/=1000.0;
		D/=1000.0;
		H/=1000.0;
		V/=1000.0;
		double t = sqrt(2.0 * H / g);
		double d = V * t;
		int ans = check(d,L,D);
		if(ans == 0) printf("FLOOR\n");
		else if(ans == 1) printf("EDGE\n");
		else printf("POOL\n");
	}
}
