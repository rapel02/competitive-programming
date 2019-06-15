#include<bits/stdc++.h>
using namespace std;

struct Id{
	int rank;
	int tot;
}alp[50];

char in[15000];

bool cmp(Id a,Id b)
{
	if(a.tot>b.tot) return true;
	if(a.tot==b.tot) return a.rank<b.rank;
	return false;
}

int main()
{
	int num;
	cin>>num;
	getchar();
	for(int a=0;a<26;a++) alp[a].rank = a;
	while(num--)
	{
		gets(in);
		int len = strlen(in);
		for(int a=0;a<len;a++)
		{
			if(toupper(in[a])>='A' && toupper(in[a])<='Z')
			{
				alp[toupper(in[a])-'A'].tot++;
			}
		}
	}
	sort(alp,alp+26,cmp);
	for(int a=0;a<26;a++)
	{
		if(alp[a].tot!=0) printf("%c %d\n",alp[a].rank+'A',alp[a].tot);
	}
}
