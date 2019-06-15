#include<bits/stdc++.h>
#define pb push_back
using namespace std;

//vector<int> vec[30];

char t1[100005],t2[100005];

int main()
{
	int v,e;
	while(scanf("%d %d",&v,&e)!=EOF)
	{
		getchar();
		for(int a=0;a<e;a++)
		{
			scanf("%s %s",t1,t2); getchar();
			//vec[t1-'A'].pb(t2-'A');
		}
		int af = 2+e-v;
		if(af<=0) af = 0;
		printf("%d\n",af);
		//for(int a=0;a<)
	}
}
