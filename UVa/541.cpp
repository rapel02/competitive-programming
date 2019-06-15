#include<bits/stdc++.h>
using namespace std;

int field[100][100];
int row[100],col[100];
int main()
{
	int test;
	scanf("%d",&test);
	while(test!=0)
	{
		memset(row,0,sizeof(row));
		memset(col,0,sizeof(col));
		for(int a=1;a<=test;a++)
		{
			for(int b=1;b<=test;b++)
			{
				scanf("%d",&field[a][b]);
				row[a]+=field[a][b];
				col[b]+=field[a][b];
			}
		}
		bool ada=false,adar=false,adac=false;
		bool check=false;
		int remr,remc;
		for(int a=1;a<=test;a++)
		{
			if(row[a]%2!=0)
			{
				if(adar==true)
				{
					check=true;
					break;
				}
				else
				{
					adar=true;
					remr=a;
				}
			}
			if(col[a]%2!=0)
			{
				if(adac==true)
				{
					check=true;
					break;
				}
				else
				{
					adac=true;
					remc=a;
				}
			}
			if(check==true)
			break;
		}
		if(check==true || (adar!=adac)) printf("Corrupt\n");
		else if(adar==adac && adac==true) printf("Change bit (%d,%d)\n",remr,remc);
		else printf("OK\n");
		scanf("%d",&test);
	}
}
