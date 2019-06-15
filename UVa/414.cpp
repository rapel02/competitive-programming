#include<bits/stdc++.h>
using namespace std;

char in[150];
int nn[150];

int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		int mini = 0;
		memset(nn,0,sizeof(nn));
		for(int a=0;a<n;a++)
		{
			scanf("%s",in);
			int len = strlen(in);
			for(int b=0;b<len;b++) if(in[b]=='X') nn[a]++;
			if(a==0) mini = nn[a];
			mini = max(mini,nn[a]);
		}
		int ans = 0;
		for(int a=0;a<n;a++) ans+=mini -nn[a];
		printf("%d\n",ans);
	}
}
