#include<bits/stdc++.h>
using namespace std;

vector<int> vec;

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	int ww;
	scanf("%d",&ww); getchar();
	while(ww--)
	{
		char tc;
		int temp = 0;
		while(1)
		{
			scanf("%c",&tc);
			if(tc=='\n') break;
			else
			{
				if(tc>='0' && tc<='9')
				{
					temp = temp*10 + tc-'0';
				}
				else
				{
					if(temp!=0)vec.push_back(temp);
					temp = 0;
				}
			}
		}
		vec.push_back(temp);
		int ans = 0;
		int sz = vec.size();
		for(int a=0;a<sz;a++)
		{
			if(vec[a]==0) continue;
			for(int b=a+1;b<sz;b++)
			{
				if(vec[b]==0) continue;
				//printf("%d %d\n",vec[a],vec[b]);
				ans = max(ans,gcd(vec[a],vec[b]));
			}
		}
		printf("%d\n",ans);
		vec.clear();
	}
}
