#include<bits/stdc++.h>
using namespace std;

map<long long,int> mmap;

int main()
{
	long long N,a,b;
	while(scanf("%lld",&N)!=EOF)
	{
		if(N==0) break;
		scanf("%lld %lld",&a,&b);
		int tot = 0;
		mmap.clear();
		mmap[0] = 1;
		long long pos = 0;
		while(mmap[pos] < 3)
		{
			pos = (a*pos%N * pos + b)%N;
			mmap[pos]++;
			if(mmap[pos]==2) tot++;
		}
		printf("%lld\n",N-tot);
	}
}
