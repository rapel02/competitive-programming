#include<bits/stdc++.h>
using namespace std;

priority_queue<int> dpq;
stack<int> ds;
queue<int> dq;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		bool q=true,s=true,pq=true;
		for(int a=1;a<=n;a++)
		{
			int i,v;
			scanf("%d %d",&i,&v); getchar();
			if(i==1)
			{
				dpq.push(v);
				ds.push(v);
				dq.push(v);
			}
			else
			{
				if(dpq.size()==0)
				{
					pq=false;
					s=false;
					q=false;
					continue;
				}
				if(dpq.top()!=v) pq=false;
				if(ds.top()!=v) s=false;
				if(dq.front()!=v) q=false;
				dpq.pop(); ds.pop(); dq.pop();
			}
		}
		if(pq==false && s==false && q==false) printf("impossible\n");
		else if(pq==true && s==false && q==false) printf("priority queue\n");
		else if(pq==false && s==true && q==false) printf("stack\n");
		else if(pq==false && s==false && q==true) printf("queue\n");
		else printf("not sure\n");
		while(dpq.size()!=0) 
		{
			dpq.pop();
		}
		while(ds.size()!=0)
		{
			 ds.pop();
		}
		while(dq.size()!=0)
		{
			dq.pop();
		}
	}
}
