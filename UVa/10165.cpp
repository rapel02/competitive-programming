#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		int ans = 0;
		for(int a=0;a<n;a++)
		{
			int t;
			scanf("%d",&t);
			ans = ans^t;
		}
		if(ans==0) printf("No\n");
		else printf("Yes\n");
	}
}
