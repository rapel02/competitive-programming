#include<bits/stdc++.h>
using namespace std;

int tre[5005][2];
int root;
int arr[200005];
int idx;

int path(int st)
{
	if(st==-1) return 0;
	arr[idx]=st;
	idx++;
	for(int a=0;a<2;a++)
	{
		if(tre[st][a]==-1) return 0;
		path(tre[st][a]);
		arr[idx]=st;
		idx++;
	}
}

int main()
{
	int t,hub;
	while(1)
	{
		scanf("%d",&hub);
		if(hub==0) break;
		memset(tre,-1,sizeof(tre));
		root=-1;
		int to,fro;
		for(int a=0;a<hub-1;a++)
		{
			scanf("%d %d",&to,&fro);
			if(root==-1) root=to;
			if(fro==root) root=to;
			if(tre[to][0]==-1) tre[to][0]=fro;
			else tre[to][1]=fro;
		}
		idx=0;
		path(root);
		for(int a=0;a<idx;a++)
		{
			printf("%d ",arr[a]);
		}
		int que;
		scanf("%d",&que);
		for(int a=0;a<que;a++)
		{
			int il=-1,ir=-1;
			scanf("%d %d",&to,&fro);
			int b=0;
			while(1)
			{
				if(arr[b]==to) il=b;
				if(arr[b]==fro) ir=b;
				if(il!=-1 && ir!=-1) break;
				b++;
			}
			if((il+ir)%2==0) printf("The fleas meet at %d.\n",arr[(il+ir)/2]);
			else
			{
				int aa=arr[(il+ir)/2];
				int bb=arr[(il+ir)/2+1];
				if(aa>bb) swap(aa,bb);
				printf("The fleas jump forever between %d and %d.\n",aa,bb);
			}
		}
	}
}
