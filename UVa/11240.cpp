#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		int tot = 0;
		int now;
		for(int a=0;a<n;a++)
		{
			int tmp;
			scanf("%d",&tmp);
			if(tot==0)
			{
				tot++;
				now = tmp;
			}
			else if(tot%2==1)
			{
				if(now>tmp)
				{
					tot++;
				}
				now = tmp;
			}
			else if(tot%2==0)
			{
				if(now<tmp)
				{
					tot++;
				}
				now = tmp;
			}
		}
		printf("%d\n",tot);
	}
}