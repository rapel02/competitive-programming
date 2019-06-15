#include<bits/stdc++.h>
using namespace std;

string in[105];
string tar;

int len1,len2;

int P[150000];

void KMP_PROCESS()
{
	len1 = tar.length();
	int i=0,j=-1;
	P[i] = j;
	while(i!=len1)
	{
		while(j>=0 && tar[i] != tar[j]) j = P[j];
		i++;
		j++;
		P[i] = j;
	}
}

long long KMP_SEARCH(int n)
{
	len2 = in[n].length();
	int i=0,j=0;
	long long tot = 0;
	while(i!=len2)
	{
		while(j>=0 && tar[j] !=in[n][i]) j = P[j];
		j++;
		i++;
		if(j == len1)
		{
			tot++;
			j = P[j];
		}
	}
	return tot;
}

long long total[150];

long long Occurence(int n)
{
	total[25] = KMP_SEARCH(25);
	total[26] = KMP_SEARCH(26);
	in[100] = "";
	int lo2 = in[26].length();
	for(int a=lo2-len1 + 1;a<lo2;a++)
	{
		in[100] += in[26][a];
	}
	int lo3 = in[25].length();
	for(int a=0;a<len1-1;a++)
	{
		in[100] += in[25][a];
	}
	long long trans1 = KMP_SEARCH(100);
	
	
	in[100] = "";
	lo2 = in[27].length();
	for(int a=lo2-len1 + 1;a<lo2;a++)
	{
		in[100] += in[27][a];
	}
	lo3 = in[26].length();
	for(int a=0;a<len1-1;a++)
	{
		in[100] += in[26][a];
	}
	long long trans2 = KMP_SEARCH(100);
	
	
	for(int a=27;a<=n;a++)
	{
		total[a] = total[a-1] + total[a-2];
		if(a%2==1) total[a] += trans1;
		else total[a] += trans2;
	}
	return total[n];
}

void pre()
{
	in[0] = "0";
	in[1] = "1";
	for(int a=2;a<=28;a++)
	{
		in[a] = in[a-1] + in[a-2];
	}
}

int main()
{
	pre();
	int tc = 0;
	int n;
	while(cin>>n)
	{
		tc++;
		cin>>tar;
		KMP_PROCESS();
		if(n <= 28)
		{
			long long ans = KMP_SEARCH(n);
			printf("Case %d: %lld\n",tc,ans);
		}
		else
		{
			printf("Case %d: %lld\n",tc,Occurence(n));
		}
	}
}
