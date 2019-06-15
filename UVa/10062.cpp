#include<bits/stdc++.h>
using namespace std;

struct Val{
	int pos;
	int tot;
}arr[15000];

char in[15000];

bool cmp(Val a,Val b)
{
	if(a.tot<b.tot) return true;
	if(a.tot == b.tot) return a.pos > b.pos;
	return false;
}

int main()
{
	bool first = true;
	while(gets(in)!=NULL)
	{
		if(!first) printf("\n");
		first = false;
		for(int a=0;a<130;a++)
			arr[a].pos = a,arr[a].tot = 0;
		int len = strlen(in);
		for(int a=0;a<len;a++)
			arr[in[a]].tot++;
		sort(arr,arr+130,cmp);
		for(int a=0;a<=130;a++)
		{
			if(arr[a].tot !=0) printf("%d %d\n",arr[a].pos,arr[a].tot);
		}
	}
}
