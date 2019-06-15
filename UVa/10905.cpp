#include<bits/stdc++.h>
using namespace std;

string in[55];

bool cmp(string a,string b)
{
	if(a+b > b+a) return true;
	return false;
}

int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		for(int a=0;a<n;a++) cin>>in[a];
		sort(in,in+n,cmp);
		for(int a=0;a<n;a++) cout<<in[a];
		cout<<endl;
	}
}
