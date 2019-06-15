#include<bits/stdc++.h>
using namespace std;

int field[505][505];

int main()
{
	while(1)
	{
		int ans=0;
		int w,h,n,x1,x2,y1,y2;
		scanf("%d %d %d",&w,&h,&n);
		if(w==0 && h==0 && n==0) break;
		memset(field,0,sizeof(field));
		for(int a=0;a<n;a++)
		{
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			if(x1>x2) swap(x1,x2);
			if(y1>y2) swap(y1,y2);
			for(int b=x1;b<=x2;b++)
			{
				for(int c=y1;c<=y2;c++)
				{
					field[b][c]=-1;
				}
			}
		}
		for(int a=1;a<=w;a++)
		{
			for(int b=1;b<=h;b++)
			if(field[a][b]==0) ans++;
		}
		if(ans==0) printf("There is no empty spots.\n");
		else if(ans==1) printf("There is one empty spot.\n");
		else printf("There are %d empty spots.\n",ans);
	}
}
