#include<bits/stdc++.h>
using namespace std;

set<pair<int,int> > s;

int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		s.clear();
		int k  = 0;
		for(int a=0;a<n;a++)
		{
			int a1,a2;
			scanf("%d %d",&a1,&a2);
			if(a1>a2) k++,swap(a1,a2);
			s.insert(make_pair(a1,a2));
		}
		if(s.size()*2<=n&&k*2==n) printf("YES\n");
		else printf("NO\n");
	}
}
