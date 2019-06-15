#include<bits/stdc++.h>
using namespace std;

int dp[15000];

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int tot = 0;
		dp[0] = 0;
		int c,n1,n5,n10;
		scanf("%d %d %d %d",&c,&n1,&n5,&n10);
		while(c!=0)
		{
			if(n10>=1) n1+=2,n10--,tot++;
			else if(n5>=2) n5-=2,n1+=2,tot+=2;
			else if(n5>=1)
			{
				n5-=1;
				n1-=3;
				tot+=4;
			}
			else n1-=8,tot+=8;
			c--;
		}
		printf("%d\n",tot);
	}
}
