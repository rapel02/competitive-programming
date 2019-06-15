#include<bits/stdc++.h>
using namespace std;

char in[16][16][3];

int pos[16];
char ans[16][3];

int main()
{
	while(1)
	{
		for(int a=0;a<4;a++)
		{
			for(int b=1;b<=13;b++)
			{
				pos[b]=3;
				scanf("%s",in[b][a]);
				getchar();	
				if(strcmp(in[b][a],"#")==0) return 0;
			}
		}
		//for(int a=0;a<4;a++)
		//	for(int b=1;b<=13;b++) printf("%s ",in[b][a]);
		int idx=13;
		int tot=0;
		while(1)
		{
			if(pos[idx]==-1) break;
	//		printf("%d %d   ",tot,pos[idx]);;
	//		printf("%s\n",in[idx][pos[idx]]);
			tot++;
			char tp=in[idx][pos[idx]][0];
		//	printf("%c ",tp);
			pos[idx]--;
			if(tp<='9'&&tp>='2') idx = (int) (tp - '0');
			else if(tp=='A') idx=1;
			else if(tp=='T') idx=10;
			else if(tp=='J') idx=11;
			else if(tp=='Q') idx=12;
			else if(tp=='K') idx=13;
			if(pos[idx]==-1) break;
			if(pos[idx]==3) strcpy(ans[idx],temp);
		//	printf("new idx: %d\n",idx);
		//	for(int a=1;a<=13;a++) printf("%d ",pos[a]);
		//	printf("\n");
		}
		printf("%d,%s\n",tot,ans[idx]);
	}
}
