#include<bits/stdc++.h>
using namespace std;


int main()
{
	int ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		int n,k,x;
		scanf("%d %d %d",&n,&k,&x);
		int total = n*(n+1)/2;
		int cc = (x + x + k -1)*k/2;
		printf("Case %d: %d\n",tc,total-cc);
	}
}
