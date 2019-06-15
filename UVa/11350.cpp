#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

char in[150];

struct node{
	node *next,*prev;
	long long to;
	long long bot;
}*head,*tail,*pos;

void clear()
{
	while(head!=NULL)
	{
		node *temp = head;
		head = head->next;
		delete(temp);
	}
}

void insert()
{
	node *temp;
	head = new node();
	head->to = 0;
	head->bot = 1;
	head->prev = NULL;
	temp = new node();
	temp->to = 1;
	temp->bot = 1;
	tail = new node();
	tail->to = 1;
	tail->bot = 0;
	tail->next = NULL;
	head->next = tail->prev = temp;
	temp->next = tail;
	temp->prev = head;
	pos = temp;
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--){
		clear();
		insert();
		scanf("%s",in);
		int len = strlen(in);
		for(int a=0;a<len;a++)
		{
			node *temp = new node();
			if(in[a]=='L')
			{
				long long to = pos->to + pos->prev->to;
				long long bot = pos->bot + pos->prev->bot;
				temp->to = to;
				temp->bot = bot;
				temp->next = pos;
				temp->prev = pos->prev;
				pos->prev->next = temp;
				pos->prev = temp;
			}
			else
			{
				long long to = pos->to + pos->next->to;
				long long bot = pos->bot + pos->next->bot;
				temp->to = to;
				temp->bot = bot;
				temp->next = pos->next;
				temp->prev=  pos;
				pos->next->prev = temp;
				pos->next = temp;
			}
			pos = temp;
		}
		printf("%lld/%lld\n",pos->to,pos->bot);
	}
}
