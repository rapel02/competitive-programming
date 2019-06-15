#include <bits/stdc++.h>
using namespace std;

double arr[15];

int main()
{
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0) break;
		for(int a=0;a<=n;a++)
			scanf("%lf",&arr[a]);
		arr[0]=-arr[0];	
		int ct = 0;
		double ans = -1e+9;
		double lo = -1;
		double hi = 15;
		for(int a=0;a<10000;a++)
		{
			double mid = (lo+hi)/2;
			double ir = 1+mid;
			double c = 1;
			double tot = 0;
			if(ir==0) break;
			for(int a=1;a<=n;a++)
			{
				c*=ir;
				tot += arr[a]/c;
			}
			//printf("%lf %lf\n",mid,tot);
			if(tot>arr[0]) lo = mid;
			else if(tot<arr[0])
			{
				ans = mid;
				hi = mid;
			}
		}
		printf("%.2lf\n",ans);
	}
}

0101101
32 8 4 1
01101
1 4 16