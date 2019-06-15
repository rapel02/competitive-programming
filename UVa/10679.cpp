#include<bits/stdc++.h>
using namespace std;

bool mark[1005];
int query;
char q_in[1005],main_in[100005];

int convert(char a)
{
	if(a>='a' && a<='z') return a-'a';
	return a-'A' + 26;
}

struct Trie
{
	Trie *next[52],*fail;
	vector<int> label;
	bool match;
	Trie()
	{
		fail = NULL;
		match = false;
		label.clear();
		memset(next,0,sizeof(next));
	}
};

void build_Trie(Trie **a,int val)
{
	int len = strlen(q_in);
	Trie *p = *a;
	for(int w=0;w<len;w++)
	{
		int idx = convert(q_in[w]);
		if(p->next[idx]==NULL) p->next[idx] = new Trie();
		p = p->next[idx];
	}
	p->label.push_back(val);
}

void build_Automation(Trie *root)
{
	queue<Trie *> q;
	Trie *state,*failure;
	root->fail = NULL;
	q.push(root);
	while(!q.empty())
	{
		state = q.front();
		q.pop();
		for(int a=0;a<52;a++)
		{
			if(state->next[a]==NULL) continue;
			q.push(state->next[a]);
			failure = state->fail;
			while(failure!=NULL && failure->next[a]==NULL) failure = failure->fail;
			if(failure==NULL) state->next[a]->fail = root;
			else state->next[a]->fail = failure->next[a];
		}
	}
}

void search_pattern(Trie *root)
{
	Trie *p = root;
	Trie *check;
	int len = strlen(main_in);
	for(int a=0;a<len;a++)
	{
		int nx = convert(main_in[a]);
		while(p!=root && p->next[nx] == NULL) p = p->fail;
		p = p->next[nx];
		if(p==NULL) p =root;
		else p = p;
		check = p;
		while(check!=root && check->match == false)
		{
			int sz = check->label.size();
			for(int b=0;b<sz;b++) mark[check->label[b]] = true;
			check->match = true;
			check = check->fail;
		}
	}
}

void clear_Automation(Trie *root)
{
	queue<Trie *> q;
	Trie *nx;
	q.push(root);
	while(!q.empty())
	{
		nx = q.front();
		q.pop();
		for(int a=0;a<52;a++) if(nx->next[a]!=NULL) q.push(nx->next[a]);
		nx->label.clear();
		delete nx;
	}
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%s",main_in);
		scanf("%d",&query);
		Trie *root = new Trie();
		for(int a=0;a<query;a++)
		{
			scanf("%s",q_in);
			mark[a] = false;
			build_Trie(&root,a);
		}
		build_Automation(root);
		search_pattern(root);
		for(int a=0;a<query;a++) printf("%c\n",(mark[a]==true)?'y':'n');
		clear_Automation(root);
	}
}
