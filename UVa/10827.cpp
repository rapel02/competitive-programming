#include<bits/stdc++.h>
using namespace std;

int pref[155][155];
int arr[155][155];

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		int lg = -2000000000;
		scanf("%d",&n);
		for(int a=0;a<n;a++) for(int b=0;b<n;b++) 
		{
			scanf("%d",&arr[a][b]);
			lg = max(lg,arr[a][b]);
		}
		for(int a=0;a<2*n;a++)
		{
			for(int b=0;b<2*n;b++)
			{
				pref[a][b] = arr[a%n][b%n];
				if(b!=0) pref[a][b] += pref[a][b-1];
				if(a!=0) pref[a][b] += pref[a-1][b];
				if(a!=0 && b!=0) pref[a][b] -= pref[a-1][b-1];
			}
		}
		int maxi = lg;
		for(int a=1;a<=n;a++)
		{
			for(int b=1;b<=n;b++)
			{
				for(int c=a-1;c<2*n;c++)
				{
					for(int d=b-1;d<2*n;d++)
					{
						int temp = pref[c][d];
						if(c!=0) temp -= pref[c-a][d];
						if(d!=0) temp -= pref[c][d-b];
						if(c!=0 && d!=0) temp += pref[c-a][d-b];
						maxi = max(maxi,temp);
					}
				}
			}
		}
		printf("%d\n",maxi);
	}
}
