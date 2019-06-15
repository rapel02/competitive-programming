#include<bits/stdc++.h>
using namespace std;

char stt[1005];

double dmax(double a,double b)
{
	if(a>b) return a;
	return b;
}

int main(){
	while(1)
	{
		double start,gas;
		double total = 0;
		double ans = 0;
		double pos_leak = 0;
		int ct = 0;
		scanf("%lf %[^0-9] %lf",&start,stt,&gas);
		if(start+gas==0) break;
		while(1)
		{
			double in;
			scanf("%lf %[^0-9\n]",&in,stt);
			if(strcmp(stt,"Fuel consumption ")==0)
			{
				total=total + (in-start)*gas/100;
				start = in;
				scanf("%lf",&gas);
			}
			else if(strcmp(stt,"Goal")==0)
			{
				total = total + (in - start)*gas/100;
				total = total + (in - pos_leak)*ct;
				ans = dmax(ans,total);
				break;
			}
			else if(strcmp(stt,"Gas station")==0)
			{
				total = total + (in-start)*gas/100;
				total = total + (in-pos_leak)*ct;
				ans = dmax(ans,total);
				start = in;
				total = 0;
				pos_leak = in;
			}
			else if(strcmp(stt,"Mechanic")==0)
			{
				total = total + (in - pos_leak)*ct;
				ct=0;
			}
			else
			{
				total = total + (in - pos_leak)*ct;
				ct++;
				pos_leak = in;
			}
		}
		printf("%.3lf\n",ans);
	}
}
