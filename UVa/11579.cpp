#include<bits/stdc++.h>
using namespace std;

double arr[15000];

double triangle(double a,double b,double c)
{
	double s = (a+b+c)/2.0;
	return sqrt(s*(s-a)) * sqrt((s-b) * (s-c));
}

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		for(int a=0;a<n;a++) cin>>arr[a];
		sort(arr,arr+n);
		double ans = 0.00;
		for(int a=0;a<n-2;a++)
		{
			if(arr[a] + arr[a+1] > arr[a+2]) ans = max(ans,triangle(arr[a],arr[a+1],arr[a+2]));
		}
		printf("%.2lf\n",ans);
	}
}
