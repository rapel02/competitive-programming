#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(b%a!=0) printf("-1\n");
		else printf("%d %d\n",a,b);
	}
}
