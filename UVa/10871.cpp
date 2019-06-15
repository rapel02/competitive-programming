#include<bits/stdc++.h>
using namespace std;

int arr[15000];

bool check(int b)
{
	for(int a=2;a*a<=b;a++) if(b%a==0) return false;
	return true;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		for(int a=0;a<n;a++) scanf("%d",&arr[a]);
		bool ada = false;
		for(int a=1;a<n;a++)
		{
			int tot = 0;
			for(int b=0;b<n;b++)
			{
				tot+=arr[b];
				if(b>=a)
				{
					if(b!=a) tot-=arr[b-a-1];
					if(check(tot))
					{
						printf("Shortest primed subsequence is length %d:",a+1);
						for(int c=b-a;c<=b;c++) printf(" %d",arr[c]);
						printf("\n");
						ada = true;
						break;
					}
				}
			}
			if(ada) break;
		}
		if(!ada) printf("This sequence is anti-primed.\n");
	}
}
