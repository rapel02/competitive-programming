#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k = 0;
	int n ;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0) break;
		k++;
		printf("Case %d: %d\n",k,(int)(ceil(log2((double)n))));
	}
}
