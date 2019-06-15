#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	bool isf = true;
	while(cin>>n)
	{
		if(!isf) printf("\n");
		isf = false;
		int D = 2*n - 1;
		int r = D/2;
		double ra = (1.0 * D)/2.0;
		int ans = 0;
		int cont = 0;
		int pre = 0;
		for(int a = -r;a<=0;a++)
		{
			double yt = sqrt(ra*ra - a*a);
			double yb = -yt;
			if(a < 0)
			{
				cont += floor(yt) - ceil(yb);
				ans += ceil(yt) - floor(yb);
				ans -= pre;
				pre = floor(yt) - ceil(yb);
			}
			else
			{
				ans += ceil(yt) - floor(yb);
				ans -= pre;
			}
		}
		cont *= 2;
		ans *= 2;
		printf("In the case n = %d, %d cells contain segments of the circle.\n",n,ans);
		printf("There are %d cells completely contained in the circle.\n",cont);
	}
}
