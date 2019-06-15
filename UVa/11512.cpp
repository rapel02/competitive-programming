#include<bits/stdc++.h>
#define mp make_pair
#define ss second
#define ff first
using namespace std;

char in[1500];

int SA[15][1500];
pair<pair<int,int>,int> temp[1500],temp2[1500];
int len;

int arr[1500];

void sort_second()
{
	memset(arr,0,sizeof(arr));
	for(int a=0;a<len;a++) arr[temp[a].ff.ss]++;
	for(int a=1;a<=1000;a++) arr[a]+=arr[a-1];
	for(int a=len-1;a>=0;a--)
	{
		temp2[arr[temp[a].ff.ss]-1] = temp[a];
		arr[temp[a].ff.ss]--;
	}
	for(int a=0;a<len;a++) temp[a] = temp2[a];
}

void sort_first()
{
	memset(arr,0,sizeof(arr));
	for(int a=0;a<len;a++) arr[temp[a].ff.ff]++;
	for(int a=1;a<=1000;a++) arr[a]+=arr[a-1];
	for(int a=len-1;a>=0;a--)
	{
		temp2[arr[temp[a].ff.ff]-1] = temp[a];
		arr[temp[a].ff.ff]--;
	}
	for(int a=0;a<len;a++) temp[a] = temp2[a];
}

void sort()
{
	sort_second();
	sort_first();
}

int LCP(int pos,int next,int add)
{
	if(add<0) return 0;
	if(SA[add][pos]==SA[add][next])
		return LCP(pos+(1<<add),next+(1<<add),add-1) + (1<<add);
	else return LCP(pos,next,add-1);
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%s",in);
		len = strlen(in);
		for(int a=0;a<len;a++)
		{
			SA[0][a] = in[a]-'A'+1;
		}
		int MAXN = ceil(log2(double(len)));
		for(int a=1;a<=MAXN;a++)
		{
			for(int b=0;b<len;b++)
			{
				temp[b].ss = b;
				temp[b].ff.ff = SA[a-1][b];
				if(b+(1<<(a-1))>=len) temp[b].ff.ss = 0;
				else temp[b].ff.ss = SA[a-1][b+(1<<(a-1))];
			}
			sort();
			int k = 1;
			for(int b=0;b<len;b++)
			{
				if(b!=0)
					if(temp[b].ff.ff!=temp[b-1].ff.ff || temp[b].ff.ss !=temp[b-1].ff.ss) k++;
				SA[a][b] = k;
			}
		}
		bool ada = false;
		int ans = 0;
		int pos = 0;
		int pref = 0;
		int total = 0;
		int rem = 0;
		for(int a=0;a<len-1;a++)
		{
			pref = LCP(temp[a].ss,temp[a+1].ss,MAXN);
			if(pref!=0)
			{
				if(pref>ans)
				{
					ada = true;
					total = 1;
					pos = temp[a].ss;
					ans = pref;
					rem = total;
				}
			}
		}
		if(ada)
		{
			for(int a=pos;a<pos+ans;a++) printf("%c",in[a]);
			printf(" %d\n",rem);
		}
		else printf("No repetitions found!\n");
	}
}
