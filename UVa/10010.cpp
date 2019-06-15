#include<bits/stdc++.h>
using namespace std;

int r,c;

char in[55][55];
char qw[55];
int len;
bool check(int p,int q,int ay,int ax,int id)
{
	if(id==len) return true;
	if(p<0 || q<0 || p>=r || q>=c) return false;
	if(tolower(in[p][q])!=tolower(qw[id]) ) return false;
	//printf("%d %d %c\n",p,q,in[p][q]);
	return check(p+ay,q+ax,ay,ax,id+1);
}

int main()
{
	int tc;
	scanf("%d",&tc);
	bool first = true;
	while(tc--)
	{
		scanf("%d %d",&r,&c);
		if(first==false) printf("\n");
		first = false; 
		for(int a=0;a<r;a++)
			scanf("%s",in[a]);
		int q;
		scanf("%d",&q);
		for(int a=0;a<q;a++)
		{
			scanf("%s",qw);
			len = strlen(qw);
			bool ada= false;
			for(int b=0;b<r;b++)
			{
				for(int d=0;d<c;d++)
				{
					for(int e=-1;e<=1;e++)
					{
						for(int f=-1;f<=1;f++)
						{
							if(b+e<0 || b+e>=r || d+f<0 || d+f>=c) continue;
							if(tolower(in[b][d]) == tolower(qw[0] ) && check(b+e,d+f,e,f,1)==true)
							{
								printf("%d %d\n",b+1,d+1);
								ada = true;
							}
							if(ada) break;
						}
						if(ada) break;
					}
					if(ada)break;
				}
				if(ada)break;
			}
		}
	}
}
