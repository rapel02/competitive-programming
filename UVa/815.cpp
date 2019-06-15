#include<bits/stdc++.h>
using namespace std;

double arr[55][55];

int main()
{
	int m,n;
	int tc = 0;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		if(m+n==0) break;
		tc++;
		double mini = 0;
		for(int a=0;a<m;a++)
		{
			for(int b=0;b<n;b++)
			{
				scanf("%lf",&arr[a][b]);
				if(a==0 && b==0) mini = arr[a][b];
				mini = min(mini,arr[a][b]);
			}
		}
		double T;
		scanf("%lf",&T);
		double lo = mini;
		double hi = 1e+9;
		int gl = 0;
		for(int a=0;a<50;a++)
		{
			gl = 0;
			double mid = (lo + hi)/2.0;
			double tot = 0;
			for(int b=0;b<m;b++)
			{
				for(int c=0;c<n;c++)
				{
					if(mid > arr[b][c]) tot += (mid - arr[b][c]) * 100.0,gl++;
				}
			}
			if(tot >= T) hi = mid;
			else lo = mid;
		}
		printf("Region %d\n",tc);
		printf("Water level is %.2lf meters.\n",lo);
		printf("%.2lf percent of the region is under water.\n\n",(100.0 * gl)/(m*n*1.0));
	}
}
