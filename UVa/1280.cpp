#include<bits/stdc++.h>
using namespace std;


const double PI = acos(-1);

double A[55],ANS[55];

double value(double xhi,double xlo,int p)
{
	double le = 1;
	double ri = 1;
	for(int a=1;a<=p;a++) le*=xhi,ri*=xlo;
	return le - ri;
}

int n;

double Integrate(double xlo,double xhi)
{
	double tot = 0;
	for(int a=0;a<=2*n;a++)
	{
		tot = tot + (ANS[a]/(a+1) * value(xhi,xlo,a+1))*PI;
	}
	return tot;
}

int main()
{
	int tc = 0;
	while(scanf("%d",&n)!=EOF)
	{
		tc++;
		for(int a=0;a<=n;a++) scanf("%lf",&A[a]);
		memset(ANS,0,sizeof(ANS));
		for(int a=0;a<=n;a++)
		{
			for(int b=0;b<=n;b++)
			{
				ANS[a+b] += A[a] * A[b];
			}
		}
		double xlo, xhi, ve;
		scanf("%lf %lf %lf",&xlo,&xhi,&ve);
		double tot = Integrate(xlo,xhi);
		double xloo = xlo;
		printf("Case %d: %.2lf\n",tc,tot);
		if(tot < ve) printf("insufficient volume\n");
		else
		{
			double lo = xlo;
			bool valid = true;
			bool ff = true;
			int tot = 0;
			while(valid == true)
			{
				valid = false;
				double hi = xhi;
				double rem = 0;
				for(int a=0;a<150;a++)
				{
					double mid = (lo + hi)/2.0;
					if(Integrate(xlo,mid) >= ve)
					{
						rem = mid;
						hi = mid;
						valid = true;
					}
					else lo = mid;
				}
				if(valid==true) 
				{
					if(ff==false) printf(" ");
					printf("%.2lf",rem-xloo);
					tot++;
					ff = false;
					xlo = rem;
				}
				if(tot == 8) valid = false;
			}
			printf("\n");
		}
	}
}
