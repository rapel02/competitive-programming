#include<bits/stdc++.h>
using namespace std;

map<string,int> mmap;

struct node{
	node *next[27];
	int val;
	int idx;
}*root;

char in[150];

int main()
{
	root = new node();
	root->idx = 0;
	root->val = 0;
	queue<node*> q;
	q.push(root);
	int ans = 0;
	while(!q.empty())
	{
		if(ans == 83682) break;
		node *temp = q.front();
		temp->val = ans++;
		q.pop();
		for(int a=temp->idx + 1;a<=26;a++)
		{
			node *next = new node();
			next->idx = a;
			temp->next[a] = next;
			q.push(next);
		}
	}
	while(scanf("%s",in)!=EOF)
	{
		int ans = -1;
		int len = strlen(in);
		node *traverse = root;
		for(int a=0;a<len;a++)
		{
			if(traverse->next[in[a] -'a' + 1] == NULL)
			{
				ans = 0;
				break;
			}
			traverse = traverse->next[in[a]-'a' + 1];
			ans = traverse->val;
		}
		printf("%d\n",ans);
	}
}
