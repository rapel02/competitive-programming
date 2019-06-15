#include<bits/stdc++.h>
using namespace std;

map<string,int> mmap;

int main()
{
	int tc;
	cin>>tc;getchar();getchar();
	while(tc--)
	{
		int tot = 0;
		mmap.clear();
		string in;
		while(getline(cin,in))
		{
			if(in.length() == 0) break;
			mmap[in]++;
			tot++;
		}
		cout.precision(4);
		cout<<fixed;
		for(map<string,int>::iterator it = mmap.begin();it!=mmap.end();it++)
		{
			cout<<it->first<<" "<<(it->second * 100.0)/(tot*1.0)<<"\n";
		}
		if(tc!=0) cout<<"\n";
	}
}
