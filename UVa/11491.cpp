#include<bits/stdc++.h>
using namespace std;

char in[150000];

struct Ident{
	char a;
	int id;
}Id[150000];

bool print[150000];

bool cmp(Ident a,Ident b)
{
	if(a.a<b.a) return true;
	if(a.a==b.a) return a.id < b.id;
	return false;
}

int main()
{
	int n,d;
	while(scanf("%d %d",&n,&d),n,d)
	{
		getchar();
		memset(print,true,sizeof(print));
		for(int a=0;a<n;a++)
		{
			scanf("%c",&in[a]);
			Id[a].a = in[a];
			Id[a].id = a;
		}
		getchar();
		sort(Id,Id+n,cmp);
		for(int a=0;a<d;a++)
		{
			print[Id[a].id ] = false;
		}
		for(int a=0;a<n;a++)
		{
			if(print[a] == true) printf("%c",in[a]);
		}
		printf("\n");
	}
}
