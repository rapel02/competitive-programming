#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
using namespace std;

vector<pair<int,int> > vec[2][2][250];

int arr[2][250];
bool vis[2][2][250];

stack <pair<int,int> > ss;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int s,aa,m;
		scanf("%d %d %d",&s,&aa,&m);
		memset(vis,false,sizeof(vis));
		for(int b=0;b<m;b++)
		{
			int s1,a1,s2,a2;
			scanf("%d %d %d %d",&s1,&a1,&s2,&a2);
			vec[1][1][s1].pb(mp(1,s2));
			vec[1][1][s1].pb(mp(0,a2));
			vec[1][0][a1].pb(mp(1,s2));
			vec[1][0][a1].pb(mp(0,a2));
			vec[1][1][s2].pb(mp(1,s1));
			vec[1][1][s2].pb(mp(0,a1));
			vec[1][0][a2].pb(mp(1,s1));
			vec[1][0][a2].pb(mp(0,a1));
			vec[0][1][s1].pb(mp(1,-s2));
			vec[0][1][s1].pb(mp(0,-a2));
			vec[0][0][a1].pb(mp(1,-s2));
			vec[0][0][a1].pb(mp(0,-a2));
			vec[0][1][s2].pb(mp(1,-s1));
			vec[0][1][s2].pb(mp(0,-a1));
			vec[0][0][a2].pb(mp(1,-s1));
			vec[0][0][a2].pb(mp(0,-a1));			
		}
		bool ada=true;
		for(int a=0;a<2;a++)
		{
			for(int b=0;b<s;b++)
			{
				if(vec[a][1][b].size()!=0)
				{
					if(vis[a][1][b]==false)
					{
						memset(arr,0,sizeof(arr));
						vis[a][1][b]=true;
						if(a==1)arr[1][b]=b;
						else arr[1][b]=-b;
						if(a==1) ss.push(mp(1,b));
						else ss.push(mp(1,-b));
						while(!ss.empty())
						{
							int sb=ss.top().ff;
							int val=ss.top().ss;
							ss.pop();
							int idx=1;
							if(val<0) idx=0;
							vis[idx][sb][abs(val)]=true;
							for(int d=0;d<vec[idx][sb][val].size();d++)
							{
								int temp1=vec[idx][sb][val][d].ff;
								int temp2=vec[idx][sb][val][d].ss;
								int idx2=1;
								if(temp2<0) idx2=0;
								if(vis[idx2][temp1][abs(temp2)]==false)
								{
									if(arr[temp1][abs(temp2)]+temp2==0) ada=false;
									else
									{
										arr[temp1][abs(temp2)]+=temp2;
										ss.push(mp(temp1,temp2));
									}
								}
							}
						}
					}
				}
			}
		}
		if(ada==true)
		{
			for(int a=0;a<2;a++)
			{
				for(int b=0;b<s;b++)
				{
					if(vec[a][0][b].size()!=0)
					{
						if(vis[a][0][b]==false)
						{
							memset(arr,0,sizeof(arr));
							vis[a][0][b]=true;
							if(a==1)arr[0][b]=b;
							else arr[0][b]=-b;
							if(a==1) ss.push(mp(0,b));
							else ss.push(mp(0,-b));
							while(!ss.empty())
							{
								int sb=ss.top().ff;
								int val=ss.top().ss;
								ss.pop();
								int idx=1;
								if(val<0) idx=0;
								vis[idx][sb][abs(val)]=true;
								for(int d=0;d<vec[idx][sb][val].size();d++)
								{
									int temp1=vec[idx][sb][val][d].ff;
									int temp2=vec[idx][sb][val][d].ss;
									int idx2=1;
									if(temp2<0) idx2=0;
									if(vis[idx2][temp1][abs(temp2)]==false)
									{
										if(arr[temp1][abs(temp2)]+temp2==0) ada=false;
										else
										{
											arr[temp1][abs(temp2)]+=temp2;
											ss.push(mp(temp1,temp2));
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(ada==true) printf("Yes\n");
		else printf("No\n");
	}
}
