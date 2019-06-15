#include<bits/stdc++.h>
using namespace std;

const double pi = acos(-1);

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n,f;
		scanf("%d %d",&n,&f);
		double tot = 0;
		for(int a=0;a<n;a++)
		{
			double r;
			scanf("%lf",&r);
			tot += r*r*pi;
		}
		printf("%.4lf\n",tot/((f+1)*1.0));
	}
}
