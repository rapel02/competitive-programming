#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		printf("%d\n",min((n-1) + n*(m-1),(m-1) + m*(n-1)));
	}
}
