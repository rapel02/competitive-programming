#include<bits/stdc++.h>
using namespace std;

double arr[1500];

int main()
{
	while(1)
	{
		double tot = 0;
		int n;
		scanf("%d",&n);
		if(n==0) break;
		double ans = 0;
		for(int a=0;a<n;a++)
		{
			scanf("%lf",&arr[a]);
			tot+=arr[a];
		}
		tot = tot*100;
		int w = (int)tot;
		if(w%4!=0) w = w - w%4;
		tot = (double) w;
		double each = 1.0*tot /(100*n);
		
		for(int a=0;a<n;a++)
		{
			if(arr[a]<each) ans += each - arr[a];
		}
		printf("$%.2lf\n",ans);
	}
}
