#include<bits/stdc++.h>
#define EPS 1e-9
using namespace std;

double x[55000],y[55000],z[55000];

int tot[50];


double sqr(double x)
{
	return x*x;
}

double dist(int a,int b)
{
	return sqrt(sqr(x[b] - x[a]) + sqr(y[b] - y[a]) + sqr(z[b] - z[a]));
}

double dmin(double a,double b)
{
	if(a-b<EPS) return a;
	else return b;
}

int main()
{
	int k =0;
	while(1)
	{
		scanf("%lf %lf %lf",&x[k],&y[k],&z[k]);
		if(x[k]==0.000 && y[k]==0.000 && z[k]==0.000)
		{
			for(int a=0;a<k;a++)
			{
				double di = 1e+12;
				for(int b=0;b<k;b++)
				{
					if(a==b) continue;
					double dii = dist(a,b);
					di = dmin(di,dii);
			//		printf("%d %d %lf %d\n",a,b,di,(int)floor(di));
				}
				if(di-10<-EPS) tot[(int)floor(di)]++;
			}
			for(int a=0;a<10;a++)
			{
	//			if(a!=0) printf(" ");
				printf("%4d",tot[a]);
			}
			printf("\n");
			break;
		}
		k++;
	}
}
