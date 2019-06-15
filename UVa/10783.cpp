#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	scanf("%d",&tc);
	for(int a=1;a<=tc;a++)
	{
		double c,d;
		scanf("%lf %lf",&c,&d);
		int ans = ceil((d)/2) *ceil((d)/2) - floor((c)/2)*floor((c)/2);
		printf("Case %d: %d\n",a,ans);
	}
}
