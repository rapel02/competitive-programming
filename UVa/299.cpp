#include<bits/stdc++.h>
using namespace std;

int arr[150];
int bit[150];
int n ;
void update(int pos,int num)
{
	for(int a=pos;a<=n;a+= a &(-a)) bit[a] += num;
}

int query(int pos)
{
	int tot = 0;
	for(int a=pos;a>0; a-=a&(-a)) tot+=bit[a];
	return tot;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d",&n);
		memset(bit,0,sizeof(bit));
		for(int a=0;a<n;a++)
		{
			bit[a+1] = 0;
			scanf("%d",&arr[a]);
		}
		int tot = 0;
		for(int a=0;a<n;a++)
		{
			tot = tot+ arr[a]-1 - query(arr[a]-1);
			update(arr[a],1);
		}
		printf("Optimal train swapping takes %d swaps.\n",tot);
	}
}
