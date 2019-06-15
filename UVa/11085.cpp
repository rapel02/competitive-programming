#include<bits/stdc++.h>
using namespace std;

int arr[10];
int rem[10];
int tot = 0;
bool vis[10];

bool check(int pos,int col)
{
	for(int a=0;a<pos;a++)
	{
		if(rem[a] - a == col - pos) return false;
		if(rem[a] + a == col + pos) return false;
	}
	return true;
}

void put(int pos)
{
	if(pos==8)
	{
		int tp = 0;
		for(int a=0;a<8;a++)
		{
			if(arr[a]!=rem[a]+1) tp++;
		}
		tot = min(tot,tp);	
	}
	else
	{
		for(int a=0;a<8;a++)
		{
			if(vis[a]==false && check(pos,a))
			{
				vis[a]=true;
				rem[pos] = a;
				put(pos+1);
				vis[a]=false;
			}
		}
	}
}

int main()
{
	int k = 0;
	while(scanf("%d",&arr[0])!=EOF)
	{
		k++;
		for(int a=1;a<8;a++) scanf("%d",&arr[a]);
		tot = 100;
		put(0);
		printf("Case %d: %d\n",k,tot);
	}
}
