#include<bits/stdc++.h>
using namespace std;

int hub[150][150];
int ans[150];

int n;

bool traverse(int pos,int s)
{
	for(int a=1;a<=s;a++)
	{
		if(pos + n >=n*n) return false;
		if(hub[pos][pos + n] == 0) return false;
		pos += n;
	}
	for(int a=1;a<=s;a++)
	{
		if(pos/n != (pos+1)/n || pos + 1 >= n*n) return false;
		if(hub[pos][pos + 1] == 0) return false;
		pos += 1;
	}
	for(int a=1;a<=s;a++)
	{
		if(pos - n < 0) return false;
		if(hub[pos][pos - n] == 0) return false;
		pos -= n;
	}
	for(int a=1;a<=s;a++)
	{
		if(pos/n != (pos - 1)/n || pos - 1 < 0) return false;
		if(hub[pos][pos - 1] == 0) return false;
		pos -= 1;
	}
	return true;
}


int main()
{
	int tc = 0;
	while(cin>>n)
	{
		if(tc!=0)
			printf("\n**********************************\n\n");
		tc++;
		memset(hub,0,sizeof(hub));
		int q;
		cin>>q;
		for(int a=0;a<q;a++)
		{
			string s;
			int x,y;
			cin>>s>>x>>y;
			x--;
			y--;
			if(s=="H")
			{
				hub[x*n + y][x*n + y + 1] = 1;
				hub[x*n + y + 1][x*n + y] = 1; 
			}
			else
			{
				hub[y*n + x][(y + 1)*n + x] = 1;
				hub[(y + 1)*n + x][y*n + x] = 1;
			}
		}
		memset(ans,0,sizeof(ans));
		printf("Problem #%d\n\n",tc);
		bool ada = false;
		for(int a=1;a<n;a++)
		{
			for(int b=0;b<n*n;b++)
			{
				if(traverse(b,a) == true) ans[a]++;
			}
		}
		for(int a=1;a<n;a++)
		{
			if(ans[a]!=0)
			{
				printf("%d square (s) of size %d\n",ans[a],a);
				ada = true;
			}
		}
		if(ada==false) printf("No completed squares can be found.\n");
	}
}
