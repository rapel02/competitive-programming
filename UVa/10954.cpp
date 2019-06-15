#include<bits/stdc++.h>
using namespace std;

int arr[5005];

priority_queue<int> pq;


int main()
{
	int t;
	while(1)
	{
		scanf("%d",&t);
		if(t==0) break;
		for(int a=0;a<t;a++)
		{
			scanf("%d",&arr[a]);
			pq.push(-arr[a]);
		}
		if(t==1) 
		{
			printf("%d\n",arr[0]);
			continue;
		}
		long long ans=0,temp=0;
		int stp=0;
		while(!pq.empty())
		{
			stp++;
			int now=-pq.top();
			pq.pop();
			if(pq.size()==0) break;
			int next=-pq.top();
			pq.pop();
			ans+=(now+next);
			pq.push(-(now+next));
		}
		printf("%lld\n",ans);
	}
}
