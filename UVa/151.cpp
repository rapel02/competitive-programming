#include<bits/stdc++.h>
using namespace std;

queue<int> q;

int main()
{
	int n;
	while (scanf("%d",&n),n)
	{
		for(int a=1;a<=n;a++)
		{
			for(int b=1;b<=n;b++) q.push(b);
			int k = 0;
			int num = 0;
			while(!q.empty())
			{
				if(k%a!=0) q.push(q.front());
				num = q.front();
				q.pop();
				k=(k+1)%a;
			}
			if(num==13)
			{
				printf("%d\n",a);
				break;
			}
		}
	}
}
