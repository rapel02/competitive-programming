#include<bits/stdc++.h>
using namespace std;

double A1[2500],A2[2500];
const double INF = 1e+17;

int main()
{
	double P = 10000;
	int n,m;
	while(cin>>n>>m)
	{
		double mv = 0;
		for(int a=0;a<n;a++){
			A1[a] = (1.0 * a) * P / (1.0 * n);
		}
		for(int a=0;a<n+m;a++){
			A2[a] = (1.0 * a) * P / (1.0 * (n+m));
		}
		for(int a=0;a<n;a++)
		{
			double pos = INF;
			for(int b=0;b<n+m;b++)
			{
				pos = min(pos,fabs(A1[a]-A2[b]));
			}
			mv += pos;
		}
		printf("%.5lf\n",mv);
	}
}
