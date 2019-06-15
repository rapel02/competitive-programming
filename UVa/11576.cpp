#include<bits/stdc++.h>
using namespace std;

int z[15000];

string pattern,text;
string conc;
int plen,len,llen;

int Compare()
{
	int l = 0,r = 0;
	len = text.length();
	llen = len + plen + 1;
	for(int a=1;a<llen;a++)
	{
		if(a > r)
		{
			l = r = a;
			while(r<llen && conc[r-l] == conc[r]) r++;
			z[a] = r-l, r--; 
		}
		else
		{
			int k = a-l;
			if(z[k] < (r - a + 1) ) z[a]= z[k];
			else
			{
				l = a;
				while(r<llen && conc[r-l] == conc[r]) r++;
				z[a] = r-l, r--; 
			}
		}
	}
	bool fin = false;
	int idx = 0;
	for(int a=0;a<llen;a++)
	{
		if(conc[a]=='$') fin = true;
		else if(fin==true && z[a] + a == llen) return z[a];
	}
	return 0;
}

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int k,w;
		cin>>k>>w;
		cin>>pattern;
		plen = pattern.length();
		for(int a=1;a<w;a++)
		{
			cin>>text;
			conc = text + "$" + pattern;
			int ans = Compare();
			pattern+= text.substr(ans);
			plen += (len - ans);
		}
		printf("%d\n",plen);
	}
}
