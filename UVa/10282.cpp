#include<bits/stdc++.h>
using namespace std;

string in,in2,in3;

map<string,string> mmap;

int main()
{
	while(getline(cin,in3),in3!="")
	{
		stringstream ss(in3);
		ss >> in >> in2;
		mmap[in2] = in;
	}
	while(cin>>in)
	{
		if(mmap[in]=="") cout<<"eh"<<endl;
		else cout<<mmap[in]<<endl;
	}
}
