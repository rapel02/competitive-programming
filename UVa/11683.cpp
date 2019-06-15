#include<bits/stdc++.h>
using namespace std;

int h[100005];

int main()
{
	int mahe,fak;
	int ma;
	scanf("%d %d",&mahe,&fak);
	while(mahe && fak !=0)
	{
		int tot=0;
		for(int a=0;a<fak;a++)
		{
			scanf("%d",&h[a]);
			if(a==0) ma=h[a];
			else
			{
				if(h[a]>ma)
				{
					tot+=(h[a]-ma);
					if(h[a]>ma) ma=h[a];
					//8lo=0;
				}
				else if(h[a]<h[a-1])
				{
					 tot+=(h[a-1]-h[a]);
				}
			}
			//printf("%d\n",tot);
		}
		tot+=(mahe-ma);
		printf("%d\n",tot);
		scanf("%d",&mahe);
		if(mahe==0) break;
		scanf("%d",&fak);
	}
}
