#include<bits/stdc++.h>
using namespace std;

struct data{
	string in;
	int x,y;
}p[250000];


string dfs(double x,double y,double s,int dep)
{
	if(dep == 0) return "";
	string ans = "";
	double s2 = s/2.0;
	if(x <= s2 && y<=s2) ans = "a" + dfs(y,x,s2,dep-1);
	else if(x<=s2 && y > s2) ans = "b" + dfs(x,y-s2,s2,dep-1);
	else if(x>s2 && y > s2) ans = "c" + dfs(x-s2,y-s2,s2,dep-1);
	else ans = "d" + dfs(s2-y,s-x,s2,dep-1);
	return ans;
}

bool cmp(data a,data b)
{
	return a.in < b.in;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	double S;
	cin>>n>>S;
	double x,y;
	for(int a=0;a<n;a++)
	{
		cin>>p[a].x>>p[a].y;
		p[a].in = dfs(p[a].x,p[a].y,S,40);
	}
	sort(p,p+n,cmp);
	for(int a=0;a<n;a++) cout<<p[a].x<<" "<<p[a].y<<"\n";
}
