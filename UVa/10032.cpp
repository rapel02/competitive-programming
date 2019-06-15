#include<bits/stdc++.h>
#define INF 1e+9
using namespace std;

int ssum[45005];
int mmax[45005],mmin[45005];
int arr[105];
int n;

int main()
{
	int tc;
	scanf("%d",&tc);
	bool ff = true;
	while(tc--)
	{
		if(ff==false) printf("\n");
		ff = false;
		memset(ssum,0,sizeof(ssum));
		scanf("%d",&n);
		ssum[0] = 1<<0;
		int tot = 0;
		for(int a=1;a<=n;a++)
		{
			scanf("%d",&arr[a]);
			tot+=arr[a];
		}
		for(int a=1;a<=n;a++)
		{
			for(int b=tot;b>=arr[a];b--)
			{
				if(ssum[b-arr[a]])
				{
					ssum[b] |= (ssum[b-arr[a]] <<1);
				}
			}
		}
		//for(int a=0;a<=tot;a++) printf("%d: %d\n",a,ssum[a]);
		int rem = 0;
		long long bit = n/2;
		bit = 1LL<<bit;
		int mid = tot/2;
		for(int i=mid, j= mid;i>=0 && j<=tot;i--,j++)
		{
			if((ssum[i] & bit))
			{
				rem = i;
				break;
			}
			if((ssum[j] & bit))
			{
				rem = j;
				break;
			}
		}
		printf("%d %d\n",min(rem,tot-rem),max(rem,tot-rem));
	}
}
