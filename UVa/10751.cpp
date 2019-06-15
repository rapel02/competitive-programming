#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		double tot = n*n;
		double red= (n-2)*(n-2);
		if(n<2) printf("0.000\n");
		else
		{
			printf("%.3lf\n",tot-red+red*sqrt(2));
		}
		if(t!=0) printf("\n");
	}
}
