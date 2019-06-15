#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;

int step[15000];

queue<pair<pair<int,int>,pair<int,int> > > q;

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		memset(step,-1,sizeof(step));
		int st = 0, fn = 0;
		for(int a=0;a<4;a++)
		{
			int t;
			cin>>t;
			st = st*10 + t;
		}
		for(int a=0;a<4;a++)
		{
			int t;
			cin>>t;
			fn = fn*10 + t;
		}
		int n;
		cin>>n;
		for(int a=0;a<n;a++)
		{
			int alert = 0;
			for(int b=0;b<4;b++)
			{
				int t;
				cin>>t;
				alert = alert*10 + t;
			}
			step[alert] = -2;
		}
		if(step[st]==-2)
		{
			printf("-1\n");
			continue;
		}
		step[st] = 0;
		int ans = -1;
		int p3 = st%10;
		st/=10;
		int p2 = st%10;
		st/=10;
		int p1 = st%10;
		st/=10;
		int p0 = st;
		q.push(mp(mp(p0,p1),mp(p2,p3)));
		while(!q.empty())
		{
			int arr[5],barr[5];
			arr[0] = q.front().ff.ff;
			arr[1] = q.front().ff.ss;
			arr[2] = q.front().ss.ff;
			arr[3] = q.front().ss.ss;
			int noo = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
			//printf("%d %d\n",noo,step[noo]);
			q.pop();
			for(int a=0;a<8;a++)
			{
				for(int b=0;b<4;b++) barr[b] = arr[b];
				if(a%2==0) barr[a/2] = (arr[a/2] + 1)%10;
				if(a%2==1) barr[a/2] = (arr[a/2] + 9)%10;
				int num = 0;
				for(int b=0;b<4;b++) num = num*10 + barr[b];
				if(step[num]!=-1) continue;
				step[num] = step[noo] + 1;
				q.push(mp(mp(barr[0],barr[1]),mp(barr[2],barr[3])));
			}
		}
		printf("%d\n",max(-1,step[fn]));
	}
}
