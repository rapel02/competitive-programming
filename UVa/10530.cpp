#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while(cin>>n && n!=0)
	{
		getchar();
		int lo = 1;
		int hi = 10;
		bool err = false;
		string in;
		while(1)
		{
			getline(cin,in);
			if(in == "right on") break;
			else if(in == "too high") hi = min(hi,n-1);
			else lo = max(lo,n + 1);
			if(lo > hi) err = true;
			cin>>n; getchar();
		}
		if(lo > hi || n < lo || n > hi) err = true;
		printf("%s\n",(err==true)?"Stan is dishonest":"Stan may be honest");
	}
}
