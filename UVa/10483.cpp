#include<bits/stdc++.h>
using namespace std;

int main()
{
	double t,f;
	scanf("%lf %lf",&t,&f);
	while(t<=f)
	{
		double a = 0.01;
		bool ans = false;
		while(a<=t)
		{
			double b = a + 0.01;
			if(a*b>t) break;
			while(b<=t)
			{
				double c = b + 0.01;
				if(a*b*c>t) break;
				while(c<=t)
				{
					//printf("%lf %lf %lf\n",a,b,c);
					if(a*b*c>=t) break;
					if(a+b+c==a*b*c)
					{
						ans = true;
						printf("%.2lf = %.2lf + %.2lf + %.2lf = %.2lf * %.2lf * %.2lf\n",t,a,b,c,a,b,c);
						break;
					}
					c+=0.01;
				}
				if(ans) break;
				b+=0.01;
			}
			if(ans) break;
			a+=0.01;
		}
		t+=0.01;
	}
}
