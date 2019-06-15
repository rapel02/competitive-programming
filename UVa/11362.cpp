#include<bits/stdc++.h>
using namespace std;

static const int apb = 10;

bool nee = false;
string in[15000];
int len;

struct trie{
	struct trie *chara[10];
};

void insert(struct trie ** a,int pos,int k)
{
	if(pos==len) return ;
	int val = in[k][pos]-'0';
	if((*a)->chara[val]==NULL)
	{
		nee = true;
		struct trie *temp = (struct trie *) malloc(sizeof(struct trie));
		for(int i=0;i<apb;i++) temp->chara[i] = NULL;
		(*a)->chara[val] = temp;
	}
	insert(&((*a)->chara[val]),pos+1,k);
}

bool cmp(string a,string b)
{
	return a.size()>b.size();
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		struct trie *root = (struct trie *) malloc(sizeof(struct trie));
		for(int i=0;i<apb;i++) root->chara[i] = NULL;
		scanf("%d",&n);
		bool ada = true;
		for(int a=0;a<n;a++)
		{
			cin>>in[a];	
		}
		sort(in,in+n,cmp);
		for(int a=0;a<n;a++)
		{
			nee = false;
		//	cout<<in[a]<<endl;
			len = in[a].length();
			insert(&root,0,a);
			if(nee==false) ada = false;
		}
		if(ada==true) printf("YES\n");
		else printf("NO\n");
	}
}
