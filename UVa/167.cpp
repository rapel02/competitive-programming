#include<bits/stdc++.h>
using namespace std;

int arr[10][10];
int rem[10];
bool vis[10];
int tot = 0;

bool check(int pos,int col)
{
	for(int a=0;a<pos;a++)
	{
		if(rem[a] - a == col - pos) return false;
		if(rem[a] + a == pos + col) return false;
	}
	return true;
}

void put(int pos)
{
	if(pos==8)
	{
		int temp = 0;
		for(int a=0;a<8;a++)
		{
			temp = temp + arr[a][rem[a]];
		}
		tot = max(tot,temp);
	}
	else
	{
		for(int a=0;a<8;a++)
		{
			if(vis[a]==false && check(pos,a))
			{
				rem[pos] = a;
				vis[a] = true;
				put(pos+1);
				vis[a] = false;
			}
		}
	}
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		for(int a=0;a<8;a++)
		{
			for(int b=0;b<8;b++) scanf("%d",&arr[a][b]);
		}
		tot = 0;
		put(0);
		printf("%5d\n",tot);
	}
}
