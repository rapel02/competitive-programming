#include<bits/stdc++.h>
using namespace std;

vector<int> vec[1500][15];

int num[1500],prime[1500];
int k = 0;
int n,t;

bool cmp(int a,int b)
{
	stringstream ss1,ss2;
	ss1 << a;
	ss2 << b;
	return ss1.str() < ss2.str();
}

void precom()
{
	for(int a=2;a<300;a++)
	{
		if(num[a]==0)
		{
			prime[k++] = a;
			if(a!=2) prime[k++] = a;
			for(int b=a*a;b<300;b+=a) num[b] = a;
		}
	}
	sort(prime,prime + k,cmp);
}

int vval[15];

bool vis[130][1003][16];

bool dfs(int idx,int ssum,int kk)
{
	if(ssum>n) return false;
	if(idx==k) return false;
	if(ssum==n)
	{
		if(kk==t) return true;
		return false;
	}
	if(vis[idx][ssum][kk]==true) return false;
	vis[idx][ssum][kk] = true;
	vval[kk] = prime[idx];
	if(dfs(idx+1,ssum+prime[idx],kk+1)==true)
	{
		return true;
	}
	if(dfs(idx+1,ssum,kk)==true) return true;
	return false;
}

int main()
{
	precom();
	int tc = 0;
	while(scanf("%d %d",&n,&t)!=EOF)
	{
		tc++;
		if(n+t==0) break;
		printf("CASE %d:\n",tc);
		memset(vis,false,sizeof(vis));
		if(dfs(0,0,0)==true)
		{
			for(int a=0;a<t;a++)
			{
				if(a!=0) printf("+");
				printf("%d",vval[a]);
			}
			printf("\n");
		}
		else printf("No Solution.\n");
	}
}
