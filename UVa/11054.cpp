#include <bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
using namespace std;

stack<pair<long long,int> > s;

int main()
{
	int tc;
	//scanf("%d",&tc);
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0) break;
		long long tot = 0;
		for(int a=0;a<n;a++)
		{
			long long in;
			scanf("%lld",&in);
			if(!s.empty())
			{
				if(in>0)
				{
					while(in!=0)
					{
						if(s.empty()) break;
						if(s.top().ff>0) break;
						long long val = -s.top().ff;
						int pos = s.top().ss;
						int red = min(val,in);
						s.pop();
						val-=red;
						in-=red;
						tot+=(red*(a-pos));
						if(val!=0) s.push(mp(-val,pos));
					}
					if(in!=0) s.push(mp(in,a));
				}
				else
				{
					in=in*-1;
					while(in!=0)
					{
						if(s.empty())break;
						if(s.top().ff<0) break;
						long long val = s.top().ff;
						int pos = s.top().ss;
						int red = min(val,in);
						val-=red;
						in-=red;
						tot+=(red*(a-pos));
						s.pop();
						if(val!=0) s.push(mp(val,pos));
					}
					if(in!=0) s.push(mp(-in,a));
				}
			}
			else s.push(mp(in,a));
		}
		printf("%lld\n",tot);
	}
}
