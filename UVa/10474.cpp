#include<bits/stdc++.h>
using namespace std;

int pos[10005];
int kel[1000005];

int main()
{
	int m,q;
	int qq=0;
	scanf("%d %d",&m,&q);
	while(m!=0 && q!=0)
	{
		qq++;
		for(int a=0;a<m;a++)
			scanf("%d",&kel[a]);
		sort(kel,kel+m);
		memset(pos,0,sizeof(pos));
		for(int a=0;a<m;a++)
		{
			if(pos[kel[a]]==0)
			{
				pos[kel[a]]=a+1;
			}
		}
		printf("CASE# %d:\n",qq);
		for(int a=0;a<q;a++)
		{
			int num;
			scanf("%d",&num);
			if(pos[num]==0)
				printf("%d not found\n",num);
			else printf("%d found at %d\n",num,pos[num]);
		}
		scanf("%d %d",&m,&q);
	}
}
