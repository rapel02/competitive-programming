#include<bits/stdc++.h>
using namespace std;

int vis[10][10];

queue<pair<int,int> > q;

int rr[]={2,-2,1,-1};
int cc[]={2,-2,1,-1};

int main()
{
	char r1,r2,temp;
	int c1,c2;
	while(scanf("%c%d%c%c%d",&r1,&c1,&temp,&r2,&c2)!=EOF)
	{
		getchar();
		memset(vis,-1,sizeof(vis));
		q.push(make_pair(r1-'a'+1,c1));
		vis[r1-'a'+1][c1] = 0;
		while(!q.empty())
		{
			int r = q.front().first;
			int c = q.front().second;
			int val = vis[r][c];
			q.pop();
			for(int a=0;a<4;a++)
			{
				for(int b=0;b<4;b++)
				{
					if(abs(rr[a])==abs(cc[b])) continue;
					int pr = r + rr[a];
					int pc = c + cc[b];
					if(pr<1 || pc<1 || pr>8 || pc>8) continue;
					if(vis[pr][pc]==-1)
					{
						vis[pr][pc] = val+1;
						q.push(make_pair(pr,pc));
					}
				}
			}
		}
		printf("To get from %c%d to %c%d takes %d knight moves.\n",r1,c1,r2,c2,vis[r2-'a'+1][c2]);
	}
}
