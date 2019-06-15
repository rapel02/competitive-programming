#include<bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

int main()
{
	int tc;
	cin>>tc;
	bool ff = true;
	while(tc--)
	{
		if(!ff) printf("\n");
		ff = false;
		double B,H;
		cin>>B>>H;
		double tot = 0;
		double r = 0;
		while(1)
		{
			double area = B*H/2.0;
			double L = sqrt((H*H + B*B/4.0));
			double kll = (L+L+B)/2.0;
			double r = area / kll;
			if(r < 0.000001) break;
			tot += 2 * PI * r;
			B = B*(H-2*r)/H;
			H-= 2* r;
		}
		printf("%13.6lf\n",tot);
	}
}
