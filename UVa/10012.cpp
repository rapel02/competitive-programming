#include<bits/stdc++.h>
using namespace std;

double arr[15];
double p[15];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		double MAXI = 0;
		for(int a=0;a<n;a++) 
		{
			cin>>arr[a];
			MAXI += 2*arr[a];
		}
		sort(arr,arr+n);
		do
		{
			double v = arr[0];
			p[0] = arr[0];
			for(int a=1;a<n;a++)
			{
				p[a] = arr[a];
				for(int b=0;b<a;b++)
				{
					double T = fabs(arr[a] - arr[b]);
					double S = arr[a] + arr[b];
					double dx = sqrt(S*S - T*T);
					p[a] = max(p[a],p[b] + dx);
				}
			}
			double V = 0;
			for(int a=0;a<n;a++) V = max(V,p[a] + arr[a]);
			MAXI = min(MAXI,V);
		}while(next_permutation(arr,arr+n));
		if(MAXI == 1e+16) MAXI = 0;
		printf("%.3lf\n",MAXI);
	}
}
