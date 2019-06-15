#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int w;
		scanf("%d",&w);
		if(w%3==2 || w%3==0) printf("YES\n");
		else printf("NO\n");
	}
}
