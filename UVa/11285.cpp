#include<bits/stdc++.h>
using namespace std;

int day[370][2];
double rate[370];
int n;

int main()
{
	while(scanf("%d",&n),n)
	{
		for(int a=1;a<=n;a++) scanf("%lf",&rate[a]);
		memset(day,0,sizeof(day));
		day[0][0] = 100000;
		day[0][1] = 0;
		for(int a=1;a<=n;a++)
		{
			double t1 = day[a-1][1] * 0.97 *rate[a];
			double t2 = day[a-1][0] * 0.97 / rate[a];
			day[a][0] = max(day[a-1][0],(int)t1);
			day[a][1] = max(day[a-1][1],(int)t2); 
		}
		printf("%d.%02d\n",day[n][0]/100,day[n][0]%100);
	}
}
