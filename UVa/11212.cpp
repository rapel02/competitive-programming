#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;

long long arr[15];
int ans = 0;
int n;
long long ppow[15];
long long anw = 0;
bool err;

map<long long,pair<int,int> > mmap;
queue<pair<long long,int> > q;

void bfs(long long num,int wew)
{
	while(!q.empty()) q.pop();
	if(wew==1) mmap[num].ff = 1;
	else mmap[num].ss = 1;
	q.push(mp(num,1));
	while(!q.empty())
	{
		long long num = q.front().ff;
		int step = q.front().ss;
		q.pop();
		if(mmap[num].ff!=0 && mmap[num].ss!=0)
		{
			ans = min(ans,mmap[num].ff + mmap[num].ss);
			continue;
		}
		if(step==4) continue;
		//printf("%lld\n",num);
		for(int a=1;a<n;a++)
		{
			for(int b=0;b<n-a+1;b++)
			{
				long long temp = num;
				long long fr = temp/ppow[b+a];
				long long be = temp%ppow[b];
				long long pk = (temp%ppow[b+a])/ppow[b];
				long long nm = fr*ppow[b] + be;
				//printf("%d %d %lld %lld %lld %lld\n",a,b,fr,be,pk,nm);
				for(int c=0;c<=n-a;c++)
				{
					long long mow = pk*ppow[c];
					long long frt = nm/ppow[c] * ppow[c+a];
					long long brt = nm%ppow[c];
					long long nww = frt + mow + brt;
					if(wew==1)
					{
						if(mmap[nww].ff==0)
						{
							mmap[nww].ff = step+1;
							q.push(mp(nww,step+1));
					 	}
					}
					else if(wew==2)
					{
						if(mmap[nww].ss==0)
						{
							mmap[nww].ss = step+1;
							q.push(mp(nww,step+1));
						}
					}
					if(mmap[nww].ff!=0 && mmap[nww].ss!=0)
					{
						//printf("%lld %d %d\n",nww,mmap[nww].ff,mmap[nww].ss);
						ans = min(ans,mmap[nww].ff + mmap[nww].ss);
					}
				}
			}
		}
	}
	if(wew==1 && mmap[anw].ff!=0)
	{
		ans = mmap[anw].ff+1;
		err = false;
		return ;
	} 
}

int main()
{
	int tc = 0;
	ppow[0] = 1;
	for(int a=1;a<14;a++) ppow[a] = ppow[a-1] * 10LL;
	while(scanf("%d",&n),n)
	{
		tc++;
		mmap.clear();
		ans = 11500;
		long long tot = 0;
		anw = 0;
		for(int a=0;a<n;a++)
		{
			scanf("%lld",&arr[a]);
			tot = tot*10 + arr[a];
			anw = anw*10 + (a+1);
		}
		err = true;
		bfs(tot,1);
		if(err==true) bfs(anw,2);
		printf("Case %d: %d\n",tc,ans-2);
	}
}
