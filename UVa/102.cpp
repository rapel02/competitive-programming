#include<bits/stdc++.h>
using namespace std;

int arr[10];

int main()
{
	while(scanf("%d",&arr[0])!=EOF)
	{
		for(int a=1;a<9;a++)
		{
			scanf("%d",&arr[a]);
		}
		swap(arr[1],arr[2]);
		swap(arr[4],arr[5]);
		swap(arr[7],arr[8]);
		int mer[] = {0,1,2};
		long long res = 1000000000000000;
		int ans[3];
		do
		{
			long long tot = 0;
			for(int a=0;a<3;a++)
			{
				for(int b=mer[a];b<9;b+=3)
				{
					if(b/3!=a) tot+=arr[b];
				}
			}
			if(tot<res)
			{
				res = tot;
				for(int a=0;a<3;a++) ans[a] = mer[a];
			}
		}while(next_permutation(mer,mer+3));
		for(int a=0;a<3;a++)
		{
			if(ans[a]==0) printf("B");
			if(ans[a]==1) printf("C");
			if(ans[a]==2) printf("G");
		}
		printf(" %lld\n",res);
	}
}
