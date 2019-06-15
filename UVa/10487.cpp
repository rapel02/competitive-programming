#include<bits/stdc++.h>
using namespace std;

map<long long,int> mmap;

vector<long long>vec;

int main()
{
	int tc = 1;
	int n;
	while(cin>>n)
	{
		if(n==0) break;
		mmap.clear();
		vec.clear();
		for(int a=0;a<n;a++)
		{
			long long v;
			cin>>v;
			vec.push_back(v);
		}
		for(int a=0;a<n;a++) for(int b=a+1;b<n;b++) mmap[vec[a] + vec[b]] = 1;
		int q;
		scanf("%d",&q);
		printf("Case %d:\n",tc++);
		while(q--)
		{
			long long m;
			cin>>m;
			long long diff = 1e+15;
			long long rem = 0;
			for(map<long long,int>::iterator it = mmap.begin();it!=mmap.end();it++)
			{
				if(diff > abs(m - it->first))
				{
					diff = abs(m - it->first);
					rem = it->first;
				}
			}
			printf("Closest sum to %lld is %lld.\n",m,rem);
		}
	}
}
