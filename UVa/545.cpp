#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		int k = 0;
		double v = 1;
		for(int a=0;a<n;a++)
		{
			if(v < 2)
			{
				v*=10;
				k++;
			}
			v/=2.0;
		}
		printf("2^-%d = %.3lfE-%d\n",n,floor(v*1000 + 0.5)/1000.00,k);
	}
}
