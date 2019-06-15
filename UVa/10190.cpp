#include<bits/stdc++.h>
using namespace std;

queue<int> q;

int main()
{
	int n,k;
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		if(n<0 || k<0) break;
		while(!q.empty()) q.pop();
		q.push(n);
		bool ada = true;
		if(n==0|| n==1|| k==1 || k==0) ada =false,n = 1;
		while(n>1)
		{
			if(n%k!=0) ada =false;
			n/=k;
			q.push(n);
		}
		if(ada==false) printf("Boring!\n");
		else
		{
			bool f = true;
			while(!q.empty())
			{
				if(!f) printf(" ");
				f = false;
				printf("%d",q.front());
				q.pop();
			}
			printf("\n");
		}
	}
}
