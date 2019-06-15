#include<bits/stdc++.h>
using namespace std;

int pos[150];
stack<int> s[30],temp;
char in[150];
int main()
{
	int block;
	scanf("%d",&block);
	for(int a=0;a<block;a++) s[a].push(a),pos[a] = a;
	while(1)
	{
		int a,b;
		scanf("%s",in); getchar();
		if(strcmp(in,"quit")==0) break;
		else if(strcmp(in,"move")==0)
		{
			scanf("%d",&a); getchar();
			scanf("%s",in); getchar();
			scanf("%d",&b); getchar();
			if(pos[a]==pos[b]) continue;
			int anw = pos[a];
			while(s[anw].top()!=a)
			{
				s[s[anw].top()].push(s[anw].top());
				pos[s[anw].top()] = s[anw].top();
				s[anw].pop();
			}
			int anr = pos[b];
			if(strcmp(in,"onto")==0)
			{
				while(s[anr].top()!=b)
				{
					s[s[anr].top()].push(s[anr].top());
					pos[s[anr].top()] = s[anr].top();
					s[anr].pop();
				}
			}
			s[anr].push(s[anw].top());
			pos[s[anr].top()] = anr;
			s[anw].pop();
		}
		else
		{
			scanf("%d",&a); getchar();
			scanf("%s",in); getchar();
			scanf("%d",&b); getchar();
			if(pos[a]==pos[b]) continue;
			int anw = pos[a];
			while(s[anw].top()!=a)
			{
				temp.push(s[anw].top());
				s[anw].pop();
			}
			temp.push(s[anw].top());
			s[anw].pop();
			int anr = pos[b];
			if(strcmp(in,"onto")==0)
			{
				while(s[anr].top()!=b)
				{
					s[s[anr].top()].push(s[anr].top());
					pos[s[anr].top()] = s[anr].top();
					s[anr].pop();
				}
			}
			while(!temp.empty())
			{
				s[anr].push(temp.top());
				pos[temp.top()] = anr;
				temp.pop();
			}
		}
	}
	for(int a=0;a<block;a++)
	{
		printf("%d:",a);
		while(!s[a].empty())
		{
			temp.push(s[a].top());
			s[a].pop();
		}
		while(!temp.empty())
		{
			printf(" %d",temp.top());
			temp.pop();
		}
		printf("\n");
	}
}
