#include<bits/stdc++.h>
using namespace std;

long long pref[150][150],arr[150][150];

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n,q;
		scanf("%d",&n);
		for(int a=1;a<=n;a++) for(int b=1;b<=n;b++) arr[a][b] = 1;
		scanf("%d",&q);
		for(int a=1;a<=q;a++)
		{
			int la,lb,lc,ld;
			scanf("%d %d %d %d",&la,&lb,&lc,&ld);
			for(int b=la;b<=lc;b++)
			{
				for(int c=lb;c<=ld;c++) arr[b][c] = 0;
			}
		}
		for(int a=1;a<=n;a++)
		{
			for(int b=1;b<=n;b++)
				pref[a][b] = pref[a][b-1] + arr[a][b];
		}
		int maxi = 0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				int temp = 0;
				for(int k=1;k<=n;k++)
				{
					if(pref[k][j] - pref[k][i-1]!=j-i+1) temp = 0;
					else temp += j-i+1;
					maxi = max(maxi,temp);
				}
			}
		}
		printf("%d\n",maxi);
	}
}
