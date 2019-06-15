#include<bits/stdc++.h>
using namespace std;


double c[5000];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double a0,an1,a1;
		int n;
		scanf("%d",&n);
		scanf("%lf %lf",&a0,&an1);
		for(int a=1;a<=n;a++)
			scanf("%lf",&c[a]);
		a1 = n * a0 + an1;
		double temp=0;
		for(int a=1;a<=n;a++)
		temp=temp + a*c[n-a+1];
		a1=a1-2*temp;
		a1=a1/(n+1);
		printf("%.2lf\n",a1);
		if(t!=0) printf("\n");
	}
}
