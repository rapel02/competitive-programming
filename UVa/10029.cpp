#include<bits/stdc++.h>
using namespace std;

string in;

map<string,int> mmap;

char ch(int a)
{
	return 'a' + a;
}

int main()
{
	int k = 0;
	int ans = 0;
	while(cin>>in)
	{
		k++;
		int len = in.length();
		int tp = 1;
		for(int a=0;a<=len;a++)
		{
			for(char b = 'a' ;b<='z';b++)
			{
				string in2 = in;
				if(in2 > in) break;
				in2.insert(a,1,b);
				tp = max(tp,mmap[in2] + 1);
			}
		}
		for(int a=0;a<len;a++)
		{
			for(char b='a' ;b<='z';b++)
			{
				string in2 = in;
				in2[a] = b;
				if(in2 > in) break;
				if(in2==in) continue;
				tp = max(tp,mmap[in2] + 1);
			}
		}
		for(int a=0;a<len;a++)
		{
			string in2 = in;
			in2.erase(a,1);
			tp = max(tp,mmap[in2] + 1);
		}
		mmap[in] = tp;
		ans = max(ans,tp);
	}
	printf("%d\n",ans);
}
