#include<bits/stdc++.h>
using namespace std;

char input[55];
char call[105];
int no[55];
int main()
{
	int test,len;
	scanf("%d",&test);
	while(test!=0)
	{
		int pos=0,val;
		char spc;
		memset(no,-1,sizeof(no));
		char ans[55][55];
		getchar();
		for(int a=0;a<test;a++)
		{
			//printf("%d\n",a);
			scanf("%s%c%s",input,&spc,call);
			getchar();
			len=strlen(call);
			if(a==0) 
			{
				pos=len-1;
				val=pos;
			}
			else
			{
				int ne=pos;
				int ada=0;
				for(int b=0;b<len;b++)
				{
					ne=(ne+1)%test;
					if(no[ne]==0) ada++;
				}
				//printf("%d\n",ada);
				while(ada!=0)
				{
					ne=(ne+1)%test;
					if(no[ne]==-1) ada--;
					//printf("%d %d\n",ne,ada);
				}
				pos=ne;
			}
			no[pos]=0;
			//printf("pos now: %d\n",pos);
			int len2=strlen(input);
			for(int b=0;b<len2;b++)
			{
				ans[pos][b]=input[b];
			}
		}
		for(int a=0;a<test;a++)
		{
			int ww=strlen(ans[a]);
			for(int e=0;e<ww;e++)
			{
				char b=ans[a][e];
				if((b>='A' && b<='Z') ||((b>='0' && b<='9')))
				printf("%c",b);
			}
			
			if(a!=test-1) printf(" ");
			else printf("\n");
		}
		printf("\n");
		scanf("%d",&test);
	}
}
