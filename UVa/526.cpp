#include<bits/stdc++.h>
using namespace std;

int dp[250][250];
int par[250][250];
int len1,len2;
string in1,in2;

int compute(int l,int r)
{
	if(l == len1) return len2 - r;
	if(r == len2) return len1 - l;
	int &ans = dp[l][r];
	if(ans != -1) return ans;
	ans = 10000;
	if(in1[l] == in2[r])
	{
		par[l][r] = 0;
		ans = compute(l+1,r+1);
	}
	else
	{
		ans = compute(l+1,r) + 1; //Delete
		par[l][r]= 1;
		int v1 = compute(l,r+1) + 1;	//Insert
		if(ans > v1) par[l][r] = 2,ans = v1;
		v1 = compute(l+1,r+1) + 1;	//Replace
		if(ans > v1) par[l][r] = 3,ans = v1;
	}
	return ans;
}

int stp = 0;
int s = 1;

void print(int l,int r)
{
	if(l == len1)
	{
		for(int a=r;a<len2;a++)
		{
			printf("%d Insert %d,%c\n",++stp,s + l,in2[a]);
			s++;
		}
	}
	else if(r == len2)
	{
		for(int a=l;a<len1;a++) 
		{
			printf("%d Delete %d\n",++stp,s + l);
		}
	}
	else
	{
		if(par[l][r] == 0) print(l+1,r+1);
		else
		{
			if(par[l][r] == 1)
			{
				printf("%d Delete %d\n",++stp,s + l);
				s--;
				print(l+1,r);
			}
			else if(par[l][r] == 2)
			{
				printf("%d Insert %d,%c\n",++stp,s + l,in2[r]);
				s++;
				print(l,r+1);
			}
			else
			{
				printf("%d Replace %d,%c\n",++stp,s + l,in2[r]);
				print(l+1,r+1);
			}
		}
	}
	return ;
}

int main()
{
	bool isf = true;
	while(getline(cin,in1))
	{
		stp = 0;
		s = 1;
		if(!isf) printf("\n");
		isf = false;
		getline(cin,in2);
		len1 = in1.length();
		len2 = in2.length();
		memset(dp,-1,sizeof(dp));
		memset(par,0,sizeof(par));
		printf("%d\n",compute(0,0));
		print(0,0);
	}
}
