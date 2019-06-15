#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int m,n,k;
		scanf("%d %d %d",&m,&n,&k);
		int tot =0;
		m = m+n;
		n = 0;
		while(m>=k)
		{
			tot+=m/k;
			m=m/k+m%k;
		}
		printf("%d\n",tot);
	}
}
