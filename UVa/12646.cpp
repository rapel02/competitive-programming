#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c;
	while(cin>>a>>b>>c)
	{
		bool ada = true;
		char ans = '*';
		if(a == b && b == c) ada = false;
		else if(a == b) ans = 'C';
		else if(a == c) ans = 'B';
		else if(b == c) ans = 'A';
		cout<<ans<<endl;
	}
}
