#include<bits/stdc++.h>
using namespace std;

queue<int> q;

int main()
{
	int test;
	scanf("%d",&test);
	while(test!=0)
	{
		for(int a=1;a<=test;a++)
			q.push(a);
		
		if(test>1) 
		{
			printf("Discarded cards: ");
			bool first=true;
			while(!q.empty())
			{
				if(first==true) printf("%d",q.front());
				else printf(", %d",q.front());
				q.pop();
				test--;
				if(test==1)
				{
					printf("\n");
					printf("Remaining card: %d\n",q.front());
					q.pop();
				}
				else
				{
					q.push(q.front());
					q.pop();
				}
				first=false;
			}
		}
		else if(test==1)
		{
			printf("Discarded cards:\n");
			printf("Remaining card: %d\n",q.front());
			q.pop();
		}
		scanf("%d",&test);
	}
}
