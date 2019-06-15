#include<bits/stdc++.h>
#define bff getchar()
#define pb push_back
using namespace std;

vector<int> vec[101];

int dfs_num[101],dfs_low[101];
int k=0;

char nm[101][40];
char aa[40],bb[40];
int main()
{
	int cit,que;
	while(1)
	{
		k=0;
		scanf("%d",&cit); bff;
		if(cit==0) break;
		for(int a=0;a<cit;a++)
			scanf("%s",nm[a]),bff;
		//sort(nm,nm+cit);
		for(int a=0;a<cit;a++)
			printf("%s\n",nm[a]);
		scanf("%d",&que),bff;
		for(int a=0;a<que;a++)
		{
			scanf("%s %s",aa,bb),bff;
			int p1=-1,p2=-1;
			for(int b=0;b<cit;b++)
			{
				if(strcmp(aa,nm[b])==0) p1=b;
				if(strcmp(bb,nm[b])==0) p2=b;
				if(p1!=-1 && p2!=-1) break;
			}
		}
		
	}
}
