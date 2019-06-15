#include<bits/stdc++.h>
using namespace std;

int arr[1005];

stack<int> s;

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		for(int a=0;a<n;a++) scanf("%d",&arr[a]);
		sort(arr,arr+n);
		for(int a=2;a<n;a++) s.push(arr[a]);
		int time = 0;
		int temp = 0 ;
		for(int a=0;a<min(n,2);a++) temp=max(arr[a],temp);
		int step = 0;
		while(!s.empty())
		{
			if(step==1)
			{
				time+=arr[0];
			}
			else if(step==2)
			{
				time+=arr[1];
				step = 3;
				continue;
			}
			else
			{
				time+=temp;
				step = 1;
				continue;
			}
			int maxi = s.top();
			s.pop();
			if(!s.empty())
			{
				s.pop();
			}
			else step = 0;
			time+=maxi;
			step++;
		}
		if(n>2)
		{
			if(step==1) ;
			else if(step==2)
			{
				time+=temp+arr[1];
			} 
		}
		else time+=temp;
		printf("%d\n",time);
		if(n>2)
		{
			for(int a=2;a<n;a++) s.push(arr[a]);
			step = 0;
			while(!s.empty())
			{
				if(step==1)
				{
					printf("%d\n",arr[0]);
				}
				else if(step==2)
				{
					printf("%d\n",arr[1]);
					step = 3;
					continue;
				}
				else
				{
					printf("%d %d\n",arr[0],arr[1]);
					step = 1;
					continue;
				}
				int maxi = s.top();
				s.pop();
				printf("%d",maxi);
				if(!s.empty())
				{
					printf(" %d",s.top());
					s.pop();
				}
				else
				{
					printf(" %d",arr[0]);
					step=0;
				}
				printf("\n");
				time+=maxi;
				step++;
			}
			if(step==1) ;
			else if(step==2)
			{
				printf("%d\n",arr[1]);
				printf("%d %d\n",arr[0],arr[1]);
			} 
		}
		else
		{
			for(int a=0;a<min(2,n);a++)
			{
				if(a!=0) printf(" ");
				printf("%d",arr[a]);
			}
			printf("\n");
		}
	}
}
