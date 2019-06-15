#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;

pair<double,double> p[1500];

int main()
{
	int n;
	int tc =0 ;
	while(scanf("%d",&n),n)
	{
		tc++;
		for(int a=0;a<n;a++) 
		{
			scanf("%lf %lf",&p[a].ff,&p[a].ss);
			p[a].ff*=60;
			p[a].ss*=60;
		}
		sort(p,p+n);
		double ans = -100;
		do
		{
			double lo = 0;
			double hi = 86400;
			for(int a=0;a<=80;a++)
			{
				double mid = (lo+hi)/2.0;
				double ll = -1.000;
				double all = true;
				for(int b=0;b<n;b++)
				{
					if(ll<p[b].ff) ll = p[b].ff + mid;
					else if(ll > p[b].ss)
					{
						all = false;
						break;
					}
					else ll = ll + mid;
				}
				if(all==false) hi = mid;
				else lo = mid, ans = max(ans,mid);
			}
			
		}while(next_permutation(p,p+n));
		//cout<<ans<<endl;
		int hh = ans/60;
		double mm = ans - hh*60;
		printf("Case %d: %d:%02.0lf\n",tc,hh,round(mm));
	}
}
