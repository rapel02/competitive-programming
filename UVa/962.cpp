#include<bits/stdc++.h>
using namespace std;

vector<long long> ans;

map<long long,int> mmap;

void precom()
{
	for(long long a=0;a<=1200;a++)
	{
		for(long long b=a;b<=1200;b++)
		{
			long long num = a*a*a + b*b*b;
			if(mmap[num]>=2) continue;
			mmap[num]++;
			if(mmap[num]==2) ans.push_back(num);
		}
	}
	sort(ans.begin(),ans.end());
}

int main()
{
	precom();
	long long a,b;
	while(scanf("%lld %lld",&a,&b)!=EOF)
	{
		b = a+b;
		int sz = ans.size();
		bool ff = false;
		for(int aa=0;aa<sz;aa++)
		{
			if(ans[aa]>b) break;
			if(ans[aa]>=a) 
			{
				printf("%lld\n",ans[aa]);
				ff=true;
			}
		}
		if(!ff) printf("None\n");
	}
}
