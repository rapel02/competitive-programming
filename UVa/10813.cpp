#include<bits/stdc++.h>
using namespace std;

int stt[5][5];
int hub[76];
int ww[5][5];

void check(int num)
{
	for(int a=0;a<5;a++)
	{
		for(int b=0;b<5;b++)
		{
			if(ww[a][b]==num)
			{
				//printf("%d %d %d\n",num,a,b);
				stt[a][b] = 1;
				return ;
			}
		}
	}
}

bool count()
{
	int sum=0;
	for(int a=0;a<5;a++)
	{
		sum=0;
		for(int b=0;b<5;b++)
		{
			sum+=stt[a][b];
		}
		if(sum==5) return true;
	}
	for(int a=0;a<5;a++)
	{
		sum=0;
		for(int b=0;b<5;b++)
		{
			sum+=stt[b][a];
		}
		if(sum==5) return true;
	}
	sum=0;
	for(int a=0;a<5;a++) sum+=stt[a][a];
	if(sum==5) return true;
	sum=0;
	for(int a=0;a<5;a++) sum+=stt[a][4-a];
	if(sum==5) return true;
	return false;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(hub,0,sizeof(hub));
		memset(stt,0,sizeof(stt));
		for(int a=0;a<5;a++)
		{
			for(int b=0;b<5;b++)
			{
				int w;
				if(a==2 &&b==2) continue;
				scanf("%d",&ww[a][b]);
				hub[ww[a][b]] = 1;
			}
		}
		stt[2][2] = 1;
		bool win =false;
		int ans =1e+7;
		for(int a=0;a<75;a++)
		{
			int num;
			scanf("%d",&num);
			if(hub[num]==1&&win==false)
			{
				check(num);
				if(count()==true) 
				{
					win = true ; 
					ans = min(ans,a+1);
				}
			}
		}
		printf("BINGO after %d numbers announced\n",ans);
	}

}
