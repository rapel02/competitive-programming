#include<bits/stdc++.h>
static const int apb = 26;
using namespace std;

struct trie{
	struct trie *chara[26];
	int k;
};

int tot = 0;
int len = 0;

char in[1500];

void insert(struct trie **a,int pos)
{
	if(pos==len) return ;
	int val = in[pos] - 'a';
	((*a)->k)++;
	if((*a)->chara[val]==NULL)
	{
		struct trie *temp = (struct trie *) malloc(sizeof(struct trie));
		temp->k = 0;
		for(int i=0;i<apb;i++) temp->chara[i] = NULL;
		(*a)->chara[val] = temp;
	}
	insert(&((*a)->chara[val]),pos+1);
}

void search(struct trie *a,int lv)
{
	int total = 0;
	int tp = 0;
	for(int i=0;i<apb;i++)
	{
		if(a->chara[i]!=NULL)
		{
			tp+=(a->chara[i]).k;
			total++;
			printf("%c\n",i+'a');
			search(a->chara[i],lv+1);
		}
	}
	if(total>1) tot+=tp;
	return ;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		trie *root = NULL;
		root = (struct trie *) malloc(sizeof(struct trie));
		root->k = 0;
		tot = 0;
		for(int i=0;i<apb;i++) root->chara[i] = NULL;
		for(int a=0;a<n;a++)
		{
			scanf("%s",in);
			len = strlen(in);
			insert(&root,0);
		}
		search(root,0);
		printf("%.2lf\n",1.0*tot / n);
	}
}
