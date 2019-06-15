#include<bits/stdc++.h>
using namespace std;

bool vis[7000];
int num[7000];
int op[7000];

char in[100005];

bool dp[50][50][7000];

int k,l;

void compute(int pos,int bracket,int val)
{
	if(pos==k)
	{
		vis[val+3000] = true;
		return ;
	}
	//printf("%d %d\n",num[pos],op[pos]);
	if(dp[pos][bracket][val+3000]==true) return ;
	dp[pos][bracket][val+3000] = true;
	int nval = val + num[pos] * op[pos] * ((bracket%2==0)?1:-1);
	//printf("%d %d %d %d\n",pos,bracket,val,nval);
	if(op[pos]==-1) compute(pos+1,bracket+1,nval);
	if(bracket>0) compute(pos+1,bracket-1,nval);
	compute(pos+1,bracket,nval);
}

int main()
{
	while(scanf("%[^\n]",in)!=EOF)
	{
		getchar();
		memset(vis,false,sizeof(vis));
		memset(dp,false,sizeof(dp));
		k = 0;
		l = 0;
		int len = strlen(in);
		bool cp = false;
		int tp = 0;
		op[0] = 1;
		for(int a=0;a<len;a++)
		{
			if(in[a]>='0' && in[a]<='9')
			{
				cp = true;
				tp = tp*10 + (in[a]-'0');
			}
			else if(cp==true)
			{
				num[k] = tp;
				tp = 0;
				cp = false;
				k++;
			}
			if(in[a]=='+' || in[a]=='-')
			{
				op[k] = (in[a]=='+')?1:-1;
			}
		}
		num[k] = tp;
		tp = 0;
		cp = false;
		k++;
		l++;
		compute(0,0,0);
		int tot = 0 ;
		for(int a=0;a<7000;a++)
			if(vis[a]==true) tot++;
		printf("%d\n",tot);
	}
}
