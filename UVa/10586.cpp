#include<bits/stdc++.h>
using namespace std;

stack<int> q;

int deg[10005];

int main()
{
	int n,k;
	while(1)
	{
		scanf("%d %d",&n,&k);
		if(n==-1 && k==-1) break;
		for(int a=0;a<=n;a++)
			scanf("%d",&deg[a]);
		for(int a=n;a>=k;a--)
		{
			deg[a-k] = deg[a-k]-deg[a];
			deg[a] = 0;
		}
		for(int a=min(k-1,n);a>=0;a--)
		{
			q.push(deg[a]);
		}
		if(k==0) printf("0");
		while(!q.empty())
		{
			printf("%d",q.top());
			q.pop();
			if(q.size()!=0) printf(" ");
		}
		printf("\n");
	}
}
