#include<bits/stdc++.h>
using namespace std;

double arr[15000];

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		double tot = 0;
		for(int a=0;a<n;a++)
		{
			scanf("%lf",&arr[a]);
			tot+=arr[a];
		}
		tot/=n;
		int k = 0;
		for(int a=0;a<n;a++)
		{
			if(arr[a]>tot) k++;
		}
		printf("%.3lf%%\n",100.0*k/n);
	}
}
