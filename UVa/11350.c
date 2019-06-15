#pragma GCC optimize("O3")
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char in[150];

struct node{
	struct node *next,*prev;
	long long to;
	long long bot;
}*head,*tail,*pos;

void insert()
{
	struct node *temp;
	head = (struct node *)(malloc(sizeof(struct node)));
	head->to = 0;
	head->bot = 1;
	head->prev = NULL;
	temp = (struct node *)(malloc(sizeof(struct node)));
	temp->to = 1;
	temp->bot = 1;
	tail = (struct node *)(malloc(sizeof(struct node)));
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
	int a,n;
	scanf("%d",&n);
	while(n--){
		insert();
		scanf("%s",in);
		int len = strlen(in);
		for(a=0;a<len;a++)
		{
			struct node *temp = (struct node *)(malloc(sizeof(struct node)));
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
