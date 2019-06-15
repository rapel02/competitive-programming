#include<bits/stdc++.h>
using namespace std;

map<string,int> mmap;

int main()
{
	int ntc;
	cin>>ntc;
	for(int tc=1;tc<=ntc;tc++)
	{
		int n;
		mmap.clear();
		cin>>n;
		for(int a=0;a<n;a++)
		{
			string in1;
			int v;
			cin>>in1>>v;
			mmap[in1] = v;
		}
		int d;
		cin>>d;
		string in;
		cin>>in;
		if(mmap[in] == 0 || mmap[in] > d + 5) printf("Case %d: Do your own homework!\n",tc);
		else if(mmap[in] <= d) printf("Case %d: Yesss\n",tc);
		else printf("Case %d: Late\n",tc);
	}
}
