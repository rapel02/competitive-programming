#include<bits/stdc++.h>
using namespace std;
deque<char> ans;

struct llist{
	char pos;
	struct llist *next;
}*head,*tail,*post;

int main()
{
	char temp;
	int idx=0;
	head=NULL,tail=NULL,post =  NULL;
	while(scanf("%c",&temp)!=EOF)
	{
		//printf("%c\n",temp);
		if(temp=='\n')
		{
			//printf("%d\n",3);
			while(head!=NULL)
			{
				printf("%c",head->pos);
				post=head;
				head=head->next;
				free(post);
			}
			head = NULL, tail = NULL, post = NULL;
			printf("\n");
			idx=0;
		}
		else
		{
			if(temp=='[') idx=1;
			else if(temp==']') post=tail,idx=0;
			else if(head==NULL)
			{
				struct llist *curr = (struct llist *) malloc(sizeof(struct llist));
				curr->pos=temp;
				head = curr;
				tail = curr;
				post = curr;
				idx=0;
			}
			else if(idx==1)
			{
				
				struct llist *curr = (struct llist *) malloc(sizeof(struct llist));
				curr->pos=temp;
				curr->next = head;
				head = curr;
				post = head;
				idx=0;
			}
			else
			{
				struct llist *curr = (struct llist *) malloc(sizeof(struct llist));
				curr->pos=temp;
				if(post->next == NULL)
				{
					post->next = curr;
					post = curr;
					tail = curr;
				}
				else
				{
					curr->next = post->next;
					post->next = curr;
					post = curr;
				}
				idx=0;
			}
		}
	}
}
