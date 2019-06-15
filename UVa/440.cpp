#include<bits/stdc++.h>
using namespace std;

queue<int> q;

int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		
		for(int a=1;;a++)
		{
			for(int b=1;b<=n;b++) q.push(b);
			int k = 0;
			int rem = -1;
			while(!q.empty())
			{
				if(k==0)
				{
					q.pop();
				}
				else
				{
					int v = q.front();
					q.pop();
					q.push(v);
					rem = v;
				}
				k = (k+1)%a;
			}
			if(rem==2)
			{
				printf("%d\n",a);
				break;
			}
		}
	}
}
