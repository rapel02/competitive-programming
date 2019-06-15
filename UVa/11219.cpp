#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t); getchar();
	for(int a=1;a<=t;a++)
	{
		int d1,d2,y1,y2,m1,m2,ans=0;
		char t1,t2;
		scanf("%d%c%d%c%d",&d1,&t1,&m1,&t2,&y1); getchar();
		scanf("%d%c%d%c%d",&d2,&t1,&m2,&t2,&y2); getchar();
		printf("Case #%d: ",a);
		if(y2>y1)
		{
			printf("Invalid birth date\n");
		}
		else if(y2==y1 &&m2>m1) printf("Invalid birth date\n");
		else if(y2==y1 &&m2==m1 &&d2>d1) printf("Invalid birth date\n");
		else
		{
			while(1)
			{
				y2++;ans++;
				if(ans>135) break;
				if(y2>y1)
				{
					break;
				}
				else if(y2==y1 &&m2>m1) break;
				else if(y2==y1 &&m2==m1 &&d2>d1) break;
			}
			--ans;
			if(ans>130) printf("Check birth date\n");
			else printf("%d\n",ans);
		}
	}
}
