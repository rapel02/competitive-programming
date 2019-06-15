#include<bits/stdc++.h>
using namespace std;

map<int,long long> mmap;

int main()
{
	int in;
	while(scanf("%d",&in)!=EOF)
	{
		if(mmap.count(in)>0)
		{
			mmap[in]++;
		}
		else mmap.insert(pair<int,long long>(in,0));
	}
	map<int,long long>::iterator it = mmap.begin();
	for(it=mmap.begin();it!=mmap.end();it++)
	{
		printf("%d %lld\n",it->first,it->second);
	}
}
