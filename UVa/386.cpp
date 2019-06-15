#include<bits/stdc++.h>
using namespace std;

struct Res{
	int b;
	int c;
	int d;
}temp;

vector<Res> vec[204];

bool cmp(Res a,Res b)
{
	if(a.b<b.b) return true;
	return false;
}

int main()
{
	for(int a=0;a<=200;a++) vec[a].clear();
	for(int b=2;b<=200;b++)
	{
		for(int c=b;c<=200;c++)
		{
			for(int d=c;d<200;d++)
			{
				int tot = b*b*b + c*c*c + d*d*d;
				int a = (int)cbrt(tot);
				if(a>200) continue;
				if(a*a*a!=tot) continue;
				temp.b = b;
				temp.c = c;
				temp.d = d;
				vec[a].push_back(temp);
			}
		}
	}
	for(int a=1;a<=200;a++)
	{
		if(vec[a].size()==0) continue;
		sort(vec[a].begin(),vec[a].end(),cmp);
		int sz = vec[a].size();
		for(int b=0;b<sz;b++)
		{
			printf("Cube = %d, Triple = (%d,%d,%d)\n",a,vec[a][b].b,vec[a][b].c,vec[a][b].d);
		}
		vec[a].clear();
	}
}
