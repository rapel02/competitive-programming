#include<bits/stdc++.h>
using namespace std;

int skew(double a,double b)
{
	if(b < 1) return 0;
	int H = 1 + (int) ((b-1)/ (sqrt(3.0)) * 2);
	int od = H / 2;
	int ev = H - od;
	int v = (int) a;
	return (int)a * ev + od * (int)(a-0.5);
}

int main()
{
	double a,b;
	while(cin>>a>>b)
	{
		int grid = (int) a * (int) b;
		int s = max(skew(a,b),skew(b,a));
		if(s > grid) printf("%d skew\n",s);
		else printf("%d grid\n",grid);
	}
}
