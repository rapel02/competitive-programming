#include<bits/stdc++.h>
using namespace std;

string in1[150],in2[150];
int dp[150][150];
int i,j;
int dir[150][150];

stack<string> s;

int LCS(int i,int j)
{
	if(i < 0 || j < 0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	if(in1[i] == in2[j])
	{
		dir[i][j] = 2;
		return dp[i][j] = LCS(i-1,j-1) + 1; 
	}
	else
	{
		int v1 = LCS(i-1,j);
		int v2 = LCS(i,j-1);
		if(v1 > v2)
		{
			dir[i][j] = 0;
			return dp[i][j] = v1;
		}
		else
		{
			dir[i][j] = 1;
			return dp[i][j] = v2;
		}
	}
}

void backtrack(int i,int j)
{
	if(i < 0 || j < 0) return ;
	if(dir[i][j] == 2)
	{
		s.push(in1[i]);
		backtrack(i-1,j-1);
	}
	else if(dir[i][j] == 0) backtrack(i-1,j);
	else backtrack(i,j-1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>in1[i])
	{
		memset(dp,-1,sizeof(dp));
		if(in1[i]!="#")
		{
			i++;
			while(cin>>in1[i])
			{
				if(in1[i]=="#") break;
				i++;
			}
		}
		while(cin>>in2[j])
		{
			if(in2[j] =="#") break;
			j++;
		}
		LCS(i-1,j-1);
		backtrack(i-1,j-1);
		bool isf = true;
		while(!s.empty())
		{
			if(!isf) cout<<" ";
			isf = false;
			cout<<s.top();
			s.pop();
		}
		cout<<endl;
		i = 0,j = 0;
	}
}
