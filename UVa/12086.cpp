#include<bits/stdc++.h>
using namespace std;

long long arr[200005];
char in[105];
int r;
long long num[200005];

int build(int idx,int num)
{
	//printf("%d %d\n",idx,num);
	if(idx>r) return 0;
	else
	{
		arr[idx]+=num;
		build(idx+(idx&(-idx)),num);
	}
}

long long count(int idx)
{
	//printf("%d\n",idx);
	if(idx==0) return 0;
	else return arr[idx]+count(idx-(idx&(-idx)));
}

int main()
{
	int k=1;		
	scanf("%d",&r);getchar();
	do
	{
		if(r==0) break;
		memset(arr,0,sizeof(arr));
		for(int a=1;a<=r;a++)
		{
			scanf("%d",&num[a]); getchar();
			build(a,num[a]);
		}
		printf("Case %d:\n",k);
		while(1)
		{
			scanf("%[^\n]",in); getchar();
			int len=strlen(in);
			if(len==3 && in[0]=='E') break;
			else
			{
				bool sp1=false;
				int n1=0,n2=0;
				for(int a=2;a<len;a++)
				{
					if(in[a]==' ') sp1=true;
					else if(sp1==false)
					{
						n1=n1*10+(in[a]-'0');
					}
					else n2=n2*10+(in[a]-'0');
				}
				//printf("%d %d %c\n",n1,n2,in[0]);
				if(in[0]=='M')
				{
					printf("%lld\n",count(n2)-count(n1-1));
				}
				else if(in[0]=='S')
				{
					build(n1,n2-num[n1]);
					num[n1]=n2;
				}
			}
		}		
		scanf("%d",&r);getchar();
		if(r!=0)printf("\n");
		k++;
	}while(r!=0);
}
