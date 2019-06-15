#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;

int SA[20][5005];
char in[5005];

pair<pair<int,int> ,int> temp[5005],temp2[5005];
int len;
int counts[5005];

void sort_second()
{
	memset(counts,0,sizeof(counts));
	for(int a=0;a<len;a++) counts[temp[a].ff.ss]++;
	for(int a=1;a<=5000;a++) counts[a]+=counts[a-1];
	for(int a=len-1;a>=0;a--)
	{
		temp2[counts[temp[a].ff.ss]-1] = temp[a];
		counts[temp[a].ff.ss]--;
	}
	for(int a=0;a<len;a++)
		temp[a] = temp2[a];
}

void sort_first()
{
	memset(counts,0,sizeof(counts));
	for(int a=0;a<len;a++) counts[temp[a].ff.ff]++;
	for(int a=1;a<=5000;a++) counts[a]+=counts[a-1];
	for(int a=len-1;a>=0;a--)
	{
		temp2[counts[temp[a].ff.ff]-1] = temp[a];
		counts[temp[a].ff.ff]--;
	}
	for(int a=0;a<len;a++)
		temp[a] = temp2[a];
}

void sort()
{
	sort_second();
	//printf("finish second\n");
	sort_first();
}

int LCP(int pos,int next,int add)
{
	//printf("%d %d %d\n",pos,next,add);
	//if(next>=len) return 0;
	if(add<0) return 0;
	if(SA[add][pos]==SA[add][next])
	{
		//printf("add %d\n",(1<<add) - 1);
		return LCP(pos+(1<<(add)),next+(1<<(add)),add-1) + (1<<add);
	}
	else
	{
	//	printf("false\n");
		return LCP(pos,next,add-1);
	}
}

int main()
{
	int tc;
	scanf("%d",&tc); getchar();
	while(tc--)
	{
		gets(in);
		len = strlen(in);
		memset(SA,0,sizeof(SA));
		for(int a=0;a<len;a++)
		{
			SA[0][a] = in[a];
		}
		int MAXN = ceil(log2(len));
		//printf("%d %d\n",len,MAXN);
		for(int a=1;a<=MAXN;a++)
		{
			//printf("%d\n",a);
			for(int b=0;b<len;b++)
			{
				temp[b].ss = b;
				temp[b].ff.ff = SA[a-1][b];
			//	printf("%d %d\n",b,b+(1<<(a-1)));
				if(b+(1<<(a-1))>=len) temp[b].ff.ss = 0;
				else temp[b].ff.ss = SA[a-1][(b+(1<<(a-1)))];
			}
			sort();
			int k = 1;
			//printf("after sorted: \n");
			for(int c=0;c<len;c++)
			{
				//printf("%d %d %d\n",temp[c].ss,temp[c].ff.ff,temp[c].ff.ss);
				if(c!=0)
				{
					if(temp[c].ff.ff!=temp[c-1].ff.ff || temp[c].ff.ss != temp[c-1].ff.ss) 
					{
					k++;
					//printf("new add\n");
					}
				}
				SA[a][temp[c].ss] = k;
			}
		}
		int ans = 0;
		int a =0 ;
		//printf("%d %d %d\n",temp[a].ss,temp[a].ff.ff,temp[a].ff.ss);
		for(int a=0;a<len-1;a++)
		{
			//printf("%d %d %d\n",temp[a+1].ss,temp[a+1].ff.ff,temp[a+1].ff.ss);
		//	printf("start %d %d\n",temp[a].ss,temp[a+1].ss);
			int maxi = LCP(temp[a].ss,temp[a+1].ss,MAXN);
		//	printf("%d\n",maxi);
			ans = max(ans, maxi);
		}
		printf("%d\n",ans);
	}
}
