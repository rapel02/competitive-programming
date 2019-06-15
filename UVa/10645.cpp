#include<bits/stdc++.h>
#define INF 1e+7
#define ff first
#define ss second
#define mp make_pair
using namespace std;

pair<double,int> dp[22][105][22][55];
int rem[22][105][22][55];

double p[55];
int v[55];
int k,n,m;

pair<double,int> compute(int day,int mon,int rep,int f)
{
	if(mon > m) return mp(-INF,INF);
	if(day==k) return mp(0,0);
	if(dp[day][mon][rep][f].ff!=-INF) return dp[day][mon][rep][f];
	pair<double,int> &ans = dp[day][mon][rep][f];
	ans = mp(-INF,INF);
	for(int a=1;a<=n;a++)
	{
		pair<double,int> temp;
		if(f==a)
		{
			temp = compute(day+1,mon + p[a],rep+1,f);
			temp.ss+=p[a];
			if(rep==0) temp.ff += v[a]/(2.0);
		}
		else
		{
			temp = compute(day+1,mon + p[a],0,a);
			temp.ss += p[a];
			temp.ff += v[a];
		}
		if(temp.ff > ans.ff)
		{
			ans = temp;
			rem[day][mon][rep][f] = a;
		}
		if(temp.ff==ans.ff)
		{
			if(temp.ss < ans.ss)
			{
				ans = temp;
				rem[day][mon][rep][f] = a;
			}
		}
	}
	return ans;
}

void backtrack(int day,int mon,int rep,int f)
{
	if(day==k)
	{
		printf("\n");
		return ;
	}
	int val = rem[day][mon][rep][f];
	if(day!=0) printf(" ");
	printf("%d",val);
	if(val==f) backtrack(day+1,mon+p[val],rep+1,val);
	else backtrack(day+1,mon+p[val],0,val);
}

int main()
{
	bool ff = true;
	while(scanf("%d %d %d",&k,&n,&m)!=EOF)
	{
		if(!ff) printf("\n");
		ff = false;
		if(k==0 && n==0 && m==0) break;
		for(int a=1;a<=n;a++) scanf("%lf %d",&p[a],&v[a]);
		for(int a=0;a<22;a++) for(int b=0;b<105;b++)
		for(int c=0;c<22;c++) for(int d=0;d<55;d++) dp[a][b][c][d] = make_pair(-INF,INF);
		pair<double,int> ans = compute(0,0,0,0);
		//cout<<ans.ff<<" "<<ans.ss<<endl;
		if(ans.ff<0)
		{
			printf("%.1lf\n",0.0);
		}
		else
		{
			printf("%.1lf\n",ans.ff);
			backtrack(0,0,0,0);
		}
	}
}
