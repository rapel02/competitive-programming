#include<bits/stdc++.h>
using namespace std;

stack<string> s;

int ranker(char a)
{
	if(a=='+' || a=='-') return 1;
	else if(a=='*' ||a=='/') return 2;
	else return 3;
}

int main()
{
	int tc;
	string in;
	scanf("%d",&tc); getchar();
	getline(cin,in); //only for first enter
	while(tc!=0)
	{
		string ans;
		tc--;
		while(1)
		{
			getline(cin,in);
			if(in.length()==0)
			{
				while(!s.empty())
				{
					ans+=s.top();
					s.pop();
				}
				cout<<ans<<endl;
				break;
			}
			if(in[0]>='0'&&in[0]<='9')
			{
				ans+=in;
			}
			else
			{
				string temp;
				if(!s.empty()) temp = s.top();
				if(in[0]!=')')
				{
					while(!s.empty()&&temp[0]!='('&&ranker(in[0])<=ranker(temp[0]))
					{
						ans+=s.top();
						s.pop();
						if(!s.empty())temp = s.top();
					}
					s.push(in);
				}
				else
				{
					while(!s.empty()&&(temp[0]!='('))
					{
						//cout<<s.top();
						ans+=s.top();
						s.pop();
						if(!s.empty()) temp = s.top();
					}
					s.pop();
				}
			}
		}
		if(tc!=0) cout<<endl;
	}
}
