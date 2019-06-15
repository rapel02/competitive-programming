#include<bits/stdc++.h>
using namespace std;

struct data{
	int tot[30];
	int app;
	string in;
	data(){
		for(int a=0;a<30;a++) this->tot[a] = 0;
	}
};

vector<data> vec,te;

int conv(char a)
{
	if(a>='a' && a<='z') return a-'a';
	return a-'A';
}

bool cmp(data a,data b){
	return a.in < b.in;
}

bool compare(data a,data b)
{
	for(int i=0;i<30;i++) if(a.tot[i] != b.tot[i]) return false;
	return true;
}

string in;

int main()
{
	int sz = 0;
	vec.clear();
	while(cin>>in)
	{
		if(in=="#") break;
		data temp;
		temp.in = in;
		temp.app = 0;
		int len = in.length();
		for(int a=0;a<len;a++)
		{
			temp.tot[conv(in[a])]++;
		}
		int idx = -1;
		for(int a=0;a<sz;a++)
		{
			if(compare(vec[a],temp))
			{
				temp.app = 1;
				vec[a].app = 1;
				idx = a;
			}
		}
		if(idx == -1) vec.push_back(temp),sz++;
	}
	sort(vec.begin(),vec.end(),cmp);
	for(int a=0;a<sz;a++) if(vec[a].app == 0)cout<<vec[a].in<<endl;
}
