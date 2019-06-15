#include<bits/stdc++.h>
using namespace std;

int main()
{
	double n;
	while(scanf("%lf",&n)!=EOF)
	{
		double tot = n-1;
		tot += ceil(log2(n))-1;
		printf("%.0lf\n",tot);
	}
}
