#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		int a = (n+m)/2;
		int b = (n-m)/2;
		if(n<m ||(n+m)%2!=0) printf("impossible\n");
		else printf("%d %d\n",a,b);
	}
}
