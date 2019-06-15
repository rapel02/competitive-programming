#include<bits/stdc++.h>
using namespace std;

long long num[100005];

int main()
{
	int n;
	int tc = 0;
	while(cin>>n)
	{
		if(n==0) break;
		tc++;
		for(int a=0;a<n;a++) cin>>num[a];
		sort(num,num+n);
		int lt = 0;
		bool isprint = false;
		printf("Case %d:\n",tc);
		for(int a=1;a<n;a++)
		{
			if(isprint==false && num[a] != num[a-1] + 1)
			{
				isprint = true;
				printf("0%lld",num[lt]);
				if(a-1 - lt != 0)
				{
					stack<int> s1;
					stack<int> s2;
					queue<int> s;
					while(num[lt]!=0 || num[a-1]!=0)
					{
						s1.push(num[lt]%10);
						s2.push(num[a-1]%10);
						num[lt]/=10;
						num[a-1]/=10;
					}
					bool isdiff = false;
					while(!s1.empty())
					{
						if(s1.top()!=s2.top()) isdiff = true;
						if(isdiff==true) s.push(s2.top());
						s1.pop(),s2.pop();
					}
					printf("-");
					while(!s.empty())
					{
						printf("%d",s.front());
						s.pop();
					}
				}
				printf("\n");
			}
			if(isprint==true) lt = a,isprint = false;
		}
		if(isprint == false)
		{
			printf("0%lld",num[lt]);
			if(n-1 - lt != 0)
			{
				stack<int> s1;
				stack<int> s2;
				queue<int> s;
				while(num[lt]!=0 || num[n-1]!=0)
				{
					s1.push(num[lt]%10);
					s2.push(num[n-1]%10);
					num[lt]/=10;
					num[n-1]/=10;
				}
				bool isdiff = false;
				while(!s1.empty())
				{
					if(s1.top()!=s2.top()) isdiff = true;
					if(isdiff==true) s.push(s2.top());
					s1.pop(),s2.pop();
				}
				printf("-");
				while(!s.empty())
				{
					printf("%d",s.front());
					s.pop();
				}
			}
			printf("\n");
		}
		printf("\n");
	}
}
