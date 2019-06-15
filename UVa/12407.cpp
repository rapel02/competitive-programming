#include<bits/stdc++.h>
#define EPS 1e-9
using namespace std;

double w,h;
int n;

double arr[1500];


double sqr(double a)
{
	return a*a;
}

double find(int idx,double m)
{
	return arr[idx]*m*100.00 / sqrt(1 - sqr(m*arr[idx]));
}

int main()
{
	int ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		scanf("%d %lf",&n,&h);
		double hi = 1e+9;
		for(int a=0;a<n;a++)
		{
			scanf("%lf",&arr[a]);
			hi = min(hi,1.0/arr[a]);
		}
		//hi = 1e+9;
		double lo = -hi;
		for(int a=1;a<=100;a++)
		{
			double mid = (lo+hi)/2.00;
		//	cout<<lo<<" "<<mid<<" "<<hi<<endl;
			double tot = 0;
			for(int b=0;b<n;b++) tot = tot + find(b,mid);
		//	cout<<tot<<endl;
			if(tot <h) lo = mid;
			else hi = mid;
		}
		double ans = 0;
		//cout<<hi<<endl;
		for(int a=0;a<n;a++) 
		{
			ans += sqrt(10000 + sqr(find(a,lo)) ) / arr[a];
			//cout<<find(a,lo)<<endl;
		}	
		printf("Case %d: %.8lf\n",tc,ans);
	}
}
