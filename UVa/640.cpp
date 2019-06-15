#include<bits/stdc++.h>
using namespace std;

vector<int> v;

bool vis[1000005];

int main()
{
	for(int a=1;a<=1000000;a++)
	{
		if(vis[a]==false)
		{
			v.push_back(a);
			int b = a;
			while(b<=1000000)
			{
				int tot = b;
				while(b!=0)
				{
					tot+=b%10;
					b/=10;
				}
				b = tot;
				if(vis[b]==true) break;
				vis[b] = true;
			}
		}
	}
	int sz = v.size();
	for(int a=0;a<sz;a++) printf("%d\n",v[a]);
}
